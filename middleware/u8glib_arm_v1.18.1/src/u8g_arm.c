/**
 * @file u8g_arm.c
 * @author Embedded Software Team
 * @version 1.0
 * @date 10-October-2017
 * @brief
 */

/* Includes ------------------------------------------------------------------*/
#include "u8g_arm.h"
/* Private includes ----------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static uint8_t buffer[DATA_BUFFER_SIZE];
/* Private function prototypes -----------------------------------------------*/
/* Private user code ---------------------------------------------------------*/

 static uint8_t control = 0;
 void u8g_Delay(uint16_t val)
 {
	 HAL_Delay(val);
 }

 void u8g_MicroDelay(void)
 {
uint16_t i;
	for (i = 0; i < 1000; i++);
 }

 void u8g_10MicroDelay(void)
 {
uint16_t i;
      for (i = 0; i < 10000; i++);
 }


 uint8_t u8g_com_hw_i2c_fn(u8g_t *u8g, uint8_t msg, uint8_t arg_val, void *arg_ptr)
{
// uint8_t buffer[DATA_BUFFER_SIZE];
uint8_t *ptr = arg_ptr;

	switch(msg)
	{
		case U8G_COM_MSG_STOP:
		break;
		case U8G_COM_MSG_INIT:
			u8g_MicroDelay();
		break;
		case U8G_COM_MSG_ADDRESS: /* define cmd (arg_val = 0) or data mode (arg_val = 1) */
			u8g_10MicroDelay();
			if (arg_val == 0)
			{
			 control = 0;
			}
			else
			{
			 control = 0x40;
			}
		break;
		case U8G_COM_MSG_WRITE_BYTE:
			buffer[0] = control;
			buffer[1] = arg_val;
			//HAL_I2C_Master_Transmit(&I2C_HANDLER, DEVICE_ADDRESS, (uint8_t*) buffer, 2, I2C_TIMEOUT);
			drvi2c_write(buffer, DEVICE_ADDRESS, 2, I2C_TIMEOUT);
			break;
		case U8G_COM_MSG_WRITE_SEQ:
		case U8G_COM_MSG_WRITE_SEQ_P:
			buffer[0] = control;
			for (int i = 1; i <= arg_val; i++)
			{
				buffer[i] = *(ptr++);
			}
			//HAL_I2C_Master_Transmit(&I2C_HANDLER, DEVICE_ADDRESS, (uint8_t *)buffer, arg_val, I2C_TIMEOUT);
			drvi2c_write(buffer, DEVICE_ADDRESS, arg_val, I2C_TIMEOUT);
		break;
	}
	return 1;
}
