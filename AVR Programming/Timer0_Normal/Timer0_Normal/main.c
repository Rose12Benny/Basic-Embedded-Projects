/*
 * Timer0_Normal.c
 *
 * Created: 07-08-2026 12:18:35
 * Author : roseb
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>

void delay_1s(void)
{
	TCNT0=0;   //Loading initial value of counter
	TCCR0A&=~((1<<WGM01) | (1<<WGM00));   //Set Normal mode for Timer0
	
	//Set No Prescaling
	TCCR0B|=(1<<CS00); 
	TCCR0B&=~((1<<CS02) | (1<<CS01));
	
	for(long int i=0;i<65500;i++)   //Repeat 62500 times to get 1 sec delay
	{   
		while(!(TIFR0&(1<<TOV0)));   //Checks the flag bit - TOV0 is 1. If its 0, while loop continues, if its 1, exits from loop.
		TIFR0|=(1<<0);   //Clears the flag by writing 1 to it. Then only next cycle starts from 0 to 255 [STRANGE RULE]
	}  
}
int main(void)
{
    DDRB|=(1<<DDB5);   //Sets PB5 as output pin to connect led
    while (1) 
    {
		PORTB^=(1<<PB5);   //Toggle logic for blink operation [XOR between previous state and new state]
		delay_1s();   //Calls the delay_1s() function for generating 1sec dealy 
    }
}

