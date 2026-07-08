
///*
// * 002Led_button.c
// *
// *  Created on: Jun 8, 2026
// *      Author: SV
// */
//

#define LOW			 0
#define BTN_PRESSED LOW

#include <string.h>
#include "stm32f411xx.h"

void delay (void)
{
	for (volatile  uint32_t i=0; i<30000; i++);
}

int main (void)
{

	GPIO_Handle_t GpioLed, GPIOBtn;
	memset(&GpioLed,0,sizeof(GpioLed));
	memset(&GPIOBtn,0,sizeof(GPIOBtn));

	GpioLed.pGPIOx = GPIOA;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_8;
	GpioLed.GPIO_PinConfig.GPIO_PinMode =GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed= GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType= GPIO_OP_TYPE_PP;
	GpioLed.GPIO_PinConfig.GPIO_PinPUPdControl=GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOA, ENABLE);
	GPIO_Init (&GpioLed);




	GPIOBtn.pGPIOx = GPIOA;
	GPIOBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_9;
	GPIOBtn.GPIO_PinConfig.GPIO_PinMode =GPIO_MODE_IT_FT;
	GPIOBtn.GPIO_PinConfig.GPIO_PinSpeed= GPIO_SPEED_FAST;
	GPIOBtn.GPIO_PinConfig.GPIO_PinPUPdControl=GPIO_PIN_PU;

//	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init (&GPIOBtn);

	//IRQ Configurations
	GPIO_IRQPriorityConfig(IRQ_NO_EXTI9_5, NVIC_IRQ_PRI5);
	GPIO_IRQInterruptConfig(IRQ_NO_EXTI9_5, ENABLE);


//	while (1)
//	{
//		GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_8);
//		delay();
//	}
//
//
	while (1);
}


//void EXTI9_5_IRQHandler (void)
//{
//	GPIO_IRQHandling(GPIO_PIN_NO_9);
//	GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_8);
//
//	GPIO_IRQInterruptConfig(IRQ_NO_EXTI9_5, DISABLE);  // ignore further edges
//	delay();                                             // wait out press+release bounce
//	GPIO_IRQInterruptConfig(IRQ_NO_EXTI9_5, ENABLE);     // re-arm for next real press
//}

//>>>>>>>>>>>>>>>>>>>>>>>>
//void EXTI9_5_IRQHandler (void)
//{
//
//	GPIO_IRQHandling(GPIO_PIN_NO_9);
//	GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_8);
//	delay();
//
//}
void EXTI9_5_IRQHandler (void)
{
	delay();                          // let bounce settle
	if (GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_9) == BTN_PRESSED)  // If still heild
	{
		GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_8);
	}
	GPIO_IRQHandling(GPIO_PIN_NO_9);  // clear PR
}

//
///*
// * 002Led_button.c
// *
// *  Created on: Jun 8, 2026
// *      Author: SV
// */
//
//#define LOW			 0
//#define BTN_PRESSED LOW
//
//#include "stm32f411xx.h"
//
//void delay (void)
//{
//	for (volatile  uint32_t i=0; i< 500000/2 ; i++);
//}
//
//int main (void)
//{
//
//	GPIO_Handle_t GpioLed, GPIOBtn;
//
//	GpioLed.pGPIOx = GPIOD;
//	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_7;
//	GpioLed.GPIO_PinConfig.GPIO_PinMode =GPIO_MODE_OUT;
//	GpioLed.GPIO_PinConfig.GPIO_PinSpeed= GPIO_SPEED_FAST;
//	GpioLed.GPIO_PinConfig.GPIO_PinOPType= GPIO_OP_TYPE_PP;
//	GpioLed.GPIO_PinConfig.GPIO_PinPUPdControl=GPIO_NO_PUPD;
//
//	GPIO_PeriClockControl(GPIOD, ENABLE);
//	GPIO_Init (&GpioLed);
//
//
//	GPIOBtn.pGPIOx = GPIOD;
//	GPIOBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_8;
//	GPIOBtn.GPIO_PinConfig.GPIO_PinMode =GPIO_MODE_IT_FT;
//	GPIOBtn.GPIO_PinConfig.GPIO_PinSpeed= GPIO_SPEED_FAST;
//	GPIOBtn.GPIO_PinConfig.GPIO_PinPUPdControl=GPIO_PIN_PU;
//
//	GPIO_PeriClockControl(GPIOD, ENABLE);
//	GPIO_Init (&GPIOBtn);
//
//	//IRQ Configurations
//	GPIO_IRQPriorityConfig(IRQ_NO_EXTI9_5, NVIC_IRQ_PRI5);
//	GPIO_IRQInterruptConfig(IRQ_NO_EXTI9_5, ENABLE);
//
//	while(1);
//
//}
//
//void EXTI9_5_IRQHandler (void)
//{
//	delay();
//	GPIO_IRQHandling(GPIO_PIN_NO_8);
//	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_7);
//}

//
//
//
//
////LOW and high bwtween the two
//// it dosent need pull up pull down
////decopuling
////problem in using pu by mistake and the LED gets low current due to the hige resistor of Push pull
//
///*
//
//#include "stm32f411xx.h"
//
//void delay(void)
//{
//    for(volatile uint32_t i = 0; i < 500000; i++);
//}
//
//int main(void)
//{
//    RCC->AHB1ENR |= (1 << 0);          // Enable GPIOA clock
//
//    GPIOA->MODER &= ~(0x3 << 10);      // Clear PA5 mode
//    GPIOA->MODER |=  (0x1 << 10);      // PA5 output
//
//    while(1)
//    {
//        GPIOA->ODR ^= (1 << 5);        // Toggle PA5
//        delay();
//    }
//}
//*/
