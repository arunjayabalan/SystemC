#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include "testbench.h"

void generate::proc_generate() {
	// Write => WE = 1 , CE = 1
	// Read => WE = 0, CE = 1 

	
	t_WE.write(0);
	t_CE.write(1);
	wait(5, SC_NS);
	t_address.write(100);
	//cout << "t_CE is \t" << t_CE.read() << endl;
	wait(5, SC_NS);
	t_WE.write(1);
	t_CE.write(1);
	wait(5, SC_NS);
	t_data.write(20);
	t_address.write(100);
}

void check::proc_check() {

	//wait(10, SC_NS);
	cout << "\nAt " << sc_time_stamp() << "\tADDR: " << c_address << "\t" << std::hex << "Data: " << c_data.read() << "\n";

	
	
}
