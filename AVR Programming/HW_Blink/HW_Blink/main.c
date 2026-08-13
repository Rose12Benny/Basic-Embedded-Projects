/*
 * HW_Blink.c
 *
 * Created: 31-07-2026 15:39:53
 * Author : roseb
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    DDRB=0b00100000;
    for(;;) 
    {
		PORTB=0b00100000;
		_delay_ms(3000);
		PORTB=0b00000000;
		_delay_ms(3000);
    }
}

