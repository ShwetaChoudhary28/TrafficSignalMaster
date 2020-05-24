#include "stm32f4xx_hal.h"
#include "fatfs.h"
#include <string.h>



extern UART_HandleTypeDef huart6;

 uint8_t frame1[180];
 uint8_t aRxBuffer6[225];




void enableGNZDAString(){

	    frame1[0] = 0xB5;
		frame1[1] = 0x62;
		frame1[2] = 0x06;
		frame1[3] = 0x01;
		frame1[4] = 0x08;
		frame1[5] = 0x00;
		frame1[6] = 0xF0;
		frame1[7] = 0x08;
		frame1[8] = 0x00;
		frame1[9] = 0x01;
		frame1[10] = 0x00;
		frame1[11] = 0x00;
		frame1[12] = 0x00;

		frame1[13] = 0x00;
		frame1[14] = 0x08;
		frame1[15] = 0x60;

		HAL_UART_Transmit(&huart6, (uint8_t*) frame1, 16, 5000);
		HAL_UART_Receive(&huart6, (uint8_t *) aRxBuffer6, 70, 0x1FFF);



}


void disableGNZDAString(){

	        frame1[0] = 0xB5;
			frame1[1] = 0x62;
			frame1[2] = 0x06;
			frame1[3] = 0x01;
			frame1[4] = 0x08;
			frame1[5] = 0x00;
			frame1[6] = 0xF0;
			frame1[7] = 0x08;
			frame1[8] = 0x00;
			frame1[9] = 0x00;
			frame1[10] = 0x00;
			frame1[11] = 0x00;
			frame1[12] = 0x00;

			frame1[13] = 0x00;
			frame1[14] = 0x07;
			frame1[15] = 0x5B;

			HAL_UART_Transmit(&huart6, (uint8_t*) frame1, 15, 5000);
			HAL_UART_Receive(&huart6, (uint8_t *) aRxBuffer6, 70, 0x1FFF);


}



void diableAllString(){

	/*----------- Disable GLL string-------------------*/
	frame1[0] = 0xB5;
	frame1[1] = 0x62;
	frame1[2] = 0x06;
	frame1[3] = 0x01;
	frame1[4] = 0x08;
	frame1[5] = 0x00;
	frame1[6] = 0xF0;
	frame1[7] = 0x01;
	frame1[8] = 0x00;
	frame1[9] = 0x00;
	frame1[10] = 0x00;
	frame1[11] = 0x00;
	frame1[12] = 0x00;

	frame1[13] = 0x00;
	frame1[14] = 0x00;
	frame1[15] = 0x2A;

	HAL_UART_Transmit(&huart6, (uint8_t*) frame1, 16, 5000);
	HAL_UART_Receive(&huart6, (uint8_t *) aRxBuffer6, 70, 0x1FFF);

	/*----------- Disable GSV string-------------------*/
	frame1[0] = 0xB5;
	frame1[1] = 0x62;
	frame1[2] = 0x06;
	frame1[3] = 0x01;
	frame1[4] = 0x08;
	frame1[5] = 0x00;
	frame1[6] = 0xF0;
	frame1[7] = 0x03;
	frame1[8] = 0x00;
	frame1[9] = 0x00;
	frame1[10] = 0x00;
	frame1[11] = 0x00;
	frame1[12] = 0x00;

	frame1[13] = 0x00;
	frame1[14] = 0x02;
	frame1[15] = 0x38;

	HAL_UART_Transmit(&huart6, (uint8_t*) frame1, 16, 5000);
	HAL_UART_Receive(&huart6, (uint8_t *) aRxBuffer6, 70, 0x1FFF);

	/*----------- Disable GSA string-------------------*/
	frame1[0] = 0xB5;
	frame1[1] = 0x62;
	frame1[2] = 0x06;
	frame1[3] = 0x01;
	frame1[4] = 0x08;
	frame1[5] = 0x00;
	frame1[6] = 0xF0;
	frame1[7] = 0x02;
	frame1[8] = 0x00;
	frame1[9] = 0x00;
	frame1[10] = 0x00;
	frame1[11] = 0x00;
	frame1[12] = 0x00;

	frame1[13] = 0x00;
	frame1[14] = 0x01;
	frame1[15] = 0x31;

	HAL_UART_Transmit(&huart6, (uint8_t*) frame1, 16, 5000);
	HAL_UART_Receive(&huart6, (uint8_t *) aRxBuffer6, 70, 0x1FFF);

	/*----------- Disable VTG string-------------------*/
	frame1[0] = 0xB5;
	frame1[1] = 0x62;
	frame1[2] = 0x06;
	frame1[3] = 0x01;
	frame1[4] = 0x08;
	frame1[5] = 0x00;
	frame1[6] = 0xF0;
	frame1[7] = 0x05;
	frame1[8] = 0x00;
	frame1[9] = 0x00;
	frame1[10] = 0x00;
	frame1[11] = 0x00;
	frame1[12] = 0x00;

	frame1[13] = 0x00;
	frame1[14] = 0x04;
	frame1[15] = 0x46;

	HAL_UART_Transmit(&huart6, (uint8_t*) frame1, 16, 5000);
	HAL_UART_Receive(&huart6, (uint8_t *) aRxBuffer6, 70, 0x1FFF);

	/*----------- Disable RMC string-------------------*/
	frame1[0] = 0xB5;
	frame1[1] = 0x62;
	frame1[2] = 0x06;
	frame1[3] = 0x01;
	frame1[4] = 0x08;
	frame1[5] = 0x00;
	frame1[6] = 0xF0;
	frame1[7] = 0x04;
	frame1[8] = 0x00;
	frame1[9] = 0x00;
	frame1[10] = 0x00;
	frame1[11] = 0x00;
	frame1[12] = 0x00;

	frame1[13] = 0x00;
	frame1[14] = 0x03;
	frame1[15] = 0x3F;

	HAL_UART_Transmit(&huart6, (uint8_t*) frame1, 16, 5000);
	HAL_UART_Receive(&huart6, (uint8_t *) aRxBuffer6, 70, 0x1FFF);

	/*----------- Disable GGA string-------------------*/
	frame1[0] = 0xB5;
	frame1[1] = 0x62;
	frame1[2] = 0x06;
	frame1[3] = 0x01;
	frame1[4] = 0x08;
	frame1[5] = 0x00;
	frame1[6] = 0xF0;
	frame1[7] = 0x00;
	frame1[8] = 0x00;
	frame1[9] = 0x00;
	frame1[10] = 0x00;
	frame1[11] = 0x00;
	frame1[12] = 0x00;

	frame1[13] = 0x00;
	frame1[14] = 0xFF;
	frame1[15] = 0x23;

	HAL_UART_Transmit(&huart6, (uint8_t*) frame1, 16, 5000);
	HAL_UART_Receive(&huart6, (uint8_t *) aRxBuffer6, 70, 0x1FFF);



}
