/*
 * app.c
 *
 *  Created on: Dec 21, 2023
 *      Author: Andr¨¦ A. M. Ara¨²jo
 */

#include "app.h"
#include "led.h"

volatile uint8_t button_flag = 0;   // Flag for External Interrupt (configured, but unused in this example)

void APP_Init(void)
{

    volatile uint32_t dt = 1000;

    uint8_t i = 0;

    APP_GPIO_Init();    // GPIO initialization

    while (1)
    {
        if (button_flag)
        {
            button_flag = 0;

            dt = 2000;
        }

        for (i = 0; i < 2; i++)
        {
            LED_RedOn();
            Delay_Ms(dt);

            LED_OrangeOn();
            Delay_Ms(dt);

            LED_BlueOn();
            Delay_Ms(dt);

            LED_YellowOn();
            Delay_Ms(dt);

            LED_RedOff();
            Delay_Ms(dt);

            LED_OrangeOff();
            Delay_Ms(dt);

            LED_BlueOff();
            Delay_Ms(dt);

            LED_YellowOff();
            Delay_Ms(dt);
        }

        for (i = 0; i < 4; i++)
        {
            LED_BlueOff();
            LED_RedOn();
            Delay_Ms(dt);

            LED_YellowOff();
            LED_OrangeOn();
            Delay_Ms(dt);

            LED_RedOff();
            LED_BlueOn();
            Delay_Ms(dt);

            LED_OrangeOff();
            LED_YellowOn();
            Delay_Ms(dt);
        }

        LED_AllOff();
    }



//    APP_GPIO_DeInit();  // Disable outputs and sets GPIO for low power mode,
//                        // except for PD0 (interrupt for waking up the MCU)
//
//    APP_Standby();      // Enter Standby Mode
//
//    APP_GPIO_Init();            // After wake up, initialize GPIO again
//    SystemCoreClockUpdate();    // Also reinitialize Clock
//    Delay_Init();               // and delay
}

void APP_GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure = {0};
    EXTI_InitTypeDef EXTI_InitStructure = {0};
    NVIC_InitTypeDef NVIC_InitStructure = {0};

// Port A

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    // Set Pins 1 to 5 as output, push-pull
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

// Port C
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

    // Set Pins 1 to 5 as output, push-pull
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Pin = 0xFF;
    GPIO_Init(GPIOC, &GPIO_InitStructure);

// Port D

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

    // Set Pins 0 and 2 to 6 as output, push-pull
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6;
    GPIO_Init(GPIOD, &GPIO_InitStructure);

    // Set Pin 1 as input
    GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_1;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_Init(GPIOD, &GPIO_InitStructure);

    // Set external interrupt
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOD, GPIO_PinSource1);
    EXTI_InitStructure.EXTI_Line = EXTI_Line1;
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    EXTI_Init(&EXTI_InitStructure);

    // Set interrupt controller
    NVIC_InitStructure.NVIC_IRQChannel = EXTI7_0_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

//    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO | RCC_APB2Periph_GPIOD, ENABLE);
//
//    // Set Pin 0 as input, pull-up
//    GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0;
//    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
//    GPIO_Init(GPIOD, &GPIO_InitStructure);
//
//    // Set external interrupt
//    GPIO_EXTILineConfig(GPIO_PortSourceGPIOD, GPIO_PinSource0);
//    EXTI_InitStructure.EXTI_Line = EXTI_Line0;
//    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
//    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
//    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
//    EXTI_Init(&EXTI_InitStructure);
//
//    // Set interrupt controller
//    NVIC_InitStructure.NVIC_IRQChannel = EXTI7_0_IRQn;
//    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
//    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
//    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//    NVIC_Init(&NVIC_InitStructure);
}

void APP_GPIO_DeInit(void)
{
    GPIO_InitTypeDef GPIO_InitStructure = {0};

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOD, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;

    GPIO_Init(GPIOA, &GPIO_InitStructure);
    GPIO_Init(GPIOC, &GPIO_InitStructure);
    // Keep PD0 as input for External Interrupt
}

void APP_Standby(void)
{
    RCC_LSICmd(ENABLE);
    while(RCC_GetFlagStatus(RCC_FLAG_LSIRDY) == RESET);
    //PWR_AWU_SetPrescaler(PWR_AWU_Prescaler_10240);    // Auto Wake Up disabled
    //PWR_AWU_SetWindowValue(25);
    //PWR_AutoWakeUpCmd(ENABLE);
    PWR_EnterSTANDBYMode(PWR_STANDBYEntry_WFI);
}

void EXTI7_0_IRQHandler(void)    // External Interrupt (configured, but unused in this example)
{
    if(EXTI_GetITStatus(EXTI_Line1)!=RESET)
    {
        button_flag = 1;                        // Sets flag to be handled in main loop
        Delay_Ms(50);                           // Delay for simple debounce
        EXTI_ClearITPendingBit(EXTI_Line1);     // Clear Flag
    }
}
