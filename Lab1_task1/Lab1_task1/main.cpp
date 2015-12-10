#define _CRT_SECURE_NO_WARNINGS

#include "testbench.h"
#include "or_gate.h"
#include "systemc.h"

int sc_main(int argc, char *argv[])
{
	sc_signal<sc_bit> t_a, t_b, t_c; // signals used to connect all the modules
	
	//or_gate *g1;
	//g1 = new or_gate("g1");
	
	driver *d1;
	d1 = new driver("d1");
	
	monitor *m1;
	m1 = new monitor("m1");
	
	//g1->a(t_a);
	//g1->b(t_b); // name binding
	//g1->c(t_c);

	or_gate g1("g1");
	g1 (t_a, t_b, t_c);
	//g1->b(t_b); // port binding
	//g1->c(t_c);
	
	d1->d_a(t_a);
	d1->d_b(t_b);
	
	m1-> m_a(t_a);
	m1-> m_b(t_b);
	m1-> m_c(t_c);
	
	sc_start(100,SC_NS); //starts the simulation and run
	
	return 0;
	
	
}