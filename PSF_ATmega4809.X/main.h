/* 
 * File:   main.h
 * Author: I41690
 *
 * Created on January 15, 2020, 10:43 PM
 */

#ifndef MAIN_H
#define	MAIN_H

#include "psf_stdinc.h"
#include "mcc_generated_files/utils/interrupt_avr8.h"

//SAMD20_UPD350AlertInit(u8PortNum)

/*
    Initialize SPI
 */
UINT8 SPI_Init(void);

/*
    Select SPI Slave 
 */
void SPI_Select_Slave(UINT8 u8PortNum, UINT8 u8EnableComm);

/*
    SPI Write
 */
UINT8 SPI_Write(UINT8 u8PortNum, UINT8 *pu8WriteBuffer, UINT8 u8Writelength);

/*
    SPI Read
 */
UINT8 SPI_Read(UINT8 u8PortNum, UINT8 *pu8WriteBuffer, UINT8 u8Writelength, UINT8 *pu8ReadBuffer, UINT8 u8Readlength);

/*
    Reset all UPD devices
 */
void Reset_UPD350(UINT8 u8PortNum);

/*
    Initialize timer callback
 */
UINT8 Timer_Init(void);

/*
    Timer callback
 */
void Timer_Callback(void);

/*
    PSF stack event handler
 */
UINT8 PDStack_Events(UINT8 u8PortNum, UINT8 u8PDEvent);

#endif	/* MAIN_H */

