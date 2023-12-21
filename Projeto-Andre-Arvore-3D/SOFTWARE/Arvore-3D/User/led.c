/*
 * led.c
 *
 *  Created on: Dec 21, 2023
 *      Author: Andre
 */

#include "led.h"

void LED_AllOn(void)
{
    GPIO_SetBits(GPIOA, PORTA_OUTS);
    GPIO_SetBits(GPIOC, PORTC_OUTS);
    GPIO_SetBits(GPIOD, PORTD_OUTS);
}
void LED_AllOff(void)
{
    GPIO_ResetBits(GPIOA, PORTA_OUTS);
    GPIO_ResetBits(GPIOC, PORTC_OUTS);
    GPIO_ResetBits(GPIOD, PORTD_OUTS);
}

void LED_RedOn(void)
{
    GPIO_SetBits(GPIOA, GPIO_Pin_1);
    GPIO_SetBits(GPIOC, GPIO_Pin_0 | GPIO_Pin_6);
    GPIO_SetBits(GPIOD, GPIO_Pin_5);
}

void LED_RedOff(void)
{
    GPIO_ResetBits(GPIOA, GPIO_Pin_1);
    GPIO_ResetBits(GPIOC, GPIO_Pin_0 | GPIO_Pin_6);
    GPIO_ResetBits(GPIOD, GPIO_Pin_5);
}

void LED_OrangeOn(void)
{
    GPIO_SetBits(GPIOA, GPIO_Pin_2);
    GPIO_SetBits(GPIOC, GPIO_Pin_1 | GPIO_Pin_7);
    GPIO_SetBits(GPIOD, GPIO_Pin_6);
}
void LED_OrangeOff(void)
{
    GPIO_ResetBits(GPIOA, GPIO_Pin_2);
    GPIO_ResetBits(GPIOC, GPIO_Pin_1 | GPIO_Pin_7);
    GPIO_ResetBits(GPIOD, GPIO_Pin_6);
}

void LED_BlueOn(void)
{
    GPIO_SetBits(GPIOC, GPIO_Pin_2 | GPIO_Pin_4);
    GPIO_SetBits(GPIOD, GPIO_Pin_0 | GPIO_Pin_3);
}

void LED_BlueOff(void)
{
    GPIO_ResetBits(GPIOC, GPIO_Pin_2 | GPIO_Pin_4);
    GPIO_ResetBits(GPIOD, GPIO_Pin_0 | GPIO_Pin_3);
}


void LED_YellowOn(void)
{
    GPIO_SetBits(GPIOC, GPIO_Pin_3 | GPIO_Pin_5);
    GPIO_SetBits(GPIOD, GPIO_Pin_2 | GPIO_Pin_4);
}

void LED_YellowOff(void)
{
    GPIO_ResetBits(GPIOC, GPIO_Pin_3 | GPIO_Pin_5);
    GPIO_ResetBits(GPIOD, GPIO_Pin_2 | GPIO_Pin_4);
}
