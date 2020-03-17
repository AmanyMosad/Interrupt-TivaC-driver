/*
 * interrupt.c
 *
 *  Created on: Mar 4, 2020
 *      Author: Amany
 */
#include "interrupt_hw_types.h"
#include "interrupt.h"
#include "interrupt_regmap.h"

void SW_TRIG(unsigned char INT_ID)
{
    SW_TRIG_INT=INT_ID;
}
void INTERRUPT_Enable(unsigned char INT_ID)
{
    NVIC_EN(INT_ID);
}

void INTERRUPT_Disable(unsigned char INT_ID)
{
    NVIC_DIS(INT_ID);
}
void INTERRUPT_PendingSet(unsigned char INT_ID)
{
    NVIC_PEND(INT_ID);
}

unsigned char INTERRUPT_PendingGet(unsigned char INT_ID, unsigned char data )
{
    data=NVIC_PEND_STATE(INT_ID)>>((INT_ID) % 32);
    return data;
}

void INTERRUPT_PendingClear(unsigned char INT_ID)
{
    NVIC_UNPEND(INT_ID);
}

unsigned char INTERRUPT_ActiveState(unsigned char INT_ID, unsigned char data)
{
    data =NVIC_ACTIVE_STATE(INT_ID)>>((INT_ID) % 32);
    return data;
}

void INTERRUPT_PerioritySet(unsigned char INT_ID,unsigned int PRI_NUM)
{
    NVIC_PRI(INT_ID,PRI_NUM);
}
unsigned char INTERRUPT_PeriorityGet(unsigned char INT_ID)
{
    unsigned char data = ((*(volatile uint32*)(((INT_ID/4) * 4) + NVIC_PRI_OFFSET + Cortex_M4F_Peripherals_Base))>> (INT_ID % 4) & 0x00000007);
    return data;
}

