#include <iostream>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/GpioControl.h"

int main (void){
	int result = 0;


	if (GpioInitLedGreen()){
		printf("Green Led is OK !\n");
	}
	else{
		printf("Green Led FAIL\n");
	}
	if (GpioInitLedRed()){
		printf("Red Led OK !\n");
	}
	else{
		printf("Red Led FAIL\n");
	}
	printf("What do you want to do ? \n (1)Turn ON Led Green\n (2)Turn OFF Led Green\n (3)Turn ON Led Red\n (4)Turn OFF Led Red\n ");
	scanf("%d",&result);

	switch(result){
	case 1:
		printf("Set Led Green ON !\n");
		GpioSetLedGreenON();
	break;

	case 2:
		printf("Set Led Green OFF !\n");
		GpioSetLedGreenOFF();
	break;

	case 3:
		printf("Set Led Red ON !\n");
		GpioSetLedRedON();
	break;

	case 4:
		printf("Set Led Red OFF !\n");
		GpioSetLedRedOFF();
	break;

	}
	printf("Closing the Gpio ! \n ");
	GpioCloseLedControl();
	return 0;

}
