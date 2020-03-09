/*
 * @file hwconf.h
 * @date Mar 8, 2020
 * @author: Embedded Software Team
 */

#ifndef INC_HWCONF_H_
#define INC_HWCONF_H_


#define HW_I2Cx								I2C1
#define HW_I2C_CLK							LL_APB1_GRP1_PERIPH_I2C1
#define HW_I2C_PEROPH_GPIO					LL_IOP_GRP1_PERIPH_GPIOA
#define HW_I2Cx_SCL_PIN                    	GPIO_PIN_9
#define HW_I2Cx_SDA_PIN                    	GPIO_PIN_10
#define HW_I2Cx_GPIO_PORT             	 	GPIOA
#define HW_I2Cx_GPIO_PULL            	 	LL_GPIO_PULL_UP
#define HW_I2Cx_GPIO_AF		           	 	LL_GPIO_AF_6
#define HW_I2Cx_DMAx						DMA1
#define HW_I2Cx_DMA_RXCHANNEL            	LL_DMA_CHANNEL_3
#define HW_I2Cx_DMA_TXCHANNEL          	 	LL_DMA_CHANNEL_2
#define HW_I2Cx_DMA_REQUEST		           	LL_DMA_REQUEST_6


#endif /* INC_HWCONF_H_ */
