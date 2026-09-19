/*
 * Timer0_Interrupt.c
 *
 * Created: 17-08-2026 15:29:54
 * Author : roseb
 */ 
#define F_CPU16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint16_t count=0;
ISR(TIMER0_OVF_vect)   //Interrupt Service Routine
{
	if(count>977)
	{
		PORTB ^=( 1<< PB5);
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
	sei();   //enabling global interrupt
	TCNT0=0;  //loading initial value
    TCCR0A &= ~((1 << WGM00) | (1 << WGM01));   //setting normal mode D6 and D3 as 0
	TCCR0B |= ((1 << CS01) | (1 << CS00));   //Pre-scalar 64 - 011
	TCCR0B &= ~(1 << CS02);   //Pre-scalar 64 - 011
    TIMSK0 |= (1 << TOIE0);   //Timer Overflow Interrupt Enabled in Timer Interrupt Mask Register
	while (1) 
    {
	}
}

