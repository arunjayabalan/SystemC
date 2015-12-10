#define _CRT_SECURE_NO_WARNINGS
#pragma once

#ifndef MASTER_HEADER
#define MASTER_HEADER

#include <systemc.h>

#include "bus_types.h"
#include "basic_initiator_port.h"

using basic_protocol::basic_initiator_port;

namespace user
{

	class master : public sc_module
	{
	public:
		master(sc_module_name module_name);
		master(sc_module_name module_name, int k);
		master(sc_module_name module_name, char k);

		SC_HAS_PROCESS(master);

		basic_initiator_port<ADDRESS_TYPE, DATA_TYPE> initiator_port;

	private:
		void write1();
		void write2();
		void read3();

	};

};

#endif
