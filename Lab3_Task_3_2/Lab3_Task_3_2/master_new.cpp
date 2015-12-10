#define _CRT_SECURE_NO_WARNINGS

#include "master_new.h"
#include "math.h"

using user::master_new;

master_new::master_new(sc_module_name module_name) :
	sc_module(module_name),
	initiator_port("iport")
{
	SC_THREAD(run);
}

void master_new::run()
{
	for (int rep = 0; rep < 5; rep++)
	{
		DATA_TYPE d, write_data, sum = 0;
		ADDRESS_TYPE a;

		for (int j = 0; j < 10; j++)
		{
			a = addr[j];
			write_data = rand() % 19 + 1; //srand() % 19 + 1;
			cout << "Writing Address " << a << " value " << write_data << endl;
			initiator_port.write(a, write_data);

		}

		for (int j = 0; j < 10; j++)
		{
			a = addr[j];
			initiator_port.read(a, d);
			cout << "Read Address " << a << " got " << d << endl;
			sum += d;
		}
		cout << "Sum is :" << sum << "\t Average is : " << sum / 10.0 << endl;
	}
}
