#ifndef RGBMAIN_H_
#define RGBMAIN_H_

#define F_CPU 3300000

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

uint8_t powerOnTest();
void shutdownGracefully(uint8_t delaySeconds);

void setupPeripherals();
void disablePeripherals();

void setupGPIO();
void setupTCA();
void setupTCB();
void setupTCC();
void setupADC();

uint8_t compensatedIntensity(uint8_t intensity);

#endif /* PROJECT_H_ */