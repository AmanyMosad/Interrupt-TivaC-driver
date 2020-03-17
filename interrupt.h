/*
 * interrupt.h
 *
 *  Created on: Mar 4, 2020
 *      Author: Amany
 */

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

void SW_TRIG(unsigned char INT_ID);
void INTERRUPT_Enable(unsigned char INT_ID);
void INTERRUPT_Disable(unsigned char INT_ID);
void INTERRUPT_PendingSet(unsigned char INT_ID);
unsigned char INTERRUPT_PendingGet(unsigned char INT_ID , unsigned char data);
void INTERRUPT_PendingClear(unsigned char INT_ID);
unsigned char INTERRUPT_ActiveState(unsigned char INT_ID, unsigned char data);

void INTERRUPT_PerioritySet(unsigned char INT_ID,unsigned int PRI_NUM);
unsigned char INTERRUPT_PeriorityGet(unsigned char INT_ID);

#endif /* INTERRUPT_H_ */
