#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "arbitrer.h"


void arbitrer::prc_arbitrer() {
	
	counter++;
	if (counter >= 10)
		selector = 1;
	else
		selector = 0;

	if (counter >= 20)
		counter = 0;
}
