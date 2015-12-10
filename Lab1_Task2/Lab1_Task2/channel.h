#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "systemc.h"

class w_if : virtual public sc_interface
{
public:
	virtual void write(char) = 0;
	virtual void reset() = 0;
};

class r_if : virtual public sc_interface
{
public:
	virtual void read(char &) = 0;
	virtual int num_available() = 0;
};


class channel : public sc_channel, public w_if, public r_if
{
public:
	channel(sc_module_name name) : sc_channel(name), num_elements(0), first(0) {}

	SC_HAS_PROCESS(channel);
	/*SC_CTOR(channel) {
		SC_METHOD(write);
		SC_METHOD(read);
		SC_METHOD(reset);
	}*/

/*	channel(sc_module_name name) : sc_module(name)
	{
		SC_THREAD(write(char c));
		SC_THREAD(read(char &c));
		SC_THREAD(reset());
	}*/

	void write(char c);
	void read(char &c);
	void reset();
	int num_available();

private:
	enum e { max = 10 };
	char data[max];
	int num_elements, first;
	sc_event write_event, read_event;

};