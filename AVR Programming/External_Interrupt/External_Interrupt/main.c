/*
 * External_Interrupt.c
 *
 * Created: 19-09-2026 10:09:39
 * Author : roseb
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

ISR(INT0_vect)   //Interrupt Service Routine for Ext Interrupt 0
{
	PORTB^=(1<<PB5);   //Toggling Led
	_delay_ms(3000);   //Providing a small delay to avoid de-bouncing
}

int main(void)
{
    sei();   //Enabling Global Interrupt
	DDRD&=~(1<<DDD2);   //Configuring PD2 as EXT INTERRUPT Input pin
	EIFR|=(1<<INTF0);   //Writing 1 to INTF0 bit to clear(make it 0) the flag, otherwise led glows without interrupt request comes.
	DDRB|=((1<<DDB5) | (1<<DDB4));   //PB5 as Output
	EIMSK|=(1<<INT0);   //Enabling Ext Interrupt 0 using Ext Int Control Register
	EICRA|=((1<<ISC00) | (1<<ISC01));   //Configuring interrupt for rising edge 
	
    while (1) 
    {
		PORTB&=~(1<<PB5);   //Initially, when interrupt is not arrived, led remains off
		PORTB^=(1<<PB4);   //Defaultly blinking led for 1 sec
		_delay_ms(1000);
    }
}

