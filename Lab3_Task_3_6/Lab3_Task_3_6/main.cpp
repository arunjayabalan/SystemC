#define _CRT_SECURE_NO_WARNINGS
#define SC_INCLUDE_DYNAMIC_PROCESSES
#include "systemc.h"
//#include "Top.h"
using namespace sc_core;
using namespace sc_dt;
using namespace std;

#include "Initiator.h"
#include "target.h"


// Target module representing a simple memory


int sc_main(int argc, char* argv[])
{
	Initiator *initiator;
	Memory *memory;
	//Top T("top");
	initiator = new Initiator("initiator");
	memory = new Memory("memory",1024);
	initiator->socket.bind(memory->socket);
	sc_start();
	return 0;
}