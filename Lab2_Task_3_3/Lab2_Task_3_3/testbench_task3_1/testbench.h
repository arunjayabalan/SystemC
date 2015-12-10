#pragma once
#include "systemc.h"


SC_MODULE(generate) {
	
	sc_out<int>					t_WE;
	sc_out<int>					t_CE;
	sc_out<sc_lv<32>>			t_address;
	sc_out<sc_lv<8>>			t_data_out;

	void proc_check();


	void proc_generate();	 // generates address and other signals

	SC_CTOR(generate) {
		SC_THREAD(proc_generate);
	
	}
	
};


	SC_MODULE(check) {

		sc_out<int>					c_WE;
		sc_out<int>					c_CE;
		sc_in<sc_lv<8>>				c_data_in;
		sc_out<sc_lv<8>>			c_data_out;
		sc_inout<sc_lv<32>>			c_address;

		sc_int<8> ram_data_t1[1041];
		int addr_T1;
		int dat_T1;
		int addr_max_T1 = 0;
		FILE *mem_T1_cor;

		sc_event rec;

		void proc_check();
		void file_update();

		SC_CTOR(check) {

			SC_METHOD(proc_check);
		
			//SC_THREAD(file_update);
			sensitive << c_data_in;

			
			FILE *mem_T1 = fopen("Memory_Data\\T3.txt", "r");
			mem_T1_cor = fopen("Memory_Data\\T3_Corruped_Task_4_2.txt", "a");
			if (!mem_T1)
			{
				cout << "Could not open the file\n";

			}

			while (fscanf(mem_T1, "%d %xn ", &addr_T1, &dat_T1) != EOF) {
				ram_data_t1[addr_T1] = dat_T1;
				addr_max_T1++;
			}
		
		}

		//FILE *mem_T1_cor = fopen("Memory_Data\\T3_Corruped_Task_4_2.txt", "a");

};