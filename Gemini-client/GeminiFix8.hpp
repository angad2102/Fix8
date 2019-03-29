#ifndef FIX8_CODECTIMING
#define FIX8_CODECTIMING
#endif
class gemini_session_client;

class gemini_router_client : public FIX8::GEMINI::gemini_Router{
	gemini_session_client& _session;
public :
	gemini_router_client(gemini_session_client& session) : _session(session) {}
	virtual bool operator() (const FIX8::GEMINI::ExecutionReport *msg) const;
};

class gemini_session_client : public FIX8::Session{
	gemini_router_client _router;
public:
	gemini_session_client(const FIX8::F8MetaCntx& ctx, const FIX8::SessionID& sid, FIX8::Persister *persist=nullptr, FIX8::Logger *logger=nullptr, FIX8::Logger *plogger=nullptr) : Session(ctx, sid, persist, logger, plogger), _router(*this) {}
    bool handle_application(const unsigned seqnum, const FIX8::Message *&msg);
    void state_change(const FIX8::States::SessionStates before, const FIX8::States::SessionStates after);
};


class controller
{
	gemini_session_client& _session;

public:
	int x;
	controller(gemini_session_client& session) : _session(session){x=0;}
	bool sendOrderMsg();
	void WaitAndTestOrder(int sec);
};