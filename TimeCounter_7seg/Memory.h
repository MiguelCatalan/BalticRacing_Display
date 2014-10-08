/*
*	Manage the Memory read and write methods
*
*	Created: 06/10/2014 22:47:49
*   Author: Miguel Catalan Bañuls
*   Team: Baltic Racing
*/

#ifndef Memory
#define Memory

#include <avr/eeprom.h>

unsigned char readStoredTime();
void writeCurrentTime(unsigned char hours, unsigned char minutes, unsigned char seconds);
unsigned char readStoredErrors();
void writeCurrentErrors(unsigned char error);

unsigned char readStoredTime(){
	return NULL;
}

void writeCurrentTime(unsigned char hours, unsigned char minutes, unsigned char seconds){
	
}

unsigned char readStoredErrors(){
	return NULL;
}

void writeCurrentErrors(unsigned char error){
	
}
#endif