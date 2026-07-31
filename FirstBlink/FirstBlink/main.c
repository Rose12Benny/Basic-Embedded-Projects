/*
 * FirstBlink.c
 *
 * Created: 31-07-2026 15:16:31
 * Author : roseb
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>



int main(void)
{
    DDRB=0b00000100;
    while (1) 
    {
		PORTB=0b00000100;
		_delay_ms(1000);
		PORTB=0b00000000;
		_delay_ms(1000);
    }
}

