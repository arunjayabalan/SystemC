#pragma once

#include "systemc.h"
#include "testbench_task3_1\testbench.h"

SC_MODULE(case1) {

	generate g1;
	check c1;

	SC_CTOR(case1) {
		SC_METHOD(proc_case1);
	}
	void proc_case1();
};

SC_MODULE(case2) {

	generate g2;
	check c2;

	SC_CTOR(case2) {
		SC_METHOD(proc_case1);
	}
	void proc_case1();

};
