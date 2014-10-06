/*
 * TimeCounter_7seg.c
 *
 *	Created: 06/10/2014 22:47:49
 *  Author: Miguel Catalan Ba�uls
 *  Team: Baltic Racing
 */ 

#define F_CPU	4000000UL
#include <avr/io.h>

#include "Display.h"
#include "Memory.h"
#include "Time.h"

#define SegmentDataPort		PORTB //TODO: just for testing, find the right port
#define SegmentDataPin		PINB
#define SegmentDataDDR		DDRB

#define SegmentControlPort		PORTC
#define SegmentControlPin		PINC
#define SegmentControlDDR		DDRC

/*
 *	Global Variables Declarations
 */
unsigned char hours = 0;
unsigned char minutes = 0;
unsigned char seconds = 0;

int main(void)
{
    while(1)
    {
		//TODO: Do my magic   
    }
}