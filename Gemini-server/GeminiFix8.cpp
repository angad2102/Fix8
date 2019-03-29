//============================================================================
// Name        : GeminiFix8.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <memory>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <vector>
#include <iterator>
#include <algorithm>
#include <typeinfo>
#include <thread>
#ifdef _MSC_VER
#include <signal.h>
#include <conio.h>
#else
#include <sys/ioctl.h>
#include <signal.h>
#include <termios.h>
#endif

#include <errno.h>
#include <string.h>

// f8 headers
#include <fix8/f8includes.hpp>
//#include <fix8/zeromq_mbus.hpp>

#ifdef FIX8_HAVE_GETOPT_H
#include <getopt.h>
#endif

#include <fix8/usage.hpp>
#include <fix8/consolemenu.hpp>
#include <fix8/multisession.hpp>
#include "gemini_types.hpp"
#include "gemini_router.hpp"
#include "gemini_classes.hpp"

#include "GeminiFix8.hpp"

using namespace std;
using namespace FIX8;

f8_atomic<bool> term_received(false);


void sig_handler(int sig)
{
   switch (sig)
   {
   case SIGTERM:
   case SIGINT:
#ifndef _MSC_VER
   case SIGQUIT:
#endif
		term_received = true;
		signal(sig, sig_handler);
		break;
   }
}

int main() {
	signal(SIGTERM, sig_handler);
	signal(SIGINT, sig_handler);
	ServerSession<gemini_session_server>::ServerSession_ptr ms(new ServerSession<gemini_session_server>(GEMINI::ctx(), "myfix_server.xml", "TEX1"));
 	Message::report_codec_timings("server");
	while (!term_received)
	{
	    if (!ms->poll())
	        continue;
	    SessionInstance<gemini_session_server>::SessionInstance_ptr inst(new SessionInstance<gemini_session_server>(*ms));
	    inst->start(true);
	    inst->stop();
	}
	return 0;
}

bool gemini_session_server::handle_application(const unsigned seqnum, const Message *&msg)
{
	return enforce(seqnum, msg) || msg->process(_router);
}

void gemini_session_server::state_change(const FIX8::States::SessionStates before, const FIX8::States::SessionStates after)
{
	cout << get_session_state_string(before) << " => " << get_session_state_string(after) << endl;
}

bool gemini_router_server::operator() (const GEMINI::NewOrderSingle *msg) const
{
	Message::report_codec_timings("server");
	cout<<"Good till here "<<endl;
	
	GEMINI::OrderQty qty;
	GEMINI::Price price;
	if (msg->get(qty))
		cout << "Order qty (copy):" << qty() << endl;

	if (msg->get(price))
		cout << "price:" << price() << endl;
	
return true; 
}

bool gemini_session_server::sample_scheduler_callback()
{
	cout << "myfix_session_server::sample_scheduler_callback Hello!" << endl;
	return true;
}


