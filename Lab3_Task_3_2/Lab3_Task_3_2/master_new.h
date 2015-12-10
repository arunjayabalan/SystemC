#pragma once
#define _CRT_SECURE_NO_WARNINGS
#pragma once

#ifndef MASTER_NEW_HEADER
#define MASTER_NEW_HEADER

#include <systemc.h>

#include "bus_types.h"
#include "basic_initiator_port.h"

using basic_protocol::basic_initiator_port;

namespace user
{

	class master_new : public sc_module
	{
	public:
		master_new(sc_module_name module_name);

		SC_HAS_PROCESS(master_new);

		basic_initiator_port<ADDRESS_TYPE, DATA_TYPE> initiator_port;

		ADDRESS_TYPE addr[10] = { 11,15,12,3,33,35,21,18,55,41 };

	private:
		void run();

	};

};

#endif
