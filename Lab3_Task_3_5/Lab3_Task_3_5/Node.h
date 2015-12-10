#define _CRT_SECURE_NO_WARNINGS
#pragma once


#include "systemc.h"

#include "bus_types.h"
#include "basic_initiator_port.h"
#include "basic_slave_base.h"
#include "string.h"
using namespace std;

using basic_protocol::basic_status;
using basic_protocol::basic_slave_base;
using basic_protocol::basic_initiator_port;
using tlm::tlm_transport_if;

namespace user
{
	class Node : public sc_module, public virtual basic_slave_base< ADDRESS_TYPE, DATA_TYPE >
	{
	public:
		Node(sc_module_name module_name, int k, string file_name);
		basic_initiator_port<ADDRESS_TYPE, DATA_TYPE> initiator_port;
		sc_export<if_type> target_port;
	
		SC_HAS_PROCESS(Node);
		void print();
		

		~Node();

	private:
		void write();
		basic_status write(const ADDRESS_TYPE &, const DATA_TYPE &);
		basic_status read(const ADDRESS_TYPE &, DATA_TYPE &);
		

		FILE *mem;
		ADDRESS_TYPE *memory;
		ADDRESS_TYPE reads = 0;
		ADDRESS_TYPE writes = 0;

	};

	
};