/*
 * interrupt_regmap.h
 *
 *  Created on: Mar 4, 2020
 *      Author: Amany
 */
#ifndef INTERRUPT_REGMAP_H_
#define INTERRUPT_REGMAP_H_


/***********************************************************************************/
#define Cortex_M4F_Peripherals_Base 0xE000E000   /*(SysTick, NVIC,MPU, FPU and SCB)*/
#define NVIC_EN_OFFSET               0x100
#define NVIC_DISABLE_OFFSET          0x180
#define NVIC_PEND_OFFSET             0x200
#define NVIC_UNPEND_OFFSET           0x280
#define NVIC_ACTIVE_OFFSET           0x300
#define NVIC_PRI_OFFSET              0x400
#define SW_TRIG_OFFSET               0xF00
#define SW_TRIG_INT   (*(volatile uint32*)(SW_TRIG_OFFSET+Cortex_M4F_Peripherals_Base))
#define NVIC_PRI_GET  (*(volatile uint32*)(NVIC_PRI_OFFSET+Cortex_M4F_Peripherals_Base))
#endif /* INTERRUPT_REGMAP_H_ */
