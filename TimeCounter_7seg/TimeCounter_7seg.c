/*
 * TimeCounter_7seg.c
 *
 *	Created: 06/10/2014 22:47:49
 *  Author: Miguel Catalan Bañuls
 *  Team: Baltic Racing
 */ 

#define F_CPU	4000000UL	//TODO: Check this
#include <avr/io.h>

#include "Display.h"
#include "Memory.h"
#include "Time.h"

#define SegmentDataPort			PORTB	//TODO: just for testing, find the right port
#define SegmentDataPin			PINB
#define SegmentDataDDR			DDRB
#define SegmentControlPort		PORTC
#define SegmentControlPin		PINC
#define SegmentControlDDR		DDRC

/*
 *	Function Declarations
 */
void checkResetButton();
char isIgnitionOn();

/*
 *	Global Variables Declarations
 */
unsigned char hours = 0;
unsigned char minutes = 0;
unsigned char seconds = 0;

int main(void){
	readStoredTime();
	readStoredErrors();
	
    while(1){
		checkResetButton();
		checkErrors();
		
		if(isIgnitionOn()){
			
		}
		
		displayCurrentTime();
    }
}

char isIgnitionOn(){
		//TODO: check if engine is running
	return NULL;
}

void checkResetButton(){
	
	/* Check if SegmentControl Pin 6 Switch is Pressed*/
	if((SegmentControlPin & 0x40) == 0 ){
		_delay_ms(200); //TODO: replace delay with 'if(elapse_time)' methods
		resetTimer();
	}
}

void checkErrors(){
	//TODO: Implement this
}