/*
 * app.h
 *
 *  Created on: Dec 21, 2023
 *      Author: Andr¨¦ A. M. Ara¨²jo
 */

#ifndef USER_APP_H_
#define USER_APP_H_

#include <ch32v00x.h>

#define APP_TIMEOUT        500
#define APP_MODE_REPEATS    50

extern volatile uint8_t flag_button;

void APP_Run(void);
void APP_GPIO_Init(void);
void APP_GPIO_DeInit(void);

void APP_Standby(void);
void APP_WakeUp(void);

void EXTI7_0_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));

#endif /* USER_APP_H_ */
