#define _CRT_SECURE_NO_WARNINGS
#define SC_INCLUDE_DYNAMIC_PROCESSES

#include "systemc.h"
#include "tlm.h"
#include "tlm_utils/simple_initiator_socket.h"
#include "tlm_utils/simple_target_socket.h"

class Memory : public sc_module
{
public:
	// TLM-2 socket, defaults to 32-bits wide, base protocol
	tlm_utils::simple_target_socket<Memory> socket;
	int *mem;
	int SIZE;
	//SC_CTOR(Memory) : socket("socket")
	Memory(sc_module_name name, int size)
	{
		// Register callback for incoming b_transport interface method call
		socket.register_b_transport(this, &Memory::b_transport);
		mem = new int[size];
		SIZE = size;
		// Initialize memory with random data
		for (int i = 0; i < size; i++)
			mem[i] = i;
	}

	// TLM-2 blocking transport method
	virtual void b_transport(tlm::tlm_generic_payload& trans, sc_time& delay);
	

	// mem[SIZE];
}; 
