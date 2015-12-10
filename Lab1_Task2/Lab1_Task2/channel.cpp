#pragma once
#include "channel.h"

void channel::write(char c) {
	
	if (num_elements == max)
		wait(read_event);

	data[(first + num_elements) % max] = c;
	++num_elements;
	//next_trigger(write_event);
	write_event.notify();
}


void channel::read(char &c)
	{

		if (num_elements == 0)
			wait(write_event);

		c = data[first];
		--num_elements;
		first = (first + 1) % max;
		//read_event.notify();

	}

void channel::reset() 
	{ 
		num_elements = first = 0; 
	}


int channel::num_available() 
	{ 
		return num_elements; 

	}