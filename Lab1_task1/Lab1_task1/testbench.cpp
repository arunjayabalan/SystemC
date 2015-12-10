#define _CRT_SECURE_NO_WARNINGS
#include "testbench.h"

//these are the two processes to generate stimuli for OR gate

void driver::drivea()
{

	d_a.write((sc_bit)false); //b a = 00
	//wait(5, SC_NS);
	next_trigger(5, SC_NS);

	d_a.write((sc_bit)true); // b a = 01
	//wait(5, SC_NS);
	next_trigger(5, SC_NS);

	d_a.write((sc_bit)0); // b a = 10, false
	//wait(5, SC_NS);
	next_trigger(5, SC_NS);

	d_a.write((sc_bit)1); // ba = 11, true
	//wait(5,SC_NS);
	next_trigger(5, SC_NS);
}

void driver::driveb()
{
	d_b.write((sc_bit)0);
	//wait(10, SC_NS);
	next_trigger(10, SC_NS);
	d_b.write((sc_bit)1);
	//wait(5,SC_NS);
	next_trigger(5, SC_NS);

}

// block name = monitor

void monitor::prc_monitor()
{
	//cout << "AT\t" << sc_simulation_time() << "\tinput is :  \t";
	cout << "AT\t" << sc_time_stamp() << "\tinput is :  \t";
	cout << m_b << "," << m_a << "\t output is :\t" << m_c << endl;
	
}

