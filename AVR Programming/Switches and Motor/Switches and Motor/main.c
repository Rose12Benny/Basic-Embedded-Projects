/*
 * Switches and Motor.c
 *
 * Created: 04-08-2026 21:00:31
 * Author : roseb
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void cw(void);
void ccw(void);
void stp(void);

int main(void)
{
    DDRD&=~(1<<DDD0);   //PD0 as input
	DDRB&=~(1<<DDB0);   //PB0 as input
	DDRD|=(1<<DDD2);   //PD2 as output
	DDRB|=(1<<DDB1);   //PB1 as output
    while (1) 
    {
		if( (PINB&(1<<PB0)) && !(PIND&(1<<PD0)) )
		{
			cw();
		}
		else if( !(PINB&(1<<PB0)) && (PIND&(1<<PD0)) )
		{
			ccw();
		}
		else
		{
			stp();
		}
    }
}
void cw()
{
	//When PB1 is 1 and PD2 is 0, then CLOCKWISE
	PORTB|=(1<<PB1);
	PORTD&=~(1<<PD2);
	
}
void ccw()
{
	//When PB1 is 0 and PD2 is 1, then ANTICLOCKWISE
	PORTB&=~(1<<PB1);
	PORTD|=(1<<PD2);
	
}
void stp()
{
	//When PB1 is 0 and PD2 is 0, then STOP
	PORTB&=~(1<<PB1);
	PORTD&=~(1<<PD2);
	
}

