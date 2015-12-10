#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include "systemc.h"
#include "string"
#include "fstream" 

SC_MODULE(Dram_Memory) {

// Data - 8 bit bidirectional
// Address	- 32 bit UniDirectional
// CE - 1 bit uni dir
// WE - 1 bit UniDir

	sc_inout<sc_lv<8>>	data;
	sc_in<sc_lv<32>>	address;
	sc_in<int>			CE;
	sc_in<int>			WE;

	int  *mem_data;
	sc_int<32> addr_range;
	int addr_max = 0;
	int addr;
	int dat;
	//int addr_max = 0;

	void proc_dram_memory();
	SC_HAS_PROCESS(Dram_Memory);

	Dram_Memory(sc_module_name , int size) {

		addr_max = size;
		mem_data = new int[size];
		SC_METHOD(proc_dram_memory);
		//sensitive << CE << WE << address;
		sensitive << address ;
		FILE *mem = fopen("Memory_Data\\T1.txt", "r");
		if (!mem)
		{
			cout << "Could not open the file\n";
			
		}
		for (int j = 0; j < size; j++) {
			//mem_data[j].write(0x0);
			mem_data[j] = 0x0;
		}

		while (fscanf(mem, "%d %xn ", &addr, &dat) != EOF) {
			mem_data[addr] = dat;
			addr_max++;
		}

		addr_range=addr_max-1;
		cout << addr_max << "\t" << addr_range << "Executed til here" << endl;
	}



};