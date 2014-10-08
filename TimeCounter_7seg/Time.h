/*
*	Manage the time counting and interruptions
*
*	Created: 06/10/2014 22:47:49
*   Author: Miguel Catalan Bañuls
*   Team: Baltic Racing
*/

#ifndef Time
#define Time

#include <avr/interrupt.h>
#include <avr/io.h>

#define MAX_RUNNING_TIME 4

unsigned char hours = 0;
unsigned char minutes = 0;
unsigned char seconds = 0;

/*
*	Function Declarations
*/
ISR(TIMER1_COMPA_vect);
void showCurrentTime();
void resetTimer();

/*
*	Timer Counter 1 Compare Match A Interrupt Service Routine/Interrupt Handler
*
*	TIMER1_COMPA_vect -
*/
ISR(TIMER1_COMPA_vect)
{
	if(hours < MAX_RUNNING_TIME){
		seconds++;
		
		if(seconds == 60){
			seconds = 0;
			minutes++;
		}
		
		if(minutes == 60){
			minutes = 0;
			hours++;
		}
		
		if(hours > 23){
			hours = 0;
		}
	}
}

/*
* Displays the current time
*/
void showCurrentTime(){
	displayCurrentTime(hours, minutes, seconds);
}

/*
* Reset the current time counter, also clean the stored memory count.
*/
void resetTimer(){
	hours = 0;
	minutes = 0;
	seconds = 0;
	
	writeCurrentTime(hours, minutes, seconds);
}

#endif