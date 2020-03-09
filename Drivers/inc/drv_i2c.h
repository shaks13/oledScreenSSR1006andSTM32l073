/**
 * @file drv_i2c.h
 * @author Embedded Software Team
 * @version 1.0
 * @date 10-October-2017
 * @brief Source file of the nfc device service
 */

#ifndef INC_DRV_I2C_H_
#define INC_DRV_I2C_H_

/* Includes ------------------------------------------------------------------*/
#include "common.h"
#include "hwconf.h"
#include "stm32l0xx_hal.h"
/* Private includes ----------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
#define I2Cx_TIMEOUT                (0x64)
#define DRVI2C_TIMEOUT_TXIS_MS    	5
#define DRVI2C_TIMEOUT_TC_MS    	5
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private user code ---------------------------------------------------------*/
void drvi2c_init(void);
uint32_t drvi2c_write ( uint8_t * const pData, const uint8_t DevAddrr, const uint16_t ui16nbByte, const uint16_t ui16timeout);
#endif /* INC_DRV_I2C_H_ */
