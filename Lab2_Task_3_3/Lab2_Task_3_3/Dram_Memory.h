#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include "systemc.h"
#include "string"
#include "fstream"
#include "Distortion.h"

class DramMemory : public sc_module {

// Data - 8 bit bidirectional
// Address	- 32 bit UniDirectional
// CE - 1 bit uni dir
// WE - 1 bit UniDir

public:
	

	sc_in<sc_lv<8>>		data_in;
	sc_out<sc_lv<8>>	data_out;
	sc_in<sc_lv<32>>	address;
	sc_in<int>			CE;
	sc_in<int>			WE;

	//sc_int<8> mem_data[1041];
	int *mem_data;
	sc_int<32> addr_range;
	int addr_max = 0;
	int addr;
	int dat;
	int mem_size = 0;
	
	//const Distortion1 &dist1;
	//int addr_max = 0;
	
	SC_HAS_PROCESS(DramMemory);

	
	DramMemory(sc_module_name name, int size)  {

		
		mem_size = size;
		mem_data = new int[size];
		SC_THREAD(Init);
		SC_METHOD(proc_dram_memory);

		sensitive << WE << CE << address << data_in;
	}

	DramMemory(sc_module_name name, int size, char t) {
		mem_size = size;
		mem_data = new int[size];
		//cout << "Listing1" << endl;
		SC_THREAD(Init);
		SC_THREAD(Listing1);
		SC_METHOD(proc_dram_memory);

		sensitive << WE << CE << address << data_in;
	}

	DramMemory(sc_module_name name, int size, int n) {
		//cout << "Listing2" << endl;
		mem_data = new int[size];
		mem_size = size;
		SC_THREAD(Init);
		SC_THREAD(Listing2);
		SC_METHOD(proc_dram_memory);

		sensitive << WE << CE << address << data_in;
	}

	void Init();
	void proc_dram_memory();
	void Listing1();
	void Listing2();

};