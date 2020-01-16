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
    PSF stack event handler
 */
UINT8 PDStack_Events(UINT8 u8PortNum, UINT8 u8PDEvent)
{
    UINT8 u8RetVal = FALSE;
    
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
    Timer callback
 */
void Timer_Callback(void)
{
    MchpPSF_PDTimerHandler();
}

/*
    Main application
*/
int main(void)
{
    /* Initializes MCU, drivers and middle ware */
    SYSTEM_Initialize();
    
    /* Register timer callback */
    TCB3_SetCaptIsrCallback(Timer_Callback);
    
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
