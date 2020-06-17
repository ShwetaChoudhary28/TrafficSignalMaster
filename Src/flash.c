#include "stm32f4xx_hal.h"
//#include "defs.h"
//#include "extern_vars.h"
//#include "calls.h"
#include "string.h"
#include "stdio.h"
//#incldue "stm32f4xx_hal_flash.h"
extern I2C_HandleTypeDef hi2c1;

extern RTC_HandleTypeDef hrtc;

//extern SD_HandleTypeDef hsd;

extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;
extern UART_HandleTypeDef huart6;



//uint32_t FirstSector = 0, NbOfSectors = 0, Address = 0;
uint32_t SectorError = 0;
//__IO uint32_t data32 = 0 , MemoryProgramStatus = 0;
//#define ADDR_FLASH_SECTOR_0     ((uint32_t)0x08000000) /* Base @ of Sector 0, 16 Kbytes */
//#define ADDR_FLASH_SECTOR_1     ((uint32_t)0x08004000) /* Base @ of Sector 1, 16 Kbytes */
//#define ADDR_FLASH_SECTOR_2     ((uint32_t)0x08008000) /* Base @ of Sector 2, 16 Kbytes */
//#define ADDR_FLASH_SECTOR_3     ((uint32_t)0x0800C000) /* Base @ of Sector 3, 16 Kbytes */
//#define ADDR_FLASH_SECTOR_4     ((uint32_t)0x08010000) /* Base @ of Sector 4, 64 Kbytes */
//#define ADDR_FLASH_SECTOR_5     ((uint32_t)0x08020000) /* Base @ of Sector 5, 128 Kbytes */
//#define ADDR_FLASH_SECTOR_6     ((uint32_t)0x08040000) /* Base @ of Sector 6, 128 Kbytes */
//#define ADDR_FLASH_SECTOR_7     ((uint32_t)0x08060000) /* Base @ of Sector 7, 128 Kbytes */
//#define ADDR_FLASH_SECTOR_8     ((uint32_t)0x08080000) /* Base @ of Sector 8, 128 Kbytes */
//#define ADDR_FLASH_SECTOR_9     ((uint32_t)0x080A0000) /* Base @ of Sector 9, 128 Kbytes */
//#define ADDR_FLASH_SECTOR_10    ((uint32_t)0x080C0000) /* Base @ of Sector 10, 128 Kbytes */
#define ADDR_FLASH_SECTOR_11    ((uint32_t)0x080E0000) /* Base @ of Sector 11, 128 Kbytes */
#define MCU_UNIQUE_ID_BASE_ADDR 0x1FFF7A10
#define Base_Address 0x080E0000;

union
{
unsigned char Byte[4];
unsigned long Word;
}SplitUnion;
unsigned long TempFlashWordArray[5],TempFlashWord;
//unsigned char TempFlashByte;
void flash_Erase();



void Flash_Sector11_Erase(void)
{
static FLASH_EraseInitTypeDef EraseInitStruct;
HAL_FLASH_Unlock();
EraseInitStruct.TypeErase = FLASH_TYPEERASE_SECTORS;
  EraseInitStruct.VoltageRange = FLASH_VOLTAGE_RANGE_3;
  EraseInitStruct.Sector = FLASH_SECTOR_11;
  EraseInitStruct.NbSectors = 1;
  HAL_FLASHEx_Erase(&EraseInitStruct, &SectorError);
HAL_FLASH_Lock();
}

void Flash_WriteTest(void)
{
HAL_FLASH_Unlock();
HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD,ADDR_FLASH_SECTOR_11,0x12345678);
HAL_Delay(10);
HAL_FLASH_Lock();
}

// XX XX XX XX XX XX XX XX XX XX XX XX

unsigned long Flash_ReadWord(unsigned long Address)
{
return (*(__IO uint32_t*)Address);
}

unsigned char Flash_ReadByte(uint32_t Address,uint8_t *byteToRead,int length)
{

//SplitUnion.Word =  *(__IO uint32_t*)Address;
//return (SplitUnion.Byte[0]);
//	Address=Address+1;
	for(int i=0;i<length;i++)
		{
		byteToRead[i]=*(uint8_t *) Address;
		Address++;
		}


}



void Flash_Write(uint32_t Address,uint8_t *byteToWrite,int length )
{
int j=1;
	HAL_FLASH_Unlock();

	for(int i=0;i<length;i++)
	{
		 FLASH_WaitForLastOperation(100);

	HAL_FLASH_Program(FLASH_TYPEPROGRAM_BYTE,Address,byteToWrite[i]);
	HAL_Delay(10);
	Address=Address+j;
	}

	HAL_FLASH_Lock();

}


void flash_Erase()
{
	                  HAL_FLASH_Unlock();
	                  FLASH_WaitForLastOperation(100);
	                  FLASH_Erase_Sector(FLASH_SECTOR_11, FLASH_VOLTAGE_RANGE_3);
	                  FLASH_Erase_Sector(FLASH_SECTOR_10, FLASH_VOLTAGE_RANGE_3);
	                  HAL_FLASH_Lock();
}







//void Flash_ReadUniqueID(void)
//{
//for(int c=0;c<12;c++)
//MCU_UniqueID[c] = Flash_ReadByte(MCU_UNIQUE_ID_BASE_ADDR+c);
//
//MCU_UniqueID[13] = 0x00;
//
//}

