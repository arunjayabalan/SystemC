#define _CRT_SECURE_NO_WARNINGS

#include "mem_slave.h"

using user::mem_slave;

using basic_protocol::basic_status;

mem_slave::mem_slave(sc_module_name module_name, int mem_size) :
	sc_module(module_name),
	target_port("iport")
{

	target_port(*this);

	memory = new ADDRESS_TYPE[mem_size]; //instantiates 4K of memory
}

basic_status mem_slave::write(const ADDRESS_TYPE &a, const DATA_TYPE &d)
{

	Writes++;
	memory[a] = d;
	return basic_protocol::SUCCESS;
}

basic_status mem_slave::read(const ADDRESS_TYPE &a, DATA_TYPE &d)
{

	d = memory[a];
	Reads++;
	//cout << name() << " reading from " << a << " value " << d << endl;
	return basic_protocol::SUCCESS;
}

void mem_slave::print(){

	cout << "Total number of Write Transactions : " << Writes++ << endl;
	cout << "Total number of Read  Transactions : " << Reads++ << endl;

}

mem_slave::~mem_slave() {

	
	delete[] memory;

}
