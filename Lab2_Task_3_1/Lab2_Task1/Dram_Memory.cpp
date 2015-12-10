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

	//cout  << "Address Read\t:\t" << address.read().to_int()<<endl;
	
	if (addr_range <= address.read().to_int()) {
		cout << "Out of address\n";
		SC_REPORT_WARNING("WARNING", "Address out of Range");
	}


	if (WE.read() == 1)
	{
			if (CE.read() == 1) 
			{
					//Perform Write Operations
				//cout << "Performing Write Operation\n";
				mem_data[address.read().to_int()] = data.read().to_int();
				//cout << "@" << sc_time_stamp() <<"  Write Data @ address : " << address.read().to_int() << "   is " << data.read() << endl;
				//cout << "DATA : " << data.read();
			}

	}

	if (WE.read() == 0) 
	{
			if (CE.read() == 0) 
			{ 
				data.write(0xFF); 
				//cout << "@" << sc_time_stamp() << " Read Data @ address : " << address.read().to_int() << "   is " << data.read() << endl;
			}
			//Perform read Operations
			else
			{
				data.write(mem_data[address.read().to_int()]);
				//wait(1, SC_NS);
				//cout << "@" << sc_time_stamp() << " Read Data1 @ address : "<< address.read().to_int() << "   is " << data.read() << "Mem Data: "<< mem_data[address.read().to_int()] << endl;
			}
	}
	
}