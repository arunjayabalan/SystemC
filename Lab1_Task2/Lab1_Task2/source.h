// file name = source.h
#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "systemc.h"
#include "channel.h"


class source : public sc_module
{
   public:
	   sc_port<w_if> out;

    SC_HAS_PROCESS(source);
	
    source(sc_module_name name) : sc_module(name)
     {
		 SC_THREAD(source_p);
     }

     void source_p();

	 /*SC_CTOR(source) {
		 SC_METHOD(source_p);
		 sensitive << out;
	 }*/
};
