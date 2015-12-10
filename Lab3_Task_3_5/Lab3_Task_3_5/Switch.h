#define _CRT_SECURE_NO_WARNINGS
#pragma once


#include "systemc.h"

#include "bus_types.h"
#include "basic_initiator_port.h"
#include "basic_slave_base.h"

using basic_protocol::basic_status;
using basic_protocol::basic_slave_base;
using tlm::tlm_transport_if;
using basic_protocol::basic_initiator_port;

namespace user
{

	class switching_master : public sc_module, public virtual basic_slave_base< ADDRESS_TYPE, DATA_TYPE >
	{
	public:
		switching_master(sc_module_name module_name);

		sc_export< if_type > target_port0;
		sc_export< if_type > target_port1;
		sc_export< if_type > target_port2;
		sc_export< if_type > target_port3;
		
		basic_initiator_port<ADDRESS_TYPE, DATA_TYPE> initiator_port0;
		basic_initiator_port<ADDRESS_TYPE, DATA_TYPE> initiator_port1;
		basic_initiator_port<ADDRESS_TYPE, DATA_TYPE> initiator_port2;
		basic_initiator_port<ADDRESS_TYPE, DATA_TYPE> initiator_port3;
		
	private:

		basic_status write(const ADDRESS_TYPE &, const DATA_TYPE &);
		basic_status read(const ADDRESS_TYPE &, DATA_TYPE &);
		basic_status read_flag(const ADDRESS_TYPE &, DATA_TYPE &);
		bool InProgress = false;
	};

};
