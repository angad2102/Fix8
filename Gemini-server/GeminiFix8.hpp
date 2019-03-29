#ifndef FIX8_CODECTIMING
#define FIX8_CODECTIMING
#endif

class gemini_session_server;

class gemini_router_server : public FIX8::GEMINI::gemini_Router{
	gemini_session_server& _session;
public :
	gemini_router_server(gemini_session_server& session) : _session(session) {}
	virtual bool operator() (const FIX8::GEMINI::NewOrderSingle *msg) const;
};

class gemini_session_server : public FIX8::Session{
	gemini_router_server _router;
public:
	gemini_session_server(const FIX8::F8MetaCntx& ctx, const FIX8::sender_comp_id& sci, FIX8::Persister *persist=nullptr,
		FIX8::Logger *logger=nullptr, FIX8::Logger *plogger=nullptr) : Session(ctx, sci, persist, logger, plogger),
		_router(*this) {}
	bool handle_application(const unsigned seqnum, const FIX8::Message *&msg);

	/*! This method id called whenever a session state change occurs
	    \param before previous session state
	    \param after new session state */
	bool sample_scheduler_callback();
	void state_change(const FIX8::States::SessionStates before, const FIX8::States::SessionStates after);
};
