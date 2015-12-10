#define _CRT_SECURE_NO_WARNINGS
#include "Switch.h"

using user::switching_master;

switching_master::switching_master(sc_module_name module_name) :
	sc_module(module_name),
	initiator_port0("iport0"),
	initiator_port1("iport1"),
	initiator_port2("iport2"),
	initiator_port3("iport3"),
	target_port0("sport0"),
	target_port1("sport1"),
	target_port2("sport2"),
	target_port3("sport3")
{
	target_port0(*this);
	target_port1(*this);
	target_port2(*this);
	target_port3(*this);
}


basic_status switching_master::write(const ADDRESS_TYPE &a, const DATA_TYPE &d)
{
	//cout << "Inside Switch a = " << a << endl;
	if (a == 0) {
		InProgress = true;
		initiator_port0.write(a, d);
		InProgress = false;
	}
	else if (a == 1) {
		InProgress = true;
		initiator_port1.write(a, d);
		InProgress = false;
	}
	else if (a == 2) {
		InProgress = true;
		initiator_port2.write(a, d);
		InProgress = false;
	}
	else if (a == 3) {
		InProgress = true;
		initiator_port3.write(a, d);
		InProgress = false;
	}
	else {
		return basic_protocol::ERROR;
	}
	return basic_protocol::SUCCESS;
}

basic_status switching_master::read_flag(const ADDRESS_TYPE &a, DATA_TYPE &d)
{
	cout << InProgress << endl;
	if (InProgress == false) return basic_protocol::SUCCESS;
	else return basic_protocol::ERROR;
}


basic_status switching_master::read(const ADDRESS_TYPE &a, DATA_TYPE &d) {
	return basic_protocol::SUCCESS;
}
