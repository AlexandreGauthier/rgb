#include "main.h"

#define POWER_ON_ERROR 0
#define PIN_POWER_EN (1 << 5)// PB5

static uint8_t PWM_DUTY_CYCLES[8];
static uint8_t POPULATED_CHANNELS;

void debugMain()
{
	uint8_t i = 0;
	int8_t direction = 1;
	while (1)
	{
		TCA0.SPLIT.LCMP2 = i*i;//compensatedIntensity(i);
		
		if (i == 255)
		{
			direction = -1;
		}
		else if (i == 0)
		{
			direction = 1;
		}
		
		i += direction;
		_delay_ms(10);
	}
}

int main(void)
{
	setupPeripherals();
	
	POPULATED_CHANNELS = powerOnTest();
	if (POPULATED_CHANNELS == POWER_ON_ERROR)
	{
		shutdownGracefully(10);
	}
	
	debugMain();

    while (1)
    {
    }
}

/*
	TODO: Activate all channels one at a time and measure current.
		- Under some low bound -> Disable the channel (may not be possible if the current sense signal is too small for that low bound)
		- Over a high bound    -> Return POWER_ON_ERROR
		- Just right           -> Set channel bit in the returned bitfield
*/
uint8_t powerOnTest()
 {
	 return 1;
 }



void shutdownGracefully(uint8_t delaySeconds)
{
	disablePeripherals();
	
	// Adding a delay prevents the user from mashing the power button which
	// could be hazardous in the case of an overcurrent shutdown
	for (uint8_t i = 0; i < delaySeconds; i++)
	{
		_delay_ms(1000);
	}
	
	// Tristating this pin cuts power to the chip
	PORTB.OUTCLR = PIN_POWER_EN;
	
	// If for some reason power is maintained, do nothing forever
	while (1)
	{
	}
}

void setupPeripherals()
{
	setupGPIO();
	setupTCA();
	setupTCC();
	setupADC();
}

// TODO  : Setup the rest of the pins
void setupGPIO()
{
	PORTB.OUTSET = PIN_POWER_EN;
	PORTB.DIRSET = PIN_POWER_EN;	
}


// TODO  : Generate the 6 PWM signals associated with TCA
// MAYBE : Invert half of them to reduce RMS current ripple
void setupTCA()
{
	// Split mode configuration
	TCA0.SPLIT.CTRLD |= 1;
	TCA0.SPLIT.HPER = 0xFF;		  // max period
	TCA0.SPLIT.LPER = 0xFF;       // max period
	TCA0.SPLIT.CTRLA |= 0x2 << 1; // CLK_SEL, prescaler of 256
	TCA0.SPLIT.CTRLA |= 1;        // Enable

	// Enable PWM outputs
	TCA0.SPLIT.CTRLB |= 0b01110111; // Enable all 6 outputs
}

// TODO : Generate the 2 PWM signals associated with TCB
void setupTCC()
{
	
}

// TODO : Setup ADC for periodic measurements of the current_sens and power_en pins
// Either periodic interrupts or in the main loop
void setupADC()
{
	
}

// Compensate for the non-linear perception of brightness
uint8_t compensatedIntensity(uint8_t intensity)
{
	return  ((uint16_t)intensity * intensity) >> 8;
}

// TODO:
// On pin interrupt, do simple debounce logic
// If the signal is not noise, increment or decrement the appropriate PWM duty cycle and update peripheral
// If this  approach is too naive, use TCB0 to implement a more robust system

ISR (PORTA_PORT_vect)
{
}

ISR (PORTB_PORT_vect)
{
}

ISR (PORTC_PORT_vect)
{
}