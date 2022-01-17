/*
 * SPI_TMC.h
 *
 *  Created on: 12.01.2018
 *      Author: MN
 */
#ifndef SPI_TMC_H
#define SPI_TMC_H

#include "TMC-API/tmc/helpers/API_Header.h"

void initSPI(void);

// TMC5160 SPI wrapper
void tmc5160_writeDatagram(uint8 motor, uint8 address, uint8 x1, uint8 x2, uint8 x3, uint8 x4);
void tmc5160_writeInt(uint8 motor, uint8 address, int value);
int tmc5160_readInt(u8 motor, uint8 address);

// General SPI functions
void tmc40bit_writeInt(u8 motor, uint8 address, int value);
int tmc40bit_readInt(u8 motor, uint8 address);

#endif /* SPI_TMC_H */