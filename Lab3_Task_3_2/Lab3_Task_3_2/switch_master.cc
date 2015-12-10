#define _CRT_SECURE_NO_WARNINGS
#include "switch_master.h"

using user::switching_master; 

switching_master::switching_master(sc_module_name module_name):
	sc_module(module_name),
	initiator_port1("iport1"),
	initiator_port2("iport2"),
	target_port("sport")
{
	target_port(*this);
}


basic_status switching_master::write(const ADDRESS_TYPE &a, const DATA_TYPE &d)
{

	if (a % 2 == 0) {

		initiator_port1.write(a, d);
	}
	else {

		initiator_port2.write(a, d);
	}
	return basic_protocol::SUCCESS;
}

basic_status switching_master::read(const ADDRESS_TYPE &a, DATA_TYPE &d)
{

	if (a % 2 == 0) {
		initiator_port1.read(a,d);
	}
	else {
		initiator_port2.read(a,d);
	}
	return basic_protocol::SUCCESS;
}

