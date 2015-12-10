#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include "systemc.h"
#include "change_case.h"
#include "filter.h"
#include "m_bus.h"
#include "testbench.h"
#include "arbitrer.h"
#include "UART.h"

int sc_main(int argc, char *argv[]) {

	sc_clock clk("clk", 25, SC_NS);
	sc_signal<bool> arb_sel;
	sc_signal<char> tb_dchar;
	sc_signal<char> tb_mchar;
	sc_signal<char> m_char_in1;
	sc_signal<char> m_char_in2;
	sc_signal<char> m_char_out;
	

	change_case *cc;
	filter *f;
	m_bus *m;
	arbitrer *a;
	driver *d1;
	monitor *m1;
	UART *u;


	cc = new change_case("ch");
	f = new  filter("f");
	m = new m_bus("m");
	a = new arbitrer("a");
	d1 = new driver("d1");
	m1 = new monitor("m1");
	u = new UART("u");


	a->selector(arb_sel);
	a->clk_in(clk);
	d1->d_char(tb_dchar);

	f->char_in(tb_dchar);
	f->char_out(m_char_in1);
	
	cc->char_in(tb_dchar);
	cc->char_out(m_char_in2);


	m->char_in1(m_char_in1);
	m->char_in2(m_char_in2);
	m->selector(arb_sel);
	m->char_out(m_char_out);
	 
	u->char_in(m_char_out);
	u->char_out(tb_mchar);

	m1->m_char(tb_mchar);
	

	sc_start(2000, SC_NS); //starts the simulation and run

	return 0;
}