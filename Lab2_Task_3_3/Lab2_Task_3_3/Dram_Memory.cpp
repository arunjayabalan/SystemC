#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include "Dram_Memory.h"

// WE is 1 -> Write operation
// 0 -> Read Operation
// If write operation is requested and CE is 0, operation should be discarded.
// If read operation is requested and CE is 0, memory should give the value 0xFF

void DramMemory::Init() {
	
	FILE *mem = fopen("Memory_Data\\T3.txt", "r");
	if (!mem)
	{
		cout << "Could not open the file\n";
	}

	for (int j = 0; j < mem_size; j++) {
		mem_data[j] = 0x0;
	}

	while (fscanf(mem, "%d %xn ", &addr, &dat) != EOF) {
		mem_data[addr] = dat;
		addr_max++;
		if(addr_max == mem_size) break;
	}
	//cout << "Done with memory read" << endl;
	addr_range = addr_max ;

	/*for (int j = 0; j < addr_range; j++) {
		cout <<"Addr :" << j << "\tData: "<< std::hex << mem_data[j] << endl;
	}
	cout << "Address Range" << addr_range << endl;*/

}

void DramMemory::proc_dram_memory() {

	//cout  << "Address Read\t:\t" << address.read().to_int()<<endl;
	
	if (addr_range <= address.read().to_int()) {
		//cout << "Out of address\n";
		SC_REPORT_WARNING("WARNING", "Address out of Range");
	}


	if (WE.read() == 1)
	{
			if (CE.read() == 1) 
			{
					//Perform Write Operations
				//cout << "Performing Write Operation\n";
				mem_data[address.read().to_int()] = data_in.read().to_int();
				//cout << "@" << sc_time_stamp() <<"  Write Data @ address : " << address.read().to_int() << "   is " << data.read() << endl;
				//cout << "DATA : " << data.read();
			}

	}

	if (WE.read() == 0) 
	{
			if (CE.read() == 0) 
			{ 
				data_out.write(0xFF); 
				//cout << "@" << sc_time_stamp() << " Read Data @ address : " << address.read().to_int() << "   is " << data.read() << endl;
			}
			//Perform read Operations
			else
			{
				data_out.write(mem_data[address.read().to_int()]);
				//cout << "@" << sc_time_stamp() << " Read Data1 @ address : "<< address.read().to_int() << "   is " << data.read() << "Mem Data: "<< mem_data[address.read().to_int()] << endl;
			}
	}
	
}

void DramMemory::Listing1()
{
	
	int k = 0;
	int data;
	for (k = 0; k < addr_range; k++)
	{
	
		data = mem_data[k];
		data = data | 0x04;
		mem_data[k] = data;
	
	}

}


void DramMemory::Listing2()
{
	//cout << " In Listing2 " << endl;
	int k = 0;
	int data;
	for (k = 0; k < addr_range; k++)
	{
		data = mem_data[k];
		if (data == 0x70) { data = data & 0x73; }
		else if (data == 0x67) { data = data & 0x63; }
		mem_data[k] = data;

	}

}

