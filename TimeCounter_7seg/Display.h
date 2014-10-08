/*
 *	Manage the Display stuff methods
 *
 *	Created: 06/10/2014 22:47:49
 *  Author: Miguel Catalan Bañuls
 *  Team: Baltic Racing
 */ 
#ifndef Display
#define Display

#define SegmentDataPort			PORTA
#define SegmentDataPin			PINA
#define SegmentDataDDR			DDRA

#define SegmentControlPort		PORTB
#define SegmentControlPin		PINB
#define SegmentControlDDR		DDRB

#define NONE	0b00000000
#define ONE		0b00000110
#define TWO		0b01011011
#define THREE	0b01001111
#define FOUR	0b01100110
#define FIVE	0b01101101
#define SIX		0b01111101
#define SEVEN	0b00000111
#define EIGHT	0b01111111
#define NINE	0b01101111
#define ZERO	0b00111111

#define _NONE	~0b00000000
#define _ONE	~0b00000110
#define _TWO	~0b01011011
#define _THREE	~0b01001111
#define _FOUR	~0b01100110
#define _FIVE	~0b01101101
#define _SIX	~0b01111101
#define _SEVEN	~0b00000111
#define _EIGHT	~0b01111111
#define _NINE	~0b01101111
#define _ZERO	~0b00111111

/*
 *	Function Declarations
 */
unsigned char getDisplayDigit(unsigned char digit, unsigned char common);
unsigned char getDisplayError(unsigned char digit, unsigned char common);
void displayCurrentTime(unsigned char hours, unsigned char minutes, unsigned char seconds);

/*
* Encode a Decimal Digit 0-9 to its Seven Segment Equivalent.
*
* digit - Decimal Digit to be Encoded
* common - Common Anode (0), Common Cathode(1)
* value - Encoded Seven Segment Value
*/
unsigned char getDisplayDigit(unsigned char digit, unsigned char common){
	
	unsigned char value;
	
	switch(digit){
		case 0:	
			if(common == 1)
				value = ZERO;
			else
				value = _ZERO;
			break;
			
		case 1:	
			if(common == 1)
				value = ONE;
			else
				value = _ONE;
			break;
			
		case 2:	
			if(common == 1)
				value = TWO;
			else
				value = _TWO;
			break;
			
		case 3:	
			if(common == 1)
				value = THREE;
			else
				value = _THREE;
			break;
			
		case 4:
			if(common == 1)
				value = FOUR;
			else
				value = _FOUR;
			break;
			
		case 5:	
			if(common == 1)
				value = FIVE;
			else
				value = _FIVE;
			break;
			
		case 6:	
			if(common == 1)
				value = SIX;
			else
				value = _SIX;
			break;
			
		case 7:	
			if(common == 1)
				value = SEVEN;
			else
				value = _SEVEN;
			break;
			
		case 8:	
			if(common == 1)
				value = EIGHT;
			else
				value = _EIGHT;
			break;
			
		case 9:	
			if(common == 1)
				value = NINE;
			else
				value = NINE;
			break;
			
		default:
			if(common == 1)
				value = NONE;
			else
				value = _NONE;
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
unsigned char getDisplayError(unsigned char digit, unsigned char common){
	
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
	return value;
}

/*
* Prints the current time on the Display
*
* hours - Current hours
* minutes - Current minutes
* seconds - Current seconds
*/
void displayCurrentTime(unsigned char hours, unsigned char minutes, unsigned char seconds){
	
	SegmentDataPort = getDisplayDigit(seconds%10,1);
	SegmentControlPort = ~0x01;
	
	SegmentDataPort = getDisplayDigit(seconds/10,1);
	SegmentControlPort = ~0x02;
	
	SegmentDataPort = getDisplayDigit(minutes%10,1);
	SegmentControlPort = ~0x04;
	
	SegmentDataPort = getDisplayDigit(minutes/10,1);
	SegmentControlPort = ~0x08;
	
	SegmentDataPort = getDisplayDigit(hours%10,1);
	SegmentControlPort = ~0x10;
	
	SegmentDataPort = getDisplayDigit(hours/10,1);
	SegmentControlPort = ~0x20;
}

#endif