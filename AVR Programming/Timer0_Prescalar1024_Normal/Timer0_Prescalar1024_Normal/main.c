/*
 * Timer0_Prescalar1024_Normal.c
 *
 * Created: 13-08-2026 11:03:26
 * Author : roseb
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>

void delay_1s(void)
{
	TCNT0=0;
	TCCR0A&=~((1<<WGM01) | (1<<WGM00));
	TCCR0B|=((1<<CS02) | (1<<CS00));
	TCCR0B&=~(1<<CS01);
	for(int i=0;i<61;i++)
	{
		while(!(TIFR0&(1<<TOV0)));
		TIFR0|=(1<<TOV0);
	}
}

int main(void)
{
    DDRB|=(1<<DDB5);
    while (1) 
    {
		PORTB^=(1<<PB5);
		delay_1s();
    }
}

