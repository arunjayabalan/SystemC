#include "systemc.h"

SC_MODULE(driver)
{

	sc_out<sc_bit> d_a ; // stimul to the OR gate 'a' input
	sc_out<sc_bit> d_b ; // stimuli to the OR gate 'b' input
	
	void drivea();
	
	void driveb();
	
	SC_CTOR(driver)
	{
		//SC_THREAD(drivea); //processes are called here
		//SC_THREAD(driveb);
		SC_METHOD(drivea); //processes are called here
		SC_METHOD(driveb);
	}
};

SC_MODULE(monitor)
{
	sc_in<sc_bit> m_a, m_b;
	sc_in<sc_bit> m_c;			//both the input and output of the OR gate are to be monitored
	
	void prc_monitor();
	
	SC_CTOR(monitor){
	
		SC_METHOD(prc_monitor);
		sensitive << m_a << m_b << m_c; // whenever the input/output of the OR gate changes prc_monitor triggers
		
		}
};
