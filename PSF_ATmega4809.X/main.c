/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "main.h"
#include "mcc_generated_files/mcc.h"

/*
    Volatile global to prevent optimization of return values
 */
volatile UINT8 u8RetVal = FALSE;

/*
    PSF stack event handler
 */
UINT8 PDStack_Events(UINT8 u8PortNum, UINT8 u8PDEvent)
{
    u8RetVal = FALSE;
    
    switch(u8PDEvent)
    {
        case eMCHP_PSF_TYPEC_DETACH_EVENT:
        {
            UPD_GPIOEnableDisable(u8PortNum,(UINT8)eUPD_PIO2, UPD_DISABLE_GPIO);
            break;
        }
        case eMCHP_PSF_TYPEC_CC1_ATTACH:
        {
            UPD_GPIOEnableDisable(u8PortNum,(UINT8)eUPD_PIO2,UPD_ENABLE_GPIO);
            UPD_GPIOSetDirection(u8PortNum,(UINT8)eUPD_PIO2,UPD_GPIO_SETDIR_OUTPUT);
            UPD_GPIOSetBufferType(u8PortNum,(UINT8)eUPD_PIO2,UPD_GPIO_SETBUF_PUSHPULL);
            UPD_GPIOSetClearOutput(u8PortNum,(UINT8)eUPD_PIO2,UPD_GPIO_CLEAR);
            break;
        }
        case eMCHP_PSF_TYPEC_CC2_ATTACH:
        {
            UPD_GPIOEnableDisable(u8PortNum,(UINT8)eUPD_PIO2,UPD_ENABLE_GPIO);
            UPD_GPIOSetDirection(u8PortNum,(UINT8)eUPD_PIO2,UPD_GPIO_SETDIR_OUTPUT);
            UPD_GPIOSetBufferType(u8PortNum,(UINT8)eUPD_PIO2,UPD_GPIO_SETBUF_PUSHPULL);
            UPD_GPIOSetClearOutput(u8PortNum,(UINT8)eUPD_PIO2,UPD_GPIO_SET);
            break;
        }
		
		case eMCHP_PSF_UPDS_IN_IDLE:
		{
			//Put MCU in LPM
			break;
		}
        
        case eMCHP_PSF_VCONN_PWR_FAULT:
        {
			/*Returning TRUE to enable PSF to handle the power fault*/
            u8RetVal = TRUE;
            break;
        }
        
        case eMCHP_PSF_VBUS_PWR_FAULT:
        {
			/*Returning TRUE to enable PSF to handle the power fault*/
            u8RetVal = TRUE;
            break;
        }
        
        default:
            break;
    }

    return u8RetVal;
}

/*
    Initialize SPI
 */
UINT8 SPI_Init(void)
{
    
    /* Initialize SPI and return TRUE*/
    SPI0_Initialize();
    
    u8RetVal = TRUE;
    return u8RetVal;
}

/*
    Select SPI Slave 
 */
void SPI_Select_Slave(UINT8 u8PortNum, UINT8 u8EnableComm)
{
    if (u8EnableComm == TRUE)
    {
        /* Drive SS low to enable port */
        if (u8PortNum == PORT0)
        {
            /* PA7_SS0 */
            PA7_SS0_SetLow();
        }
        else if(u8PortNum == PORT1)
        {
            /* PE1_SS1 */
            PE1_SS1_SetLow();
        }
    }
    else if (u8EnableComm == FALSE)
    {
        /* Drive SS high to disable port */
        if (u8PortNum == PORT0)
        {
            PA7_SS0_SetHigh();
        }
        else if(u8PortNum == PORT1)
        {
            PE1_SS1_SetHigh();
        }
    }
}

/*
    SPI Write
 */
UINT8 SPI_Write(UINT8 u8PortNum, UINT8 *pu8WriteBuffer, UINT8 u8Writelength)
{
    /* Write buffer to SPI bus, SS is handled by PSF through SPI_Select_Slave() */
    SPI0_WriteBlock(pu8WriteBuffer, u8Writelength);
    
    /* Return TRUE */
    u8RetVal = TRUE;
    return u8RetVal;
}

/*
    SPI Read
 */
UINT8 SPI_Read(UINT8 u8PortNum, UINT8 *pu8WriteBuffer, UINT8 u8Writelength, UINT8 *pu8ReadBuffer, UINT8 u8Readlength)
{
    /* Write buffer to SPI bus, SS is handled by PSF through SPI_Select_Slave() */
    SPI0_WriteBlock(pu8WriteBuffer, u8Writelength);
    /* Read buffer from SPI bus, SS is handled by PSF through SPI_Select_Slave() */
    SPI0_ReadBlock(pu8ReadBuffer, u8Readlength);
    
    /* Return TRUE */
    u8RetVal = TRUE;
    return u8RetVal;
}

/*
    Initialize timer callback
 */
UINT8 Timer_Init(void)
{   
    /* Initialize timer*/
    TCB3_Initialize();
    /* Register timer callback and return TRUE*/
    TCB3_SetCaptIsrCallback(Timer_Callback);
    
    u8RetVal = TRUE;
    return u8RetVal;
}

/*
    Timer callback
 */
void Timer_Callback(void)
{
    MchpPSF_PDTimerHandler();
}

/*
    Initialize UPD IRQs
 */
void IRQ_Init(UINT8 u8PortNum)
{
    if(u8PortNum == PORT0)
    {
        /* Register IRQ0 callback */
        PORTC_PC6_IRQ0_SetInterruptHandler(IRQ0_Callback);
    }
    else if(u8PortNum == PORT1)
    {
        /* Register IRQ1 callback */
        PORTB_PB2_IRQ1_SetInterruptHandler(IRQ1_Callback);
    }
}

/*
    IRQ0 callback (PORT0)
 */
void IRQ0_Callback(void)
{
    MchpPSF_UPDIrqHandler(PORT0);
}

/*
    IRQ1 callback (PORT1)
 */
void IRQ1_Callback(void)
{
    MchpPSF_UPDIrqHandler(PORT1);
}

/*
    Reset all UPD devices
 */
void Reset_UPD350(UINT8 u8PortNum)
{
    if(u8PortNum == PORT0)
    {
        PA2_RESET_SetLow();
        /* Minimum reset time is 1 microsecond */
        DELAY_microseconds(10);
        PA2_RESET_SetHigh();
    }
}

/*
    Main application
*/
int main(void)
{
    /* Initializes MCU, drivers and middle ware */
    SYSTEM_Initialize();

    /* Initialize PSF Stack */
    while(!MchpPSF_Init());
    
    /* Replace with your application code */
    while (1){
        /*Run PSF stack */
		MchpPSF_RUN();
    }
}

/**
    End of File
*/
