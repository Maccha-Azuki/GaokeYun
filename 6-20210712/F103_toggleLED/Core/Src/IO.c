#include "IO.h"


/**
* @brief �ⲿ�жϺ�������
* @param GPIO_Pin:�ж����ź�
* @retval None
*/
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
    if(GPIO_Pin == K1_EXTI_Pin)
        LED_RED = !LED_RED;
}
