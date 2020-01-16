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
#ifndef PINS_H_INCLUDED
#define PINS_H_INCLUDED

#include <avr/io.h>
#include "port.h"

//get/set PA2_RESET aliases
#define PA2_RESET_SetHigh() do { PORTA_OUTSET = 0x4; } while(0)
#define PA2_RESET_SetLow() do { PORTA_OUTCLR = 0x4; } while(0)
#define PA2_RESET_Toggle() do { PORTA_OUTTGL = 0x4; } while(0)
#define PA2_RESET_GetValue() (VPORTA.IN & (0x1 << 2))
#define PA2_RESET_SetDigitalInput() do { PORTA_DIRCLR = 0x4; } while(0)
#define PA2_RESET_SetDigitalOutput() do { PORTA_DIRSET = 0x4; } while(0)
#define PA2_RESET_SetPullUp() do { PORTA_PIN2CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PA2_RESET_ResetPullUp() do { PORTA_PIN2CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PA2_RESET_SetInverted() do { PORTA_PIN2CTRL  |= PORT_INVEN_bm; } while(0)
#define PA2_RESET_ResetInverted() do { PORTA_PIN2CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PA2_RESET_DisableInterruptOnChange() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PA2_RESET_EnableInterruptForBothEdges() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PA2_RESET_EnableInterruptForRisingEdge() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PA2_RESET_EnableInterruptForFallingEdge() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PA2_RESET_DisableDigitalInputBuffer() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PA2_RESET_EnableInterruptForLowLevelSensing() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set PB2_IRQ1 aliases
#define PB2_IRQ1_SetHigh() do { PORTB_OUTSET = 0x4; } while(0)
#define PB2_IRQ1_SetLow() do { PORTB_OUTCLR = 0x4; } while(0)
#define PB2_IRQ1_Toggle() do { PORTB_OUTTGL = 0x4; } while(0)
#define PB2_IRQ1_GetValue() (VPORTB.IN & (0x1 << 2))
#define PB2_IRQ1_SetDigitalInput() do { PORTB_DIRCLR = 0x4; } while(0)
#define PB2_IRQ1_SetDigitalOutput() do { PORTB_DIRSET = 0x4; } while(0)
#define PB2_IRQ1_SetPullUp() do { PORTB_PIN2CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PB2_IRQ1_ResetPullUp() do { PORTB_PIN2CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PB2_IRQ1_SetInverted() do { PORTB_PIN2CTRL  |= PORT_INVEN_bm; } while(0)
#define PB2_IRQ1_ResetInverted() do { PORTB_PIN2CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PB2_IRQ1_DisableInterruptOnChange() do { PORTB.PIN2CTRL = (PORTB.PIN2CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PB2_IRQ1_EnableInterruptForBothEdges() do { PORTB.PIN2CTRL = (PORTB.PIN2CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PB2_IRQ1_EnableInterruptForRisingEdge() do { PORTB.PIN2CTRL = (PORTB.PIN2CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PB2_IRQ1_EnableInterruptForFallingEdge() do { PORTB.PIN2CTRL = (PORTB.PIN2CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PB2_IRQ1_DisableDigitalInputBuffer() do { PORTB.PIN2CTRL = (PORTB.PIN2CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PB2_IRQ1_EnableInterruptForLowLevelSensing() do { PORTB.PIN2CTRL = (PORTB.PIN2CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set PC6_IRQ0 aliases
#define PC6_IRQ0_SetHigh() do { PORTC_OUTSET = 0x40; } while(0)
#define PC6_IRQ0_SetLow() do { PORTC_OUTCLR = 0x40; } while(0)
#define PC6_IRQ0_Toggle() do { PORTC_OUTTGL = 0x40; } while(0)
#define PC6_IRQ0_GetValue() (VPORTC.IN & (0x1 << 6))
#define PC6_IRQ0_SetDigitalInput() do { PORTC_DIRCLR = 0x40; } while(0)
#define PC6_IRQ0_SetDigitalOutput() do { PORTC_DIRSET = 0x40; } while(0)
#define PC6_IRQ0_SetPullUp() do { PORTC_PIN6CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PC6_IRQ0_ResetPullUp() do { PORTC_PIN6CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PC6_IRQ0_SetInverted() do { PORTC_PIN6CTRL  |= PORT_INVEN_bm; } while(0)
#define PC6_IRQ0_ResetInverted() do { PORTC_PIN6CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PC6_IRQ0_DisableInterruptOnChange() do { PORTC.PIN6CTRL = (PORTC.PIN6CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PC6_IRQ0_EnableInterruptForBothEdges() do { PORTC.PIN6CTRL = (PORTC.PIN6CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PC6_IRQ0_EnableInterruptForRisingEdge() do { PORTC.PIN6CTRL = (PORTC.PIN6CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PC6_IRQ0_EnableInterruptForFallingEdge() do { PORTC.PIN6CTRL = (PORTC.PIN6CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PC6_IRQ0_DisableDigitalInputBuffer() do { PORTC.PIN6CTRL = (PORTC.PIN6CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PC6_IRQ0_EnableInterruptForLowLevelSensing() do { PORTC.PIN6CTRL = (PORTC.PIN6CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set PB5 aliases
#define PB5_SetHigh() do { PORTB_OUTSET = 0x20; } while(0)
#define PB5_SetLow() do { PORTB_OUTCLR = 0x20; } while(0)
#define PB5_Toggle() do { PORTB_OUTTGL = 0x20; } while(0)
#define PB5_GetValue() (VPORTB.IN & (0x1 << 5))
#define PB5_SetDigitalInput() do { PORTB_DIRCLR = 0x20; } while(0)
#define PB5_SetDigitalOutput() do { PORTB_DIRSET = 0x20; } while(0)
#define PB5_SetPullUp() do { PORTB_PIN5CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PB5_ResetPullUp() do { PORTB_PIN5CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PB5_SetInverted() do { PORTB_PIN5CTRL  |= PORT_INVEN_bm; } while(0)
#define PB5_ResetInverted() do { PORTB_PIN5CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PB5_DisableInterruptOnChange() do { PORTB.PIN5CTRL = (PORTB.PIN5CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PB5_EnableInterruptForBothEdges() do { PORTB.PIN5CTRL = (PORTB.PIN5CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PB5_EnableInterruptForRisingEdge() do { PORTB.PIN5CTRL = (PORTB.PIN5CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PB5_EnableInterruptForFallingEdge() do { PORTB.PIN5CTRL = (PORTB.PIN5CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PB5_DisableDigitalInputBuffer() do { PORTB.PIN5CTRL = (PORTB.PIN5CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PB5_EnableInterruptForLowLevelSensing() do { PORTB.PIN5CTRL = (PORTB.PIN5CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set PA4 aliases
#define PA4_SetHigh() do { PORTA_OUTSET = 0x10; } while(0)
#define PA4_SetLow() do { PORTA_OUTCLR = 0x10; } while(0)
#define PA4_Toggle() do { PORTA_OUTTGL = 0x10; } while(0)
#define PA4_GetValue() (VPORTA.IN & (0x1 << 4))
#define PA4_SetDigitalInput() do { PORTA_DIRCLR = 0x10; } while(0)
#define PA4_SetDigitalOutput() do { PORTA_DIRSET = 0x10; } while(0)
#define PA4_SetPullUp() do { PORTA_PIN4CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PA4_ResetPullUp() do { PORTA_PIN4CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PA4_SetInverted() do { PORTA_PIN4CTRL  |= PORT_INVEN_bm; } while(0)
#define PA4_ResetInverted() do { PORTA_PIN4CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PA4_DisableInterruptOnChange() do { PORTA.PIN4CTRL = (PORTA.PIN4CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PA4_EnableInterruptForBothEdges() do { PORTA.PIN4CTRL = (PORTA.PIN4CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PA4_EnableInterruptForRisingEdge() do { PORTA.PIN4CTRL = (PORTA.PIN4CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PA4_EnableInterruptForFallingEdge() do { PORTA.PIN4CTRL = (PORTA.PIN4CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PA4_DisableDigitalInputBuffer() do { PORTA.PIN4CTRL = (PORTA.PIN4CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PA4_EnableInterruptForLowLevelSensing() do { PORTA.PIN4CTRL = (PORTA.PIN4CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set PA6 aliases
#define PA6_SetHigh() do { PORTA_OUTSET = 0x40; } while(0)
#define PA6_SetLow() do { PORTA_OUTCLR = 0x40; } while(0)
#define PA6_Toggle() do { PORTA_OUTTGL = 0x40; } while(0)
#define PA6_GetValue() (VPORTA.IN & (0x1 << 6))
#define PA6_SetDigitalInput() do { PORTA_DIRCLR = 0x40; } while(0)
#define PA6_SetDigitalOutput() do { PORTA_DIRSET = 0x40; } while(0)
#define PA6_SetPullUp() do { PORTA_PIN6CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PA6_ResetPullUp() do { PORTA_PIN6CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PA6_SetInverted() do { PORTA_PIN6CTRL  |= PORT_INVEN_bm; } while(0)
#define PA6_ResetInverted() do { PORTA_PIN6CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PA6_DisableInterruptOnChange() do { PORTA.PIN6CTRL = (PORTA.PIN6CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PA6_EnableInterruptForBothEdges() do { PORTA.PIN6CTRL = (PORTA.PIN6CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PA6_EnableInterruptForRisingEdge() do { PORTA.PIN6CTRL = (PORTA.PIN6CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PA6_EnableInterruptForFallingEdge() do { PORTA.PIN6CTRL = (PORTA.PIN6CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PA6_DisableDigitalInputBuffer() do { PORTA.PIN6CTRL = (PORTA.PIN6CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PA6_EnableInterruptForLowLevelSensing() do { PORTA.PIN6CTRL = (PORTA.PIN6CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set PA5 aliases
#define PA5_SetHigh() do { PORTA_OUTSET = 0x20; } while(0)
#define PA5_SetLow() do { PORTA_OUTCLR = 0x20; } while(0)
#define PA5_Toggle() do { PORTA_OUTTGL = 0x20; } while(0)
#define PA5_GetValue() (VPORTA.IN & (0x1 << 5))
#define PA5_SetDigitalInput() do { PORTA_DIRCLR = 0x20; } while(0)
#define PA5_SetDigitalOutput() do { PORTA_DIRSET = 0x20; } while(0)
#define PA5_SetPullUp() do { PORTA_PIN5CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PA5_ResetPullUp() do { PORTA_PIN5CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PA5_SetInverted() do { PORTA_PIN5CTRL  |= PORT_INVEN_bm; } while(0)
#define PA5_ResetInverted() do { PORTA_PIN5CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PA5_DisableInterruptOnChange() do { PORTA.PIN5CTRL = (PORTA.PIN5CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PA5_EnableInterruptForBothEdges() do { PORTA.PIN5CTRL = (PORTA.PIN5CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PA5_EnableInterruptForRisingEdge() do { PORTA.PIN5CTRL = (PORTA.PIN5CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PA5_EnableInterruptForFallingEdge() do { PORTA.PIN5CTRL = (PORTA.PIN5CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PA5_DisableDigitalInputBuffer() do { PORTA.PIN5CTRL = (PORTA.PIN5CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PA5_EnableInterruptForLowLevelSensing() do { PORTA.PIN5CTRL = (PORTA.PIN5CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set PA7_SS0 aliases
#define PA7_SS0_SetHigh() do { PORTA_OUTSET = 0x80; } while(0)
#define PA7_SS0_SetLow() do { PORTA_OUTCLR = 0x80; } while(0)
#define PA7_SS0_Toggle() do { PORTA_OUTTGL = 0x80; } while(0)
#define PA7_SS0_GetValue() (VPORTA.IN & (0x1 << 7))
#define PA7_SS0_SetDigitalInput() do { PORTA_DIRCLR = 0x80; } while(0)
#define PA7_SS0_SetDigitalOutput() do { PORTA_DIRSET = 0x80; } while(0)
#define PA7_SS0_SetPullUp() do { PORTA_PIN7CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PA7_SS0_ResetPullUp() do { PORTA_PIN7CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PA7_SS0_SetInverted() do { PORTA_PIN7CTRL  |= PORT_INVEN_bm; } while(0)
#define PA7_SS0_ResetInverted() do { PORTA_PIN7CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PA7_SS0_DisableInterruptOnChange() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PA7_SS0_EnableInterruptForBothEdges() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PA7_SS0_EnableInterruptForRisingEdge() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PA7_SS0_EnableInterruptForFallingEdge() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PA7_SS0_DisableDigitalInputBuffer() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PA7_SS0_EnableInterruptForLowLevelSensing() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set PE1_SS1 aliases
#define PE1_SS1_SetHigh() do { PORTE_OUTSET = 0x2; } while(0)
#define PE1_SS1_SetLow() do { PORTE_OUTCLR = 0x2; } while(0)
#define PE1_SS1_Toggle() do { PORTE_OUTTGL = 0x2; } while(0)
#define PE1_SS1_GetValue() (VPORTE.IN & (0x1 << 1))
#define PE1_SS1_SetDigitalInput() do { PORTE_DIRCLR = 0x2; } while(0)
#define PE1_SS1_SetDigitalOutput() do { PORTE_DIRSET = 0x2; } while(0)
#define PE1_SS1_SetPullUp() do { PORTE_PIN1CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PE1_SS1_ResetPullUp() do { PORTE_PIN1CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PE1_SS1_SetInverted() do { PORTE_PIN1CTRL  |= PORT_INVEN_bm; } while(0)
#define PE1_SS1_ResetInverted() do { PORTE_PIN1CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PE1_SS1_DisableInterruptOnChange() do { PORTE.PIN1CTRL = (PORTE.PIN1CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PE1_SS1_EnableInterruptForBothEdges() do { PORTE.PIN1CTRL = (PORTE.PIN1CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PE1_SS1_EnableInterruptForRisingEdge() do { PORTE.PIN1CTRL = (PORTE.PIN1CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PE1_SS1_EnableInterruptForFallingEdge() do { PORTE.PIN1CTRL = (PORTE.PIN1CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PE1_SS1_DisableDigitalInputBuffer() do { PORTE.PIN1CTRL = (PORTE.PIN1CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PE1_SS1_EnableInterruptForLowLevelSensing() do { PORTE.PIN1CTRL = (PORTE.PIN1CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

void PIN_MANAGER_Initialize();
void PORTA_PA2_RESET_DefaultInterruptHandler(void);
void PORTA_PA2_RESET_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTB_PB2_IRQ1_DefaultInterruptHandler(void);
void PORTB_PB2_IRQ1_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTC_PC6_IRQ0_DefaultInterruptHandler(void);
void PORTC_PC6_IRQ0_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTB_PB5_DefaultInterruptHandler(void);
void PORTB_PB5_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTA_PA4_DefaultInterruptHandler(void);
void PORTA_PA4_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTA_PA6_DefaultInterruptHandler(void);
void PORTA_PA6_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTA_PA5_DefaultInterruptHandler(void);
void PORTA_PA5_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTA_PA7_SS0_DefaultInterruptHandler(void);
void PORTA_PA7_SS0_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTE_PE1_SS1_DefaultInterruptHandler(void);
void PORTE_PE1_SS1_SetInterruptHandler(void (* interruptHandler)(void)) ;
#endif /* PINS_H_INCLUDED */
