/*
 * Blink_Bitwise500ms.c
 *
 * Created: 03-04-2026 14:47:57
 * Author : roseb
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include<util/delay.h>


int main(void)
{
	DDRC|=(1<<DDC6);                 //configuring DDRC's 6th pin as output
    /* Replace with your application code */
    while (1) 
    {
		PORTC|=(1<<PC6);             //setting Port C's 6th pin as high
		_delay_ms(500);
		PORTC&=~(1<<PC6);            //setting Port C's 6th pin as low
		_delay_ms(500);
		
		
		


		
			
    }
}

