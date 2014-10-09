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

unsigned char EEMEM NonVolatileCharSeconds;
unsigned char EEMEM NonVolatileCharMinutes;
unsigned char EEMEM NonVolatileCharHours;
unsigned char EEMEM NonVolatileCharError;

/*
*	Function Declarations
*/
unsigned char readStoredHours();
unsigned char readStoredMinutes();
unsigned char readStoredSeconds();
void writeTime(unsigned char hours, unsigned char minutes, unsigned char seconds);
unsigned char readStoredError();
void writeCurrentError(unsigned char error);

/*
* Retrieve the stored hours from the EEPROM
*/
unsigned char readStoredHours(){
	return eeprom_read_byte (&NonVolatileCharHours);
}

/*
* Retrieve the stored minutes from the EEPROM
*/
unsigned char readStoredMinutes(){
	return eeprom_read_byte (&NonVolatileCharMinutes);
}

/*
* Retrieve the stored seconds from the EEPROM
*/
unsigned char readStoredSeconds(){
	return eeprom_read_byte (&NonVolatileCharSeconds);
}

/*
* Writes the given time to the EEPROM
*
* hours	- number of hours to be stored
* minutes - number of minutes to be stored
* seconds - number of seconds to be stored
*/
void writeTime(unsigned char hours, unsigned char minutes, unsigned char seconds){
	eeprom_update_byte (&NonVolatileCharHours, hours);
	eeprom_update_byte (&NonVolatileCharHours, minutes);
	eeprom_update_byte (&NonVolatileCharHours, seconds);
}

/*
* Retrieve the stored error from the EEPROM
*/
unsigned char readStoredError(){
	return eeprom_read_byte (&NonVolatileCharError);
}

/*
* Writes the given error to the EEPROM
*
* error	- number of the error to be stored
*/
void writeCurrentError(unsigned char error){
	eeprom_update_byte (&NonVolatileCharError, error);
}
#endif