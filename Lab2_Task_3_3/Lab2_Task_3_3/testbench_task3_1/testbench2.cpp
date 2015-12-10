#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include "testbench2.h"

void generate2 :: proc_generate2() {
	// Write => WE = 1 , CE = 1
	// Read => WE = 0, CE = 1 
	
	//WAIT(2, SC_NS);
	
	//cout << "WE => 0" << endl;
	t_CE.write(1);
	t_WE.write(0);
	//cout << "CE => 1" << endl;
	t_address.write(0x8);
	//cout << "Address => 0x4" << endl;
	wait(2, SC_NS);
	
	
	
	t_CE.write(1);
	t_WE.write(0);	
	t_address.write(0x20);
	wait(2, SC_NS);

	t_CE.write(1);
	t_WE.write(0);
	t_address.write(0x310);
	wait(2, SC_NS);
	
}

void check2::proc_check2() {
	
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
