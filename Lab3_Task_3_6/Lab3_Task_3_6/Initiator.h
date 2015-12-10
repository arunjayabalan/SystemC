#define _CRT_SECURE_NO_WARNINGS
#define SC_INCLUDE_DYNAMIC_PROCESSES
#pragma once
/*using namespace sc_core;
using namespace sc_dt;
using namespace std;*/

#include "systemc.h"
#include "tlm.h"
#include "tlm_utils/simple_initiator_socket.h"
#include "tlm_utils/simple_target_socket.h"

// Initiator module generating generic payload transactions

class Initiator : public sc_module
{
public:
	// TLM-2 socket, defaults to 32-bits wide, base protocol
	tlm_utils::simple_initiator_socket<Initiator> socket;

	SC_CTOR(Initiator)
		: socket("socket")  // Construct and name socket
	{
		SC_THREAD(thread_process);
	}

	void thread_process();

	// Internal data buffer used by initiator with generic payload
	int data;
};
