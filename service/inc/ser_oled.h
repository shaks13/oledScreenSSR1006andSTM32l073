/*
 * ser_oled.h
 *
 *  Created on: Mar 8, 2020
 *      Author: thmet
 */

#ifndef INC_SER_OLED_H_
#define INC_SER_OLED_H_

/* Includes ------------------------------------------------------------------*/
#include "u8g.h"
#include "drv_i2c.h"
/* Private includes ----------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private user code ---------------------------------------------------------*/
uint32_t 	seroled_init	( void );
void 		seroled_draw 	( void );
#endif /* INC_SER_OLED_H_ */
