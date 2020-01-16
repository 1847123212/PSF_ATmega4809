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

//SAMD20_DriveChipSelect(u8PortNum,u8Enable)
//SAMD20_SPIWritedriver(u8PortNum,pu8WriteBuf,u8WriteLen)
//SAMD20_SPIReaddriver(u8PortNum,pu8WriteBuf,u8WriteLen,pu8ReadBuf, u8ReadLen)
//SAMD20_UPD350AlertInit(u8PortNum)

/*
    Initialize SPI
 */
UINT8 SPI_Init(void);

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

