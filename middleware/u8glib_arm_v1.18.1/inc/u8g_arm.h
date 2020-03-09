 #ifndef _U8G_ARM_H
 #define _U8G_ARM_H

/**
 * @file u8g_arm.c
 * @author Embedded Software Team
 * @version 1.0
 * @date 10-October-2017
 * @brief
 */

/* Includes ------------------------------------------------------------------*/
#include "u8g.h"
#include "drv_i2c.h"
/* Private includes ----------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define DATA_BUFFER_SIZE 		1000
#define I2C_TIMEOUT 			10000
#define DEVICE_ADDRESS 			0x78 //device address is written on back side of your display
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private user code ---------------------------------------------------------*/

uint8_t u8g_com_hw_i2c_fn(u8g_t *u8g, uint8_t msg, uint8_t arg_val, void *arg_ptr);

#endif
