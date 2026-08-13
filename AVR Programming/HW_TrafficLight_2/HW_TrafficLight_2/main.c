/*
 * HW_TrafficLight_2.c
 *
 * Created: 06-08-2026 14:08:54
 * Author : roseb
 */ 


#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void LightSequence(void);
void PedestrianCross(void);

int main(void)
{
	DDRD&=~(1<<DDD2);   //Emergency Switch at PD2 as input
	PORTD|=(1<<PD2);   //Emergency pin internally pulled up
	PORTB|=(1<<PB0);   //Motor input pin Internally pulled up   
	PORTD|=(1<<PD0);   //Motor input pin Internally pulled up
	DDRC|=((1<<DDC5) | (1<<DDC4) | (1<<DDC3));   //PC5, PC4 and PC3 as Output(signal lights)
	DDRC|=(1<<DDC1);   //Motor Clockwise pin made as output
	DDRB|=(1<<DDB2);   //Motor Anticlockwise pin made as output
	
    
    while (1) 
    {
		if(!(PIND&(1<<PD2)))   //If the emergency switch is not pressed(ie. PD2 has 1 (connected internally to Vcc), not 0)
		{
			
			PedestrianCross();
			
		}
		else
		{
			LightSequence();
		}
	}
}
void LightSequence()
{
	PORTC|=(1<<PC5);   //PC5 - Green is ON
	PORTC&=~( (1<<PC4) | (1<<PC3) );   //PC4 - Orange and PC3 - Red is OFF
	_delay_ms(5000);
	
	PORTC|=(1<<PC4);   //PC4 - Orange is ON
	PORTC&=~( (1<<PC5) | (1<<PC3) );   //PC5 - Green and PC3 - Red is OFF
	_delay_ms(3000);
	
	PORTC|=(1<<PC3);   //PC3 - Red is ON
	PORTC&=~( (1<<PC4) | (1<<PC5) );   //PC4 - Orange and PC5 - Green is OFF
	_delay_ms(5000);
}
void PedestrianCross()
{
	PORTC|=(1<<PC3);   //Only the Red Led turns ON, rest all are OFF
	PORTC&=~( (1<<PC5) | (1<<PC4) );
	
	PORTC|=(1<<PC1);   //Clockwise output pin is HIGH
	PORTB&=~(1<<PB2);   //Anticlockwise pin is Low
	_delay_ms(3000);   //Arm blocks the vehicles
	PORTC&=~(1<<PC1);   //Clockwise output pin is Low
	PORTB&=~(1<<PB2);   //Anticlockwise pin is Low
	_delay_ms(10000);   //Time for the pedestrian to cross the road
	PORTC&=~(1<<PC1);   //Clockwise output pin is Low
	PORTB|=(1<<PB2);   //Anticlockwise pin is High
	_delay_ms(3000);   //Arm unblocks the vehicles
	PORTC&=~(1<<PC1);   //Clockwise output pin is Low
	PORTB&=~(1<<PB2);   //Anticlockwise pin is Low
	LightSequence();
	
}

