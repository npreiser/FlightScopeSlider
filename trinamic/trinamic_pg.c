#include <stdint.h>
#include <stdio.h>
#include <wiringPi.h>
#include <bcm2835.h>
#include "SPI_TMC.h"

// Include the IC(s) you want to use
#include "TMC-API/tmc/ic/TMC5160/TMC5160.h"

#define MOTOR0			0 // Motor 0
#define MAX_VEL 600000
#define MAX_ACC 5000

void resetMotorDrivers(char motor);

void waitFor(char motor, int position) {
	int pos = tmc5160_readInt(motor, TMC5160_XACTUAL);
	while (pos != position)
	{
		//delay(100);
		pos = tmc5160_readInt(motor, TMC5160_XACTUAL);
	}
}

int bcminit() {
	if (!bcm2835_init()) {
		printf("bcm2835_init() failed");
		exit(-1);
	}
	return 0;
}

int initwirepi() {
	wiringPiSetupGpio();
}

void initSpi() {
	// Initiate SPI
	bcm2835_spi_begin();
	bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_MSBFIRST);	// MSB first
	bcm2835_spi_setDataMode(BCM2835_SPI_MODE3);					// SPI Mode 3
	bcm2835_spi_setClockDivider(BCM2835_SPI_CLOCK_DIVIDER_256); // 1 MHz clock
	bcm2835_spi_chipSelect(BCM2835_SPI_CS0);					// define CS pin
	bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS0, LOW);	// set CS polarity to low
}

int setupGpio() {
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

void configureMotor(char motor) {
	resetMotorDrivers(motor);

	// MULTISTEP_FILT=1, EN_PWM_MODE=1 enables stealthChop™
	tmc5160_writeInt(motor, TMC5160_GCONF, 0x0000000C);

	// TOFF=3, HSTRT=4, HEND=1, TBL=2, CHM=0 (spreadCycle™)
	tmc5160_writeInt(motor, TMC5160_CHOPCONF, 0x000100C3);

	// IHOLD=8, IRUN=15 (max. current), IHOLDDELAY=6
	tmc5160_writeInt(motor, TMC5160_IHOLD_IRUN, 0x00080F0A);

	// TPOWERDOWN=10: Delay before power down in stand still
	tmc5160_writeInt(motor, TMC5160_TPOWERDOWN, 0x0000000A);

	// TPWMTHRS=500
	tmc5160_writeInt(motor, TMC5160_TPWMTHRS, 0x000001F4);
}

int vstart = 0;
int a1 = 100;
int v1 = 100 ;
int amax = 1000;
int vmax = 3000;
int dmax = 4700;
int d1 = 1400;
int vstop = 10;
float revs = 0.5;

void initMotorParams(char motor)
{
	// Values for speed and acceleration
	tmc5160_writeInt(motor, TMC5160_VSTART, vstart);
	tmc5160_writeInt(motor, TMC5160_A1, a1);
	tmc5160_writeInt(motor, TMC5160_V1, v1);
	tmc5160_writeInt(motor, TMC5160_AMAX, amax);
	tmc5160_writeInt(motor, TMC5160_VMAX, vmax);
	tmc5160_writeInt(motor, TMC5160_DMAX, dmax);
	tmc5160_writeInt(motor, TMC5160_D1, d1);
	tmc5160_writeInt(motor, TMC5160_VSTOP, vstop);
	tmc5160_writeInt(motor, TMC5160_RAMPMODE, TMC5160_MODE_POSITION);
}

void gotoTarget(char motor, int targetPos, int wait)
{
	tmc5160_writeInt(motor, TMC5160_XTARGET, targetPos);
	if (wait) {
		waitFor(motor, targetPos);
	}
}

void disableMotorPower() {
	digitalWrite(4, HIGH); // Disable driver stage
	delay(10);
	digitalWrite(2, LOW);  // Remove VCC_IO voltage from Motor 0
	delay(10);
}

void shutdown() {
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

int tune_max_speed() {
	if (setupGpio() == 1)
	{
		return 1;
	}
	configureMotor(MOTOR0);

	initMotorParams(MOTOR0);
}

int run_example()
{
	if (setupGpio() == 1) {
      return 1;
	}
	configureMotor(MOTOR0);

	initMotorParams(MOTOR0);

	//waitFor(0, 10);

	int targetPos = (int)(revs * 51200.0);
	gotoTarget(MOTOR0, targetPos, 1);
	printf("TMC5160 Position: %d\n", tmc5160_readInt(MOTOR0, TMC5160_XACTUAL));

	delay(500);

	//gotoTarget(MOTOR0, 0, 1);
	//printf("TMC5160 Position: %d\n", tmc5160_readInt(MOTOR0, TMC5160_XACTUAL));

	disableMotorPower();

	shutdown();

	return 0;
}

int return_pass() {
	return 0;
}

void main() {
	run_example();
}
