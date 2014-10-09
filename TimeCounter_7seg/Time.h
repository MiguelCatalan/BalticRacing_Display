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

#define MAX_RUNNING_TIME 4 //4hrs

unsigned char hours = 0;
unsigned char minutes = 0;
unsigned char seconds = 0;

char boolean = 0;

/*
*	Function Declarations
*/
ISR(TIMER1_CMPA_vect);
void showCurrentTime();
void resetTimer();
void saveCurrentTime();
void setCounterState(char _boolean);

/*
*	Timer Counter 1 Compare Match A Interrupt Service Routine/Interrupt Handler
*
*	TIMER1_CMPA_vect -
*/
ISR(TIMER1_CMPA_vect)
{
	if(boolean == 1){
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
	
	saveCurrentTime();
}

/*
* Changes the current time to the new one given by parameter
*
* _hours - number of hours to be updated
* _minutes - number of minutes to be updated
* _seconds - number of seconds to be updated
*/
void setCurrentTime(unsigned char _hours, unsigned char _minutes, unsigned char _seconds){
	hours = _hours;
	minutes = _minutes;
	seconds = _seconds;	
}

/*
* Saves to current time to the EEPROM
*/
void saveCurrentTime(){
	writeTime(hours, minutes, seconds);
}

/*
* Enables o disables the counter
*
* _boolean - state of the counter (1 = running , 0 = stopped)
*/
void setCounterState(char _boolean){
	boolean = _boolean;
}

#endif