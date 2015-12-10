#define _CRT_SECURE_NO_WARNINGS

#include "master.h"

using user::master;

master::master(sc_module_name module_name) :
	sc_module(module_name),
	initiator_port("iport")
{
	SC_THREAD(run);

}

void master::run()
{

	DATA_TYPE d;

	for (ADDRESS_TYPE a = 0; a < 100; a++)
	{

		cout << "Writing Address " << a << " value " << a + 50 << endl;
		initiator_port.write(a, a + 200);

	}

	for (ADDRESS_TYPE a = 0; a < 100; a++)
	{

		initiator_port.read(a, d);
		cout << "Read Address " << a << " got " << d << endl;

	}

	//initiator_port.print();
}
