
#define _CRT_SECURE_NO_WARNINGS

#include "master.h"
#include "mem_slave.h"

using user::master;
using user::mem_slave;


int sc_main(int argc, char **argv)
{

	master m1("master");
	master m2("master", 5);
	master m3("master", 'c');
	mem_slave s("slave", 4096);

	m1.initiator_port(s.target_port1);
	m2.initiator_port(s.target_port2);
	m3.initiator_port(s.target_port3);
	

	sc_start(10000, SC_NS);
	
	return 0;

}
