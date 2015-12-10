#define _CRT_SECURE_NO_WARNINGS

#include "master.h"

using user::master;

master::master(sc_module_name module_name) :
	sc_module(module_name),
	initiator_port("iport")
{
	SC_THREAD(write1);
}

master::master(sc_module_name module_name, int k) :
	sc_module(module_name),
	initiator_port("iport")
{
	SC_THREAD(write2);
}

master::master(sc_module_name module_name, char k) :
	sc_module(module_name),
	initiator_port("iport")
{
	SC_THREAD(read3);
}


void master::write1()
{

	DATA_TYPE d = 1;

	for (ADDRESS_TYPE a = 0; a < 20; a++)
	{
		wait(5, SC_NS);	// Delay is added so that we can test concurrency by not finishing this module till others starts
		while (initiator_port.read_flag(a, d) != basic_protocol::ERROR);
		cout << "Writing Address " << a << " value " << d << endl;
		initiator_port.write(a,d);

	}

	
	//initiator_port.print();
}

void master::write2()
{

	DATA_TYPE d=2;

	for (ADDRESS_TYPE a = 0; a < 20; a++)
	{
		wait(5, SC_NS);
		while (initiator_port.read_flag(a,d) != basic_protocol::ERROR);
		cout << "Writing Address " << a << " value " << d << endl;
		initiator_port.write(a, d);
	}

}

void master::read3()
{
	DATA_TYPE d;
	
	for (ADDRESS_TYPE a = 0; a < 20; a++)
	{
		wait(5, SC_NS);
		while (initiator_port.read_flag(a, d) != basic_protocol::ERROR);
		initiator_port.read(a, d);
		cout << "Read Address " << a << " got " << d << endl;

	}

}