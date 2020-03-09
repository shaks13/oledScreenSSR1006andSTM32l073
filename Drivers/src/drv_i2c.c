/**
 * @file drv_i2c.c
 * @author Embedded Software Team
 * @version 1.0
 * @date 10-October-2017
 * @brief Source file of the nfc device service
 */

/* Includes ------------------------------------------------------------------*/
#include "drv_i2c.h"
/* Private includes ----------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
#define	USE_LL_DRIVER 			1
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private user code ---------------------------------------------------------*/
/* I2C1 init function */
void drvi2c_init(void)
{
LL_I2C_InitTypeDef I2C_InitStruct = {0};
LL_GPIO_InitTypeDef GPIO_InitStruct = {0};

  LL_IOP_GRP1_EnableClock(HW_I2C_PEROPH_GPIO);
  /**I2C1 GPIO Configuration */
  GPIO_InitStruct.Pin = HW_I2Cx_SDA_PIN;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_OPENDRAIN;
  GPIO_InitStruct.Pull = HW_I2Cx_GPIO_PULL;
  GPIO_InitStruct.Alternate = HW_I2Cx_GPIO_AF;
  LL_GPIO_Init(HW_I2Cx_GPIO_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = HW_I2Cx_SCL_PIN;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_OPENDRAIN;
  GPIO_InitStruct.Pull = HW_I2Cx_GPIO_PULL;
  GPIO_InitStruct.Alternate = HW_I2Cx_GPIO_AF;
  LL_GPIO_Init(HW_I2Cx_GPIO_PORT, &GPIO_InitStruct);

  /* Peripheral clock enable */
  LL_APB1_GRP1_EnableClock(HW_I2C_CLK);
  /* I2C1 DMA Init */
  /* I2C1_RX Init */
  LL_DMA_SetPeriphRequest(HW_I2Cx_DMAx, HW_I2Cx_DMA_RXCHANNEL, HW_I2Cx_DMA_REQUEST);
  LL_DMA_SetDataTransferDirection(HW_I2Cx_DMAx, HW_I2Cx_DMA_RXCHANNEL, LL_DMA_DIRECTION_PERIPH_TO_MEMORY);
  LL_DMA_SetChannelPriorityLevel(HW_I2Cx_DMAx, HW_I2Cx_DMA_RXCHANNEL, LL_DMA_PRIORITY_LOW);
  LL_DMA_SetMode(HW_I2Cx_DMAx, HW_I2Cx_DMA_RXCHANNEL, LL_DMA_MODE_NORMAL);
  LL_DMA_SetPeriphIncMode(HW_I2Cx_DMAx, HW_I2Cx_DMA_RXCHANNEL, LL_DMA_PERIPH_NOINCREMENT);
  LL_DMA_SetMemoryIncMode(HW_I2Cx_DMAx, HW_I2Cx_DMA_RXCHANNEL, LL_DMA_MEMORY_INCREMENT);
  LL_DMA_SetPeriphSize(HW_I2Cx_DMAx, HW_I2Cx_DMA_RXCHANNEL, LL_DMA_PDATAALIGN_BYTE);
  LL_DMA_SetMemorySize(HW_I2Cx_DMAx, HW_I2Cx_DMA_RXCHANNEL, LL_DMA_MDATAALIGN_BYTE);
  /* I2C1_TX Init */
  LL_DMA_SetPeriphRequest(HW_I2Cx_DMAx, HW_I2Cx_DMA_TXCHANNEL, HW_I2Cx_DMA_REQUEST);
  LL_DMA_SetDataTransferDirection(HW_I2Cx_DMAx, HW_I2Cx_DMA_TXCHANNEL, LL_DMA_DIRECTION_MEMORY_TO_PERIPH);
  LL_DMA_SetChannelPriorityLevel(HW_I2Cx_DMAx, HW_I2Cx_DMA_TXCHANNEL, LL_DMA_PRIORITY_LOW);
  LL_DMA_SetMode(HW_I2Cx_DMAx, HW_I2Cx_DMA_TXCHANNEL, LL_DMA_MODE_NORMAL);
  LL_DMA_SetPeriphIncMode(HW_I2Cx_DMAx, HW_I2Cx_DMA_TXCHANNEL, LL_DMA_PERIPH_NOINCREMENT);
  LL_DMA_SetMemoryIncMode(HW_I2Cx_DMAx, HW_I2Cx_DMA_TXCHANNEL, LL_DMA_MEMORY_INCREMENT);
  LL_DMA_SetPeriphSize(HW_I2Cx_DMAx, HW_I2Cx_DMA_TXCHANNEL, LL_DMA_PDATAALIGN_BYTE);
  LL_DMA_SetMemorySize(HW_I2Cx_DMAx, HW_I2Cx_DMA_TXCHANNEL, LL_DMA_MDATAALIGN_BYTE);
  /** I2C Initialization  */
  LL_I2C_EnableAutoEndMode(HW_I2Cx);
  LL_I2C_DisableOwnAddress2(HW_I2Cx);
  LL_I2C_DisableGeneralCall(HW_I2Cx);
  LL_I2C_EnableClockStretching(HW_I2Cx);
  I2C_InitStruct.PeripheralMode = LL_I2C_MODE_I2C;
  I2C_InitStruct.Timing = 0x00000708;
  I2C_InitStruct.AnalogFilter = LL_I2C_ANALOGFILTER_ENABLE;
  I2C_InitStruct.DigitalFilter = 0;
  I2C_InitStruct.OwnAddress1 = 0;
  I2C_InitStruct.TypeAcknowledge = LL_I2C_ACK;
  I2C_InitStruct.OwnAddrSize = LL_I2C_OWNADDRESS1_7BIT;
  LL_I2C_Init(HW_I2Cx, &I2C_InitStruct);
  LL_I2C_SetOwnAddress2(HW_I2Cx, 0, LL_I2C_OWNADDRESS2_NOMASK);

}

/**
  * @brief  write N bytes of Data using DMA, starting from the specified I2C address.
  * @param[in]  ui16devAddr I2C data memory address to read.
  * @param[in]  ui16memAddr I2C data memory address to read.
  * @param[in]  ui16nbByte  Number of bytes to be read.
  * @return STATUS_SUCCESS
  * @return STATUS_ERROR_READ
  */
uint32_t drvi2c_write ( uint8_t * const pData, const uint8_t DevAddr, const uint16_t ui16nbByte, const uint16_t ui16timeout)
{
uint16_t Timeout = DRVI2C_TIMEOUT_TXIS_MS ;
uint8_t * pTransmitBuffer = pData;
uint32_t status = STATUS_SUCCESS;
#if USE_LL_DRIVER == 1
	  /* (1) Initiate a Start condition to the Slave device ***********************/
	  /* Master Generate Start condition for a write request :              */
	  /*    - to the Slave with a 7-Bit SLAVE_OWN_ADDRESS                   */
	  /*    - with a auto stop condition generation when transmit all bytes */
	  LL_I2C_HandleTransfer(HW_I2Cx, DevAddr, LL_I2C_ADDRSLAVE_7BIT, ui16nbByte, LL_I2C_MODE_AUTOEND, LL_I2C_GENERATE_START_WRITE);
	  /* (2) Loop until end of transfer received (STOP flag raised) ***************/
	  /* Loop until STOP flag is raised  */
	  while(!LL_I2C_IsActiveFlag_STOP(HW_I2Cx))
	  {	/* (2.1) Transmit data (TXIS flag raised) *********************************/
	    /* Check TXIS flag value in ISR register */
	    if(LL_I2C_IsActiveFlag_TXIS(HW_I2Cx))
	    {/* Write data in Transmit Data register.
	      TXIS flag is cleared by writing data in TXDR register */
	      LL_I2C_TransmitData8(HW_I2Cx, (*pTransmitBuffer++));
	      Timeout = ui16timeout;
	    }
	    /* Check Systick counter flag to decrement the time-out value */
	    if (LL_SYSTICK_IsActiveCounterFlag())
	    {
	      if(Timeout-- == 0)
	      {/* Time-out occurred.  */
	    	  status = STATUS_ERROR_TIMEOUT;
	      }
	    }
	  }
	  /* (3) Clear pending flags, Data consistency are checking into Slave process */
	  /* End of I2C_SlaveReceiver_MasterTransmitter Process */
	  LL_I2C_ClearFlag_STOP(HW_I2Cx);
	  return status;
#else
	return HAL_I2C_Master_Transmit ( &hi2c1, DevAddr, pData, ui16nbByte, ui16timeout);
#endif
}
