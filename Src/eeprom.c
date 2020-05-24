#include "stm32f4xx_hal.h"
//#include "defs.h"
//#include "extern_vars.h"
//#include "calls.h"

extern I2C_HandleTypeDef hi2c1;

extern RTC_HandleTypeDef hrtc;

extern SD_HandleTypeDef hsd;

extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;
extern UART_HandleTypeDef huart6;

const unsigned char EEPROM_Addr=0xA0;

unsigned char TmpData;
static unsigned int i;

void EEPROM_WriteByte(unsigned int Addr, unsigned char Data)
{
	HAL_I2C_Mem_Write(&hi2c1,EEPROM_Addr,Addr,I2C_MEMADD_SIZE_16BIT,&Data,1,500);
	HAL_Delay(8);
}

unsigned char EEPROM_ReadByte(unsigned int Addr)
{
	HAL_I2C_Mem_Read(&hi2c1,EEPROM_Addr,Addr,I2C_MEMADD_SIZE_16BIT,&TmpData,1,500);

	return TmpData;
}

void EEPROM_WriteArray(unsigned char *Array, unsigned int len,unsigned int StartAddr)
{
	for(i=0;i<len;i++)
	{
		EEPROM_WriteByte(StartAddr+i,*Array);
		Array++;
	}


}

void EEPROM_ReadArray(unsigned char *Array,unsigned int len,unsigned int StartAddr)
{
	for(i=0;i<len;i++)
	{
		*Array  = EEPROM_ReadByte(StartAddr+i);
		Array++;
	}
}




