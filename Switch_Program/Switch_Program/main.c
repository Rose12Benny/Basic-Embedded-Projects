/*
 * Switch_Program.c
 *
 * Created: 04-08-2026 20:03:16
 * Author : roseb
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRD&=~(1<<DDD2);
	DDRB|=(1<<DDB5);
    while (1) 
    {
		if(PIND&(1<<PD2)) //Checks 1 at PD2
		{
			PORTB|=(1<<PB5); //PB5 as high
		}
		else
		{
			PORTB&=~(1<<PB5); //PB5 as low
		}
		
    }
}

