#define _CRT_SECURE_NO_WARNINGS
#include "systemc.h"
#include "Dram_Memory.h"
#include "Distortion.h"
#include "testbench_task3_1\testbench.h"



// sc_main in top level function like in C++ main
int sc_main(int argc, char* argv[]) {

	sc_signal<sc_lv<32>> mem_add[2];
	sc_signal<sc_lv<8>> mem_data_in[2];
	sc_signal<sc_lv<8>> mem_data_out[2];
	sc_signal<int> mem_we[2];
	sc_signal<int> mem_ce[2];

	DramMemory	mem1("mem1", 1024, 'c');
	DramMemory	mem2("mem2", 1024, 5);
	generate	genReq1("gen1");
	check		check1("check1");
	generate    genReq2("gen2");
	check		check2("check2");

	mem1.address(mem_add[0]);
	mem1.data_in(mem_data_in[0]);
	mem1.data_out(mem_data_out[0]);
	mem1.CE(mem_ce[0]);
	mem1.WE(mem_we[0]);

	mem2.address(mem_add[1]);
	mem2.data_in(mem_data_in[1]);
	mem2.data_out(mem_data_out[1]);
	mem2.CE(mem_ce[1]);
	mem2.WE(mem_we[1]);

	
	
	genReq1.t_address(mem_add[0]);
	genReq1.t_data_out(mem_data_in[0]);
	genReq1.t_CE(mem_ce[0]);
	genReq1.t_WE(mem_we[0]);

	check1.c_address(mem_add[0]);
	check1.c_data_in(mem_data_out[0]);
	check1.c_data_out(mem_data_in[0]);
	check1.c_WE(mem_we[0]);
	check1.c_CE(mem_ce[0]);


	genReq2.t_address(mem_add[1]);
	genReq2.t_data_out(mem_data_in[1]);
	genReq2.t_CE(mem_ce[1]);
	genReq2.t_WE(mem_we[1]);

	check2.c_address(mem_add[1]);
	check2.c_data_in(mem_data_out[1]);
	check2.c_data_out(mem_data_in[1]);
	check2.c_WE(mem_we[1]);
	check2.c_CE(mem_ce[1]);
	
	
	mem_add[0] = 0;
	mem_data_in[0] = 0;
	mem_data_out[0] = 0;

	mem_add[1] = 0;
	mem_data_in[1] = 0;
	mem_data_out[1] = 0;


	sc_report_handler::set_actions(SC_ID_VECTOR_CONTAINS_LOGIC_VALUE_, SC_DO_NOTHING);
	sc_start(90000, SC_NS);
	
	return(0);
}