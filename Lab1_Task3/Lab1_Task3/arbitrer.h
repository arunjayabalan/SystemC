#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "systemc.h"

SC_MODULE(arbitrer) {

	sc_in<bool> clk_in;
	sc_out<bool> selector;
	int counter = 0;

	void prc_arbitrer();

	SC_CTOR(arbitrer)
	{
		SC_METHOD(prc_arbitrer);
		sensitive << clk_in.pos() ;
	}


};