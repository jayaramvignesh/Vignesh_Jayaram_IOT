/*
 * 	File:clock.c
 *
 *  Created on: Feb 8, 2017
 *  Author: Vignesh Jayaram
 *
 *  Permission is granted to anyone to use this software for any purpose,
 *  including commercial applications, and to alter it and redistribute it
 *  freely, subject to the following restrictions:
 *
 *  1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software.
 *  2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 *  3. This notice may not be removed or altered from any source distribution.
 *
 *  DISCLAIMER OF WARRANTY/LIMITATION OF REMEDIES: Silicon Labs has no
 *  obligation to support this Software. Silicon Labs is providing the
 *  Software "AS IS", with no express or implied warranties of any kind,
 *  including, but not limited to, any implied warranties of merchantability
 *  or fitness for any particular purpose or warranties against infringement
 *  of any proprietary rights of a third party.
 *
 *  Silicon Labs will not be liable for any consequential, incidental, or
 *  special damages, or any other relief, or for any claim by any third party,
 *  arising from your use of this Software.
 *
 *  CLOCK_SETUP()
 *  This routine is used to enable clocks to the peripheral.
 *
 *
 */

#include "clock.h"


/* ****************************************************
 * Function to set up the clock tree
 *
 * Input variable:  CMU_Osc_TypeDef osc
 * Local variable: none
 * Global variable: none
 * Return type: none
 * macro: ENERGY_MIN
 *******************************************************/
void CLOCK_SETUP(CMU_Osc_TypeDef osc)
{

	CMU_OscillatorEnable(osc, true, true);  	    		//Enabling low frequeuncy
	CMU_ClockSelectSet(cmuClock_LFA, osc);					//Selecting low frequency clock for LFA tree
	CMU_ClockEnable(cmuClock_CORELE, true);					//Enabling Low frequency Clock tree
	CMU_ClockEnable(cmuClock_LETIMER0, true);				//Enabling LFA clock tree to LETIMER0
	CMU_ClockEnable(cmuClock_GPIO, true);					//Enabling Clock to GPIO
	CMU_ClockEnable(cmuClock_ACMP0, true);					//Enabling Clock to ACMP
	CMU_ClockEnable(cmuClock_ADC0, true);					//Enabling Clock to ADC0
	CMU_ClockEnable(cmuClock_DMA, true);					//Enabling Clock to DMA
}


