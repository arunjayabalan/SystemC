// file name = source.cpp
#pragma once
#include"source.h"

void source :: source_p()
     {
       const char *alphabet = "abcdefghijklmnopqrstuvwxyz\n";

       while (*alphabet)
       {
         out->write(*alphabet++);
       }

     }
