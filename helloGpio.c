#include <stdio.h>
#include <wiringPi.h>
#include <stdlib.h>

#define loopCount 5
#define delayTime 500

// ./helloGpio [PinNumber]
int main(int argc, char** argv)
{
    int gpioNo;
    int i;

    //Step 1. WiringPi Init
    wiringPiSetup();
   
    //Pin number Error
    if(argc<2)
    {
	printf("Usage : %s gpioNo\n", argv[0]);
	return -1;
    }

    gpioNo = atoi(argv[1]);
    
    //Step 2. Pin direction setup
    pinMode(gpioNo, OUTPUT);

    for(i = 0; i < 1000; i ++)
    {
        //Step 3. Pin write
    	digitalWrite(gpioNo, HIGH);
    	delay(i*5);
    	digitalWrite(gpioNo, LOW);
    	delay(i*5);
    }

    return 0;
}
