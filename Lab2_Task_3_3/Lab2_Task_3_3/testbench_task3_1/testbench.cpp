#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include "testbench.h"

void generate::proc_generate() {
	// Write => WE = 1 , CE = 1
	// Read => WE = 0, CE = 1 
	
	
	
	int k = 0;
	while(k < 1024){
		t_CE.write(1);
		t_WE.write(0);
		t_address.write(k);
		wait(10, SC_NS);
		k++;
	}
	
}
void check :: proc_check( ) {
	
	//wait(rec);

	//for (int m = 0; m < 200000; m++);

	cout << "\n@" << sc_time_stamp() << "\tADDR: " << c_address.read().to_int() << "\t" << std::hex << "Data: " << c_data_in.read() << "\n";	
	short unsigned int data_read			=	 c_data_in.read().to_int();
	short unsigned int address_read		=	 c_address.read().to_int();
	short unsigned int data_actual		=    ram_data_t1[address_read].to_int();
	short int parity=0 ;
	int odd_par = 0;
	int parity_error = 0;
	short int par_data = data_read & 0x7F;
	
	while (par_data > 0) {
		if (par_data % 2 != 0) { parity++; }
		par_data /= 2;
	}
	//cout << "PARITY is " << parity << endl;
	if (parity % 2) {
		odd_par = 0x80;
	}
	
	if ((data_read & 0x80) == odd_par) { parity_error = 1; }

	//cout << "masked value " << (data_read & 0x80) << "odd_par " << odd_par << endl;

	
	if (data_read != data_actual)
	{
		cout << "Address mismatch at " << address_read << " Actual: " << data_actual << " Memory_Data : " << data_read << "   Odd_Parity_Value -> " << parity_error << endl;
		fprintf(mem_T1_cor, "Address: %d \t Actual_Data : %d \t Data_Read %d \t Odd_Parity_Value -> %d\n", address_read, (data_actual&0xFF) , (data_read&0xFF), parity_error);
		int data_corrected = 0;
		int inc = 0;
		if (data_actual < data_read) inc = 1;
	/*	while (data_read != data_actual)
		{
			if ((data_read & 0xFF) == 0xFF) { break; }
			if (inc) { data_read -= 1; }
			else { data_read += 1; }
			fprintf(mem_T1_cor, "In correction phase - Address: 0x%x \t Actual_Data : 0x%x \t Data_Read 0x%x \t \n ", address_read, data_actual, data_read);
		}
		cout << "Corrected Data at " << address_read << " Actual: " << data_actual << " Memory_Data : " << data_read << "   Odd_Parity_Value  " << parity_error << endl;
		//cout << "Writing back to Memory" << endl;
		
		
		c_CE.write(1);
		c_WE.write(1);
		c_address.write(address_read);
		c_data_out.write(data_read);
	*/
	}

}
