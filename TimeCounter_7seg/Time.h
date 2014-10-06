/*
 *	Manage the time counting and interruptions
 *
 *	Created: 06/10/2014 22:47:49
 *  Author: Miguel Catalan Bañuls
 *  Team: Baltic Racing
 */ 

#ifndef Time
#define Time

#include <avr/interrupt.h>

ISR(TIMER1_COMPA_vect);

/*
 *	Timer Counter 1 Compare Match A Interrupt Service Routine/Interrupt Handler
 */
ISR(TIMER1_COMPA_vect)
{
	seconds++;
	
	if(seconds == 60)
	{
		seconds = 0;
		minutes++;
	}
	if(minutes == 60)
	{
		minutes = 0;
		hours++;
	}
	if(hours > 23)
	hours = 0;
}
#endif