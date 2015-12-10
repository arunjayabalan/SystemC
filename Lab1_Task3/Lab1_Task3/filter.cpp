// file name = filter.cpp
#define _CRT_SECURE_NO_WARNINGS
#include"filter.h"

void filter :: prc_filter(){

	char_out='#';

	if (char_in=='s' || char_in=='y' || char_in=='t' || char_in=='e' || char_in=='m' || char_in=='c')
	char_out=char_in; 
}
