#include "stm32f4xx_hal.h"


extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;
extern UART_HandleTypeDef huart6;




void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart)
{
	__HAL_UART_CLEAR_OREFLAG (huart);

}
