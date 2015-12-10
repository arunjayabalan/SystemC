#define _CRT_SECURE_NO_WARNINGS
#pragma once


#include "systemc.h"

#include "bus_types.h"
#include "basic_initiator_port.h"
#include "basic_slave_base.h"

using basic_protocol::basic_status;
using basic_protocol::basic_slave_base;
using basic_protocol::basic_initiator_port;
using tlm::tlm_transport_if;

namespace user
{
	class Node : public sc_module, public virtual basic_slave_base< ADDRESS_TYPE, DATA_TYPE >
	{
	public:
		Node(sc_module_name module_name, int k=4);
		sc_export< if_type > target_port;
		basic_initiator_port<ADDRESS_TYPE, DATA_TYPE> initiator_port;
		~Node();

	private:
		basic_status write(const ADDRESS_TYPE &, DATA_TYPE &);
		basic_status read(const ADDRESS_TYPE &, DATA_TYPE &);
		void print();

		FILE *mem;
		ADDRESS_TYPE *memory;
		int reads = 0;
		int writes = 0;


	};

};
/*


namespace user
{

	class Node : public sc_module , public virtual basic_slave_base< ADDRESS_TYPE, DATA_TYPE >
	{
	public:
		Node(sc_module_name module_name, int k=4);

		SC_HAS_PROCESS(Node);

		sc_export <if_type> target_port;
		basic_initiator_port<ADDRESS_TYPE, DATA_TYPE> initiator_port;
		
		~Node();

	private:
		void write();
		basic_status read(const ADDRESS_TYPE &, DATA_TYPE &);
		void print();
		
		FILE *mem;
		ADDRESS_TYPE *memory;
		int reads = 0;
		int writes = 0;

	};

};

*/