#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define OK 1
#define FAIL 0
#define LED_GREEN "1"
#define LED_RED "2"

int GpioInitLedGreen(void){
	char Pin [4];
	FILE *fp;
	// Check to verify if the port is available.
	fp = fopen("/sys/class/gpio/export","ab");
	if(fp == NULL){
		printf("Cannot export the Pin %s!\n",LED_GREEN);
		perror("fopen");
		return FAIL;
	}
	rewind(fp);
	strcpy(Pin,LED_GREEN);
	fwrite(&Pin,sizeof(char),1,fp);
	fclose(fp);

	/*Define the port as Output*/
	fp = fopen("/sys/class/gpio/gpio1_pd1/direction","rb+");
	if(fp == NULL){
			printf("Cannot define the Pin %s as OutPut\n",LED_GREEN);
			perror("fopen");
			return FAIL;
		}
	rewind(fp);
	strcpy(Pin,"out");
	fwrite(&Pin,sizeof(char),3,fp);
	fclose(fp);

	return OK;
}

int GpioInitLedRed(void){
	char Pin [4];
	FILE *fp;
	// Check to verify if the port is available.
	fp = fopen("/sys/class/gpio/export","ab");
	if(fp == NULL){
		printf("Cannot export the Pin %s!\n",LED_RED);
		perror("fopen");
		return FAIL;
	}
	rewind(fp);
	strcpy(Pin,LED_RED);
	fwrite(&Pin,sizeof(char),1,fp);
	fclose(fp);

	/*Define the port as Output*/
	fp = fopen("/sys/class/gpio/gpio2_pd2/direction","rb+");
	if(fp == NULL){
			printf("Cannot define the Pin %s as OutPut\n",LED_RED);
			perror("fopen");
			return FAIL;
		}
	rewind(fp);
	strcpy(Pin,"out");
	fwrite(&Pin,sizeof(char),3,fp);
	fclose(fp);

	return OK;
}

int GpioSetLedGreenON(void){
	char Pin [4];
	FILE *fp;
	// Check to verify if the port is available.
	fp = fopen("/sys/class/gpio/gpio1_pd1/value","rb+");
	if(fp == NULL){
			printf("Cannot set the Pin %s! to ON! \n",LED_GREEN);
			perror("fopen");
			return FAIL;
	}
	rewind(fp);
	strcpy(Pin,"1"); // "1" means ON
	fwrite(&Pin,sizeof(char),1,fp);
	fclose(fp);
	return OK;
}
int GpioSetLedGreenOFF(void){
	char Pin [4];
	FILE *fp;
	// Check to verify if the port is available.
	fp = fopen("/sys/class/gpio/gpio1_pd1/value","rb+");
	if(fp == NULL){
			printf("Cannot set the Pin %s! to ON! \n",LED_GREEN);
			perror("fopen");
			return FAIL;
	}
	rewind(fp);
	strcpy(Pin,"0"); // "0" means OFF
	fwrite(&Pin,sizeof(char),1,fp);
	fclose(fp);
	return OK;
}


int GpioSetLedRedON(void){
	char Pin [4];
	FILE *fp;
	// Check to verify if the port is available.
	fp = fopen("/sys/class/gpio/gpio2_pd2/value","rb+");
	if(fp == NULL){
			printf("Cannot set the Pin %s! to ON! \n",LED_RED);
			perror("fopen");
			return FAIL;
	}
	rewind(fp);
	strcpy(Pin,"1"); // "1" means ON
	fwrite(&Pin,sizeof(char),1,fp);
	fclose(fp);
	return OK;
}
int GpioSetLedRedOFF(void){
	char Pin [4];
	FILE *fp;
	// Check to verify if the port is available.
	fp = fopen("/sys/class/gpio/gpio2_pd2/value","rb+");
	if(fp == NULL){
			printf("Cannot set the Pin %s! to ON! \n",LED_RED);
			perror("fopen");
			return FAIL;
	}
	rewind(fp);
	strcpy(Pin,"0"); // "0" means OFF
	fwrite(&Pin,sizeof(char),1,fp);
	fclose(fp);
	return OK;
}
int GpioCloseLedControl(void){
	char Pin [4];
	FILE *fp;
	// Check to verify if the port is available.
	fp = fopen("/sys/class/gpio/unexport", "r+");
	if(fp == NULL){
			printf("Cannot unexport the pins !! \n");
			perror("fopen");
			return FAIL;
	}
	rewind(fp);
	strcpy(Pin,"1"); // "1" means close led Green !
	fwrite(&Pin,sizeof(char),1,fp);

	strcpy(Pin,"2"); // "2" means close led Red !
	fwrite(&Pin,sizeof(char),1,fp);
	fclose(fp);
	return OK;
}


