#include "stm32f4xx_hal.h"
#define EEPROM_ADDRESS  0xA0
//uint8_t dataToWrite=50;
//uint8_t dataToRead[10];
//
extern I2C_HandleTypeDef hi2c1;


void writeI2C(unsigned position,uint8_t data);
//
//
//void writeI2C(uint16_t MemAddress,uint16_t MemAddSize,uint8_t *pData, uint16_t Size);
//void readI2C(uint16_t MemAddress,uint16_t MemAddSize, uint8_t *pData,uint16_t Size);
//
//
//
//
//
//
//
//void writeI2C(uint16_t MemAddress,uint16_t MemAddSize,uint8_t *pData, uint16_t Size){
//HAL_I2C_Mem_Write(&hi2c1, 0x0A,MemAddress,MemAddSize,pData,Size, 100);
//
//}
//
//
//void readI2C(uint16_t MemAddress,uint16_t MemAddSize, uint8_t *pData,uint16_t Size){
//
//
// HAL_I2C_Mem_Read(&hi2c1,0x0A,MemAddress,MemAddSize,(uint8_t *)pData,Size,100);
//
//
//}
//
//
void writeI2C(unsigned position,uint8_t data) {

int count=0;
if(data>255){
while(data>255){

data=data-255;
count++;
}

}

if(count>0){
HAL_I2C_Mem_Write(&hi2c1,EEPROM_ADDRESS, position,0xFF,(uint8_t*)&data,1,1);
HAL_Delay(5);
}




}
