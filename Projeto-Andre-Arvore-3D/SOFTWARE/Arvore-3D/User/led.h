/*
 * led.h
 *
 *  Created on: Dec 21, 2023
 *      Author: Andre
 */

#ifndef USER_LED_H_
#define USER_LED_H_

#include <ch32v00x.h>

#define PORTA_OUTS  (GPIO_Pin_1 | GPIO_Pin_2)
#define PORTC_OUTS  (GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7)
#define PORTD_OUTS  (GPIO_Pin_0              | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6)

void LED_AllOn(void);
void LED_AllOff(void);

void LED_RedOn(void);
void LED_RedOff(void);

void LED_OrangeOn(void);
void LED_OrangeOff(void);

void LED_BlueOn(void);
void LED_BlueOff(void);

void LED_YellowOn(void);
void LED_YellowOff(void);

#endif /* USER_LED_H_ */
