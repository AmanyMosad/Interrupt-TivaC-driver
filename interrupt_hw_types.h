/*
 * interrupt_hw_types.h
 *
 *  Created on: Mar 5, 2020
 *      Author: Amany
 */

#ifndef INTERRUPT_HW_TYPES_H_
#define INTERRUPT_HW_TYPES_H_
#include <stdint.h>
#include "std_types.h"
#include "interrupt_regmap.h"

#define NVIC_EN(INT_NUM)     (*(volatile uint32*)(((INT_NUM/32) * 4) + NVIC_EN_OFFSET+ Cortex_M4F_Peripherals_Base))|= (1 << ((INT_NUM) % 32))
#define NVIC_DIS(INT_NUM)    (*(volatile uint32*)(((INT_NUM/32) * 4) + NVIC_DISABLE_OFFSET+ Cortex_M4F_Peripherals_Base))|= (1 << ((INT_NUM) % 32))
#define NVIC_PEND(INT_NUM)   (*(volatile uint32*)(((INT_NUM/32) * 4) + NVIC_PEND_OFFSET+ Cortex_M4F_Peripherals_Base))|= (1 << ((INT_NUM) % 32))
#define NVIC_UNPEND(INT_NUM) (*(volatile uint32*)(((INT_NUM/32) * 4) + NVIC_UNPEND_OFFSET+ Cortex_M4F_Peripherals_Base))|= (1 << ((INT_NUM) % 32))
#define NVIC_ACTIVE_STATE(INT_NUM) (*(volatile uint32*)(((INT_NUM/32) * 4) + NVIC_ACTIVE_OFFSET+ Cortex_M4F_Peripherals_Base))& (1 << ((INT_NUM) % 32))
#define NVIC_PEND_STATE(INT_NUM)   (*(volatile uint32*)(((INT_NUM/32) * 4) + NVIC_PEND_OFFSET+ Cortex_M4F_Peripherals_Base))& (1 << ((INT_NUM) % 32))


#define NVIC_PRI(INT_NUM,PRI_NUM)  (*(volatile uint32*)(((INT_NUM/4) * 4) + NVIC_PRI_OFFSET + Cortex_M4F_Peripherals_Base))&= (0xFFFFFFF0 << ((INT_NUM) % 4));\
                                      (*(volatile uint32*)(((INT_NUM/4) * 4) + NVIC_PRI_OFFSET + Cortex_M4F_Peripherals_Base)) |= ((PRI_NUM & 0x0f) << ((INT_NUM) % 4))

#endif /* INTERRUPT_HW_TYPES_H_ */
