#pragma once
#include "systemc.h"
#include "Dram_Memory.h"

class Distortion1 : public sc_module
{

	public:

		//DramMemory mem1;
		
		SC_HAS_PROCESS(Distortion1);

		Distortion1(sc_module_name name){
			//SC_THREAD(Listing1);
		}

		//void Listing1();
};

class Distortion2 : public sc_module
{

public:

	//DramMemory mem2;

	SC_HAS_PROCESS(Distortion2);

	Distortion2(sc_module_name name) {
		//SC_THREAD(Listing2);
	}

	//void Listing2();
};