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
#include <stdlib.h>
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
#include <unistd.h>

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

//controller newController; 

int main() {
	ReliableClientSession<gemini_session_client>::ReliableClientSession_ptr mc(new ReliableClientSession<gemini_session_client>(GEMINI::ctx(), "myfix_client.xml", "DLD1"));
	controller main_controller(*mc->session_ptr());
	thread t1(&controller::WaitAndTestOrder,main_controller,1);
	mc->start(true);
	return 0;
}

bool controller::sendOrderMsg(){
	//cout<<"Hi";
	GEMINI::NewOrderSingle *nos(new GEMINI::NewOrderSingle);
	*nos += new GEMINI::TransactTime;
	*nos += new GEMINI::Symbol("BTCUSD");
	*nos += new GEMINI::OrdType(GEMINI::OrdType_LIMIT);
	*nos += new GEMINI::Side(GEMINI::Side_SELL);
	*nos += new GEMINI::OrderQty(1);
	*nos += new GEMINI::Price(4000);
	*nos += new GEMINI::ClOrdID(to_string(x++));
	*nos += new GEMINI::TimeInForce(GEMINI::TimeInForce_FILL_OR_KILL);
	//cout<<"Hello "<<endl;

	_session.send(nos);
	//delete nos; 
	return true;
}

void controller::WaitAndTestOrder(int sec){
	unsigned int microseconds = sec*1000000;
	usleep(microseconds);
	for(int i=0;i<100;i++){
		sendOrderMsg();	
	}
	Message::report_codec_timings("client");
}

bool gemini_session_client::handle_application(const unsigned seqnum, const Message *&msg)
{
	return enforce(seqnum, msg) || msg->process(_router);
}

void gemini_session_client::state_change(const FIX8::States::SessionStates before, const FIX8::States::SessionStates after)
{
	cout << get_session_state_string(before) << " => " << get_session_state_string(after) << endl;	
}

bool gemini_router_client::operator() (const GEMINI::ExecutionReport *msg) const
{
	GEMINI::OrdStatus status; 
	GEMINI::OrderID id;
	GEMINI::Text text; 
	GEMINI::ExecType type; 
	GEMINI::AvgPx price; 
	GEMINI::CumQty qty;

	cout<<endl<<endl<<"** New ER **"<<endl;
	if (msg->get(status))
	{
		cout<<"Status : "<<status<<endl;
	}
	if (msg->get(id))
	{
		cout<<"ID : "<<id<<endl;
	}
	if (msg->get(text))
	{
		cout<<"Text : "<<text<<endl;
	}
	if (msg->get(type))
	{
		cout<<"Type : "<<type<<endl;
	}
	if (msg->get(price))
	{
		cout<<"Price : "<<price<<endl;
	}
	if (msg->get(qty))
	{
		cout<<"Quantity : "<<qty<<endl;
	}
	return true;
}


