/*
 * 2Pin_Blinking.c
 *
 * Created: 04-08-2026 10:08:57
 * Author : roseb
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRB|=(1<<DDB4);   //setting PB4 as output
	DDRB|=(1<<DDB5);   //setting PB5 as output
	
	
    for(;;)
    {
		PORTB|=(1<<PB4);   //PB4 ON for 5 sec
		PORTB&=~(1<<PB5);   //PB5 OFF for 5 sec
		_delay_ms(5000);
		
		PORTB&=~(1<<PB4);   //PB4 OFF for 3 sec
		PORTB&=~(1<<PB5);   //PB5 OFF for 3 sec
		_delay_ms(3000);
		
		PORTB&=~(1<<PB4);   //PB4 OFF for 5 sec
		PORTB|=(1<<PB5);   //PB5 ON for 5 sec
		_delay_ms(5000);
	
		
    }
}

