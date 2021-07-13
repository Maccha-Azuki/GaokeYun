#ifndef __IO_H
#define __IO_H

#ifdef __cplusplus
extern "C" {
#endif

/*------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"
#include "main.h"


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);

#ifdef __cplusplus
}
#endif

#endif /* __IO_H */
