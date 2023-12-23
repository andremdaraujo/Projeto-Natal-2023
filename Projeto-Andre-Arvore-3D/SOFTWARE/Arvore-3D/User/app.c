/*
 * app.c
 *
 *  Created on: Dec 21, 2023
 *      Author: Andr¨¦ A. M. Ara¨²jo
 */

#include "app.h"
#include "led.h"

volatile uint8_t flag_button  = 0;  // Flag for External Interrupt (Global)
volatile uint8_t flag_standby = 0;

void APP_Run(void)
{
    enum LED_modes mode = interleaved;

    uint8_t     mode_counter =   0;
    uint8_t         sub_mode =   0;
    uint16_t timeout_counter =   0;
    uint32_t              dt = 100;

    APP_GPIO_Init();        // GPIO initialization

    LED_AllBlink3x();
    Delay_Ms(400);

    while (1)
    {
        if (flag_button)    // If button was pressed
        {
            flag_button = 0;    // Clear flag for next interrupt

            mode++;             // Next mode
        }

        timeout_counter++;
        if (timeout_counter >= APP_TIMEOUT)     // If timeout passed, enter standby
        {
            mode = standby;
        }

        if (mode_counter >= APP_MODE_REPEATS)   // If mode repeated enough times, go to next mode
        {
            mode++;
            mode_counter = 0;
        }

        switch (mode)
        {
            case interleaved:       // Interleaved colors (2 at a time)
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

                mode_counter++;

                break;

            case sequential:        // Turn on each color and then turn them off one by one
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

                mode_counter++;

                break;

            case blinky:            // Blinks one color at a time
                switch (sub_mode)
                {
                    case 0:
                        LED_RedBlink();
                        sub_mode++;
                        break;

                    case 1:
                        LED_OrangeBlink();
                        sub_mode++;
                        break;

                    case 2:
                        LED_BlueBlink();
                        sub_mode++;
                        break;

                    case 3:
                        LED_YellowBlink();
                        sub_mode = 0;
                        mode_counter++;
                        break;

                    default:
                        LED_AllOff();
                        sub_mode = 0;
                        break;
                }
                break;

            case pulsating:         // Brightens and dims one color at a time
                switch (sub_mode)
                {
                    case 0:
                        LED_RedSweep();
                        sub_mode++;
                        break;

                    case 1:
                        LED_OrangeSweep();
                        sub_mode++;
                        break;

                    case 2:
                        LED_BlueSweep();
                        sub_mode++;
                        break;

                    case 3:
                        LED_YellowSweep();
                        sub_mode = 0;
                        mode_counter++;
                        break;

                    default:
                        LED_AllOff();
                        sub_mode = 0;
                        break;
                }
                break;

            case standby:           // Enter standby mode
                flag_standby = 1;

                LED_AllOff();

                APP_GPIO_DeInit();  // Disable outputs and sets GPIO for low power mode,
                                    // except for PD1 (interrupt for waking up the MCU)

                APP_Standby();      // Enter Standby Mode

                APP_WakeUp();       // Reinitializes MCU

                // Clear counters and flags to restart
                mode = 0;
                timeout_counter = 0;
                flag_standby = 0;

                break;

            default:
                LED_AllOff();
                mode = standby;
                break;
        }
    }
}

void APP_GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure = {0};
    EXTI_InitTypeDef EXTI_InitStructure = {0};
    NVIC_InitTypeDef NVIC_InitStructure = {0};

// Port A

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

// Port C
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;
    GPIO_Init(GPIOC, &GPIO_InitStructure);

// Port D

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

    // Set Pins 0 and 2 to 6 as output, push-pull
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
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
}

void APP_GPIO_DeInit(void)
{
    GPIO_InitTypeDef GPIO_InitStructure = {0};
    EXTI_InitTypeDef EXTI_InitStructure = {0};
    NVIC_InitTypeDef NVIC_InitStructure = {0};

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOD, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;

    GPIO_Init(GPIOA, &GPIO_InitStructure);
    GPIO_Init(GPIOC, &GPIO_InitStructure);
    GPIO_Init(GPIOD, &GPIO_InitStructure);

    // Keep PD0 as input for External Interrupt

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
}

void APP_Standby(void)
{
    RCC_LSICmd(ENABLE);
    while(RCC_GetFlagStatus(RCC_FLAG_LSIRDY) == RESET);
    PWR_EnterSTANDBYMode(PWR_STANDBYEntry_WFI);
}

void APP_WakeUp(void)
{
    SystemCoreClockUpdate();    // Also reinitialize Clock
    Delay_Init();               // and delay
    APP_GPIO_Init();            // After wake up, initialize GPIO again
}

void EXTI7_0_IRQHandler(void)    // External Interrupt (configured, but unused in this example)
{
    if(EXTI_GetITStatus(EXTI_Line1)!=RESET)
    {
        if (flag_standby == 0)
        {
            flag_button = 1;                // Sets flag to be handled in main loop
        }

        Delay_Ms(50);                       // Delay for simple debounce
        EXTI_ClearITPendingBit(EXTI_Line1); // Clear Flag
    }
}
