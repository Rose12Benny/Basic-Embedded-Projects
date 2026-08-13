/*
 * Timer0_Prescalar64_Normal.c
 *
 * Created: 10-08-2026 15:11:51
 * Author : roseb
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>

void delay_1s(void)
{
	
	for(int i=0;i<977;i++)   //Repeat up to 977 cycles for 1 sec delay
	{   
		while(!(TIFR0&(1<<TOV0)));   //Check the Tov0 Flag is set
		TIFR0|=(1<<TOV0);   //Clear the Flag bit by writing 1
	}
}
int main(void)
{
	TCNT0=0;   //load initial value
	TCCR0A&=~(1<<WGM00 | 1<<WGM01);   //Configure D6 and D3 as 0 [Normal Mode]
	TCCR0B|=(1<<CS01|1<<CS00);   //CS02, CS01, CS00 bits are 011, Here CS00 and CS01 as 1
	TCCR0B&=~(1<<CS02);   //CS02 as 0
    DDRB|=(1<<DDB5);   //Set pb5 as output pin for connecting led
    while (1) 
    {
		PORTB^=(1<<PB5);   //Toggle operation for blinking led
		delay_1s();   //This function generates 1 sec delay using TIMER0 with prescalar 64
    }
}

