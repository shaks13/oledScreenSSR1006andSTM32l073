/*
 * app_unittest.c
 *
 *  Created on: Nov 29, 2019
 *      Author: thmet
 */

/* Includes ------------------------------------------------------------------*/
#include "app_unittest.h"
#include "ser_oled.h"

/* Private includes ----------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
#if ENABLE_UNITTEST == 1
/* Private function prototypes -----------------------------------------------*/
/* Private user code ---------------------------------------------------------*/

/**
  * @brief run an echo command to check the nfc channel
  */
static void apptest_assert ( const bool bIsEnable )
{
	if (true == bIsEnable)
	{
		assert_param( true );
		assert_param( false);
	}
}

/**
  * @brief run an echo command to check the nfc channel
  */
static void apptest_display ( const bool bIsEnable )
{
	if (true == bIsEnable)
	{
		seroled_draw();

	}
}
#endif
/* public function declaration -----------------------------------------------*/

/**
  * @brief init the unit test
  */
void apptest_init ( void )
{
#if ENABLE_UNITTEST == 1

#endif
}
/**
  * @brief run the unit test
  */
void apptest_run ( const bool bIsEnable )
{
#if ENABLE_UNITTEST == 1
	if (true == bIsEnable)
	{
		apptest_assert 			( false );
		apptest_display			( true );
	}
#endif
}

