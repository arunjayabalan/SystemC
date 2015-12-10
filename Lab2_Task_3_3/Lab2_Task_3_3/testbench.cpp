#pragma once
#include "testbench.h"


void testbench :: proc_generate() {

	t_CE.write(1);
	t_WE.write(0);
	t_address.write(0x4);
	wait(2, SC_NS);



	t_CE.write(1);
	t_WE.write(0);
	t_address.write(0x10);
	wait(2, SC_NS);

}

void testbench::proc_check() {

	cout << "\n@" << sc_time_stamp() << "\tADDR: " << t_address.read().to_int() << "\t" << std::hex << "Data: " << t_data.read() << "\n";
	int data_read = t_data.read().to_int();
	int address_read = t_address.read().to_int();
	int data_actual = ram_data_t3[address_read].to_int();
	if (data_read != data_actual)
	{
		cout << "Address mismatch at " << address_read << " Actual: " << data_actual << " Memory_Data : " << data_read << endl;
		fprintf(mem_T3_cor, "Address: 0x%x \t Actual_Data : 0x%x \t Data_Read 0x%x \n ", address_read, data_actual, data_read);

	}



}