#define _CRT_SECURE_NO_WARNINGS

#include "Node.h"

using user::Node;

Node::Node(sc_module_name module_name, int k) :
	sc_module(module_name),
	initiator_port("iport")
	,target_port("sport0")

{
	SC_THREAD(write);
	target_port(*this);

	memory = new ADDRESS_TYPE[k *1024 ]; //instantiates 4K of memory
	mem = fopen("E:\EIT_ICT_Labs\Second_Year\SystemC\Lab3\files\node0.txt", "r");
	if (!mem) { cout << "Could not open the file"; }
	
}

basic_status Node::write(const ADDRESS_TYPE &a, DATA_TYPE &d) {
	DATA_TYPE d;
	ADDRESS_TYPE a;
	while (fscanf(mem, "%a %d", &d, &a) != EOF) {

		initiator_port.write(a, d);
		writes++;

	}

}

basic_status Node::read(const ADDRESS_TYPE &a, DATA_TYPE &d) {
	
	memory[a] = d;
	reads++;
	cout << "Data written into Memory is: " << d << endl;
	return basic_protocol::SUCCESS;

}
/*void Node::read() {

	DATA_TYPE d;
	ADDRESS_TYPE a;
	target_port.read(a, d);

	reads++;
}*/

void Node::print() {

	cout << "Number of Reads : "  << reads << endl;
	cout << "Number of Writes : " << writes << endl;
}

Node::~Node() {
	
	delete[] memory;
}
/*
void Node::write()
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
*/