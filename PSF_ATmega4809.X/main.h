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

//SAMD20_SPIInitialisation();              
//SAMD20_DriveChipSelect(u8PortNum,u8Enable)
//SAMD20_SPIWritedriver(u8PortNum,pu8WriteBuf,u8WriteLen)
//SAMD20_SPIReaddriver(u8PortNum,pu8WriteBuf,u8WriteLen,pu8ReadBuf, u8ReadLen)
//SAMD20_HWTimerInit()
//SAMD20_UPD350AlertInit(u8PortNum)
//SAMD20_UPD350ResetGPIOInit(u8PortNum)              
//SAMD20_ResetUPD350(u8PortNum) 
//SAMD20_EnterCriticalSection()            
//SAMD20_ExitCriticalSection()

/*
    Timer callback
 */
void Timer_Callback(void);

/*
    PSF stack event handler
 */
UINT8 PDStack_Events(UINT8 u8PortNum, UINT8 u8PDEvent);

#endif	/* MAIN_H */

