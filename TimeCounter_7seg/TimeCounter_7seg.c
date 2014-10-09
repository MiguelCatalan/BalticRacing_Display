/*
*	TimeCounter_7seg.c
*
*	Created: 06/10/2014 22:47:49
*	Author: Miguel Catalan Bañuls
*	Team: Baltic Racing
*/

#define F_CPU	4000000UL	//TODO: Check this
#include <avr/io.h>
#include <avr/delay.h>

#include "Display.h"
#include "Memory.h"
#include "Time.h"

#define SegmentDataPort			PORTA
#define SegmentDataPin			PINA
#define SegmentDataDDR			DDRA

#define SegmentControlPort		PORTB
#define SegmentControlPin		PINB
#define SegmentControlDDR		DDRB

/*
*	Function Declarations
*/
void checkResetButton();
char isIgnitionOn();

int main(void){
	
	SegmentDataDDR = 0xFF;
	SegmentControlDDR = 0x3F;
	SegmentControlPort = 0xFF;
	
	/* TODO: clean this
	TCCR1B = (1<<CS12|1<<WGM12);
	OCR1A = 15625-1;
	TIMSK = 1<<OCIE1A;
	sei();*/
	
	setCurrentTime(readStoredHours(), readStoredMinutes(), readStoredSeconds());
	//readStoredErrors();
	
	while(1){
		checkResetButton();
		checkErrors();
		
		if(isIgnitionOn() == 1){
			setCounterState((char)1);
		}else{
			saveCurrentTime(); //Only saves if the stored time it's different from the current
		}
		
		showCurrentTime();
	}
}

char isIgnitionOn(){
	//TODO: check if engine is running
	return 1;
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