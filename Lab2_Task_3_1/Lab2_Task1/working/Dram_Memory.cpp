#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include "systemc.h"
#include "Dram_Memory.h"

// WE is 1 -> Write operation
//       0 -> Read Operation
// If write operation is requested and CE is 0, operation should be discarded.
// If read operation is requested and CE is 0, memory should give the value 0xFF

void Dram_Memory::proc_dram_memory() {
	//WAIT(5, SC_NS);
	cout << addr_range << "\t" << address.read()<<endl;
	
	if (addr_range <= address.read()) {
		cout << "Out of address\n";
	//	SC_REPORT_WARNING("WARNING", "Address out of Range");
	}


	if (WE.read() == 1)
	{
			if (CE.read() == 1) 
			{
					//Perform Write Operations
				cout << "Performing Write Operation\n";
				mem_data[address.read()] = data.read();
				//cout << "DATA : " << data.read();
			}

	}

	if (WE.read() == 0) 
	{
			if (CE.read() == 0) 
			{ 
				//cout << "Hello";
				data =  0xFF; 
			}
			//Perform read Operations
			else
			{
				cout << "Performing Read Operation\n";
				//cout << "Address is " << address.read() << endl;
				data = mem_data[address.read()];
				//cout << "Data is " << data << endl;
			}
	}

}