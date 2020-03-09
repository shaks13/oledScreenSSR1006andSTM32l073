/*
 * ser_oled.c
 *
 *  Created on: Mar 8, 2020
 *      Author:
 */


/* Includes ------------------------------------------------------------------*/
#include "ser_oled.h"
#include "u8g_arm.h"
#include "senplifyLogo.h"
/* Private includes ----------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static u8g_t u8g;
/* Private function prototypes -----------------------------------------------*/
/* Private user code ---------------------------------------------------------*/
/* public user code ---------------------------------------------------------*/
/**
  * @brief  init the service of the oled
  * @retval int
  */
uint32_t seroled_init ( void )
{
	drvi2c_init();
	u8g_InitComFn(&u8g, &u8g_dev_ssd1306_128x32_i2c, u8g_com_hw_i2c_fn); //here we init our u8glib driver /* u8g_ll_api.c */
	u8g_SetFont(&u8g,u8g_font_profont10);//set current font
}

/**
  * @brief  display a box and a text
  */
void seroled_draw ( void )
{

	u8g_FirstPage(&u8g);
	do
	{
		u8g_DrawStr(&u8g, 40, 14, "Senplify");//write string - you set coordinates and string
		u8g_DrawXBM(&u8g, 0, 0,ui8senplifyLogo_width, ui8senplifyLogo_height, ui8senplifyLogo);

	} while ( u8g_NextPage(&u8g) );
}
