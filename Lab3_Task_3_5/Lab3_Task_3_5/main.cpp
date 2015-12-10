
#define _CRT_SECURE_NO_WARNINGS

#include "Node.h"
#include "Switch.h"

using user::Node;
using user::switching_master;


int sc_main(int argc, char **argv)
{
	Node n0("Node0", 1024, "files\\node0.txt");
	Node n1("Node1", 1024, "files\\node1.txt");
	Node n2("Node2", 1024, "files\\node2.txt");
	Node n3("Node3", 1024, "files\\node3.txt");
	switching_master sw("switch");

	n0.initiator_port(sw.target_port0);
	n1.initiator_port(sw.target_port1);
	n2.initiator_port(sw.target_port2);
	n3.initiator_port(sw.target_port3);

	sw.initiator_port0(n0.target_port);
	sw.initiator_port1(n1.target_port);
	sw.initiator_port2(n2.target_port);
	sw.initiator_port3(n3.target_port);

	sc_start(10000, SC_NS);
	cout << "Printing for object 0" << endl;
	n0.print();
	cout << "Printing for object 1" << endl;
	n1.print();
	cout << "Printing for object 2" << endl;
	n2.print();
	cout << "Printing for object 3" << endl;
	n3.print();
	return 0;

}
