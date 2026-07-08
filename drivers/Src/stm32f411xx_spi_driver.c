/*
 * stm32f411xx_spi_driver.c
 *
 *  Created on: Jul 4, 2026
 *      Author: SV
 */


#include "stm32f11xx_spi_driver.h"
/*
 * Peripheral Clock setup
 */
/******************************************************************************
 * @fn          - GPIO_PerClockControl
 *
 * @brief       - This function enables and disables prehihpral clock for given GPIO port
 *
 * @param[in]   -base address of the gpio peripheral
 * @param[in]   -ENABLE or Disable macros
 * @param[in]   -
 *
 * @return      - none
 *
 * @Note        - none
 *
 *****************************************************************************/

void SPI_PeriClockControl(SPI_RegDef_t *pSPIx, uint8_t EnorDi)

 {
	if(EnorDi == ENABLE)
	{
		if(pSPIx == SPI1)
		{
			SPI1_PCLK_EN();
		}else if (pSPIx == SPI2)
		{
			SPI2_PCLK_EN();
		}else if (pSPIx== SPI3)
		{
			SPI3_PCLK_EN();

	}else
	{
		if(pSPIx == SPI1)
		{
			SPI1_PCLK_DI();
		}else if (pSPIx == SPI2)
		{
			SPI2_PCLK_DI();
		}else if (pSPIx== SPI3)
		{
			SPI3_PCLK_DI();
		}

}
}
 }

/*
 * Init and De-init
 */
void SPI_Init(SPI_Handle_t *pSPIHandle)  // (void), the parameters will be written later
{

}


/*
 * Data read and write
 */


/*
 * Peripheral Clock setup
 */
/******************************************************************************
 * @fn          - GPIO_ReadFromInputPin
 *
 * @brief       -
 *
 * @param[in]   -
 * @param[in]   -
 * @param[in]   -
 *
 * @return      - 0 or 1
 *
 * @Note        - none
 *
 *****************************************************************************/

void SPI_DeInit(SPI_RegDef_t *pSPIx)
{

}




/******************************************************************************
 * @fn          - GPIO_writeToOutpotPort
 *
 * @brief       - This function enables and disables prehihpral clock for given GPIO port
 *
 * @param[in]   -base address of the gpio peripheral
 * @param[in]   -ENABLE or Disable macros
 * @param[in]   -
 *
 * @return      - none
 *
 * @Note        - none
 *
 *****************************************************************************/

void SPI_SendData(SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer, uint32_t Len)
{

}


/******************************************************************************
 * @fn          - GPIO_ToggleOutputPin
 *
 * @brief       -
 * @param[in]   -
 * @param[in]   -
 * @param[in]   -
 *
 * @return      - none
 *
 * @Note        - none
 *
 *****************************************************************************/

void SPI_ReceiveData(SPI_RegDef_t *pSPIx, uint8_t *pRxBuffer, uint32_t Len)
{

}

/*
 * IRQ Configuration and ISR Handling
 */


/******************************************************************************
 * @fn          - GPIO_IRQConfig
 *
 * @brief       - This function enables and disables prehihpral clock for given GPIO port
 *
 * @param[in]   -base address of the gpio peripheral
 * @param[in]   -ENABLE or Disable macros
 * @param[in]   -
 *
 * @return      - none
 *
 * @Note        - none
 *
 *****************************************************************************/

void SPI_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi)			// message the intrrupt ([config]enable and give the prioraty)
{

}


	/******************************************************************************
	 * @fn          - GPIO_PerClockControl
	 *
	 * @brief       - This function enables and disables prehihpral clock for given GPIO port
	 *
	 * @param[in]   -base address of the gpio peripheral
	 * @param[in]   -ENABLE or Disable macros
	 * @param[in]   -
	 *
	 * @return      - none
	 *
	 * @Note        - none
	 *
	 *****************************************************************************/

void SPI_IRQPriorityConfig(uint32_t IRQNumber, uint32_t IRQPriority)
{

}




/******************************************************************************
 * @fn          - GPIO_PerClockControl
 *
 * @brief       - This function enables and disables prehihpral clock for given GPIO port
 *
 * @param[in]   -base address of the gpio peripheral
 * @param[in]   -ENABLE or Disable macros
 * @param[in]   -
 *
 * @return      - none
 *
 * @Note        - none
 *
 *****************************************************************************/

void SPI_IRQHandling(SPI_Handle_t *pHandle)		//To prossesor that interrupt when it comes
{

}
