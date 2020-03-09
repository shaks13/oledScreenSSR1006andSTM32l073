/**
 * @file common.h
 * @author Embedded Software Team
 * @version 1.0
 * @date 10-October-2017
 * @brief
 */

#ifndef COMMON_H_
#define COMMON_H_
/* Includes ------------------------------------------------------------------*/
#include <stdbool.h>
#include <stdint.h>
#include "statuscode.h"

/* public define ------------------------------------------------------------------*/
#define BOARD_VERSION	 					((const uint8_t*)"1.97")
#define BOARD_VERSION_NBCHAR				4
#define BOARD_VERSIONINT 					(0x1907)

#define VERBOSE_LEVEL_0 					0
#define VERBOSE_LEVEL_1 					1
#define VERBOSE_LEVEL_2 					2

#define	ENABLE_RELEASE						0

#if ENABLE_RELEASE == 1
#else
#define ENABLE_UNITTEST						1

#endif

/* extern prototype  ------------------------------------------------------------------*/
extern void Error_Handler(void); 			/*define in main.c*/
#endif /* COMMON_H_ */
