/*
 *	Manage the Display stuff methods
 *
 *	Created: 06/10/2014 22:47:49
 *  Author: Miguel Catalan Bañuls
 *  Team: Baltic Racing
 */ 
#ifndef Display
#define Display

unsigned char displayDigit(unsigned char digit, unsigned char common)
unsigned char displayError(unsigned char digit, unsigned char common)
/*
* Encode a Decimal Digit 0-9 to its Seven Segment Equivalent.
*
* digit - Decimal Digit to be Encoded
* common - Common Anode (0), Common Cathode(1)
* value - Encoded Seven Segment Value
*/
unsigned char displayDigit(unsigned char digit, unsigned char common){
	unsigned char value;
	
	switch(digit){
		case 0:	
			if(common == 1)
				value = 0b00111111;
			else
				value = ~0b00111111;
			break;
			
		case 1:	
			if(common == 1)
				value = 0b00000110;
			else
				value = ~0b00000110;
			break;
			
		case 2:	
			if(common == 1)
				value = 0b01011011;
			else
				value = ~0b01011011;
			break;
			
		case 3:	
			if(common == 1)
				value = 0b01001111;
			else
				value = ~0b01001111;
			break;
			
		case 4:
			if(common == 1)
				value = 0b01100110;
			else
				value = ~0b01100110;
			break;
			
		case 5:	
			if(common == 1)
				value = 0b01101101;
			else
				value = ~0b01101101;
			break;
			
		case 6:	
			if(common == 1)
				value = 0b01111101;
			else
				value = ~0b01111101;
			break;
			
		case 7:	
			if(common == 1)
				value = 0b00000111;
			else
				value = ~0b00000111;
			break;
			
		case 8:	
			if(common == 1)
				value = 0b01111111;
			else
				value = ~0b01111111;
			break;
			
		case 9:	
			if(common == 1)
				value = 0b01101111;
			else
				value = ~0b01101111;
			break;
			
		default:
			if(common == 1)
				value = 0b00000000;
			else
				value = ~0b00000000;
			break;
		
	}
	return value;
}

/*
* Encode a error code to the Seven Segment.
*
* digit - Decimal Digit to be Encoded
* common - Common Anode (0), Common Cathode(1)
* value - Encoded Seven Segment Value
*/
unsigned char displayError(unsigned char digit, unsigned char common){
	unsigned char value;
	
	switch(digit){
		case 1:
			if(common == 1)
				value = 0;
			else
				value = ~0;
			break;
			
		default:
			break;
	}
	
}
#endif