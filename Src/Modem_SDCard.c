#include "stm32f4xx_hal.h"



//
//int returnMode1=0;
//uint8_t junctionId = 111;
//uint8_t noOfSides = 0;
//uint8_t noOfPlans = 0;
//uint8_t noOfPhase = 0;
//uint8_t programVersionNo = 0;
////uint8_t phaseNo=0  ;
//uint8_t programVersionNoLast = 0;
//uint8_t registrationStatus = 0;
//uint8_t totalPhase=0;
//int padestarianTime = 10;
//int noOfPlansNew;
//int noOfPlanCnt = 1;
//uint8_t signalData[20];
//uint8_t planNo;
//uint8_t phaseNo;



void init4_SD();

//void init4_SD() {


//	 returnMode1=0;
//
//    /*-------SD Card--------*/
//	 seek("CommonInfo.txt",0);
//	 SDcardReadSeek("CommonInfo.txt",7);
//
//	junctionId = *(__IO uint8_t*) (Address);
//	Address = Address + 4;
//	programVersionNo = *(__IO uint8_t*) (Address);
//	Address = Address + 4;
//	fileNo = *(__IO uint8_t*) (Address);
//	Address = Address + 4;
//	registrationStatus = *(__IO uint8_t*) (Address);
//	Address = Address + 4;
//	noOfSides = *(__IO uint8_t*) (Address);
//	Address = Address + 4;
//	noOfPlans = *(__IO uint8_t*) (Address);
//	Address = Address + 4;
//	padestarianTime = *(__IO uint8_t*) (Address++);
////		program3();
//	if (junctionId == 0xFF || junctionId == 0x00) {
////		Address = 0x08006440;
//		Address = 0x08006340;
//		program3();
//	} else {
////function1();
////function2();
////function2();
//		function9();
//function9();
////function2();
//
//	}
//	programVersionNoLast = programVersionNo;
//
// 	 /* Get the RTC current Time */
//  	 HAL_RTC_GetTime(&hrtc, &sTime, FORMAT_BIN);
//  	 /* Get the RTC current Date */
//  	HAL_RTC_GetDate(&hrtc, &sDate, FORMAT_BIN);
//
//  	Address = 0x080065C8;//planStartAddress
//for(int i=1;i<noOfPlans+1;i++)
//{
//
//
//readMem();
//
//for(int j=0;j<4;j++){
//	 planTime[j]= Flash_Data[j];
//
//}
//
//
///*------------------comapering with OFF Time------------------------*/
//if (sTime.Hours>planTime[2])
//{
//continue;
//}
///*------------------comapering with OFF Time------------------------*/
//if (sTime.Hours==planTime[2])
//{
//if   (sTime.Minutes < planTime[1])
//{
//	   planNo=i;
//	   break;
//	 	 }
//}
//
//if (sTime.Hours==planTime[0])
//{if (!(sTime.Minutes <= planTime[1]))
//planNo=i;
//break;
//}
//
//
//  if (sTime.Hours>planTime[0])
//	   if (sTime.Hours< planTime[2]){
//			   planNo=i;
//			    break;
//
//
//	   }
//
//
//
//
//
//
//}
////planNo=2;
//planDetail(planNo);//gets the plan details

//}
