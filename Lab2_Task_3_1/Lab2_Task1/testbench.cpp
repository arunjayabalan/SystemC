#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include "testbench.h"

void generate::proc_generate() {
	// Write => WE = 1 , CE = 1
	// Read => WE = 0, CE = 1 
/*
	t_CE.write(0);
	t_WE.write(1);
	for (int i = 0; i < 1024; i++) {
		t_address.write(i);
		t_data.write(10);
		wait(5, SC_NS);
	}

*/
	
	t_CE.write(1);
	t_WE.write(0);
	for (int i = 0; i < 1024; i++) {
		t_address.write(i);
		wait(5, SC_NS);
	}
	
	

}

void check::proc_check() {
	
	cout << "\n@" << sc_time_stamp() << "\tADDR: " << c_address.read().to_int() << "\t" << std::hex << "Data: " << c_data.read() << "\n";	
	int data_read		=	 c_data.read().to_int();
	int address_read	=	 c_address.read().to_int();
	int data_actual     =    ram_data_t1[address_read].to_int();
	if (data_read != data_actual)
	{
		cout << "Address mismatch at " << address_read << " Actual: " << data_actual << " Memory_Data : " << data_read << endl;
		fprintf(mem_T1_cor, "Address: 0x%x \t Actual_Data : 0x%x \t Data_Read 0x%x \n ", address_read, data_actual, data_read);

	}

}
