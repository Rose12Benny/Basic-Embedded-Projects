/*
 * Blink_XOR.c
 *
 * Created: 04-08-2026 09:46:17
 * Author : roseb
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>



int main(void)
{
   DDRD|=(1<<DDD3); // set Pin 3 in Port D as output
     for(;;)
    {
		PORTD^=(1<<PD3); //set PD3 as high, after the delay it toggles to Low then repeats the blink operation for 2 seconds 
		_delay_ms(2000);
    }
}

