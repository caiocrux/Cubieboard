/*
 * GpioControl.h
 *
 *  Created on: Feb 5, 2015
 *      Author: caio
 */

#ifndef GPIOCONTROL_H_
#define GPIOCONTROL_H_

int GpioInitLedGreen(void);
int GpioInitLedRed(void);
int GpioSetLedGreenON(void);
int GpioSetLedGreenOFF(void);
int GpioSetLedRedON(void);
int GpioSetLedRedOFF(void);
int GpioCloseLedControl(void);
#endif /* GPIOCONTROL_H_ */
