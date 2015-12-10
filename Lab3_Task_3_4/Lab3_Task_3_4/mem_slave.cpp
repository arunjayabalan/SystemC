#define _CRT_SECURE_NO_WARNINGS

#include "mem_slave.h"

using user::mem_slave;

using basic_protocol::basic_status;

mem_slave::mem_slave(sc_module_name module_name, int mem_size) :
	sc_module(module_name),
	target_port1("iport1"), target_port2("iport2"), target_port3("iport3")
{

	target_port1(*this);
	target_port2(*this);
	target_port3(*this);

	memory = new ADDRESS_TYPE[mem_size]; //instantiates 4K of memory
}

basic_status mem_slave::write(const ADDRESS_TYPE &a, const DATA_TYPE &d)
{
	cout << InProgress << endl;
	InProgress = true;
	cout << InProgress << endl;
	Writes++;
	memory[a] = d;
	InProgress = false;
	return basic_protocol::SUCCESS;
}

basic_status mem_slave::read(const ADDRESS_TYPE &a, DATA_TYPE &d)
{
	InProgress = true;
	d = memory[a];
	Reads++;
	InProgress = false;
	//cout << name() << " reading from " << a << " value " << d << endl;
	return basic_protocol::SUCCESS;
}

basic_status mem_slave::read_flag(const ADDRESS_TYPE &a, DATA_TYPE &d)
{
	cout << InProgress << endl;
	if(InProgress == false) return basic_protocol::SUCCESS;
	else return basic_protocol::ERROR;
}


void mem_slave::print(){

	cout << "Total number of Write Transactions : " << Writes++ << endl;
	cout << "Total number of Read  Transactions : " << Reads++ << endl;

}

mem_slave::~mem_slave() {

	
	delete[] memory;

}
