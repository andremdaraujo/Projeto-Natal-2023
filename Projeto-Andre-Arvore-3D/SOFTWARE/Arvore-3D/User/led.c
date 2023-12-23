/*
 * led.c
 *
 *  Created on: Dec 21, 2023
 *      Author: Andr¨¦ A. M. Ara¨²jo
 */

#include "led.h"



void LED_AllOn(void)
{
    GPIO_SetBits(GPIOA, LED_PORTA_OUTPUTS);
    GPIO_SetBits(GPIOC, LED_PORTC_OUTPUTS);
    GPIO_SetBits(GPIOD, LED_PORTD_OUTPUTS);
}
void LED_AllOff(void)
{
    GPIO_ResetBits(GPIOA, LED_PORTA_OUTPUTS);
    GPIO_ResetBits(GPIOC, LED_PORTC_OUTPUTS);
    GPIO_ResetBits(GPIOD, LED_PORTD_OUTPUTS);
}

void LED_AllBlink3x(void)
{
    LED_AllOn();
    Delay_Ms(100);
    LED_AllOff();
    Delay_Ms(100);

    LED_AllOn();
    Delay_Ms(100);
    LED_AllOff();
    Delay_Ms(100);

    LED_AllOn();
    Delay_Ms(100);
    LED_AllOff();
    Delay_Ms(100);
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

void LED_RedBlink(void)
{
    uint8_t blink_counter   = 0;
    uint8_t dt              = LED_DELTA_T;
    uint8_t pwm_counter     = 0;
    uint8_t pwm_period      = LED_PWM_PERIOD;
    uint8_t pwm_duty_cycle  = LED_PWM_DUTY_CYCLE;

    for (blink_counter = 0; blink_counter < dt; blink_counter++)
    {
        for (pwm_counter = 0; pwm_counter < pwm_period; pwm_counter++)
        {
            if (pwm_counter < pwm_duty_cycle)
            {
                LED_RedOn();
            }
            else
            {
                LED_RedOff();
            }
            Delay_Us(LED_PWM_CYCLE_T_1);
        }
    }
    for (blink_counter = 0; blink_counter < dt; blink_counter++)
    {
        for (pwm_counter = 0; pwm_counter < pwm_period; pwm_counter++)
        {
            if (pwm_counter < pwm_duty_cycle)
            {
                LED_RedOff();
            }
            else
            {
                LED_RedOff();
            }
            Delay_Us(LED_PWM_CYCLE_T_1);
        }
    }
}

void LED_RedSweep(void)
{
    uint8_t blink_counter   = 0;
    uint8_t dt              = LED_DELTA_T;
    uint8_t pwm_counter     = 0;
    uint8_t pwm_period      = LED_PWM_PERIOD;
    uint8_t pwm_duty_cycle  = 0;

    for (blink_counter = 0; blink_counter < dt; blink_counter++)
    {
        for (pwm_counter = 0; pwm_counter < pwm_period; pwm_counter++)
        {
            if (pwm_counter < pwm_duty_cycle)
            {
                LED_RedOn();
            }
            else
            {
                LED_RedOff();
            }
            Delay_Us(LED_PWM_CYCLE_T_2);
        }
        pwm_duty_cycle++;

    }
    for (blink_counter = 0; blink_counter < dt; blink_counter++)
    {
        for (pwm_counter = 0; pwm_counter < pwm_period; pwm_counter++)
        {
            if (pwm_counter < pwm_duty_cycle)
            {
                LED_RedOn();
            }
            else
            {
                LED_RedOff();
            }
            Delay_Us(LED_PWM_CYCLE_T_2);
        }
        pwm_duty_cycle--;
    }
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

void LED_OrangeBlink(void)
{
    uint8_t blink_counter   = 0;
    uint8_t dt              = LED_DELTA_T;
    uint8_t pwm_counter     = 0;
    uint8_t pwm_period      = LED_PWM_PERIOD;
    uint8_t pwm_duty_cycle  = LED_PWM_DUTY_CYCLE;

    for (blink_counter = 0; blink_counter < dt; blink_counter++)
    {
        for (pwm_counter = 0; pwm_counter < pwm_period; pwm_counter++)
        {
            if (pwm_counter < pwm_duty_cycle)
            {
                LED_OrangeOn();
            }
            else
            {
                LED_OrangeOff();
            }
            Delay_Us(LED_PWM_CYCLE_T_1);
        }
    }
    for (blink_counter = 0; blink_counter < dt; blink_counter++)
    {
        for (pwm_counter = 0; pwm_counter < pwm_period; pwm_counter++)
        {
            if (pwm_counter < pwm_duty_cycle)
            {
                LED_OrangeOff();
            }
            else
            {
                LED_OrangeOff();
            }
            Delay_Us(LED_PWM_CYCLE_T_1);
        }
    }
}

void LED_OrangeSweep(void)
{
    uint8_t blink_counter   = 0;
    uint8_t dt              = LED_DELTA_T;
    uint8_t pwm_counter     = 0;
    uint8_t pwm_period      = LED_PWM_PERIOD;
    uint8_t pwm_duty_cycle  = 0;

    for (blink_counter = 0; blink_counter < dt; blink_counter++)
    {
        for (pwm_counter = 0; pwm_counter < pwm_period; pwm_counter++)
        {
            if (pwm_counter < pwm_duty_cycle)
            {
                LED_OrangeOn();
            }
            else
            {
                LED_OrangeOff();
            }
            Delay_Us(LED_PWM_CYCLE_T_2);
        }
        pwm_duty_cycle++;

    }
    for (blink_counter = 0; blink_counter < dt; blink_counter++)
    {
        for (pwm_counter = 0; pwm_counter < pwm_period; pwm_counter++)
        {
            if (pwm_counter < pwm_duty_cycle)
            {
                LED_OrangeOn();
            }
            else
            {
                LED_OrangeOff();
            }
            Delay_Us(LED_PWM_CYCLE_T_2);
        }
        pwm_duty_cycle--;
    }
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

void LED_BlueBlink(void)
{
    uint8_t blink_counter   = 0;
    uint8_t dt              = LED_DELTA_T;
    uint8_t pwm_counter     = 0;
    uint8_t pwm_period      = LED_PWM_PERIOD;
    uint8_t pwm_duty_cycle  = LED_PWM_DUTY_CYCLE;

    for (blink_counter = 0; blink_counter < dt; blink_counter++)
    {
        for (pwm_counter = 0; pwm_counter < pwm_period; pwm_counter++)
        {
            if (pwm_counter < pwm_duty_cycle)
            {
                LED_BlueOn();
            }
            else
            {
                LED_BlueOff();
            }
            Delay_Us(LED_PWM_CYCLE_T_1);
        }
    }
    for (blink_counter = 0; blink_counter < dt; blink_counter++)
    {
        for (pwm_counter = 0; pwm_counter < pwm_period; pwm_counter++)
        {
            if (pwm_counter < pwm_duty_cycle)
            {
                LED_BlueOff();
            }
            else
            {
                LED_BlueOff();
            }
            Delay_Us(LED_PWM_CYCLE_T_1);
        }
    }
}

void LED_BlueSweep(void)
{
    uint8_t blink_counter   = 0;
    uint8_t dt              = LED_DELTA_T;
    uint8_t pwm_counter     = 0;
    uint8_t pwm_period      = LED_PWM_PERIOD;
    uint8_t pwm_duty_cycle  = 0;

    for (blink_counter = 0; blink_counter < dt; blink_counter++)
    {
        for (pwm_counter = 0; pwm_counter < pwm_period; pwm_counter++)
        {
            if (pwm_counter < pwm_duty_cycle)
            {
                LED_BlueOn();
            }
            else
            {
                LED_BlueOff();
            }
            Delay_Us(LED_PWM_CYCLE_T_2);
        }
        pwm_duty_cycle++;

    }
    for (blink_counter = 0; blink_counter < dt; blink_counter++)
    {
        for (pwm_counter = 0; pwm_counter < pwm_period; pwm_counter++)
        {
            if (pwm_counter < pwm_duty_cycle)
            {
                LED_BlueOn();
            }
            else
            {
                LED_BlueOff();
            }
            Delay_Us(LED_PWM_CYCLE_T_2);
        }
        pwm_duty_cycle--;
    }
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

void LED_YellowBlink(void)
{
    uint8_t blink_counter   = 0;
    uint8_t dt              = LED_DELTA_T;
    uint8_t pwm_counter     = 0;
    uint8_t pwm_period      = LED_PWM_PERIOD;
    uint8_t pwm_duty_cycle  = LED_PWM_DUTY_CYCLE;

    for (blink_counter = 0; blink_counter < dt; blink_counter++)
    {
        for (pwm_counter = 0; pwm_counter < pwm_period; pwm_counter++)
        {
            if (pwm_counter < pwm_duty_cycle)
            {
                LED_YellowOn();
            }
            else
            {
                LED_YellowOff();
            }
            Delay_Us(LED_PWM_CYCLE_T_1);
        }
    }
    for (blink_counter = 0; blink_counter < dt; blink_counter++)
    {
        for (pwm_counter = 0; pwm_counter < pwm_period; pwm_counter++)
        {
            if (pwm_counter < pwm_duty_cycle)
            {
                LED_YellowOff();
            }
            else
            {
                LED_YellowOff();
            }
            Delay_Us(LED_PWM_CYCLE_T_1);
        }
    }
}

void LED_YellowSweep(void)
{
    uint8_t blink_counter   = 0;
    uint8_t dt              = LED_DELTA_T;
    uint8_t pwm_counter     = 0;
    uint8_t pwm_period      = LED_PWM_PERIOD;
    uint8_t pwm_duty_cycle  = 0;

    for (blink_counter = 0; blink_counter < dt; blink_counter++)
    {
        for (pwm_counter = 0; pwm_counter < pwm_period; pwm_counter++)
        {
            if (pwm_counter < pwm_duty_cycle)
            {
                LED_YellowOn();
            }
            else
            {
                LED_YellowOff();
            }
            Delay_Us(LED_PWM_CYCLE_T_2);
        }
        pwm_duty_cycle++;

    }
    for (blink_counter = 0; blink_counter < dt; blink_counter++)
    {
        for (pwm_counter = 0; pwm_counter < pwm_period; pwm_counter++)
        {
            if (pwm_counter < pwm_duty_cycle)
            {
                LED_YellowOn();
            }
            else
            {
                LED_YellowOff();
            }
            Delay_Us(LED_PWM_CYCLE_T_2);
        }
        pwm_duty_cycle--;
    }
}
