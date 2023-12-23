/*
 * led.h
 *
 *  Created on: Dec 21, 2023
 *      Author: Andr¨¦ A. M. Ara¨²jo
 */

#ifndef USER_LED_H_
#define USER_LED_H_

#include <ch32v00x.h>

#define LED_PORTA_OUTPUTS  (GPIO_Pin_1 | GPIO_Pin_2)
#define LED_PORTC_OUTPUTS  (GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7)
#define LED_PORTD_OUTPUTS  (GPIO_Pin_0              | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6)

#define LED_DELTA_T        100
#define LED_PWM_PERIOD     100
#define LED_PWM_DUTY_CYCLE  10
#define LED_PWM_CYCLE_T_1   25
#define LED_PWM_CYCLE_T_2  175

enum LED_modes
{
    interleaved = 0,
    sequential  = 1,
    blinky      = 2,
    pulsating   = 3,
    standby     = 4
};

void LED_AllOn(void);
void LED_AllOff(void);
void LED_AllBlink3x(void);

void LED_RedOn(void);
void LED_RedOff(void);
void LED_RedBlink(void);
void LED_RedSweep(void);

void LED_OrangeOn(void);
void LED_OrangeOff(void);
void LED_OrangeBlink(void);
void LED_OrangeSweep(void);

void LED_BlueOn(void);
void LED_BlueOff(void);
void LED_BlueBlink(void);
void LED_BlueSweep(void);

void LED_YellowOn(void);
void LED_YellowOff(void);
void LED_YellowBlink(void);
void LED_YellowSweep(void);

#endif /* USER_LED_H_ */
