#pragma once
#include "systemc.h"

SC_MODULE(generate) {

	sc_out<int>			t_WE;
	sc_out<int>			t_CE;
	sc_out<int>			t_address;
	sc_out<int>			t_data;



	void proc_generate();	 // generates address and other signals
	//void proc_check();		 // Reaads the text file and compares

	SC_CTOR(generate) {
		SC_THREAD(proc_generate);
	}

};

SC_MODULE(check) {

	sc_in<int>			c_WE;
	sc_in<int>			c_CE;
	sc_in<int>			c_data;
	sc_in<int>			c_address;

	void proc_check();
	SC_CTOR(check) {
		
		SC_THREAD(proc_check);
		sensitive << c_data;
	}

};
