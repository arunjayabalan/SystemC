// file name= change_case.h
#define _CRT_SECURE_NO_WARNINGS
#include"systemc.h"

SC_MODULE(change_case)
{
	sc_in<char> char_in;
	sc_out<char> char_out;

	void prc_change_case();

	SC_CTOR(change_case)
	{
	SC_METHOD (prc_change_case);
	sensitive << char_in;
	}

};

