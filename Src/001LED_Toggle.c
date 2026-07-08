/*
 * 001LED_Toggle.c
 *
 *  Created on: Jun 8, 2026
 *      Author: SV
 */


#include "stm32f411xx.h"

void delay (void)
{
	for (volatile  uint32_t i=0; i< 500000; i++);
}

int main (void)
{
	GPIO_Handle_t GpioLed;

	GpioLed.pGPIOx = GPIOA;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5;
	GpioLed.GPIO_PinConfig.GPIO_PinMode =GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed= GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType= GPIO_OP_TYPE_PP;
	GpioLed.GPIO_PinConfig.GPIO_PinPUPdControl=GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOA, ENABLE);
	GPIO_Init (&GpioLed);

	while (1)
	{
		GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_5);
		delay();
	}


	return 0;
}



/*

#include "stm32f411xx.h"

void delay(void)
{
    for(volatile uint32_t i = 0; i < 500000; i++);
}

int main(void)
{
    RCC->AHB1ENR |= (1 << 0);          // Enable GPIOA clock

    GPIOA->MODER &= ~(0x3 << 10);      // Clear PA5 mode
    GPIOA->MODER |=  (0x1 << 10);      // PA5 output

    while(1)
    {
        GPIOA->ODR ^= (1 << 5);        // Toggle PA5
        delay();
    }
}
*/
