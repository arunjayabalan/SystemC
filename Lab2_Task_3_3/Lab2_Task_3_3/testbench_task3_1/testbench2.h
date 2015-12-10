#pragma once
#include "systemc.h"


SC_MODULE(generate2) {
	
	sc_out<int>					t_WE;
	sc_out<int>					t_CE;
	sc_out<sc_lv<32>>			t_address;
	sc_out<sc_lv<8>>			t_data;

	void proc_generate2();	 // generates address and other signals

	SC_CTOR(generate2) {
		SC_THREAD(proc_generate2);
	}

};

SC_MODULE(check2) {

	sc_in<int>				c_WE;
	sc_in<int>				c_CE;
	sc_in<sc_lv<8>>			c_data;
	sc_in<sc_lv<32>>		c_address;

	sc_int<8> ram_data_t1[1041];
	int addr_T1;
	int dat_T1;
	int addr_max_T1 = 0;

	//sc_event rec;

	void proc_check2();
	SC_CTOR(check2) {
		
		SC_METHOD(proc_check2);
		sensitive << c_data ;


		FILE *mem_T1 = fopen("Memory_Data\\T3.txt", "r");
		if (!mem_T1)
		{
			cout << "Could not open the file\n";

		}
		/*for (int j = 0; j < 1040; j++) {
			//mem_data[j].write(0x0);
			ram_data_t1[j] = 0x0;
		}*/

		while (fscanf(mem_T1, "%d %xn ", &addr_T1, &dat_T1) != EOF) {
			ram_data_t1[addr_T1] = dat_T1;
			addr_max_T1++;
		}
	}

	FILE *mem_T1_cor = fopen("Memory_Data\\T3_Mem2_Corruped.txt", "w");


};
