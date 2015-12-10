#define _CRT_SECURE_NO_WARNINGS

#include "Node.h"

using user::Node;
using namespace std;
std::string str;

Node::Node(sc_module_name module_name, int k, string filename) :
	sc_module(module_name),
	initiator_port("iport"),
	target_port("sport0")

{
	SC_THREAD(write);
	target_port(*this);

	memory = new ADDRESS_TYPE[k]; //instantiates 4K of memory
	mem = fopen(filename.c_str(), "r");
	if (!mem) { cout << "Could not open the file"; }
	
}


void Node::write() {
	DATA_TYPE d;
	ADDRESS_TYPE a;
	while (fscanf(mem, "%d %xn", &a, &d) != EOF) {
		//cout << "Node  " << d << "\t data  " << a << endl;
		while (initiator_port.read_flag(a, d) != basic_protocol::ERROR);
		initiator_port.write(a, d);
		wait(5, SC_NS);
	}

}

basic_status Node::write(const ADDRESS_TYPE &a, const DATA_TYPE &d) {

	memory[reads] = d;
	//cout << "Data written into Memory is: " << d << "and " << memory[reads] << endl;
	reads++;
	return basic_protocol::SUCCESS;

}

basic_status Node::read(const ADDRESS_TYPE &a, DATA_TYPE &d) { return basic_protocol::SUCCESS; }

void Node::print() {
	
	for (ADDRESS_TYPE n = 0; n < reads; n++) {

		cout << "Memory Read " << std::hex << memory[n] << endl;
	}
}

Node::~Node() {
	//print();
	delete[] memory;
}
