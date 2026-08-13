/*
 * Internally_Pullup_Concept.c
 *
 * Created: 06-08-2026 12:19:11
 * Author : roseb
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>



int main(void)
{
    DDRD&=~(1<<DDD2);   //PD2 is made as input pin
	PORTD|=(1<<PD2);   //Since, PD2 is made as input, this line means, PD2 is internally connected to Vcc
	DDRB|=(1<<DDB5);   //PB5 is made as output
    while (1) 
    {
		if(!(PIND&(1<<PD2)))   //when 0 comes to PD2, ie, PD2 is connected to ground through switch
		{
			PORTB|=(1<<PB5);   //PB5 high
		}
		else
		{
			PORTB&=~(1<<PB5);   //PB5 low
		}
    }
}

