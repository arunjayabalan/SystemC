#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "systemc.h"
#include "sink.h"
#include "source.h"
#include "channel.h"

int sc_main(int argc, char *argv[]) 

{
	channel *ch;
	source *so;
	sink *si;

	ch = new channel("ch");
	so = new source("so");
	si = new sink("si");

	so->out(*ch);
	si->in(*ch);

	sc_start();

	return 0;

}
