/*
 * Blink_Bitwise.c
 *
 * Created: 01-08-2026 11:50:50
 * Author : roseb
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    DDRB|=(1<<DDB3); // Set PB3 as output
	
    for(;;)
    {
		PORTB|=(1<<PB3); // Set PD3 as high
		_delay_ms(1000);
		PORTB&=~(1<<PB3); //Set PD3 as low
		_delay_ms(1000);
    }
}

