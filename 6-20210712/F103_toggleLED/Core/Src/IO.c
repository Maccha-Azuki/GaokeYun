#include "IO.h"


/**
* @brief 外部中断函数处理
* @param GPIO_Pin:中断引脚号
* @retval None
*/
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
    if(GPIO_Pin == K1_EXTI_Pin)
        LED_RED = !LED_RED;
}
