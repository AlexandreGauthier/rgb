/*
 * devboard.cpp
 *
 * Created: 2021-01-09 2:24:01 PM
 * Author : Alexandre Gauthier
 */ 

#define F_CPU 3300000

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

const unsigned int LED1 = 1 << 3;
const unsigned int LED2 = 1 << 1;

#define ENCODER_A_bm (1 << 2)
#define ENCODER_B_bm (1 << 3)
#define ENCODER_MEASURE_PERIOD 20

volatile uint8_t encoderBitshift;
volatile uint8_t count;

void TCA_init()
{
	// Split mode configuration
	TCA0.SPLIT.CTRLD |= 1;
	TCA0.SPLIT.HPER = 0xFF;		  // max period
	TCA0.SPLIT.LPER = 0xFF;       // max period
	TCA0.SPLIT.CTRLA |= 0x2 << 1; // CLK_SEL, prescaler of 256
	TCA0.SPLIT.CTRLA |= 1;        // Enable

	// Enable PWM outputs
	TCA0.SPLIT.CTRLB |= 1; // Enable LCMP0

	// Set PWM duty cycle
	TCA0.SPLIT.LCMP0 = 0xFF/10; // 25%
}

void TCB_init()
{
	TCB0.CCMP = ENCODER_MEASURE_PERIOD;
	TCB0.CTRLB |= TCB_CCMPEN_bm;
	TCB0.CTRLA |= 1;
	TCB0.INTCTRL |= 1;
}

void smooth()
{
	for(uint16_t i = 0; i < 0xFF; i++)
	{
		TCA0.SPLIT.LCMP0 = i*i >> 8;
		_delay_ms(10);
	}
}

void blink()
{
	PORTA.OUTCLR = LED1;
	_delay_ms(50);
	PORTA.OUTSET = LED1;
	_delay_ms(50);
}

int main(void)
{

	// Pin configuration
	//	  Built-in LED	
	PORTA.DIRSET = LED1;
	PORTA.OUTSET = LED1;

	// PWM output pins
	PORTB.DIRSET = 1 << 0;
	
	//	 Rotary encoder
	PORTB.PIN2CTRL |= PORT_PULLUPEN_bm;
	PORTB.PIN2CTRL |= PORT_ISC_FALLING_gc;
	
	PORTC.PIN3CTRL |= PORT_PULLUPEN_bm;
	//PORTC.PIN3CTRL |= PORT_ISC_FALLING_gc;
	
	//TCB_init();
	TCA_init();

	 count = 100;
	
	sei(); // Enable interrupts
		while (1) 
    {
	}
}

ISR(PORTB_PORT_vect)
{
	_delay_ms(2);
	if (PORTC.IN & ENCODER_B_bm)
	{
		if (count <= 245)
		{
			count += 10;
			TCA0.SPLIT.LCMP0 = count*count >> 8;
		}
	} 
	else if (count >= 10)
	{
		count -= 5;
		TCA0.SPLIT.LCMP0 = count*count >> 8;
	}

	PORTB.INTFLAGS = 0xFF;
}