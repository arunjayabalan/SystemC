#define _CRT_SECURE_NO_WARNINGS

#ifndef MEM_SLAVE_HEADER
#define MEM_SLAVE_HEADER

#include "systemc.h"

#include "bus_types.h"
#include "basic_protocol.h"
#include "basic_slave_base.h"

using basic_protocol::basic_status;
using basic_protocol::basic_slave_base;
using tlm::tlm_transport_if;

namespace user
{

	class mem_slave :
		public sc_module,
		public virtual basic_slave_base< ADDRESS_TYPE, DATA_TYPE >
	{
	public:
		mem_slave(sc_module_name module_name, int mem_size);

		sc_export< if_type > target_port;
	

		basic_status write(const ADDRESS_TYPE &, const DATA_TYPE &);
		basic_status read(const ADDRESS_TYPE &, DATA_TYPE &);

		~mem_slave();
		void print();

	private:
		ADDRESS_TYPE *memory;
		int Reads = 0;
		int Writes = 0;

	};

};

#endif

