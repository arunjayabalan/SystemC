#define _CRT_SECURE_NO_WARNINGS
#pragma once


#include "systemc.h"
#include "Dram_Memory.h"
#include "testbench.h"
#include "fstream"
#include "string"

int main() {
	sc_signal<int> mem_add;
	sc_signal<int> mem_data;
	sc_signal<int> mem_we;
	sc_signal<int> mem_ce;

	Dram_Memory *dram;
	dram = new Dram_Memory("dram");

	generate *testb;
	testb = new generate("testb");

	dram->address(mem_add);
	dram->data(mem_data);
	dram->WE(mem_we);
	dram->CE(mem_ce);

	testb->t_address(mem_add);
	testb->t_WE(mem_we);
	testb->t_CE(mem_ce);
	testb->t_data(mem_data);

	check *testc;
	testc = new check("testc");

	testc->c_data(mem_data); 
	testc->c_address(mem_add);
	testc->c_WE(mem_we);
	testc->c_CE(mem_ce);


	sc_report_handler::set_actions(SC_ID_VECTOR_CONTAINS_LOGIC_VALUE_,SC_DO_NOTHING);
	sc_start(1500,SC_NS);

	return 0;
}