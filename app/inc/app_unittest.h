/**
 * @file app_unittest.c
 * @author Embedded Software Team
 * @version 1.0
 * @date 01-December-2017
 * @brief Source file of the unittest application
 */
#ifndef INC_APP_UNITTEST_H_
#define INC_APP_UNITTEST_H_

/* Includes ------------------------------------------------------------------*/
#include "ser_test.h"
/* Private includes ----------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private user code ---------------------------------------------------------*/
/* public function declaration -----------------------------------------------*/
void apptest_init 	( void );
void apptest_run 	( const bool bIsEnable );
#endif /* INC_APP_UNITTEST_H_ */
