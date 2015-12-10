#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "systemc.h"
#include "Dram_Memory.h"

class testbench : public sc_module
{
	public:
		sc_out<int>					t_WE;
		sc_out<int>					t_CE;
		sc_out<sc_lv<32>>			t_address;
		sc_out<sc_lv<8>>			t_data;

		sc_int<8> ram_data_t3[1024];
		int addr_T3;
		int dat_T3;
		int addr_max_T3 = 0;


		SC_HAS_PROCESS(testbench);

		testbench(sc_module_name name) : sc_module(name) {
			FILE *mem_T3 = fopen("Memory_Data\\T3.txt", "r");
			if (!mem_T3)
			{
				cout << "Could not open the file\n";

			}

			while (fscanf(mem_T3, "%d %xn ", &addr_T3, &dat_T3) != EOF) {
				ram_data_t3[addr_T3] = dat_T3;
				addr_max_T3++;
			}
		}



		void proc_generate();
		void proc_check();

		FILE *mem_T3_cor = fopen("Memory_Data\\T3_Corruped.txt", "w");


};
