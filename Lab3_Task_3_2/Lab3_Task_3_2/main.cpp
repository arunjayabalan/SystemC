
#define _CRT_SECURE_NO_WARNINGS

#include "master.h"
#include "mem_slave.h"
#include "switch_master.h"
#include "master_new.h"

using user::master;
using user::master_new;
using user::mem_slave;
using user::switching_master;

int sc_main(int argc, char **argv)
{

	//master m("master");
	master_new m("master");
	switching_master sw("switch");
	mem_slave s1("slave1", 4096);
	mem_slave s2("slave2", 4096);

	m.initiator_port(sw.target_port);
	sw.initiator_port1(s1.target_port);
	sw.initiator_port2(s2.target_port);

	sc_start(10000, SC_NS);
	cout << "Number of transactions from Slave Even: " << endl;
	s1.print();
	cout << "Number of transactions from Slave Odd: " << endl; 
	s2.print();
	return 0;

}
