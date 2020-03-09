/**
 * statuscode.h
 *
 *  Created on: 3 mars 2018
 *      Author: mas
 */

#ifndef INC_STATUSCODE_H_
#define INC_STATUSCODE_H_

/* Exported types ------------------------------------------------------------*/

/**
  * @brief  HAL Status structures definition
  */
typedef enum
{
	STATUS_SUCCESS 	= 0x00  ,
	STATUS_ERROR_INIT		,
	STATUS_ERROR_UNKNOWN	,
	STATUS_ERROR_STATE		,
	STATUS_ERROR_BUSY		,
	STATUS_ERROR_TIMEOUT	,
	STATUS_ERROR_OVERFLOW	,
	STATUS_ERROR_READ		,
	STATUS_ERROR_WRITE		,
	STATUS_ERROR_PARAMETER 	,
	STATUS_ERROR_EMPTY		,
	STATUS_ERROR_CHECKSUM	,
} STATUSCODE;

/**
  * @brief  peripheral Id
  */
typedef enum
{
	PERIPHERAL_I2C =0		,
	PERIPHERAL_SPI		,
	PERIPHERAL_UART		,
	PERIPHERAL_RTC		,
	PERIPHERAL_ADC		,
} PERIPHERAL_ID;


#endif /* INC_STATUSCODE_H_ */
