#include "stm32f4xx_hal.h"
#include "fatfs.h"
#include <string.h>




/*-----------------------SD card variables----------------------*/
FATFS FatFs;
FRESULT fres;
 FIL fil;
BYTE readBytes[350];
TCHAR* rres;
/*-----------------------SD card end----------------------*/



void SDcardRead(char fileName[],int bytesToRead);
void SDcardWrite(char fileName[],int bytesToWrite,uint8_t *buffer );
void seek(char fileName[],int bytes);
void SDcardReadSeek(char fileName[],int bytesToRead,int seekBytes);
void SDcardWriteSeek(char fileName[],int bytesToWrite,uint8_t *buffer,int seekBytes );
void SDCardTruncateFile();

/*----------------------------function definition---------------------------*/

void SDcardRead(char fileName[],int bytesToRead){

//	                  fres= f_mount(&FatFs, SDPath, 1);

	                  fres = f_open(&fil, fileName, FA_READ);

	         	      rres = f_gets((TCHAR*)readBytes, bytesToRead, &fil);

	         	      f_close(&fil);

}




void SDcardWrite(char fileName[],int bytesToWrite,uint8_t *buffer ){


//	                   fres= f_mount(&FatFs, SDPath, 1);

	         	       fres = f_open(&fil, fileName, FA_OPEN_APPEND | FA_WRITE);

	         	       fres = f_write(&fil, buffer, bytesToWrite, 0);

	         	       f_close(&fil);


}

void seek(char fileName[],int bytes)
{

	fres = f_open(&fil, fileName, FA_OPEN_APPEND | FA_WRITE |  FA_READ);
	f_lseek(&fil, bytes);

}

void SDcardReadSeek(char fileName[],int bytesToRead,int bytes){

//	                  fres= f_mount(&FatFs, SDPath, 1);

	                  fres = f_open(&fil, fileName, FA_READ);

	                  f_lseek(&fil, bytes);

	         	      rres = f_gets((TCHAR*)readBytes, bytesToRead, &fil);

	         	      f_close(&fil);

}




void SDcardWriteSeek(char fileName[],int bytesToWrite,uint8_t *buffer,int bytes ){


//	                   fres= f_mount(&FatFs, SDPath, 1);

	         	       fres = f_open(&fil, fileName, FA_OPEN_APPEND | FA_WRITE);

	         	      f_lseek(&fil, bytes);

	         	       fres = f_write(&fil, buffer, bytesToWrite, 0);

	         	       f_close(&fil);


}

void SDCardTruncateFile(){

	 f_truncate (&fil);
}
