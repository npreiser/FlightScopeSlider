#include <stdint.h>
#include <stdio.h>
#include <wiringPi.h>
#include <bcm2835.h>
#include "SPI_TMC.h"

// Include the IC(s) you want to use
#include "TMC-API/tmc/ic/TMC5160/TMC5160.h"

#define MOTOR0 0 // Motor 0
#define MAX_VEL 600000
#define MAX_ACC 5000

int vstart = 0;
int a1 = 100;
int v1 = 100;
int amax = 5000; // 1000;
int vmax = 50000; // 3000;
int dmax = 4700;
int d1 = 1400;
int vstop = 10;
float revs = 20; // 60; //0.5;

#define MAX_REVOLUTIONS 20			 // this will be based on testing of system...
#define NUMBER_OF_REGIONS 5			 //
#define TOTAL_WIDTH_STEPS 51200 * 10 // this should be tuned per length of raild..

void resetMotorDrivers(char motor);

void waitFor(char motor, int position)
{
	int pos = tmc5160_readInt(motor, TMC5160_XACTUAL);

	while (pos != position)
	{
		//delay(100);
		pos = tmc5160_readInt(motor, TMC5160_XACTUAL);
	}
}

void waitForVelocity0(char motor)
{
	int velocity = tmc5160_readInt(motor, TMC5160_VACTUAL);
	while (velocity > 0)
	{
		velocity = tmc5160_readInt(motor, TMC5160_VACTUAL);
	}
	//printf("velocity is now 0\n");
}

int bcminit()
{
	if (!bcm2835_init())
	{
		printf("bcm2835_init() failed");
		exit(-1);
	}
	return 0;
}

int initwirepi()
{
	wiringPiSetupGpio();
}

void initSpi()
{
	// Initiate SPI
	bcm2835_spi_begin();
	bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_MSBFIRST);	// MSB first
	bcm2835_spi_setDataMode(BCM2835_SPI_MODE3);					// SPI Mode 3
	bcm2835_spi_setClockDivider(BCM2835_SPI_CLOCK_DIVIDER_256); // 1 MHz clock
	bcm2835_spi_chipSelect(BCM2835_SPI_CS0);					// define CS pin
	bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS0, LOW);	// set CS polarity to low
}

int setupGpio()
{
	bcminit();

	initwirepi();

	initSpi();

	pinMode(2, OUTPUT);
	pinMode(3, OUTPUT);
	pinMode(4, OUTPUT);

	digitalWrite(2, HIGH); // Apply VCC_IO voltage to Motor 0
	digitalWrite(3, LOW);  // Use internal clock
	digitalWrite(4, LOW);  // Enable driver stage

	return 0;
}

void configureMotor(char motor)
{
	resetMotorDrivers(motor);

	// MULTISTEP_FILT=1, EN_PWM_MODE=1 enables stealthChop™
	tmc5160_writeInt(motor, TMC5160_GCONF, 0x0000000C);

	// TOFF=3, HSTRT=4, HEND=1, TBL=2, CHM=0 (spreadCycle™)
	tmc5160_writeInt(motor, TMC5160_CHOPCONF, 0x000100C3);

	// IHOLD=8, IRUN=15 (max. current), IHOLDDELAY=6
	//tmc5160_writeInt(motor, TMC5160_IHOLD_IRUN, 0x00080F0A);

	// ihold = 0,  irun 15 ,  ihold delay = 6
	tmc5160_writeInt(motor, TMC5160_IHOLD_IRUN, 0x00080F01);

	// TPOWERDOWN=10: Delay before power down in stand still
	tmc5160_writeInt(motor, TMC5160_TPOWERDOWN, 0x0000000A);

	// TPWMTHRS=500
	tmc5160_writeInt(motor, TMC5160_TPWMTHRS, 0x000001F4);
}

void initMotorParams(char motor)
{
	// Values for speed and acceleration
	tmc5160_writeInt(motor, TMC5160_VSTART, vstart);
	tmc5160_writeInt(motor, TMC5160_A1, a1);
	tmc5160_writeInt(motor, TMC5160_V1, v1);
	tmc5160_writeInt(motor, TMC5160_AMAX, amax);
	tmc5160_writeInt(motor, TMC5160_VMAX, 200000);
	tmc5160_writeInt(motor, TMC5160_DMAX, dmax);
	tmc5160_writeInt(motor, TMC5160_D1, d1);
	tmc5160_writeInt(motor, TMC5160_VSTOP, vstop);
	tmc5160_writeInt(motor, TMC5160_RAMPMODE, TMC5160_MODE_POSITION);
	tmc5160_writeInt(motor, TMC5160_SWMODE, 0x00);

	
}

void initMotorParamsHoming(char motor)
{
	// Values for speed and acceleration
	tmc5160_writeInt(motor, TMC5160_VSTART, vstart);
	tmc5160_writeInt(motor, TMC5160_A1, a1);
	tmc5160_writeInt(motor, TMC5160_V1, v1);
	tmc5160_writeInt(motor, TMC5160_AMAX, amax);
	tmc5160_writeInt(motor, TMC5160_VMAX, 20000);
	tmc5160_writeInt(motor, TMC5160_DMAX, dmax);
	tmc5160_writeInt(motor, TMC5160_D1, d1);
	tmc5160_writeInt(motor, TMC5160_VSTOP, vstop);
	tmc5160_writeInt(motor, TMC5160_RAMPMODE, TMC5160_MODE_POSITION);
	tmc5160_writeInt(motor, TMC5160_SWMODE, 0x90A); //enable  right, and flip polarity, for pull up. set xlatch up
	tmc5160_writeInt(motor, TMC5160_XLATCH, 0x00);	// set xlatch as point 0
}

void gotoTarget(char motor, int targetPos, int wait)
{
	tmc5160_writeInt(motor, TMC5160_XTARGET, targetPos);
	if (wait)
	{
		waitFor(motor, targetPos);
	}
}

void gotoTargetHome(char motor, int targetPos)
{
	tmc5160_writeInt(motor, TMC5160_XTARGET, targetPos);
	delay(100);
	waitForVelocity0(motor);
}

void disableMotorPower()
{
	digitalWrite(4, HIGH); // Disable driver stage
	delay(10);
	digitalWrite(2, LOW); // Remove VCC_IO voltage from Motor 0
	delay(10);
}

void shutdown()
{
	// End SPI communication
	bcm2835_spi_end();
	bcm2835_close();
}

int getPosition(char motor)
{
	return tmc5160_readInt(motor, TMC5160_XACTUAL);
}

void resetMotorDrivers(char motor)
{
	if (!tmc5160_readInt(motor, TMC5160_VACTUAL))
	{
		digitalWrite(2, LOW); // Apply VCC_IO voltage to Motor 0
		delay(10);
		digitalWrite(2, HIGH); // Apply VCC_IO voltage to Motor 0
		delay(10);
	}
}

int tune_max_speed()
{
	if (setupGpio() == 1)
	{
		return 1;
	}
	configureMotor(MOTOR0);

	initMotorParams(MOTOR0);
}


// public routines start
// ******************************************************
int initDriver()
{
	printf("TMC5160 Driver init\n");

	if (setupGpio() == 1)
	{
		return 1;
	}
	configureMotor(MOTOR0);
	return 0;
}

int cleanupDriver()
{
	printf("TMC5160 Driver cleanup\n");

	disableMotorPower();
	shutdown();
	return 0;
}

int setNormalRunModeParams()
{
	initMotorParams(MOTOR0);
}

// will find right most postion,  and set that as 0...
int findHome()
{

	initMotorParamsHoming(MOTOR0);
	int targetPos = (int)(MAX_REVOLUTIONS * 51200.0); ///  NOTE  51200 is the number of microsteps per rev.

	gotoTargetHome(MOTOR0, targetPos); // go right until velocity == 0,

	printf("TMC5160 Position: %d\n", tmc5160_readInt(MOTOR0, TMC5160_XACTUAL));
	printf("TMC5160 Xlatch: %d\n", tmc5160_readInt(MOTOR0, TMC5160_XLATCH));
	int diff = tmc5160_readInt(MOTOR0, TMC5160_XACTUAL) - tmc5160_readInt(MOTOR0, TMC5160_XLATCH);
	printf("diff calc : %d\n", diff);
	tmc5160_writeInt(MOTOR0, TMC5160_XACTUAL, diff); //set new home position
	gotoTarget(MOTOR0, 0, 1);						 //go back to home postion that was just set..

	printf("FINAL HOME TMC5160 Position: %d\n", tmc5160_readInt(MOTOR0, TMC5160_XACTUAL));

	delay(500);
	return 0;
}

// testing code,
// assume total width is dified up 5 positions 0, 1, 2,3,4.. 0 = home,  2 center, 4 left most region.
//
void gotoRegion(int targetRegion)
{
	//initMotorParams(MOTOR0);
	// 0 based region number  .
	int tpos = 0;
	if (targetRegion > 0)
	{
		int region = targetRegion;
		if (region > NUMBER_OF_REGIONS - 1) // never let it get above the max amount.
			region = NUMBER_OF_REGIONS - 1;

		// total width in # of steps .
		int stepsPerRegion = TOTAL_WIDTH_STEPS / NUMBER_OF_REGIONS;

		tpos = -1 * (stepsPerRegion * region);
	}

    printf("going to target position: %d\n", tpos);

	tmc5160_writeInt(MOTOR0, TMC5160_XTARGET, tpos);
	waitFor(MOTOR0, tpos); // wait for position. to be found.
	printf("TMC5160 Position: %d\n", tmc5160_readInt(MOTOR0, TMC5160_XACTUAL));
}

int wiggle_test()
{
	setNormalRunModeParams();
	printf("running wiggle test \n");
	int targetPos = (int)(3 * 51200.0);
	gotoRegion(4);
	printf("TMC5160 Position: %d\n", tmc5160_readInt(MOTOR0, TMC5160_XACTUAL));
	delay(2000);
	gotoRegion(0);
}



int run_example()
{
	if (setupGpio() == 1)
	{
		return 1;
	}
	configureMotor(MOTOR0);
	initMotorParams(MOTOR0);

	int targetPos = (int)(revs * 51200.0); ///  NOTE  51200 is the number of microsteps per rev.
	gotoTarget(MOTOR0, targetPos, 1);
	printf("TMC5160 Position: %d\n", tmc5160_readInt(MOTOR0, TMC5160_XACTUAL));

	delay(500);

	gotoTarget(MOTOR0, 0, 1);
	//printf("TMC5160 Position: %d\n", tmc5160_readInt(MOTOR0, TMC5160_XACTUAL));

	disableMotorPower();

	shutdown();

	return 0;
}
void main()
{
	//run_example();
	initDriver();
	//setNormalRunModeParams();
	//printf("Init TMC5160 Position: %d\n", tmc5160_readInt(MOTOR0, TMC5160_XACTUAL));

     // gotoRegion(2);
	findHome();
	
	delay(2000);
	//gotoRegion(1);
	//wiggle_test();

	//cleanupDriver();
}
