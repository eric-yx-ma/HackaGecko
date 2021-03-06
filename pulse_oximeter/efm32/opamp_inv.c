/**************************************************************************//**
 * @file
 * @brief OPA2 configured as an inverting amplifier.
 * @author Energy Micro AS
* @version 1.01
 ******************************************************************************
 * @section License
 * <b>(C) Copyright 2009 Energy Micro AS, http://www.energymicro.com</b>
 ******************************************************************************
 *
 * This source code is the property of Energy Micro AS. The source and compiled
 * code may only be used on Energy Micro "EFM32" microcontrollers.
 *
 * This copyright notice may not be removed from the source code nor changed.
 *
 * DISCLAIMER OF WARRANTY/LIMITATION OF REMEDIES: Energy Micro AS has no
 * obligation to support this Software. Energy Micro AS is providing the
 * Software "AS IS", with no express or implied warranties of any kind,
 * including, but not limited to, any implied warranties of merchantability
 * or fitness for any particular purpose or warranties against infringement
 * of any proprietary rights of a third party.
 *
 * Energy Micro AS will not be liable for any consequential, incidental, or
 * special damages, or any other relief, or for any claim by any third party,
 * arising from your use of this Software.
 *
 *****************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include "efm32.h"
#include "efm32_chip.h"
#include "efm32_opamp.h"
#include "efm32_cmu.h"

int main(void)
{ 
    CHIP_Init();

    /*Turn on the DAC clock*/
    CMU_ClockEnable(cmuClock_DAC0, true);
  
    /*Define the configuration for OPA2*/
    OPAMP_Init_TypeDef configuration = OPA_INIT_INVERTING_OPA2;

    /*Enable OPA2*/
    OPAMP_Enable(DAC0, OPA2, &configuration);
  
    /*Never end*/
    while(1);   
}
