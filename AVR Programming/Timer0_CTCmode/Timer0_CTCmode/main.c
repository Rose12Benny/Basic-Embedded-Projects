/*
 * Timer0_CTCmode.c
 *
 * Created: 13-08-2026 19:06:12
 * Author : roseb
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>

void delay_1s(void)
{
	TCNT0=0;
	OCR0A=0xC8;
	TCCR0A|=(1<<WGM01);
	TCCR0A&=~(1<<WGM00);
	TCCR0B|=(1<<CS02 | 1<<CS00);
	TCCR0B&=~(1<<CS01);
	for(int i=0;i<78;i++)
	{
		while(!(TIFR0&(1<<OCF0A)));
		TIFR0|=(1<<OCF0A);
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

