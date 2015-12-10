
// All systemc modules should include systemc.h header file
#define _CRT_SECURE_NO_WARNINGS


#include "systemc.h"
#include "master.h"
#include "mem_slave.h"

using user::master;
using user::mem_slave;

int sc_main(int argc, char **argv)
{

	master m("master");
	mem_slave s("slave");

	m.initiator_port(s.target_port);
	
	sc_start(10000, SC_NS);
	s.print();
	return 0;

}
