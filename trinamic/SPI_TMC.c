#include <bcm2835.h>
#include "SPI_TMC.h"


// TMC5160 SPI wrapper
void tmc5160_writeDatagram(uint8 motor, uint8 address, uint8 x1, uint8 x2, uint8 x3, uint8 x4)
{
    int value = x1;
	value <<= 8;
	value |= x2;
	value <<= 8;
	value |= x3;
	value <<= 8;
	value |= x4;

    tmc40bit_writeInt(motor, address, value);
}

void tmc5160_writeInt(uint8 motor, uint8 address, int value)
{
    tmc40bit_writeInt(motor, address, value);
}

int tmc5160_readInt(u8 motor, uint8 address)
{
    tmc40bit_readInt(motor, address);
    return tmc40bit_readInt(motor, address);
}

// General SPI decription
void tmc40bit_writeInt(u8 motor, uint8 address, int value)
{
    char tbuf[5];
    tbuf[0] = address | 0x80;
    tbuf[1] = 0xFF & (value>>24);
    tbuf[2] = 0xFF & (value>>16);
    tbuf[3] = 0xFF & (value>>8);
    tbuf[4] = 0xFF & value;

    bcm2835_spi_writenb (tbuf, 5);
}

int tmc40bit_readInt(u8 motor, uint8 address)
{
    char tbuf[5], rbuf[5];
    int value;
	// clear write bit
	tbuf[0] = address & 0x7F;
    
    bcm2835_spi_transfernb (tbuf, rbuf, 5);

	value =rbuf[1];
	value <<= 8;
	value |= rbuf[2];
	value <<= 8;
	value |= rbuf[3];
	value <<= 8;
	value |= rbuf[4];

	return value;
}