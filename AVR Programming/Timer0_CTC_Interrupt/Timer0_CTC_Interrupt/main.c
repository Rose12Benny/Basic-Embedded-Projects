/*
 * Timer0_CTC_Interrupt.c
 *
 * Created: 04-09-2026 12:15:06
 * Author : roseb
 */ 
#define F_CPU16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint8_t count=0;
ISR(TIMER0_COMPA_vect)
{
	if(count>78)
	{
		PORTB^=(1<<PB5);
		count=0;
	}
	else
	{
		count++;
	}
}

int main(void)
{
    DDRB |= (1 << DDB5);   //PB5 as output
	sei();   //enabling Global Interrupt
	TCNT0=0;
	OCR0A=0xC8;
	TCCR0A|=(1<<WGM01);
	TCCR0A&=~(1<<WGM00);
	TCCR0B|=((1<<CS02) | (1<<CS00));
	TCCR0B&=~(1<<CS01);
	TIMSK0|=(1<<OCIE0A);
    while (1) 
    {
    }
}

