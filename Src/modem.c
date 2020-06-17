#include "stm32f4xx_hal.h"
#include "fatfs.h"
#include <string.h>

#define Base_Address 0x080E0000
#define ADDR_FLASH_SECTOR_11    ((uint32_t)0x080E0000) /* Base @ of Sector 11, 128 Kbytes */
#define ADDR_FLASH_SECTOR_10    ((uint32_t)0x080C0000) /* Base @ of Sector 10, 128 Kbytes */
#define ADDR_FLASH_SECTOR_9     ((uint32_t)0x080A0000) /* Base @ of Sector 9, 128 Kbytes */
RTC_TimeTypeDef sTime;
RTC_DateTypeDef sDate;
extern uint8_t RecMsg2[250];
uint8_t frame[180];
//extern UART_HandleTypeDef huart2;
//extern UART_HandleTypeDef huart4;
extern UART_HandleTypeDef huart6;
extern UART_HandleTypeDef huart3;
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart1;
extern RTC_HandleTypeDef hrtc;

extern uint8_t aRxBuffer[225];
extern uint8_t aRxBuffer1[225];
extern uint8_t RecMsg1[250];
extern uint8_t aRxBuffer3[225];
extern uint8_t RecMsg3[250];
extern uint8_t aRxBuffer4[225];
extern uint8_t RecMsg4[250];
extern uint8_t aRxBuffer5[225];
extern uint8_t RecMsg5[250];
int function32();
int zxx9 = 4;
int zxx9Res = 6;
uint8_t Data[100];
int state;
int clearanceMode;
int serverMode;
uint8_t fileNo = 111;
extern int signVal;
uint8_t string[130]; // string array to store messege received in uart
uint8_t junctionId = 111;
uint8_t noOfDateSlots=0;
uint8_t dateSlotNo=0;
uint8_t dateID=0;
uint8_t dayID=0;
uint8_t totalNoOfPlans=0;
uint8_t totalNoOfPhases=0;
uint8_t noOfDaySlots=0;
uint8_t daySlotNo=0;
uint8_t noOfSides = 0;
uint8_t noOfPlans = 0;
uint8_t noOfPhase = 0;
uint8_t programVersionNo = 0;
//uint8_t phaseNo=0  ;
uint8_t programVersionNoLast = 0;
uint8_t registrationStatus = 0;
uint8_t totalPhase=0;
int padestarianTime = 10;
int noOfPlansNew;
int noOfPlanCnt = 1;
uint8_t signalData[20];
uint8_t planNo;
uint8_t plan_ID;
uint8_t mapID;
int noOfPhases_Map;
uint8_t phaseNo;
uint8_t phase_ID;
uint8_t phaseMapArray[100];
int phaseMapCnt=0;
int phaseMapCnt1=0;//total no of phases in phase.txt
__IO uint32_t stringInt[25]; // string array to store messege received in uart
char data1[17];
extern uint8_t second[17];
int indexCnt = 0;
int indexCnt1 = 0;
uint8_t first[17];
int cntVal;
extern int recCnt;
extern int recCnt1;
char crcVal[5];
__IO uint32_t test = 0;
uint8_t planID;
uint8_t planOnHr;
uint8_t planOnM;
uint8_t planOffHr;
uint8_t planOffM;
uint8_t planS1GT;
uint8_t planS2GT;
uint8_t planS3GT;
uint8_t planS4GT;
uint8_t planS5GT = 15;
uint8_t planA1GT;
uint8_t planA2GT;
uint8_t planA3GT;
uint8_t planA4GT;
uint8_t planA5GT = 4;
uint8_t planMode;
//uint32_t Address = 0x08006440;
uint32_t Address = 0x08006340;
char junctionName[15];
char side1[15];
char side2[15];
char side3[15];
char side4[15];
char side5[15];
int Flash_Data[1005];
int signVal1;
int count;
extern uint8_t planTime[50];
uint32_t test1[10][10][10];
__IO uint8_t Disp[40];
//uint32_t addressInfo = 0x08005340;
uint32_t addressInfo = 0x08007000;
uint32_t a[10][10][10];
int primaryByte[6];
int secondaryByte[6];
int primaryHorizontalByte[6];
int primaryVerticalByte[6];
int secondaryHorizontalByte[6];
int secondaryVerticalByte[6];
int hundredPlaceSegment[6];
int tenPlaceSegment[6];
int unitPlaceSegment[6];
uint8_t powerStatus=0;
uint8_t GPSDay;
uint8_t GPSMonth;
uint8_t GPSYear;
uint8_t GPSHr;
uint8_t GPSMin;
uint8_t GPSSec;
int laserOn = 0 ;
int seekCntForDayAndDate;
int noOfPhasesInMapID=0;
uint8_t phaseMapIDList[200];
uint8_t phaseList[500];
uint8_t currentPlanPhases[250];
uint8_t Color[100];

extern int msgUnPrcd;
extern int functionRec;
extern CRC_HandleTypeDef hcrc;
extern __IO uint32_t CRCValue;
extern  __IO uint32_t crcbits;
extern char crcstring[4];
extern int slave1Rsp;
extern int slave2Rsp;
extern int slave3Rsp;
extern int slave4Rsp;
extern uint8_t communicationStatus;
extern int slave1Transmit;
extern int slave2Transmit;
extern int slave3Transmit;
extern int slave4Transmit;
extern  int msgRec;
extern  int commFlag;
extern int msgTx;
extern  int slaveNo;
extern int millisec1;
extern int msgUnPrcd4;
extern int msgUnPrcd3;
extern int msgUnPrcd1;
extern int msgUnPrcd;
int colour=0;
int phaseTime=0;
int secLast=0;
int returnMode=0;
extern BYTE readBytes[350];
uint8_t bytesToWriteInSD[50];
extern int sec1;
int AddressOfPhase;
uint8_t clearenceMode=0  ;
uint8_t clearenceModeLast=0  ;
uint8_t clearenceSide=0  ;
int changeMode;
int side1PoleType;
int side2PoleType;
int side3PoleType;
int side4PoleType;
int side5PoleType;
int sideNo1;
int sideNo2;
int sideNo3;
int sideNo4;
int primaryByteCommand[5];
 int secondaryByteCommand[5];

 uint8_t leftGreen;
 uint8_t pedestrainByte;
 int inputPinStatus;
 int incCnt=0;
 int noOfPhaseCnt=0;
 int phaseData[300];
 int totalNoOfPhasesInMapID=0;
 /*----------------for server and field actions--------------------*/
 int checkServerJumpExtend;
 int extendCnt=0;
 int extendCnt1=0;
 int lSec=10;
 int pin_High=0;
 int pin_HighLast=0;
 uint8_t clearance_Side=0;
 uint8_t clearance_Mode;
 int clearance_Mode_Last=0;
 int  fieldActionFlag=0;
 //---------------for extend pin----//
 int pinExtend_High=0;
 int pinExtend_HighLast=0;
 int pinExtend_On = 0 ;
 int lsSec=10;
 uint8_t dateSlot[10];
 int totalNoOfMap=0;
 uint8_t planDetailsArray[150];

 unsigned int eepromAddress =0;

 int counterOfPlan=0;
 int total_Phases=0;
int mapIDForCurrentPhases=0;
//char changed_side;
char changedSide;
char side;
uint8_t Map_IDCurrent[50];
extern void clearingRecBuffer();
 int isReprogrammed=0;


 extern int pointerOfArray;


 int programFromBLE;
 int phase_No;


 /*-------------RTC--------------*/
 uint8_t MaxDayOfMonth[3];
 uint8_t Date;
 uint8_t Month;
 uint8_t Year;
 uint8_t Hours;
 uint8_t Minutes;
 uint8_t Seconds;
 uint8_t DateLast;

 extern int min;


 /*-----------slave detail array ---------------*/
 uint8_t slaveDetails[30];
 char sideNo1_1,sideNo2_1,sideNo3_1,sideNo4_1;


extern int check;
/*------------------------functions------------------------------*/
void clearBuffer();
void transmit();
void clearaRxBuffer1();
void clearBuffer1();
void clearaRxBuffer3();
void clearBuffer3();
void clearaRxBuffer4();
void clearBuffer4();
void clearaRxBuffer5();
void clearBuffer5();
void function7_1();
void function7_2();
void function3_1();
void function3_2();
int crcApi();
void transferDataValues(int cnt);
void function6_2();
void function6_1();
void sendToUsart1();
void outputPin();
void inputPin();
int function8();
void checkMode();
void checkClearenceMode();
int crcApiResponse();
int function1();
void function1Response();
int crcApi2(int signval);
void program3();
void function4Response();
void byteToIntegerVal(char *dat, uint8_t index);
void byteToIntegerVal1(uint8_t dat);
void intToString(__IO uint32_t dat);
void clearStringBuffer();
void intToChar(uint8_t dat);
void intToChar1(uint8_t dat);
void trafficDisplay2Value();
void trafficDisplay1Value();
void checkMsgLengthForUart4();
void checkMsgLengthForUart2();
void intToByte(int val);
int function_10();
int function1_1();
void readMem();
void clearFlashDataBuffer();
void init4();
int crcApi3(int signval);
int crcApi4(int signval);
void getPhase(uint8_t planNo);
int function_10_2();
int function3();
extern short msgParse(uint8_t *SPtr ,char *sigPtr , short pointer );
int signal();
int blinker();
void phaseInfoAddress();
int phaseInfoData(uint8_t planNo,uint8_t phaseNo);
extern void transferRecValuesToData(int cnt);
void slaveResponse();
void sendMsgToSlave();
extern int SDCardMsg;
int espCommunication();
void f0Communication();
int transmitData();
extern  void functionTransmitToSlave(uint8_t *sendFrame,uint8_t length);
extern  void function6_A();
extern void SDcardRead(char fileName[],int bytesToRead);
extern  void SDcardWrite(char fileName[],int bytesToWrite,uint8_t *buffer );
extern void seek(char fileName[],int bytes);
extern void SDcardReadSeek(char fileName[],int bytesToRead,int seekBytes);
extern void SDcardWriteSeek(char fileName[],int bytesToWrite,uint8_t *buffer,int seekBytes );
void clearReadBytes();
void getPhaseSD(uint8_t planNo);
void readPhaseSD(int cnt);
void readMemSD(int cnt);
int planDetailSD(int planNo);
void clearanceModeAction();
void analysingResponseOfSlave();
void checkSideColour(int aspectColor,int slaveAspectColor,int poleType);
extern void clearingDataBuffer();
void slaveResponseLORA();
extern void transferRecValuesToDataRecMsg2(int cnt);
void leftGreen1();
void pedestrain();
extern void enableGNZDAString();
extern void disableGNZDAString();
extern void diableAllString();
void getDateAndTimeFromGPS();
void convertStringToByte();
int function11N();
void readInputPin();
void checkFieldAction();
void checkClearenceSide();
void laser();
void extend();
void checkServerFieldAction();
int function13(void);
int function12(void);
int function14(void);
int function15(void);
int function16(void);
void getPhaseSDCardNew(uint8_t planNoN);
void readDateSD(int cnt);
void readDaySD(int cnt);
void readPlanSD(int cnt);
extern void SDCardTruncateFile();
void countNoOfMapDetails();
void currentDayAllPlan();
void clearPlanDetailsArrayBuffer();
void clearPlanTimeBuffer();
void getCurrentPlanTotalNoOfPhases();
int function17(void);
void EEPROM_WriteArray(unsigned char *Array, unsigned int len,unsigned int StartAddr);
void EEPROM_ReadArray(unsigned char *Array,unsigned int len,unsigned int StartAddr);
void getCurrentPlanPhases();
//unsigned char DetectChange(unsigned char currentSide13Color,unsigned char previousSide13Color,
//		unsigned char currentSide24Color,unsigned char previousSide24Color);
unsigned char DetectChange(unsigned char currentSide13Color,unsigned char previousSide13Color);
void BLECommunication();
void sideChange(char previousSide13Color,char currentSide13Color
		,char previousSide24Color,char currentSide24Color);

void findSide(uint8_t side13Color,uint8_t side24Color);

void clearPrimaryAndSecByte();
void resetVariables();
/*-----------flash functions---------start-----*/
extern void Flash_Write(uint32_t Address,uint8_t *byteToWrite,int length );
extern unsigned char Flash_ReadByte(uint32_t Address,uint8_t *byteToRead,int length);
extern void flash_Erase();
/*-----------flash functions---------end-----*/
void sendData();
void countDown();
void clearDispBuffer() ;
void RTC_UtcToIstSet(unsigned char uDate,unsigned char uMonth, unsigned char uYear,unsigned char uHours, unsigned char uMinutes,unsigned char uSeconds);
int function18();
void extractSlaveInfo();

void  populatePrimaryHVSecondaryHV();




void clearframe() {
	int x = 0;
	for (; x < 160; x++) {
		frame[x] = 0x00;

	}
}

void clearReadBytes() {
	int x = 0;
	for (; x < 350; x++) {
		readBytes[x] = 0x00;

	}
}
void clearBuffer() {
	int x = 0;
	for (; x < 160; x++) {
		RecMsg2[x] = 0x00;

	}
}

void clearDispBuffer() {
//	int x = 0;
//	for (; x < 40; x++) {
		Disp[0] = 0x00;
		Disp[1] = 0x00;
		Disp[2] = 0x00;
		Disp[3] = 0x00;
		Disp[6] = 0x00;
		//	}
}

void clearFlashDataBuffer() {
	int x = 0;
	for (; x < 1000; x++) {
		Flash_Data[x] = 0x00;

	}
}

void clearaRxBuffer() {
	int x = 0;
	for (; x < 160; x++) {
		aRxBuffer[x] = 0x00;

	}
}

void clearBuffer1() {
	int x = 0;
	for (; x < 160; x++) {
		RecMsg1[x] = 0x00;

	}
}

void clearaRxBuffer1() {
	int x = 0;
	for (; x < 160; x++) {
		aRxBuffer1[x] = 0x00;

	}
}
void clearBuffer3() {
	int x = 0;
	for (; x < 160; x++) {
		RecMsg3[x] = 0x00;

	}
}

void clearaRxBuffer3() {
	int x = 0;
	for (; x < 160; x++) {
		aRxBuffer3[x] = 0x00;

	}
}

void clearBuffer4() {
	int x = 0;
	for (; x < 160; x++) {
		RecMsg4[x] = 0x00;

	}
}

void clearaRxBuffer4() {
	int x = 0;
	for (; x < 160; x++) {
		aRxBuffer4[x] = 0x00;

	}
}

void clearBuffer5() {
	int x = 0;
	for (; x < 160; x++) {
		RecMsg5[x] = 0x00;

	}
}

void clearaRxBuffer5() {
	int x = 0;
	for (; x < 160; x++) {
		aRxBuffer5[x] = 0x00;

	}
}



void clearPlanDetailsArrayBuffer() {
	int x = 0;
	for (; x < 149; x++) {
		planDetailsArray[x] = 0x00;

	}
}



void clearPlanTimeBuffer() {
	int x = 0;
	for (; x < 49; x++) {
		planTime[x] = 0x00;

	}
}




void transmit() {

//	frame[0] = 0x41;
//	frame[1] = 0x54;
//	frame[2] = 0x2B;
//	frame[3] = 0x43;
//	frame[4] = 0x50;
//	frame[5] = 0x42;
//	frame[6] = 0x46;
//	frame[7] = 0x0D;
//	frame[8] = 0x0A;
	//HAL_UART_Transmit (&huart2, (uint8_t*)frame, 9,5000) ;

//	HAL_UART_Transmit (&huart4, (uint8_t*)Data,38,5000) ;
//	HAL_UART_Transmit (&huart2, (uint8_t*)Data,38,5000) ; cntVal

	HAL_UART_Transmit(&huart3, (uint8_t*) Data, cntVal, 5000);
//		HAL_UART_Transmit (&huart2, (uint8_t*)Data,cntVal,5000) ;

	cntVal = 0;

}

void function7_1() // read SD Card
{

	frame[0] = 0x7E;
	frame[1] = 0x7E;
	frame[2] = 0x00; //byte size 1
	frame[3] = 0x0E; //byte size 2
	frame[4] = 0x01; //project number
	frame[5] = 0x01; //program version
	frame[6] = 0x01; //file_num
	frame[7] = 0x07; //function num
	frame[8] = 0x01; //read
	frame[9] = 0x02; //msg
	frame[10] = 0x01; //data
	frame[11] = 0x01; //data
	frame[12] = 0x00; //data
	frame[13] = 0x00; //data
	frame[14] = 0x00; //data
	frame[15] = 0x00; //data
	frame[16] = 0x00; //data
	frame[17] = 0x00; //data
	frame[18] = 0xFF - crcApi(); //CRC
	frame[19] = 0x7D; // ending delimeter
	frame[20] = 0x7D; //ending delimeter
//		frame[21] = 0x0D;
	HAL_UART_Transmit(&huart3, (uint8_t*) frame, 21, 5000);

}
void function7_2() //write SD Card
{

	frame[0] = 0x7E;
	frame[1] = 0x7E;
	frame[2] = 0x00; //byte size 1
	frame[3] = 0x0E; //byte size 2
	frame[4] = 0x01; //project number
	frame[5] = 0x01; //program version
	frame[6] = 0x01; //file_num
	frame[7] = 0x07; //function num
	frame[8] = 0x02; //write
	frame[9] = 0x02; //Data[1];//msg
	frame[10] = 0x31; //Data[2];//data2
	frame[11] = 0x32; //Data[3];//data3
	frame[12] = 0x33; //Data[4];//data4
	frame[13] = 0x34; //Data[5];//data5
	frame[14] = 0x35; //Data[6];//data6
	frame[15] = 0x36; //Data[7];//data7
	frame[16] = 0x37; //Data[8];//data8
	frame[17] = 0x38; //Data[9];//data9
	frame[18] = 0x39; //Data[10];//data1
	frame[19] = 0x30; //Data[11];//data2
	frame[20] = 0x31; //Data[12];//data3
	frame[21] = 0x32; //Data[13];//data4
	frame[22] = 0x33; //Data[14];//data5
	frame[23] = 0x34; //Data[15];//data6
	frame[24] = 0x35; //Data[16];//data7
	frame[25] = 0x36; //Data[17];//data8
	frame[26] = 0x37; //Data[18];//data9
	frame[27] = 0x38; //Data[19];//data7
	frame[28] = 0x39; //Data[20];//data8
	frame[29] = 0x30; //Data[21];//data9
	frame[30] = 0x31; //Data[22];//data9
	frame[31] = 0xFF - crcApi(); //CRC
	frame[32] = 0x7D; // ending delimeter
	frame[33] = 0x7D; //ending delimeter
//		frame[21] = 0x0D;
	HAL_UART_Transmit(&huart3, (uint8_t*) frame, 34, 5000);

}

void function3_1() // read RTC
{

	frame[0] = 0x7E;
	frame[1] = 0x7E;
	frame[2] = 0x00; //byte size 1
	frame[3] = 0x0E; //byte size 2
	frame[4] = 0x01; //project number
	frame[5] = 0x01; //program version
	frame[6] = 0x01; //file_num
	frame[7] = 0x03; //function num
	frame[8] = 0x01; //read
	frame[9] = 0x00; //Day
	frame[10] = 0x00; //Month
	frame[11] = 0x00; //Year
	frame[12] = 0x00; //Hr
	frame[13] = 0x00; //Min
	frame[14] = 0x00; //data
	frame[15] = 0x00; //data
	frame[16] = 0x00; //data
	frame[17] = 0x00; //data
	frame[18] = 0xFF - crcApi(); //CRC
	frame[19] = 0x7D; // ending delimeter
	frame[20] = 0x7D; //ending delimeter
//		frame[21] = 0x0D;
	HAL_UART_Transmit(&huart3, (uint8_t*) frame, 21, 5000);

}

void function3_2() // write RTC
{

	frame[0] = 0x7E;
	frame[1] = 0x7E;
	frame[2] = 0x00; //byte size 1
	frame[3] = 0x0E; //byte size 2
	frame[4] = 0x01; //project number
	frame[5] = 0x01; //program version
	frame[6] = 0x01; //file_num
	frame[7] = 0x03; //function num
	frame[8] = 0x02; //write
	frame[9] = 0x01; //Day
	frame[10] = 0x02; //Month
	frame[11] = 0x13; //Year
	frame[12] = 0x0D; //Hr
	frame[13] = 0x14; //Min
	frame[14] = 0x00; //data
	frame[15] = 0x00; //data
	frame[16] = 0x00; //data
	frame[17] = 0x00; //data
	frame[18] = 0xFF - crcApi(); //CRC
	frame[19] = 0x7D; // ending delimeter
	frame[20] = 0x7D; //ending delimeter
//		frame[21] = 0x0D;
	HAL_UART_Transmit(&huart3, (uint8_t*) frame, 21, 5000);

}

int crcApi(void) {

	int zzzz = zxx9 + frame[3]; // have changed frame[3] to frame[5]
	int zyy9 = 0;
	int zxx9 = 4;           // have changed zxx9=4; to zxx9=6;
	zzzz = zxx9 + frame[3];
	while (zxx9 < zzzz) {
		zyy9 = zyy9 + frame[zxx9++];
	}

	return zyy9;

}

int crcApiResponse(void) {

	int zzzzRes = zxx9Res + frame[5]; // have changed frame[3] to frame[5]
	int zyy9Res = 0;
	int zxx9Res = 6;           // have changed zxx9=4; to zxx9=6;
	zzzzRes = zxx9Res + frame[5];
	while (zxx9Res < zzzzRes) {
		zyy9Res = zyy9Res + frame[zxx9Res++];
	}

	return zyy9Res;

}

void transferDataValues(int cnt) {
////int i=0;
//	   Data[cnt-3]=0x7E;
//	  // Data[cnt-2]=0x7E;
//cnt=cnt-1;
//  for(int i=1;i<38;i++){
//  // while(RecMsg1== '0x7D'){
//	   Data[i]=RecMsg1[cnt];
//	   cnt++;
//	   //i++;

	int i = 0;
	int counter;
//	   Data[cnt-3]=0x7E;
//	   cnt=cnt-1;
//	   Data[0]=0x7E;
//	   Data[1]=0x7E;
	counter = cnt - 2;
	while (!(RecMsg1[i] == 0x7D)) {
		Data[i] = RecMsg1[counter];
		i++;
		counter++;

	}
	Data[i++] = 0x7D;
//	   Data[i]=0x7D;
	cntVal = i;

}

void function6_2()           //write server
{

	frame[0] = 0x7E;
	frame[1] = 0x7E;
	frame[2] = 0x00;           //byte size 1
	frame[3] = 0x1B;           //byte size 2
	frame[4] = 0x01;           //project number
	frame[5] = 0x01;           //program version
	frame[6] = 0x01;           //file_num
	frame[7] = 0x06;           //function num
	frame[8] = 0x02;           //write
	frame[9] = Data[1];           //data1
	frame[10] = Data[2];           //data2
	frame[11] = Data[3];           //data3
	frame[12] = Data[4];           //data4
	frame[13] = Data[5];           //data5
	frame[14] = Data[6];           //data6
	frame[15] = Data[7];           //data7
	frame[16] = Data[8];           //data8
	frame[17] = Data[9];           //data9
	frame[18] = Data[10];           //data1
	frame[19] = Data[11];           //data2
	frame[20] = Data[12];           //data3
	frame[21] = Data[13];           //data4
	frame[22] = Data[14];           //data5
	frame[23] = Data[15];           //data6
	frame[24] = Data[16];           //data7
	frame[25] = Data[17];           //data8
	frame[26] = Data[18];           //data9
	frame[27] = Data[19];           //data7
	frame[28] = Data[20];           //data8
	frame[29] = Data[21];           //data9
	frame[30] = Data[22];           //data9
	frame[31] = 0xFF - crcApi();           //CRC
	frame[32] = 0x7D;           // ending delimeter
	frame[33] = 0x7D;           //ending delimeter
	//		frame[21] = 0x0D;
	HAL_UART_Transmit(&huart3, (uint8_t*) frame, 34, 5000);

}

void function6_1()   //read server
{

	frame[0] = 0x7E;
	frame[1] = 0x7E;
	frame[2] = 0x00;   //byte size 1
	frame[3] = 0x0E;   //byte size 2
	frame[4] = 0x01;   //project number
	frame[5] = 0x01;   //program version
	frame[6] = 0x01;   //file_num
	frame[7] = 0x06;   //function num
	frame[8] = 0x01;   //read
	frame[9] = Data[1];   //data1
	frame[10] = Data[2];   //data2
	frame[11] = Data[3];   //data3
	frame[12] = Data[4];   //data4
	frame[13] = Data[5];   //data5
	frame[14] = Data[6];   //data6
	frame[15] = Data[7];   //data7
	frame[16] = Data[8];   //data8
	frame[17] = Data[9];   //data9
	frame[18] = Data[10];   //data1
	frame[19] = Data[11];   //data2
	frame[20] = Data[12];   //data3
	frame[21] = Data[13];   //data4
	frame[22] = Data[14];   //data5
	frame[23] = Data[15];   //data6
	frame[24] = Data[16];   //data7
	frame[25] = Data[17];   //data8
	frame[26] = Data[18];   //data9
	frame[27] = Data[19];   //data7
	frame[28] = Data[20];   //data8
	frame[29] = Data[21];   //data9
	frame[30] = Data[22];   //data9
	frame[31] = 0xFF - crcApi();   //CRC
	frame[32] = 0x7D;   // ending delimeter
	frame[33] = 0x7D;   //ending delimeter
	//		frame[21] = 0x0D;
	HAL_UART_Transmit(&huart3, (uint8_t*) frame, 34, 5000);

}

void sendToUsart1() {
	uint8_t send[20];

	for (int i = 0; i < 18; i++) {
		send[i] = RecMsg4[i];

	}

//	HAL_UART_Transmit (&huart1, (uint8_t*)send,18,5000) ;

}

void outputPin() {

	uint8_t pinValue = 0xA5;
	uint8_t pinValue1 = 0xA5;
	if ((pinValue & 0x01) == 0x01) {
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);

	} else {
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
	}

	if ((pinValue & 0x02) == 0x02) {
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);

	} else {
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
	}

	if ((pinValue & 0x04) == 0x04) {
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);

	} else {
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
	}

	if ((pinValue & 0x08) == 0x08) {
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET);

	} else {
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);
	}

	if ((pinValue & 0x10) == 0x10) {
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_SET);

	} else {
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_RESET);
	}

	if ((pinValue & 0x20) == 0x20) {
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_SET);

	} else {
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_RESET);
	}
	if ((pinValue & 0x40) == 0x40) {
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);

	} else {
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);
	}

	if ((pinValue & 0x80) == 0x80) {
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_SET);

	} else {
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET);
	}
//-----------------------------------
	if ((pinValue1 & 0x01) == 0x01) {
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, GPIO_PIN_SET);

	} else {
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, GPIO_PIN_RESET);
	}
	if ((pinValue1 & 0x02) == 0x02) {
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_SET);

	} else {
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_RESET);
	}
	if ((pinValue1 & 0x04) == 0x04) {
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_SET);

	} else {
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_RESET);
	}
	if ((pinValue1 & 0x08) == 0x08) {
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_SET);

	} else {
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_RESET);
	}
	if ((pinValue1 & 0x10) == 0x10) {
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_SET);

	} else {
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_RESET);
	}
	if ((pinValue1 & 0x20) == 0x20) {
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_SET);

	} else {
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_RESET);
	}
	if ((pinValue1 & 0x40) == 0x40) {
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_SET);

	} else {
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_RESET);
	}
	if ((pinValue1 & 0x80) == 0x80) {
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_14, GPIO_PIN_SET);

	} else {
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_14, GPIO_PIN_RESET);
	}

}

void inputPin() {

	if (HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_4)) {
		state = 1;
	} else {
		state = 0;
	}
	if (HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_5)) {
		state = 1;
	} else {
		state = 0;
	}
	if (HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_6)) {
		state = 1;
	} else {
		state = 0;
	}
	if (HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_7)) {
		state = 1;
	} else {
		state = 0;
	}

	if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3)) {
		state = 1;
	} else {
		state = 0;
	}
	if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5)) {
		state = 1;
	} else {
		state = 0;
	}
	if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6)) {
		state = 1;
	} else {
		state = 0;
	}
	if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_7)) {
		state = 1;
	} else {
		state = 0;
	}

}

int function8() {

//	junctionId = 11;
//	programVersionNo = 71;
	fileNo = 111;

//	        frame[0] = 0x7E;
//		   	frame[1] = 0x7E;
	frame[0] = 0x7E;
	frame[1] = 0x7E;
	frame[2] = 0x00;   //byte size 1
	frame[3] = 66;   //byte size 2
	frame[4] = junctionId;   //junction id
	frame[5] = programVersionNo;   //program_version_number
	frame[6] = fileNo;   //file_num
	frame[7] = 0x08;   //function num
	frame[8] = Disp[0];   //side1
	frame[9] = Disp[1];   //side2
	frame[10] = Disp[2];   //side3
	frame[11] = Disp[3];   //side4

	frame[12] = 0;   //side5

	frame[13] = Disp[4];   //side13
	frame[14] =Disp[5];   //side24
	frame[15] =0;   //side5
	frame[16] =Disp[25];//readBytes[12];   //padestrainTime
	frame[17] = plan_ID;//Disp[25];//readBytes[0];   //planNumb
	frame[18] = Disp[25];//readBytes[1];   //planMode
	frame[19] = clearenceMode;
	frame[20] = sTime.Hours ;
	frame[21] = sTime.Minutes ;
	frame[22] = sDate.Date;
	frame[23] = sDate.Month;//'1'
	frame[24] = sDate.Year;//'0' ; //'5' ;
	frame[25] = phase_ID;

	frame[26] = 0x30;//primaryHorizontalByte[1];//aspectColorFeedback  HorizontalSide1
	frame[27] = primaryVerticalByte[1];//VerticalSide1
	frame[28] = secondaryHorizontalByte[1];//secondaryForSide1  HorizontalSide3
	frame[29] = secondaryVerticalByte[1];//VerticalSide3
	frame[30] = hundredPlaceSegment[1];
	frame[31] = tenPlaceSegment[1];
	frame[32] = unitPlaceSegment[1];

	frame[33] = primaryHorizontalByte[2]; //side2  HorizontalSide2
	frame[34] = primaryVerticalByte[2];//  VerticalSide2
	frame[35] = secondaryHorizontalByte[2];
	frame[36] = secondaryVerticalByte[2];
	frame[37] = hundredPlaceSegment[2];
	frame[38] = tenPlaceSegment[2];
	frame[39] = unitPlaceSegment[2];

	frame[40] = primaryHorizontalByte[3]; //side3
	frame[41] = primaryVerticalByte[3];
	frame[42] = secondaryHorizontalByte[3];
	frame[43] = secondaryVerticalByte[3];
	frame[44] = hundredPlaceSegment[3];
	frame[45] = tenPlaceSegment[3];
	frame[46] = unitPlaceSegment[3];

	frame[47] = primaryHorizontalByte[4]; //side4
	frame[48] = primaryVerticalByte[4];
	frame[49] = secondaryHorizontalByte[4];
	frame[50] = secondaryVerticalByte[4];
    frame[51] = hundredPlaceSegment[4];
    frame[52] = tenPlaceSegment[4];
    frame[53] = unitPlaceSegment[4];

	frame[54] = primaryHorizontalByte[5]; //side5
	frame[55] = primaryVerticalByte[5];
	frame[56] = secondaryHorizontalByte[5];
	frame[57] = secondaryVerticalByte[5];
    frame[58] = hundredPlaceSegment[5];
    frame[59] = tenPlaceSegment[5];
    frame[60] = unitPlaceSegment[5];

    frame[61] =powerStatus;
    frame[62] =communicationStatus;
    frame[63] =mapIDForCurrentPhases;//side5
    frame[64] =1;
    frame[65] =1;
    frame[66] =1;
    frame[67] =1;
    frame[68] =1;//TBD
    frame[69] =1;
	frame[70] = 0xFF - crcApi();   //crcApiResponse();//CRC
	frame[71] = 0x7D;   // ending delimeter
	frame[72] = 0x7D;   //ending delimeter
	frame[73] = 0x0D;   // ending delimeter
    frame[74] = 0x0A;   //ending delimeter

//	frame[38] = 0x7D;   //ending delimeter

	HAL_UART_Transmit(&huart3, (uint8_t*) frame, 72, 5000); //For ESP
	HAL_UART_Transmit(&huart1, (uint8_t*) frame, 72, 5000); //For BLE

	clearPrimaryAndSecByte();
//	slave4Rsp=0;
//	HAL_UART_Receive(&huart4, (uint8_t *) aRxBuffer, 29, 0x3FF);
////	HAL_Delay(300);
//	signVal = msgParse((uint8_t *) aRxBuffer, "~~~~", 0);
//
//	if (!(signVal == 0)) {
//		if (aRxBuffer[signVal + (aRxBuffer[signVal + 1]) + 2] + crcApi3(signVal)
//						== 0xFF) {
//
//			if (!(aRxBuffer[signVal+3]==programVersionNo))
//			{
////			 imei[29]=2;
//
//		// 		function1();
//		// 		function4();
//		// 		function42();
//
//			}
//
//			signVal =signVal+3 ;
//		if (!(aRxBuffer[signVal++]==programVersionNo))
//		 programVersionNo=aRxBuffer[signVal]-1;
//			signVal =signVal+2 ;
//
//		if (aRxBuffer[signVal++]==1)
//		if (aRxBuffer[signVal++]==1)
//		if (aRxBuffer[signVal++]==1)
//		if (aRxBuffer[signVal++]==1)
//		{
//			clearenceMode=1;
////			checkServerJumpExtend=0;
////		GPIOA->BSRR = GPIO_Pin_4;
//			return 1 ;			// Reset msg receive counter
//
//
//		}
//		 	if (!(aRxBuffer[7]==programVersionNo))
//		 		{
//		 		program3();
////					checkServerJumpExtend=0;
//		 		}
//			if (aRxBuffer[9]==8)
//		//		clearenceMode=RxBuffer[10];
//			if ((!(aRxBuffer[10]==1)))
//			{
////				checkServerJumpExtend=0;
//				//----------------------------For Shutdown---------------//
//				if (aRxBuffer[10]==5)
//			{
////				GPIOA->BRR = GPIO_Pin_4;//set bit as high
//				clearenceMode=9;
//				clearenceSide=aRxBuffer[11];
//				return 1 ;
//			}
//			else{
////			GPIOA->BSRR = GPIO_Pin_4;
//
//			}
//					//----------------------------For ChangeMode---------------//
//				if (aRxBuffer[10]==3)
//			{
//				//GPIOA->BRR = GPIO_Pin_4;//set bit as high
//				//if()
//				changeMode=1;
//				if(planMode==3){
//					planMode=1;}
//					if(planMode==1){
//					planMode=3;
//					}
//				//clearenceSide=RxBuffer[11];
//				return 1 ;
//			}
//
//
//
//				//----------------------------For  extend---------------//
//
//
//
//			if (aRxBuffer[10]==6) // extend request
//			{clearenceMode=aRxBuffer[10];
//				clearenceSide=aRxBuffer[11];
////				checkServerJumpExtend=1;
//				return 1 ;
//			}
//
//			//----------------------------For  clearance---------------//
//			if (aRxBuffer[10]==2)
//			{clearenceMode=aRxBuffer[10];
//				clearenceSide=aRxBuffer[11];
//				return 1 ;
//			}
//
//
//
//
//			}
//			//----------------------------For  jump---------------//
//			if (aRxBuffer[10]==4) // jump request
//			{
//				clearenceMode=4;
////				checkServerJumpExtend=1;
//				return 1 ;
//			}
//
//
//		clearBuffer4();
//		}
//
//	}
	return 0 ;

}
/*----------------------- registration function----------------------------------*/
int function1()   // check registration
{
	clearframe();
	frame[0] = 126;
	frame[1] = 126;
	frame[2] = 00;   //byte size 1
	frame[3] = 31;   //byte size 2
	frame[4] = junctionId;   // 127 ;//
	frame[5] = programVersionNo;   // 127 ;//
	frame[6] = fileNo;
	frame[7] = 1;   //function no
	frame[8] = '0';
	frame[9] = '1';
	frame[10] = '3';
	frame[11] = '7';
	frame[12] = '7';
	frame[13] = '7';
	frame[14] = '0';
	frame[15] = '0';
	frame[16] = '0';
	frame[17] = '6';
	frame[18] = '2';
	frame[19] = '0';
	frame[20] = '9';   //'1'
	frame[21] = '1';   //'0' ; //'5' ;
	frame[22] = '5';   // '2' ;//'9' ;//'1' ;

	frame[23] = 1;
	frame[24] = 1;
	frame[25] = 1;
	frame[26] = 1;
	frame[27] = 1;
	frame[28] = 1;
	frame[29] = 1;
	frame[30] = 1;
	frame[31] = 1;
	frame[32] = 1;   //'1'
	frame[33] = 1;   //'0' ; //'5' ;
	frame[34] = 1;   // '2' ;//'9' ;//'1' ;
	frame[35] = 0xFF - crcApi();
	frame[36] = 125;
	frame[37] = 125;
//	frame[38] = 125;
//		frame[21] = 0x0D;
	HAL_UART_Transmit(&huart3, (uint8_t*) frame, 37, 5000);
	HAL_UART_Receive(&huart3, (uint8_t *) aRxBuffer, 40, 0x2FFF);
	HAL_Delay(300);
	signVal = msgParse((uint8_t *) aRxBuffer, "~~~~", 0);


	if (!(signVal == 0)){

		if (aRxBuffer[signVal + (aRxBuffer[signVal + 1]) + 2] + crcApi3(signVal)
				== 0xFF) {
//				if(aRxBuffer[signVal] != 0x00)
//						{

//				signVal=signVal+3;
			signVal = signVal + 2;
			/*-----------------flash--------------------*/
//			junctionId = aRxBuffer[signVal];
//			signVal = signVal + 1;
//			programVersionNo = aRxBuffer[signVal];
//			signVal = signVal + 1;
//			fileNo = aRxBuffer[signVal];
//			signVal = signVal + 3;
//			noOfSides = aRxBuffer[signVal];
//			signVal = signVal + 1;
//			noOfPlans = aRxBuffer[signVal];
//			signVal = signVal + 1;
//			padestarianTime = aRxBuffer[signVal];
int j=0;
			for (int i = 0; i < 14; i++) {
				    bytesToWriteInSD[j]=aRxBuffer[signVal+i];
				    j++;
				    if(i==2)
				    {
				    	i=i+1;
				    }
						}
			//--------------------------SD Card Write----------------------//
//			SDcardWrite("info.txt",6,(uint8_t *)bytesToWrite);
//			 seek("info.txt",0);
			SDcardWriteSeek("info.txt", 13, (uint8_t *) bytesToWriteInSD, 0);
				SDcardReadSeek("info.txt", 15, 0);

			           junctionId = readBytes[0];
//			           junctionId = 13;
			           programVersionNo = readBytes[1];
			           fileNo = readBytes[2];

			            noOfSides = readBytes[4];

						noOfPlans = readBytes[5];

						padestarianTime = readBytes[6];

						side1PoleType= readBytes[7]; // 1= standard ,2= l Cantilever,3= T cantilever pole
						side2PoleType= readBytes[8];
						side3PoleType= readBytes[9];
						side4PoleType= readBytes[10];
						side5PoleType= readBytes[11];


//			//--------------------------flash write------------------------//
//
//			HAL_FLASH_Unlock();
//			FLASH_Erase_Sector(FLASH_SECTOR_1, FLASH_VOLTAGE_RANGE_3);
//			HAL_FLASH_Program(TYPEPROGRAM_BYTE, Address, junctionId);
//			Address = Address + 4;
//			HAL_FLASH_Program(TYPEPROGRAM_BYTE, Address, programVersionNo);
//			Address = Address + 4;
//			HAL_FLASH_Program(TYPEPROGRAM_BYTE, Address, fileNo);
//			Address = Address + 4;
//			HAL_FLASH_Program(TYPEPROGRAM_BYTE, Address, aRxBuffer[10]); //registration status
//			Address = Address + 4;
//			HAL_FLASH_Program(TYPEPROGRAM_BYTE, Address, noOfSides); //no of sides
//			Address = Address + 4;
//			HAL_FLASH_Program(TYPEPROGRAM_BYTE, Address, noOfPlans); //no of plans
//			Address = Address + 4;
//			HAL_FLASH_Program(TYPEPROGRAM_BYTE, Address, padestarianTime); //padestarianTime


//----------------------------------junction name ----------------------------------//
//			junctionName[0] = 'a';
//			junctionName[1] = 'b';
//			junctionName[2] = 'a';
//			junctionName[3] = 'a';
//			junctionName[4] = 'a';
//			junctionName[5] = 'a';
//			junctionName[6] = 'a';
//			junctionName[7] = 'a';
//			junctionName[8] = 'a';
//			junctionName[9] = 'a';
//			junctionName[10] = 'a';
//			junctionName[11] = 'z';
//			junctionName[12] = 'a';
//			junctionName[13] = 'a';
//			junctionName[14] = 'w';
//
//			Address = Address + 4;
//			for (int i = 0; i < 15; i++) {
//				HAL_FLASH_Program(TYPEPROGRAM_BYTE, Address, junctionName[i]);
//				Address = Address + 4;
//			}
////--------------------------------side1--------------------------------//
//			side1[0] = 'a';
//			side1[1] = 'b';
//			side1[2] = 'a';
//			side1[3] = 'a';
//			side1[4] = 'a';
//			side1[5] = 'a';
//			side1[6] = 'a';
//			side1[7] = 'a';
//			side1[8] = 'a';
//			side1[9] = 'a';
//			side1[10] = 'a';
//			side1[11] = 'z';
//			side1[12] = 'a';
//			side1[13] = 'a';
//			side1[14] = 'o';
//			for (int i = 0; i < 15; i++) {
//				HAL_FLASH_Program(TYPEPROGRAM_BYTE, Address, side1[i]);
//				Address = Address + 4;
//			}
////-------------------------------side2--------------------------------//
//			for (int i = 0; i < 15; i++) {
//				HAL_FLASH_Program(TYPEPROGRAM_BYTE, Address, side2[i]);
//				Address = Address + 4;
//			}
////-------------------------------side3--------------------------------//
//			for (int i = 0; i < 15; i++) {
//				HAL_FLASH_Program(TYPEPROGRAM_BYTE, Address, side3[i]);
//				Address = Address + 4;
//			}
////-------------------------------side4--------------------------------//
//			for (int i = 0; i < 15; i++) {
//				HAL_FLASH_Program(TYPEPROGRAM_BYTE, Address, side4[i]);
//				Address = Address + 4;
//			}
////-------------------------------side5--------------------------------//
//			side5[0] = 'a';
//			side5[1] = 'b';
//			side5[2] = 'a';
//			side5[3] = 'a';
//			side5[4] = 'a';
//			side5[5] = 'a';
//			side5[6] = 'a';
//			side5[7] = 'a';
//			side5[8] = 'a';
//			side5[9] = 'a';
//			side5[10] = 'a';
//			side5[11] = 'z';
//			side5[12] = 'a';
//			side5[13] = 'a';
//			side5[14] = 'o';
//			for (int i = 0; i < 15; i++) {
//				HAL_FLASH_Program(TYPEPROGRAM_BYTE, Address, side5[i]);
//				Address = Address + 4;
//			}
////			HAL_FLASH_Lock();
//				Address=Address+24;

			clearaRxBuffer();
			clearBuffer4();
			function1_1();
			return 1;
//				}
//				else{
//				clearaRxBuffer();
//				return 0;
//				}

		}} else {
			clearBuffer4();
			clearaRxBuffer();
			return 0;
		}

}

int function1_1()   // check registration
{
	clearframe();
	frame[0] = 126;
	frame[1] = 126;
	frame[2] = 00;   //byte size 1
	frame[3] = 34;   //byte size 2
	frame[4] = junctionId;   // 127 ;//
	frame[5] = programVersionNo;   // 127 ;//
	frame[6] = fileNo;
	frame[7] = 1;   //function no
	frame[8] = '0';
	frame[9] = '1';
	frame[10] = '3';
	frame[11] = '7';
	frame[12] = '7';
	frame[13] = '7';
	frame[14] = '0';
	frame[15] = '0';
	frame[16] = '0';
	frame[17] = '6';
	frame[18] = '2';
	frame[19] = '0';
	frame[20] = '9';   //'1'
	frame[21] = '1';   //'0' ; //'5' ;
	frame[22] = '5';   // '2' ;//'9' ;//'1' ;
	frame[23] = noOfSides;
	frame[24] = noOfPlans;
	frame[25] = padestarianTime;

	frame[26] = side1PoleType;
	frame[27] = side2PoleType;
	frame[28] = side3PoleType;
	frame[29] = side4PoleType;
	frame[30] = side5PoleType;
	frame[31] = '1';
	frame[32] = '1';
	frame[33] = '1';
	frame[34] = '1';
	frame[35] = '1';   //'1'
	frame[36] = '1';   //'0' ; //'5' ;
	frame[37] = '1';   // '2' ;//'9' ;//'1' ;

	frame[38] = 0xFF - crcApi();
	frame[39] = 125;
	frame[40] = 125;
//		frame[21] = 0x0D;
	HAL_UART_Transmit(&huart3, (uint8_t*) frame, 40, 5000);
	HAL_UART_Receive(&huart3, (uint8_t *) aRxBuffer, 70, 0x2FFF);
	HAL_Delay(300);
	signVal = msgParse((uint8_t *) aRxBuffer, "~~~~", 0);

	if (!(signVal == 0)) {
		clearaRxBuffer();
		clearBuffer4();
		return 0;

	} else {
		clearaRxBuffer();
		clearBuffer4();
		return 0;
	}

}
/*------------------------------------getting plan info--------------------------------------*/
int function4(void) {
	int resmsg = 0;
	int seekCnt=0;
	for (int i = 1; i < noOfPlans + 1;) {
		if (resmsg == 1) {
			planNo = i;
			i++;
		}
		if (i == 1) {
			planNo = i;
			i++;
		}
		clearframe();
//msg_processed = 0 ;     //Raise flag to indicate a msg to be processed by main is present
//RxCount = 0 ;			// Reset msg receive counter
//
//flag  = 0 ;
//// puts1("AT+CIPSEND\r\n",11);
//// delay(9800000);
////    signVal = msgParse(RxBuffer,"T\r\r\nOK",0);
		frame[0] = 126;
		frame[1] = 126;
		frame[2] = 0; // function no
		frame[3] = 17;
		frame[4] = junctionId; // junction no
		frame[5] = programVersionNo; // junction no
		frame[6] = fileNo; // junction no
		frame[7] = 4; // function no
		frame[8] = planNo;  // plan no

		frame[9] = 0;
		frame[10] = 0;
		frame[11] = 0;
		frame[12] = 0;
		frame[13] = 0;
		frame[14] = 0;
		frame[15] = 0;
		frame[16] = 0;
		frame[17] = 0;
		frame[18] = 0;  //'1'
		frame[19] = 0;  //'0' ; //'5' ;
		frame[20] = 0;  // '2' ;//'9' ;//'1' ;

		frame[21] = 0xFF - crcApi();  // junction no
		frame[22] = 125;
		frame[23] = 125;
		HAL_UART_Transmit(&huart3, (uint8_t*) frame, 23, 5000);
		HAL_UART_Receive(&huart3, (uint8_t *) aRxBuffer, 50, 0x1FFF);
//		HAL_Delay(300);
//		signVal = msgParse((uint8_t *) aRxBuffer, "~~~~", 0);

//		while (!(aRxBuffer[signVal] == 126)) {
//			signVal = signVal + 1;
//			if(!(aRxBuffer[signVal] == 126))
//							break;
//		}
		HAL_Delay(900);
		signVal=4;
		if (!(signVal == 0)){
			if (aRxBuffer[signVal + (aRxBuffer[signVal + 1]) + 2]
					+ crcApi3(signVal) == 0xFF) {
//				if((aRxBuffer[signVal]==126)){
//					signVal=signVal+1;
//				}

				signVal = signVal + 2;
				if ((aRxBuffer[signVal] == junctionId)) {
					signVal = signVal + 3;
					if ((aRxBuffer[signVal] == 4))
						signVal = signVal + 1;
					if ((aRxBuffer[signVal] == planNo))

					{

						string[0] = aRxBuffer[signVal];  //planNo
						// 	fnData[0] = RxBuffer[6] ;// junctiond id
						signVal = signVal + 1;
						string[1] = aRxBuffer[signVal];			// on time hour
						if (string[1] == 0x6F)
							string[1] = 0;
						signVal = signVal + 1;
						string[2] = aRxBuffer[signVal];			// on time min
						if (string[2] == 0x6F)
							string[2] = 0;
						signVal = signVal + 1;
						for (int i = 0; i < 15; i++) {
							string[3 + i] = aRxBuffer[signVal];
							signVal++;
						}

//						signVal = signVal + 1;
					string[17] = 0xFF ;//
//					byteToInteger(0);
//					eepromData[planNo*4+4]=stringInt[0];


						//-------------------------SD card write-----------------------//
						SDcardWriteSeek("plan.txt", 18, (uint8_t *) string, seekCnt);
						SDcardReadSeek("plan.txt", 100, 0);
						seekCnt=seekCnt+18;
//						seek("plan.txt",seekCnt);
//						SDcardWriteSeek("plan.txt",17,(uint8_t *)string);
//						//--------------------------flash write------------------------//
//						HAL_FLASH_Unlock();
////						Address = Address + 4;
//						for (int i = 0; i < 17; i++) {
////						FLASH_Erase_Sector(FLASH_SECTOR_1,FLASH_VOLTAGE_RANGE_3);
//							HAL_FLASH_Program(TYPEPROGRAM_BYTE, Address,
//									string[i]);
//							Address = Address + 4;
//
//						}
//						HAL_FLASH_Lock();
//						//--------------------------flash write------------------------//
						clearaRxBuffer();
						clearBuffer4();
						resmsg = 1;
//						Address=Address+4;
//						return 1 ;

					}
				}
			} }else {
				i = i - 1;
				resmsg = 0;
				clearaRxBuffer();
				clearBuffer4();
				return 0;
			}

	}
	clearaRxBuffer();
	return 1;
}
/*---------------------------------------validate plan info with server----------------------------------*/
int function42(void) {
//	Address=0x080065C8;
//	noOfPlans=3;
	int seekCnt=0;
	for (int i = 1; i < noOfPlans + 1; i++) {
		planNo = i;

		clearframe();
/*-------------------read data from memory ---------------------------*/
//		readMem();// for flash
		clearReadBytes();
		SDcardReadSeek("plan.txt", 18, seekCnt);
		seekCnt=seekCnt+18;
//		for (int i = 1; i < 18;i++) {
//			Flash_Data[i]=readBytes[i];
//		}

/*-----------send frames-------------------------*/
		frame[0] = 126;
		frame[1] = 126;
		frame[2] = 0; // function no
		frame[3] = 32;
		frame[4] = junctionId; // function no
		frame[5] = programVersionNo; // junction no
		frame[6] = fileNo; // junction no
		frame[7] = 4; // function no
		frame[8] = planNo;  // plan no planOnHr
		frame[9] = readBytes[1];  // plan no
		frame[10] = readBytes[2];  // plan no
		frame[11] = readBytes[3];  // plan no
		frame[12] = readBytes[4];  // plan no
		frame[13] = readBytes[5];  // plan no
		frame[14] = readBytes[6];  // plan no
		frame[15] = readBytes[7];  // plan no
		frame[16] = readBytes[8];  // plan no
		frame[17] = readBytes[9];  // plan no
		frame[18] = readBytes[10];// plan no
		frame[19] = readBytes[11];  // plan no
		frame[20] = readBytes[12];  // plan no
		frame[21] = readBytes[13];  // plan no
		frame[22] = readBytes[14];  // plan no
		frame[23] = readBytes[15];  // plan no

		frame[24] = readBytes[16];
		frame[25] = '1';
		frame[26] = '1';
		frame[27] = '1';
		frame[28] = '1';
		frame[29] = '1';
		frame[30] = '1';
		frame[31] = '1';
		frame[32] = '1';
		frame[33] = '1';  //'1'
		frame[34] = '1';  //'0' ; //'5' ;
		frame[35] = '1';  // '2' ;//'9' ;//'1' ;

		frame[36] = 0xFF - crcApi();  // junction no
		frame[37] = 125;
		frame[38] = 125;
		clearBuffer();
		HAL_UART_Transmit(&huart3, (uint8_t*) frame, 38, 5000);
		HAL_UART_Receive(&huart3, (uint8_t *) aRxBuffer, 70, 0x1FFF);
		HAL_Delay(300);
		signVal = msgParse((uint8_t *) aRxBuffer, "~~~~", 0);

//signVal = msgParse(aRxBuffer,"~~~~",0);
		while (aRxBuffer[signVal] == 126) {
			signVal = signVal + 1;
			if(!(aRxBuffer[signVal] == 126))
				break;
		}
		signVal=4;
		if (!(signVal == 0))
			if (aRxBuffer[signVal + (aRxBuffer[signVal + 1]) + 2]
					+ crcApi3(signVal) == 0xFF) {
				signVal = signVal + 2;

				if ((aRxBuffer[signVal] == junctionId))
					if ((aRxBuffer[signVal + 3] == 4))
						if ((aRxBuffer[signVal + 4] == planNo))

						{
							{



							}

						}
				clearBuffer4();
				clearaRxBuffer();
			}
		clearBuffer4();
		clearaRxBuffer();
	}
	clearaRxBuffer();
	clearBuffer4();
	return 1;
}
void readMem() {
	clearFlashDataBuffer();

	if (junctionId == 111) {
//		Address = 0x08006440;
		Address = 0x08006340;

		junctionId = *(__IO uint8_t*) Address;
		Address = Address + 4;
		programVersionNo = *(__IO uint8_t*) Address;
		Address = 0x080065C8;

	}

	for (int i = 0; i < 17; i++) {
		Flash_Data[i] = *(__IO uint8_t*) Address;
		Address = Address + 4;
//		dataToWrite++;
	}
//	Address=Address+4;
//	Address = Address + 4;

}
void readMemSD(int cnt){
	clearReadBytes();
	SDcardReadSeek("plan.txt", 18, cnt);




}
void readDateSD(int cnt){
	clearReadBytes();
	SDcardReadSeek("date.txt", 18, cnt);




}

void readDaySD(int cnt){
	clearReadBytes();
	SDcardReadSeek("day.txt", 100, cnt);




}
void readPlanSD(int cnt){
	clearReadBytes();
	SDcardReadSeek("planN.txt", 19, cnt);




}


void readPhaseSD(int cnt){
	clearReadBytes();
	SDcardReadSeek("phase.txt", 15, cnt);




}
void readPhase() {
	clearFlashDataBuffer();
	for (int i = 0; i < 14; i++) {
		Flash_Data[i] = *(__IO uint8_t*) Address;
		Address = Address + 4;
		//		dataToWrite++;
	}
	Address = Address + 4;
//	Address = Address + 4;
}
int function2(void) {

	frame[0] = 126;
	frame[1] = 126;
	frame[2] = 00;
	frame[3] = 7;
	frame[4] = junctionId;
	frame[5] = programVersionNo;
	frame[6] = fileNo;
	frame[7] = 1;  //function no
	frame[8] = noOfSides;
	frame[9] = noOfPlans;
	frame[10] = padestarianTime;
	frame[11] = 0xFF - crcApi();
	frame[12] = 125;
	frame[13] = 125;
	HAL_UART_Transmit(&huart3, (uint8_t*) frame, 14, 5000);
	HAL_UART_Receive(&huart3, (uint8_t *) aRxBuffer, 70, 0x1FFF);
	HAL_Delay(300);
	signVal = msgParse((uint8_t *) aRxBuffer, "~~~~", 0);

	if (!(signVal == 0))
		if (aRxBuffer[signVal + (aRxBuffer[signVal + 1]) + 2] + crcApi2(signVal)
				== 0xFF) {
			if (!(aRxBuffer[signVal + 6] == 2)) {

				return 0;
			}
			return 0;
// 	signVal =signVal+2 ;
// 	if (!(RxBuffer[signVal]==111))
// 	if (RxBuffer[signVal+1]==1)

// 		// 	fnData[0] = RxBuffer[6] ;// junctiond id
//
// 		string[0]=RxBuffer[signVal];//junction id
// 		junctionId=RxBuffer[signVal];
// 		string[1]=RxBuffer[signVal+2];//no of sides
// 		registrationStatus=RxBuffer[signVal+2];
// 		string[2]=RxBuffer[signVal+3];//no of sides
// 		noOfSides=RxBuffer[signVal+3];
// 		string[3]=RxBuffer[signVal+4];// no of plans
// 		noOfPlans=RxBuffer[signVal+4];
// 		byteToInteger(0);
// 		eepromData[0]=stringInt[0];
//
// 		string[0]=RxBuffer[signVal+5];// program version no
// 		padestarianTime=RxBuffer[signVal+5];
// 		string[1]=RxBuffer[signVal+6];//junction id
// 		programVersionNo=RxBuffer[signVal+6];
// 		string[2]=RxBuffer[signVal+7];//no of sides
// 		string[3]=RxBuffer[signVal+7];// no of plans
// 		byteToInteger(0);
// 		eepromData[1]=stringInt[0];
//

		}
	return 1;
}

/*---------------------------------time check function---------------------------------------*/
int function9(void) {
//	junctionId=1;
//	programVersionNo=71;
	/* Get the RTC current Time */
	HAL_RTC_GetTime(&hrtc, &sTime, FORMAT_BIN);
	/* Get the RTC current Date */
	HAL_RTC_GetDate(&hrtc, &sDate, FORMAT_BIN);

	frame[0] = 126;
	frame[1] = 126;
	frame[2] = 0; // function no
	frame[3] = 21;
	frame[4] = junctionId;
	frame[5] = programVersionNo; // junction no
	frame[6] = fileNo; // junction no
	frame[7] = 9;
	frame[8] = sTime.Hours;
	frame[9] = sTime.Minutes;
	frame[10] = sDate.Date;
	frame[11] = sDate.Month;
	frame[12] = 12;

	frame[13] = '1';
	frame[14] = '1';
	frame[15] = '1';
	frame[16] = '1';
	frame[17] = '1';
	frame[18] = '1';
	frame[19] = '1';
	frame[20] = '1';
	frame[21] = '1';
	frame[22] = '1'; //'1'
	frame[23] = '1'; //'0' ; //'5' ;
	frame[24] = '1'; // '2' ;//'9' ;//'1' ;

	frame[25] = 0xFF - crcApi();
	frame[26] = 125;
	frame[27] = 125;
//	frame[28]=0 ;

	if(programFromBLE==1)
	{
		HAL_UART_Transmit(&huart1, (uint8_t*) frame, 27, 5000);
		HAL_UART_Receive(&huart1, (uint8_t *) aRxBuffer, 40, 0x2FFF);
	}
	else
	{

	HAL_UART_Transmit(&huart3, (uint8_t*) frame, 27, 5000);
	HAL_UART_Receive(&huart3, (uint8_t *) aRxBuffer, 70, 0x1FFF);

	}
	HAL_Delay(300);
	signVal = msgParse((uint8_t *) aRxBuffer, "~~~~", 0);

//	while (aRxBuffer[signVal] == 126) {
//		signVal = signVal + 1;
//		if(!(aRxBuffer[signVal] == 126))
//						break;
//	}

//	if (!(signVal == 0))
	signVal=4;
//if (aRxBuffer[signVal+(aRxBuffer[signVal+1])+2]+crcApi2(signVal)==0xFF)
		if (aRxBuffer[signVal + (aRxBuffer[signVal + 1]) + 2] + crcApi3(signVal)
				== 0xFF)
		{

			signVal = signVal + 4;


			sTime.Hours = aRxBuffer[signVal + 2]; // current hour
			sTime.Minutes =aRxBuffer[signVal + 3]; // current min
			sDate.Date = aRxBuffer[signVal + 4]; // current date
			sDate.Month = aRxBuffer[signVal + 5]; // current month
			sDate.Year = aRxBuffer[signVal + 6];	// current year
			sDate.WeekDay=aRxBuffer[signVal + 8];	// current weekday

			HAL_RTC_SetTime(&hrtc, &sTime, FORMAT_BIN);
			HAL_RTC_SetDate(&hrtc, &sDate, FORMAT_BIN);


			  /*---------get the date and update the DateLast variable---start----*/
			   HAL_RTC_GetDate(&hrtc, &sDate, FORMAT_BIN);
			   DateLast=sDate.Date;
			   /*---------get the date and update the DateLast variable--end-----*/




			string[1] = aRxBuffer[signVal + 7];	// current clock sync status
			clearBuffer3();
				clearaRxBuffer();
				HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_4);
			return 1;
		}
	clearBuffer3();
	clearaRxBuffer();
//	return 1;
}
void planDetail(int planNo) {

	 if(returnMode==1)
	     return ;
	switch (planNo) {
		case 1:
			Address = 0x080065C8;
			break;
		case 2:
			Address = 0x0800660C;
			break;
		case 3:
			Address = 0x08006650;
			break;
		case 4:
			Address = 0x08006694;
			break;
		case 5:
			Address = 0x080066D8;
			break;
		case 6:
			Address = 0x0800671C;
			break;
		case 7:
			Address = 0x08006760;
			break;
		case 8:
			Address = 0x080067A4;
			break;
		case 9:
			Address = 0x080067E8;
			break;
		case 10:
			Address = 0x0800682C;
			break;
		case 11:
			Address = 0x08006870;
			break;
		case 12:
			Address = 0x080068B4;
			break;
		case 13:
			Address = 0x080068F8;
			break;
		case 14:
			Address = 0x0800693C;
			break;
		case 15:
			Address = 0x08006980;
			break;
		case 16:
	//Address=0x08080004 ;
			break;

		}
		planOnHr = *(__IO uint8_t*) (Address);
		Address = Address + 4;
		planOnM = *(__IO uint8_t*) (Address);
		Address = Address + 4;
		planOffHr = *(__IO uint8_t*) (Address);
		Address = Address + 4;
		planOffM = *(__IO uint8_t*) (Address);
		Address = Address + 4;
		planS1GT = *(__IO uint8_t*) (Address);
		Address = Address + 4;
		planS2GT = *(__IO uint8_t*) (Address);
		Address = Address + 4;
		planS3GT = *(__IO uint8_t*) (Address);
		Address = Address + 4;
		planS4GT = *(__IO uint8_t*) (Address);
		Address = Address + 4;
		planS5GT = *(__IO uint8_t*) (Address);
	    Address = Address + 4;
		planA1GT = *(__IO uint8_t*) (Address);
		Address = Address + 4;
		planA2GT = *(__IO uint8_t*) (Address);
		Address = Address + 4;
		planA3GT = *(__IO uint8_t*) (Address);
		Address = Address + 4;
		planA4GT = *(__IO uint8_t*) (Address);
		Address = Address + 4;
		planA5GT = *(__IO uint8_t*) (Address);
		Address = Address + 4;
		planMode = *(__IO uint8_t*) (Address);
		Address = Address + 4;
		noOfPhase = *(__IO uint8_t*) (Address);
		totalPhase=noOfPhase;
		if (planMode == 1 )
			blinker();
		else
			signal();
}
int planDetailSD(int planNo) {



//			getPhaseSD(planNo);//get plan no and no of phases

//		planOnHr = readBytes[1];
//		planOnM = readBytes[2];
//		planOffHr = readBytes[3];
//		planOffM = readBytes[4];
//		planS1GT = readBytes[5];
//		planS2GT = readBytes[6];
//		planS3GT = readBytes[7];
//		planS4GT = readBytes[8];
//		planS5GT = readBytes[9];
//		planA1GT = readBytes[10];
//		planA2GT = readBytes[11];
//		planA3GT = readBytes[12];
//		planA4GT = readBytes[13];
//		planA5GT = readBytes[14];
//		planMode = readBytes[15];
//		noOfPhase = readBytes[16];
//		totalPhase=noOfPhase;
	/*--------------after changes of day and date---------------*/
	incCnt=incCnt-19;
	plan_ID = planDetailsArray[incCnt+1];
	planOnHr = planDetailsArray[incCnt+2];
	planOnM = planDetailsArray[incCnt+3];
	planOffHr = planDetailsArray[incCnt+4];
	planOffM = planDetailsArray[incCnt+5];
	planS1GT = planDetailsArray[incCnt+6];
	planS2GT = planDetailsArray[incCnt+7];
	planS3GT = planDetailsArray[incCnt+8];
	planS4GT = planDetailsArray[incCnt+9];
	planS5GT = planDetailsArray[incCnt+10];
	planA1GT = planDetailsArray[incCnt+11];
	planA2GT = planDetailsArray[incCnt+12];
	planA3GT = planDetailsArray[incCnt+13];
	planA4GT = planDetailsArray[incCnt+14];
	planA5GT = planDetailsArray[incCnt+15];
	planMode = planDetailsArray[incCnt+16];
	noOfPhase = planDetailsArray[incCnt+17];
	totalPhase=noOfPhase;
	getCurrentPlanTotalNoOfPhases(); //get the total no of phases in current dat/date plan and save it in phaseList[].
	getCurrentPlanPhases();
		if (planMode == 1 )
			blinker();
		else
			signal();

		 if(returnMode==1)
			     return 1 ;

		 if(isReprogrammed==1)
			 return 1;
}



void function4Response(void) {
	signVal = signVal + 2;

	if ((RecMsg4[signVal] == junctionId))
		if ((RecMsg4[signVal + 3] == 4))
			if ((RecMsg4[signVal + 4] == planNo)) {

				signalData[0] = RecMsg4[signVal + 5];	// on time hour
				if (signalData[0] == 0x6F)
					signalData[0] = 0;
				signalData[1] = RecMsg4[signVal + 6];	// on time min
				if (signalData[1] == 0x6F)
					signalData[1] = 0;
				signalData[2] = RecMsg4[signVal + 7];	// off time hour
				signalData[3] = RecMsg4[signVal + 8];	// off time min

//				byteToInteger(0);
//				eepromData[planNo*4+1]=stringInt[0];

				signalData[4] = RecMsg4[signVal + 9];	// side1 green time
				signalData[5] = RecMsg4[signVal + 10];	// side2 green time
				signalData[6] = RecMsg4[signVal + 11];	// side3 green time
				signalData[7] = RecMsg4[signVal + 12];	// side4 green time
//				byteToInteger(0);
//				eepromData[planNo*4+2]=stringInt[0];

				signalData[8] = RecMsg4[signVal + 14];	// side1 amber time
				signalData[9] = RecMsg4[signVal + 15];	// side2 amber time
				signalData[10] = RecMsg4[signVal + 16];	// side3 amber time
				signalData[11] = RecMsg4[signVal + 17];	// side4 amber time
//				byteToInteger(0);
//				eepromData[planNo*4+3]=stringInt[0];

				signalData[12] = RecMsg4[signVal + 19];	// plan mode
				signalData[13] = RecMsg4[signVal + 13];	// side5 green time
				signalData[14] = RecMsg4[signVal + 18];	// side5 amber time
				signalData[15] = 0xFF;	//
//				byteToInteger(0);
//				eepromData[planNo*4+4]=stringInt[0];

				if (noOfPlanCnt < noOfPlansNew) {
					noOfPlanCnt++;
					function4();

				}

			}

}

//void checkClearenceMode() {
////----------------------------PD4 for jump---------------------//
//	if (HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_4)) {
//		clearanceMode = 4;
//	}
//
////----------------------------PD5 for extend---------------------//
//	if (HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_5)) {
//		clearanceMode = 6;
//	}
//
////----------------------------PD6 for modeChange--------------------//
//	if (HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_6)) {
//		clearanceMode = 3;
//	}
//
////--------------------------PD7 for shutdown-----------------------//
//	if (HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_7)) {
//		clearanceMode = 5;
//	}
//
//}

//-------------------changeMode()---> whether serverMode or manualMode---------------//
void checkMode()

{

	if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3)) {
		serverMode = 1;
	} else {
		serverMode = 0;
	}

}

void function1Response() {

	//if (RecMsg4[signVal+(RecMsg4[signVal+1])+2]+crcApi2(signVal)==0xFF)
//		{
//		signVal =signVal+2 ;
//		signVal =signVal+3 ;
//		signVal =signVal+6 ;
	signVal = signVal + 2;
//	    junctionId=RecMsg4[signVal];
	if (!(RecMsg4[signVal] == 111))
	//if (RecMsg4[signVal+1]==1)
	{

		junctionId = RecMsg4[signVal];
		programVersionNo = RecMsg4[signVal + 1];
		programVersionNoLast = RecMsg4[signVal + 1];
		fileNo = RecMsg4[signVal + 2];
		registrationStatus = RecMsg4[signVal + 4];
		noOfSides = RecMsg4[signVal + 5];
		noOfPlans = RecMsg4[signVal + 6];
		padestarianTime = RecMsg4[signVal + 7];
		//junctionId=RecMsg4[signVal];

//		}
//		}

		// 	fnData[0] = RxBuffer[6] ;// junctiond id

//			string[0]=RxBuffer[signVal];//junction id
//			string[0]=RxBuffer[signVal];//junction id
//			junctionId=RxBuffer[signVal];
//			string[1]=RxBuffer[signVal+1];//no of sides
//			programVersionNo=RxBuffer[signVal+1];
//			programVersionNoLast=RxBuffer[signVal+1];
//			string[2]=RxBuffer[signVal+2];//no of sides
//			fileNo=RxBuffer[signVal+2];
//			string[3]=RxBuffer[signVal+4];//no of sides
//			registrationStatus=RxBuffer[signVal+4];
//			byteToInteger(0);
//			eepromData[0]=stringInt[0];
//			string[0]=RxBuffer[signVal+5];//no of sides
//			noOfSides=RxBuffer[signVal+5];
//			string[1]=RxBuffer[signVal+6];// no of plans
//			noOfPlans=RxBuffer[signVal+6];
//			//noOfPlans=3;
//			string[2]=RxBuffer[signVal+7];// program version no
//			padestarianTime=RxBuffer[signVal+7];
//	//		padestarianOn=RxBuffer[signVal+8];
//			string[3]=RxBuffer[signVal+8];
//			byteToInteger(0);
//			eepromData[1]=stringInt[0];

		signVal = 0;

		if (junctionId == 111) {
			function1();
		} else {
			noOfPlansNew = noOfPlans + 1;
//	if(noOfPlanCnt<noOfPlansNew)
//	{
			function4();
//
//	}

		}

	}

}

int crcApi2(int signval) {
	int zxx9 = signval + 2;
	int zyy9 = 0;
	int zzzz = zxx9 + RecMsg4[signval + 1];
	while (zxx9 < zzzz) {
		zyy9 = zyy9 + RecMsg4[zxx9++];
	}

	return zyy9;

}
/*------------------------------programming function----------------------------*/
void program3() {

//while(1){
//	planNo=1;
//	function_10();
//	HAL_Delay(500);
//	function_10();
//}

//	SDCardTruncateFile();
	resetVariables();

	int temp = 1;
	int temp2 = 1;
	/*----------delete the existing file from SD card before new programming (START)---- */
	f_unlink ("infoN.txt");
	f_unlink ("date.txt");
	f_unlink ("day.txt");
	f_unlink ("planN.txt");
	f_unlink ("mapDate.txt");
	f_unlink ("mapDay.txt");
	f_unlink ("phase.txt");
	f_unlink ("mapPhase.txt");
	f_unlink ("SlaveD.txt");
	/*----------delete the existing file from SD card before new programming (END)---- */
	/*----------delete the existing data from flash-begin-------------*/
	flash_Erase();
	/*----------delete the existing data from flash-end-------------*/
    /*----------Programming -------------*/
	while (1) {
		switch (temp) {
		case 1:
			HAL_Delay(500);
////			if (temp2 == function1())
//			function11N();
//			HAL_Delay(1000);
//			function12();
//			HAL_Delay(1000);
//			function13();
//			HAL_Delay(1000);
//			function14();
//			HAL_Delay(1000);
//			function15();
//			HAL_Delay(1000);
//			function16();
			if(temp2 == function11N()) //basic info function
				temp++;

			break;
		case 2:


			if (temp2 == function12()) //date slot function
				temp++;
			break;
		case 3:


			if (temp2 == function13()) //day slot function
			temp++;
			break;
		case 4:
			HAL_Delay(500);

			if (temp2 == function14())  //plan info function

				temp++;
			break;
		case 5:
			HAL_Delay(500);

			if (temp2 == function15()) // map date function

				temp++;
			break;
		case 6:
				HAL_Delay(500);

				if (temp2 == function16()) //map day function

					temp++;
				break;
		case 7:
			HAL_Delay(500);

			planNo = 1;
			if (temp2 == function_10())	//phase info
				temp++;

			break;
		case 8:
			HAL_Delay(500);
			if(temp2 == function17()) //phaseMap
			temp++;


			break;

		case 9:
		   HAL_Delay(500);
		   if (temp2 == function18())
			temp++;

			break;

		case 10:
			HAL_Delay(1000);
			if (temp2 == function9())
				temp++;
			break;

		}
		if (temp == 11)
			break;
	}

	/*---------------------SD Card-----------------------*/

	/*----------------update that programming was done successfully-------start------------*/
	string[0]=1;
	string[1]=1;
	SDcardWriteSeek("prog.txt", 5, (uint8_t *) string, 0);

    /*--------------------------end----------------------------------------*/



    /*-------------------------extracting common info----------------------*/
		SDcardReadSeek("infoN.txt", 16, 0);


		junctionId = readBytes[0];
		programVersionNo = readBytes[1];
		fileNo = readBytes[2];
		noOfSides = readBytes[4];
		noOfDateSlots = readBytes[5];
		noOfDaySlots = readBytes[6];
		noOfPlans = readBytes[7];
		padestarianTime = readBytes[8];
		side1PoleType = readBytes[10]; // 1= standard ,2= l Cantilever,3= T cantilever pole
		side2PoleType = readBytes[11];
		side3PoleType = readBytes[12];
		side4PoleType = readBytes[13];
		side5PoleType = readBytes[14];
		totalNoOfPhases=readBytes[9];
}



/*-------------------------------------before day and date ------------------------------*/
//void program3() {
//
//
//
//	int temp = 1;
//	int temp2 = 1;
//	while (1) {
//		switch (temp) {
//		case 1:
//			HAL_Delay(1000);
////			if (temp2 == function1())
//			function11N();
//			HAL_Delay(1000);
//			function12();
//			HAL_Delay(1000);
//			function13();
//			HAL_Delay(1000);
//			function14();
//			HAL_Delay(1000);
//			function15();
//			HAL_Delay(1000);
//			function16();
//			if(temp2 == function11N())
//				temp++;
//
//			break;
//		case 2:
////			HAL_Delay(1000);
//
////			if (temp2 == function3())
//				temp++;
//			break;
//		case 3:
////			HAL_Delay(3000);
//
////			if (temp2 == function32())
//			temp++;
//			break;
//		case 4:
//			HAL_Delay(1000);
////			Address = 0x080065C4;
//			if (temp2 == function4())
////if(temp2 == function12())
//				temp++;
//			break;
//		case 5:
//			HAL_Delay(1000);
////			Address = 0x080065C8;
//			if (temp2 == function42())
////			if(temp2== function13())
//				temp++;
//			break;
//		case 6:
//			HAL_Delay(1000);
////			Address = 0x08007000;
//			planNo = 1;
//			if (temp2 == function_10())	//phase info
//				temp++;
////				function2();
////		  	function2();
////				temp++;
////				function9();
//			break;
//		case 7:
//			HAL_Delay(1000);
////			Address = 0x08007000;
////			noOfPlans= *(__IO uint8_t*) 0x08006354;
//			SDcardReadSeek("info.txt", 10, 0);
//			noOfPlans = readBytes[5];
//			planNo = 1;
//			if (temp2 == function_10_2())	//phase info validation
//				temp++;
//			//				function2();
//			//		  	function2();
//			//				temp++;
//			//				function9();
//			break;
//
//		case 8:
//			if (temp2 == function9())
//				temp++;
//			break;
//
//		}
//		if (temp == 9)
//			break;
//	}
//}
void byteToIntegerVal(char *dat, uint8_t index) {
	int zx = 0;
//	while (zx<8)
	while (zx < 24)

	{
		stringInt[zx + index] = *dat;

		*dat++;
		zx++;

	}
}

void intToByte(int val) {
	test = val;
	test &= 0xFF;
	crcVal[0] = test;

	test = (val & 0xFF00) >> 8;
	crcVal[1] = test;

	test = (val & 0xFF0000) >> 16;
	crcVal[2] = test;
	test = (val & 0xFF000000) >> 24;
	crcVal[3] = test;
	crcVal[4] = 0;

}

void byteToIntegerVal1(uint8_t dat) {
//	int z = 0;
	stringInt[0] = string[dat + 0];
	stringInt[0] |= (string[dat + 0] << 0);
	stringInt[0] |= (string[dat + 1] << 8);
	stringInt[0] |= (string[dat + 2] << 16);
	stringInt[0] |= (string[dat + 3] << 24);

}
void intToString(__IO uint32_t dat) {
	int i = 0;
	int k = 0;
	char buf[10];
	while (dat > 0) {
		buf[i] = dat % 10;
		buf[i] = buf[i] + 48;
		dat = dat / 10;
		i++;
	}
	string[125] = i;
	buf[i] = 0;
	string[i] = 0;
	while (i > 0) {
		string[i - 1] = buf[k];
		i--;
		k++;
	}
}

void clearStringBuffer() {
	for (int i = 0; i < 10; i++) {
		string[i] = 0x00;
	}
}

void intToChar(uint8_t dat) {

	data1[0] = dat;

	if ((data1[0] > 0x64))	//3digit value
	{
		data1[1] = data1[0] / 100; // 235/100=2
		second[indexCnt] = data1[1] + 0x30; //

		indexCnt++;
		data1[2] = (data1[1] * 100); //2*100=200
		data1[2] = data1[0] - data1[2]; //235-200=35
		data1[3] = data1[2] / 10; // 35/10=3
		second[indexCnt] = data1[3] + 0x30; //
		indexCnt++;

		data1[4] = (data1[3] * 10); //3*10=30
		data1[4] = data1[2] - data1[4]; //35-30=5
		second[indexCnt] = data1[4] + 0x30; //
		indexCnt++;

		second[indexCnt] = 0x3A; //

	}

	if ((data1[0] < 0x64) && (data1[0] > 0x0A)) //2digit value
			{
		data1[1] = data1[0] / 10; // 19/10=1
		second[indexCnt] = data1[1] + 0x30;
		indexCnt++;

		data1[2] = (data1[1] * 10); //1*10=10
		data1[2] = data1[0] - data1[2]; //19-10=9
		second[indexCnt] = data1[2] + 0x30; //
		indexCnt++;

		second[indexCnt] = 0x3A; //

//	data1[1]=data1[0]/100; // 235/100=2
//	second[indexCnt]=data1[1]+ 0x30;//
//
//	indexCnt++;
//	data1[2]=(data1[1]*100); //2*100=200
//	data1[2]=data1[0]-data1[2]; //235-200=35
//	data1[3]=data1[2]/10;// 35/10=3
//	second[indexCnt]=data1[2]+ 0x30;//
//
//	data1[4]=(data1[3]*10); //3*10=30
//	data1[4]=data1[2]-data1[4]; //35-30=5
//	data1[10]=data1[4]+ 0x30;//

	}
	if ((data1[0] < 0x0A) && (data1[0] > 0x00)) //1digit value
			{
		second[indexCnt] = data1[0] + 0x30; //
		indexCnt++;

		second[indexCnt] = 0x3A; //

	}

}

void clearSecondBuffer() {
	int x = 0;
	for (; x < 16; x++) {
		second[x] = 0x00;

	}
}

void trafficDisplay2Value() {

	clearSecondBuffer();
	intToChar((uint8_t) Data[18]);
	indexCnt++;
	intToChar((uint8_t) Data[19]);
	indexCnt++;
	intToChar((uint8_t) Data[20]);
	indexCnt++;
	intToChar((uint8_t) Data[21]);
	indexCnt++;
	intToChar((uint8_t) Data[22]);
//	indexCnt++;
//	intToChar((uint8_t)Data[12]);
	clearData1Buffer();
	indexCnt = 0;

}

void clearFirstBuffer() {
	int x = 0;
	for (; x < 16; x++) {
		first[x] = 0x00;

	}
}
void clearData1Buffer() {
	int x = 0;
	for (; x < 16; x++) {
		data1[x] = 0x00;

	}
}

void trafficDisplay1Value() {
	clearFirstBuffer();
	intToChar1((uint8_t) Data[5]);
	indexCnt1++;
	intToChar1((uint8_t) Data[8]);
	indexCnt1++;
	intToChar1((uint8_t) Data[9]);
	indexCnt1++;
	intToChar1((uint8_t) Data[10]);
	indexCnt1++;
	intToChar1((uint8_t) Data[11]);
	indexCnt1++;
	intToChar1((uint8_t) Data[12]);
//	clearData1Buffer();
	indexCnt1 = 0;

}
void intToChar1(uint8_t dat) {

	data1[0] = dat;

	if ((data1[0] > 0x64)) //3digit value
	{
		data1[1] = data1[0] / 100; // 235/100=2
		first[indexCnt1] = data1[1] + 0x30; //

		indexCnt1++;
		data1[2] = (data1[1] * 100); //2*100=200
		data1[2] = data1[0] - data1[2]; //235-200=35
		data1[3] = data1[2] / 10; // 35/10=3
		first[indexCnt1] = data1[3] + 0x30; //
		indexCnt1++;

		data1[4] = (data1[3] * 10); //3*10=30
		data1[4] = data1[2] - data1[4]; //35-30=5
		first[indexCnt1] = data1[4] + 0x30; //
		indexCnt1++;

		first[indexCnt1] = 0x3A; //

	}

	if ((data1[0] < 0x64) && (data1[0] > 0x0A)) //2digit value
			{
		data1[1] = data1[0] / 10; // 19/10=1
		first[indexCnt1] = data1[1] + 0x30;
		indexCnt1++;

		data1[2] = (data1[1] * 10); //1*10=10
		data1[2] = data1[0] - data1[2]; //19-10=9
		first[indexCnt1] = data1[2] + 0x30; //
		indexCnt1++;

		first[indexCnt1] = 0x3A; //

//	data1[1]=data1[0]/100; // 235/100=2
//	second[indexCnt]=data1[1]+ 0x30;//
//
//	indexCnt++;
//	data1[2]=(data1[1]*100); //2*100=200
//	data1[2]=data1[0]-data1[2]; //235-200=35
//	data1[3]=data1[2]/10;// 35/10=3
//	second[indexCnt]=data1[2]+ 0x30;//
//
//	data1[4]=(data1[3]*10); //3*10=30
//	data1[4]=data1[2]-data1[4]; //35-30=5
//	data1[10]=data1[4]+ 0x30;//

	}
	if ((data1[0] < 0x0A) && (data1[0] > 0x00)) //1digit value
			{
		first[indexCnt1] = data1[1] + 0x30; //
		indexCnt1++;

		first[indexCnt1] = 0x3A; //

	}

}

void checkMsgLengthForUart4() {
	int i = 0;
	while (!(RecMsg4[i] == 0x7D)) {
		recCnt++;
		i++;
	}
	recCnt++;
}

void checkMsgLengthForUart2() {
	int i = 0;
	while (!(RecMsg2[i] == 0x7D)) {
		recCnt1++;
		i++;
	}
	recCnt1++;
}
void getPhase(uint8_t planNo) {
//	0x080065C8
	uint32_t Address1;
	switch (planNo) {
	case 1:

		Address1 = 0x080065C8; //plan number
		planNo = *(__IO uint8_t*) Address1;
		Address1 = 0x08006604; //phase number
		noOfPhase = *(__IO uint8_t*) Address1;

		break;
	case 2:
		Address1 = 0x08006608; //plan number
		planNo = *(__IO uint8_t*) Address1;
		Address1 = 0x08006648; //phase number
		noOfPhase = *(__IO uint8_t*) Address1;
		break;
	case 3:
		Address1 = 0x0800664C; //plan number
		planNo = *(__IO uint8_t*) Address1;
		Address1 = 0x0800668C; //phase number
		noOfPhase = *(__IO uint8_t*) Address1;
		break;
	case 4:
		Address1 = 0x08006640; //plan number
		planNo = *(__IO uint8_t*) Address1;
		Address1 = 0x08006684; //phase number
		noOfPhase = *(__IO uint8_t*) Address1;
		break;
	case 5:
		Address1 = 0x08006688; //plan number
		planNo = *(__IO uint8_t*) Address1;
		Address1 = 0x080066C8; //phase number
		noOfPhase = *(__IO uint8_t*) Address1;
		break;
	case 6:
		Address1 = 0x080066CC; //plan number
		planNo = *(__IO uint8_t*) Address1;
		Address1 = 0x0800670C; //phase number
		noOfPhase = *(__IO uint8_t*) Address1;
		break;
	case 7:
		Address1 = 0x08006710; //plan number
		planNo = *(__IO uint8_t*) Address1;
		Address1 = 0x08006750; //phase number
		noOfPhase = *(__IO uint8_t*) Address1;
		break;
	case 8:
		Address1 = 0x08006754; //plan number
		planNo = *(__IO uint8_t*) Address1;
		Address1 = 0x08006794; //phase number
		noOfPhase = *(__IO uint8_t*) Address1;
		break;
	case 9:
		Address1 = 0x08006798; //plan number
		planNo = *(__IO uint8_t*) Address1;
		Address1 = 0x080067D8; //phase number
		noOfPhase = *(__IO uint8_t*) Address1;
		break;
	case 10:
		Address1 = 0x080067DC; //plan number
		planNo = *(__IO uint8_t*) Address1;
		Address1 = 0x0800681C; //phase number
		noOfPhase = *(__IO uint8_t*) Address1;
		break;
	case 11:
		Address1 = 0x08006820; //plan number
		planNo = *(__IO uint8_t*) Address1;
		Address1 = 0x08006860; //phase number
		noOfPhase = *(__IO uint8_t*) Address1;

		break;
	case 12:
		Address1 = 0x08006864; //plan number
		planNo = *(__IO uint8_t*) Address1;
		Address1 = 0x080068A4; //phase number
		noOfPhase = *(__IO uint8_t*) Address1;
		break;
	case 13:
		Address1 = 0x080068A8; //plan number
		planNo = *(__IO uint8_t*) Address1;
		Address1 = 0x080068E8; //phase number
		noOfPhase = *(__IO uint8_t*) Address1;
	case 14:
		Address1 = 0x080068EC; //plan number
		planNo = *(__IO uint8_t*) Address1;
		Address1 = 0x0800692C; //phase number
		noOfPhase = *(__IO uint8_t*) Address1;
	case 15:
		Address1 = 0x08006930; //plan number
		planNo = *(__IO uint8_t*) Address1;
		Address1 = 0x08006970; //phase number
		noOfPhase = *(__IO uint8_t*) Address1;
	}

}
void getPhaseSD(uint8_t planNo) {
//	0x080065C8
//	uint32_t Address1;
	int seekCnt;
	clearReadBytes();
	switch (planNo) {
	case 1:

//		clearReadBytes();
		seekCnt=0;
		SDcardReadSeek("plan.txt", 18, seekCnt);
		planNo =readBytes[0];
		noOfPhase =readBytes[16];


		break;
	case 2:
		    seekCnt=18;
			SDcardReadSeek("plan.txt", 18, seekCnt);
			planNo =readBytes[0];
			noOfPhase =readBytes[16];
		break;
	case 3:
		    seekCnt=36;
			SDcardReadSeek("plan.txt", 18, seekCnt);
			planNo =readBytes[0];
			noOfPhase =readBytes[16];
		break;
	case 4:
		 seekCnt=54;
		 SDcardReadSeek("plan.txt", 18, seekCnt);
		 planNo =readBytes[0];
		 noOfPhase =readBytes[16];
		break;
	case 5:
		seekCnt = 72;
		SDcardReadSeek("plan.txt", 18, seekCnt);
		planNo = readBytes[0];
		noOfPhase = readBytes[16];
		break;
	case 6:
		seekCnt = 90;
		SDcardReadSeek("plan.txt", 18, seekCnt);
		planNo = readBytes[0];
		noOfPhase = readBytes[16];
		break;
	case 7:
		seekCnt = 108;
		SDcardReadSeek("plan.txt", 18, seekCnt);
		planNo = readBytes[0];
		noOfPhase = readBytes[16];
		break;
	case 8:
		seekCnt = 126;
		SDcardReadSeek("plan.txt", 18, seekCnt);
		planNo = readBytes[0];
		noOfPhase = readBytes[16];
		break;
	case 9:
		seekCnt = 144;
		SDcardReadSeek("plan.txt", 18, seekCnt);
		planNo = readBytes[0];
		noOfPhase = readBytes[16];
		break;
	case 10:
		seekCnt = 162;
		SDcardReadSeek("plan.txt", 18, seekCnt);
		planNo = readBytes[0];
		noOfPhase = readBytes[16];
		break;
	case 11:
		seekCnt = 180;
		SDcardReadSeek("plan.txt", 18, seekCnt);
		planNo = readBytes[0];
		noOfPhase = readBytes[16];

		break;
	case 12:
		seekCnt = 198;
		SDcardReadSeek("plan.txt", 18, seekCnt);
		planNo = readBytes[0];
		noOfPhase = readBytes[16];
		break;
	case 13:
		seekCnt = 216;
		SDcardReadSeek("plan.txt", 18, seekCnt);
		planNo = readBytes[0];
		noOfPhase = readBytes[16];
		break;
	case 14:
		seekCnt = 234;
		SDcardReadSeek("plan.txt", 18, seekCnt);
		planNo = readBytes[0];
		noOfPhase = readBytes[16];
		break;
	case 15:
		seekCnt = 252;
		SDcardReadSeek("plan.txt", 18, seekCnt);
		planNo = readBytes[0];
		noOfPhase = readBytes[16];
		break;
	}

}

void getPhaseSDCardNew(uint8_t planNoN){
	    int seekCnt;
		clearReadBytes();
		planNoN=planNoN-1;
//		if(planNoN==0){
	    seekCnt = planNoN * 19;
//		}
//		else{
//			seekCnt = planNoN * 19;
//			seekCnt=seekCnt+1;
//		}
		SDcardReadSeek("planN.txt", 19, seekCnt);
		planID = readBytes[0];
		planNo = readBytes[1];
		noOfPhase = readBytes[17];

}


/*---------------------------------------check phase info validation from server - ------------------------------------*/
int function_10_2() {

//	getPhase(planNo);
int counter=0;
	noOfPlans = noOfPlans + 1;
	//	for (int i = 1; i < noOfPlans + 1; i++)
	for (int i = 1; i < noOfPlans; i++) {
//		getPhase(planNo);
		getPhaseSD(planNo);
		//	Address = 0x08007000;
		noOfPhase = noOfPhase + 1;
		//	for (int i = 1; i < noOfPhase + 1; i++)
		for (int i = 1; i < noOfPhase; i++) {
			phaseNo = i;

			clearframe();
			 readPhaseSD(counter);
			 counter=counter+15;
//		readMem();
//			readPhase();
//		phaseNo=i ;
//		phaseNo = 1;
//		junctionId = 1;
//		programVersionNo = 71;
//		fileNo = 111;
//		planNo = 1;
//		phaseNo = 1;

			frame[0] = 0x7E;
			frame[1] = 0x7E;
			frame[2] = 0x00;									//byte size 1
			frame[3] = 30;									//byte size 2
			frame[4] = junctionId;									//junctionID
			frame[5] = programVersionNo;					//programVerNumber
			frame[6] = fileNo;									//fileNumb
			frame[7] = 0x0A;									//functionNo
//		frame[8] = planNo;									//planNo
//		frame[9] = phaseNo;									//phaseNo
//

			for (int i = 0; i < 14; i++) {
//				frame[8 + i] = Flash_Data[i];
				frame[8 + i] = readBytes[i];

			}

			frame[22] = '1';
			frame[23] = '1';
			frame[24] = '1';
			frame[25] = '1';
			frame[26] = '1';
			frame[27] = '1';
			frame[28] = '1';
			frame[29] = '1';
			frame[30] = '1';
			frame[31] = '1';									//'1'
			frame[32] = '1';									//'0' ; //'5' ;
			frame[33] = '1';							// '2' ;//'9' ;//'1' ;
			frame[34] = 0xFF - crcApiResponse();						//CRC
			frame[35] = 0x7D;								// ending delimeter
			frame[36] = 0x7D;								//ending delimeter

			HAL_UART_Transmit(&huart3, (uint8_t*) frame, 36, 5000);
			HAL_UART_Receive(&huart3, (uint8_t *) aRxBuffer, 70, 0x1FFF);
			HAL_Delay(300);
			signVal = msgParse((uint8_t *) aRxBuffer, "~~~~", 0);

			//signVal = msgParse(RxBuffer,"~~~~",0);
			HAL_Delay(1000);
			while (aRxBuffer[signVal] == 126) {
				signVal = signVal + 1;
				if(!(aRxBuffer[signVal] == 126))
								break;
			}
			signVal=4;
			if (!(signVal == 0))
				if (aRxBuffer[signVal + (aRxBuffer[signVal + 1]) + 2]
						+ crcApi3(signVal) == 0xFF)
				{
					//				if((aRxBuffer[signVal]==126)){
					//					signVal=signVal+1;
					//				}

					signVal = signVal + 2;
					if ((aRxBuffer[signVal] == junctionId)) {
						signVal = signVal + 3;
						if ((aRxBuffer[signVal] == 10))
							signVal = signVal + 1;
						if ((aRxBuffer[signVal] == planNo))
							signVal = signVal + 1;
						if ((aRxBuffer[signVal] == phaseNo))

						{
							signVal = signVal - 1;

//
							clearaRxBuffer();
							clearBuffer4();

							//						Address=Address+4;
							//						return 1 ;

						}
					}
//					return 1;
				} else {
					return 0;
				}

//		if (!(signVal == 0)) {
//			signVal = signVal + 2;
//			clearBuffer4();
//		}

		}

		planNo++;
	}
	return 1;

}
/*--------------------------get phase info from server-----------------------------------------*/
int function_10() {
//	Address = 0x08007000;
//	noOfPlans=3;
//	junctionId=1;
//	programVersionNo=71;
	int seekCnt=0;
    uint32_t flashAdd=ADDR_FLASH_SECTOR_10;
//	noOfPlans = noOfPlans + 1;
//	for (int i = 1; i < noOfPlans + 1; i++)
//	for (int i = 1; i < noOfPlans; i++)
//	{
//		getPhase(planNo); //eeprom
//		getPhaseSD(planNo);
//		getPhaseSDCardNew(planNo);
//	Address = 0x08007000;
//		noOfPhaseCnt=noOfPhaseCnt+noOfPhase;

		SDcardReadSeek("infoN.txt", 15, 0);
		totalNoOfPhases=readBytes[9];


		totalNoOfPhases = totalNoOfPhases + 1;
//	for (int i = 1; i < noOfPhase + 1; i++)
		for (int i = 1; i < totalNoOfPhases; i++) {
			phaseNo = i;
			clearframe();

//		phaseNo=i ;
//		phaseNo = 1;
//			junctionId = 1;
//			programVersionNo = 71;
			fileNo = 111;
//		planNo = 1;
//		phaseNo = 1;

			frame[0] = 0x7E;
			frame[1] = 0x7E;
			frame[2] = 0x00;									//byte size 1
			frame[3] = 18;									//byte size 2
			frame[4] = junctionId;									//junctionID
			frame[5] = programVersionNo;					//programVerNumber
			frame[6] = fileNo;									//fileNumb
			frame[7] = 0x0A;									//functionNo
			frame[8] = planNo;									//planNo
			frame[9] = planID;									//phaseNo
			frame[10] = phaseNo;
			frame[11] = '1';
			frame[12] = '1';
			frame[13] = '1';
			frame[14] = '1';
			frame[15] = '1';
			frame[16] = '1';
			frame[17] = '1';
			frame[18] = '1';
			frame[19] = '1';									//'1'
			frame[20] = '1';									//'0' ; //'5' ;
			frame[21] = '1';							// '2' ;//'9' ;//'1' ;
			frame[22] = 0xFF - crcApiResponse();						//CRC
			frame[23] = 0x7D;								// ending delimeter
			frame[24] = 0x7D;								//ending delimeter

			if(programFromBLE==1)
			{
				HAL_UART_Transmit(&huart1, (uint8_t*) frame, 24, 5000);
				HAL_UART_Receive(&huart1, (uint8_t *) aRxBuffer, 40, 0x2FFF);
			}
			else
			{

			HAL_UART_Transmit(&huart3, (uint8_t*) frame, 24, 5000);
			HAL_UART_Receive(&huart3, (uint8_t *) aRxBuffer, 40, 0x1FFF);
			}

			HAL_Delay(300);
			signVal = msgParse((uint8_t *) aRxBuffer, "~~~~", 0);

			//signVal = msgParse(RxBuffer,"~~~~",0);
			HAL_Delay(1000);
//			while (aRxBuffer[signVal] == 126) {
//				signVal = signVal + 1;
//				if(!(aRxBuffer[signVal] == 126))
//								break;
//			}
			signVal=4;
			if (!(signVal == 0))
			{
					if (aRxBuffer[signVal + (aRxBuffer[signVal + 1]) + 2]
							+ crcApi3(signVal) == 0xFF)
			{
				//				if((aRxBuffer[signVal]==126)){
				//					signVal=signVal+1;
				//				}

				signVal = signVal + 2;
				if ((aRxBuffer[signVal] == junctionId)) {
					signVal = signVal + 3;
					if ((aRxBuffer[signVal] == 10))
						signVal = signVal + 1;
					if ((aRxBuffer[signVal] == planNo))
						signVal = signVal + 2;
//					if ((aRxBuffer[signVal] == phaseNo))

					{
						signVal = 10;

						for (int i = 0; i < 15; i++) {
							string[i] = aRxBuffer[signVal];
							signVal++;

						}
						string[16]=0xFF;

						//-------------------------SD card write begin-----------------------//
						SDcardWriteSeek("phase.txt", 17, (uint8_t *) string, seekCnt);
						SDcardReadSeek("phase.txt", 350, 0);
						//-------------------------SD card write end-----------------------//

						/*-------write phase in flash begin---------*/
						HAL_FLASH_Unlock();
						Flash_Write(flashAdd, string, 17);
						HAL_FLASH_Lock();

						/*-------write phase in flash end-----------*/

						/*-------write phase in eeprom begin----------*/
						EEPROM_WriteArray(string,17,eepromAddress);
						clearReadBytes();
						clearStringBuffer();
						EEPROM_ReadArray(string,17,eepromAddress);
						/*-------write phase in eeprom end----------*/



						/*----------increment the counter value--------------*/
						seekCnt=seekCnt+17; //SD card counter
                         eepromAddress= seekCnt; //eeprom Counter
                         flashAdd=flashAdd+17; //Flash Counter

						//--------------------------flash write------------------------//
//						HAL_FLASH_Unlock();
////								Address = Address + 4;
//						for (int i = 0; i < 14; i++) {
//							//						FLASH_Erase_Sector(FLASH_SECTOR_1,FLASH_VOLTAGE_RANGE_3);
//							HAL_FLASH_Program(TYPEPROGRAM_BYTE, Address,
//									string[i]);
//							Address = Address + 4;
//
//						}
//						Address = Address + 4;
//						HAL_FLASH_Lock();
						//-----------------------------flash ---------------------------//
                         HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_4);
						clearaRxBuffer();
						clearBuffer4();
						//						Address=Address+4;
						//						return 1 ;

					}
//					else {
//						return 0;
//					}
				} else {
					return 0;
				}
			}
			else {
					return 0;
				 }


			}else {
				return 0;
			}

//		if (!(signVal == 0)) {
//			signVal = signVal + 2;
//			clearBuffer4();
//		}

		}
//		planNo++;
//	}
//	//-------------------------SD card write-----------------------//
//	string[0]=eepromAddress;
//	string[1]=0xFF;
//	string[2]=0xFF;
//	SDcardWriteSeek("phaseCnt.txt", 4, (uint8_t *) string, 0);
//	SDcardReadSeek("phaseCnt.txt", 5, 0);


//		SDcardWriteSeek("Cnt.txt", 3, (uint8_t *) string, 0);
//		SDcardReadSeek("Cnt.txt", 5, 0);
	return 1;

}

void init4(void) {

//	function_10();
	 returnMode=0;
	 int counter=0;
     int noOfPlansN;
     int isProgrammed=0;


     isReprogrammed=0;
     resetVariables();
/*---------------------SD Card-----------------------*/

     clearReadBytes();
     SDcardReadSeek("prog.txt", 3, 0);
     isProgrammed = readBytes[0];
//     isProgrammed=0;
     clearReadBytes();
     if(isProgrammed==1){
	SDcardReadSeek("infoN.txt", 16, 0);
     }

	junctionId = readBytes[0];
	programVersionNo = readBytes[1];
	fileNo = readBytes[2];
	noOfSides = readBytes[4];
	noOfDateSlots = readBytes[5];
	noOfDaySlots = readBytes[6];
	noOfPlans = readBytes[7];
	padestarianTime = readBytes[8];
	side1PoleType = readBytes[10]; // 1= standard ,2= l Cantilever,3= T cantilever pole
	side2PoleType = readBytes[11];
	side3PoleType = readBytes[12];
	side4PoleType = readBytes[13];
	side5PoleType = readBytes[14];
	totalNoOfPhases=readBytes[9];

//	SDcardReadSeek("mapPhase.txt", 100, 0);
/*---------------------Flash mem---------------------*/
//	Address = 0x08006340;  0x080E0000;
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
//		program3();
//program3();
	if (junctionId == 0xFF || junctionId == 0x00)
	{
//		Address = 0x08006440;
//		Address = 0x08006340;
	     if(HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_5))
	      {
	    	  programFromBLE=1;
	      }
	     else
	     {
	    	  programFromBLE=0;
	      }
	     program3();
	} else {
//function1();
//function2();
//function2();
		HAL_RTC_GetDate(&hrtc, &sDate, FORMAT_BIN);
//					            sTime.Hours = 12;//aRxBuffer[signVal + 2]; // current hour
//								sTime.Minutes =50;//aRxBuffer[signVal + 3]; // current min
//								sDate.Date = 14;//aRxBuffer[signVal + 4]; // current date
//								sDate.Month = 12;//aRxBuffer[signVal + 5]; // current month
//								sDate.Year = 19;//aRxBuffer[signVal + 6];	// current year
//								sDate.WeekDay=6;//aRxBuffer[signVal + 8];	// current weekday
//
//								HAL_RTC_SetTime(&hrtc, &sTime, FORMAT_BIN);
//								HAL_RTC_SetDate(&hrtc, &sDate, FORMAT_BIN);
//		function9();
		if((sDate.Year==0))
		{
//			            sTime.Hours = 12;//aRxBuffer[signVal + 2]; // current hour
//						sTime.Minutes =50;//aRxBuffer[signVal + 3]; // current min
//						sDate.Date = 14;//aRxBuffer[signVal + 4]; // current date
//						sDate.Month = 12;//aRxBuffer[signVal + 5]; // current month
//						sDate.Year = 19;//aRxBuffer[signVal + 6];	// current year
//						sDate.WeekDay=6;//aRxBuffer[signVal + 8];	// current weekday
//
//						HAL_RTC_SetTime(&hrtc, &sTime, FORMAT_BIN);
//						HAL_RTC_SetDate(&hrtc, &sDate, FORMAT_BIN);


		function9();
		}
		else{
			DateLast=sDate.Date;
		}
//function9();
//function2();

	}

	/*-----------for testing(begin)-------------------*/
//	if(check==1){
//	sTime.Hours = 0x17; // current hour
//	sTime.Minutes =0x39 ; // current min
//	sDate.Date = 0x11;//aRxBuffer[signVal + 4]; // current date
//	sDate.Month = 0x06;//aRxBuffer[signVal + 5]; // current month
//	sDate.Year = 0x14;//aRxBuffer[signVal + 6];	// current year
//
//	HAL_RTC_SetTime(&hrtc, &sTime, FORMAT_BIN);
//	sDate.WeekDay=0x06;
//	HAL_RTC_SetDate(&hrtc, &sDate, FORMAT_BIN);
//	check++;
//	}
	/*-----------for testing(end)-------------------*/



	programVersionNoLast = programVersionNo;

 	 /* Get the RTC current Time */
  	 HAL_RTC_GetTime(&hrtc, &sTime, FORMAT_BIN);
  	 /* Get the RTC current Date */
  	HAL_RTC_GetDate(&hrtc, &sDate, FORMAT_BIN);

  	while (sDate.Year==0){
  		function9();
  		HAL_RTC_GetDate(&hrtc, &sDate, FORMAT_BIN);

  	}


/*------------------checks the current date with dateSlot or with daySlot-------------*/
  	/*------------------checking dateSlot---------date.txt-----*/
  	dateID = 0xFE;
  	dayID = 0xFE;
  	noOfPlansN = 0xFE;
  	for(int i=1;i<noOfDateSlots+1;i++)
  	{


  	//readMem();
//  		readMemSD(counter);
  	    readDateSD(counter);
  		counter=counter+11;
  	for(int j=0;j<6;j++){
  		 dateSlot[j]= readBytes[j+3];

  	}
//  		dateSlot[0]=14;
//  		dateSlot[1]=11;
//  		dateSlot[2]=19;
//  		dateSlot[3]=30;
//  		dateSlot[4]=11;
//  		dateSlot[5]=19;
if(dateSlot[5]==sDate.Year)//comparing present year with ToYear
{
	if(dateSlot[4] >= sDate.Month)//comparing present month with ToMonth
	{
		if(dateSlot[1] <= sDate.Month)//comparing present month with FromMonth
		{
			if(dateSlot[3] >= sDate.Date)//comparing present day with ToDay
			{
				if(dateSlot[0] <= sDate.Date)//comparing present day with FromDay
				{
					dateID=readBytes[2];
					noOfPlansN=readBytes[9];
					 break;
				}
			}
		}
	}
}

if(dateSlot[5]>sDate.Year)//comparing present year with ToYear
{
	if(dateSlot[2]== sDate.Year)//comparing present year with FromYear
	{
		if(dateSlot[1]==sDate.Month)//comparing present month with FromMonth
		{
			if(dateSlot[0] <= sDate.Date)//comparing present day with FromDay
			{
				dateID=readBytes[2];
				noOfPlansN=readBytes[9];
				 break;
			}
		}

	}



}


  	}
/*--------checking day.txt---------*/
//  	dayID=0xFE;
if(dateID==0xFE) //if means the present date is not coming in date slot and we have to find it in day
{
	counter=0;

	for(int i=1;i<noOfDaySlots+1;i++)
  	{
		   readDaySD(counter);
		  	counter=counter+6;

		  	if(sDate.WeekDay==readBytes[3])
		  	{
		  		dayID=readBytes[2];
		  		noOfPlansN=readBytes[4];
		  		break;
		  	}



  	}
}
/*------------if it is weekday-----------------*/
if((dayID==0xFE)&&(dateID==0xFE))
{

	counter=0;

	for(int i=1;i<noOfDaySlots+1;i++)
  	{
		   readDaySD(counter);
		  	counter=counter+6;

		  	if(0==readBytes[2]){
		  		dateID=0;
		  		dayID=readBytes[2];
		  		noOfPlansN=readBytes[4];
		  		break;
		  	}



  	}




}
countNoOfMapDetails();
currentDayAllPlan();
clearPlanTimeBuffer();


HAL_Delay(50);
/*-------write Current day plan in eeprom begin----------*/
/*---------incrementing the value of counter by 50 ------------*/

eepromAddress=4001;
EEPROM_WriteArray(planDetailsArray,counterOfPlan,eepromAddress);
//clearReadBytes();


//clearPlanDetailsArrayBuffer();//------------------commented because eeprom was not available to enable eeprom do check getCurrentPlanTotalNoOfPhases();
//EEPROM_ReadArray(planDetailsArray,349,eepromAddress);//------------------commented because eeprom was not available

/*-------write Current day plan in eeprom end----------*/

/*--------write current day plan in flash---------*/
  HAL_FLASH_Unlock();
  Flash_Write(ADDR_FLASH_SECTOR_11,planDetailsArray,counterOfPlan);
  HAL_FLASH_Lock();
 /*--------write current day plan in flash---------*/

///*-------write all phases in eeprom begin----------*/
////EEPROM_WriteArray(phases,noOfPhase*16,counterOfPlan);
////clearReadBytes();
////EEPROM_ReadArray(readBytes,350,0);
//
///*-------write all phases in eeprom end----------*/

/*---------------getting the planID and mapID from mapDate.txt file----------- */
//int mapCnt=noOfDateSlots+noOfDaySlots;
//int cnt=0;
//counter=0;
//for(int i=0;i<mapCnt+1;i++)
//for(int i=1;i<totalNoOfMap;i++)

//if(dateID)
//while()

for(int i=1;i<noOfPlansN+1;i++)
{

	  for(int j=0;j<4;j++){
	        planTime[j]= planDetailsArray[incCnt+2+j];

	       }
	       incCnt=incCnt+19;
//	SDcardReadSeek("mapDate.txt", 100, cnt);
//	cnt=cnt+6;
//	if((dateID==readBytes[0])||(dayID ==readBytes[1])){
//		planID=readBytes[2];
//		mapID=readBytes[4];
////		break;
//	}

//}

/*------------------getting the plan from plan.txt file------------------*/

//counter=0;
//  	Address = 0x080065C8;//planStartAddress
//if(!((planID==0x00)&&(mapID==0x00)))
//{
////for(int i=1;i<noOfPlansN+1;i++)
//{
//
//
////readMem();
//	readPlanSD(counter);
//	counter=counter+19;
//	/*---------if planID matches so get the plan details------------*/
//	if(planID==readBytes[0])
//	{
//for(int j=0;j<4;j++){
//	 planTime[j]= readBytes[j+2];
//
//}


/*------------------Comparing with OFF Time------------------------*/
if (sTime.Hours>planTime[2])
{
continue;
}
/*------------------Comparing with OFF Time------------------------*/
if (sTime.Hours==planTime[2])
{
if   (sTime.Minutes < planTime[1])
{
	   planNo=i;
	   break;
	 	 }
else if(sTime.Minutes > planTime[1])
{
	continue;
}
}


/*------------------Comparing with ON Time------------------------*/
if (sTime.Hours==planTime[0])
{if (!(sTime.Minutes <= planTime[1]))
planNo=i;
break;
}



/*------------------Comparing with ON Time------------------------*/
  if (sTime.Hours>planTime[0])
	   if (sTime.Hours< planTime[2]){
			   planNo=i;
			    break;


	   }


}

//if(!(i==0))
//{
planDetailSD(planNo); //planNo was used earlier but now it do not have any utilization.
//}

}
////}
//if(!(i==0))
//{
//planDetailSD(planNo);
//}
//}
////planNo=2;
////planDetail(planNo);//gets the plan details
////planDetailSD(planNo);
//}


int signal()
{
/*----------old logic-----*/
//		phaseInfoAddress();
//		phaseNo=1;
//		AddressOfPhase=test1[planNo][1][1];
//		SDcardReadSeek("phase.txt", 150, AddressOfPhase);
//		phaseInfoData(planNo,phaseNo);
//        if(returnMode==1)
//        	return 1;
/*------------new logic------------*/
	int cnt=0;
    int phaseID=0;
    int cntr1=0;
    int cntr2=0;

	for(int m=1;m<total_Phases+1;)
	{

	if((mapIDForCurrentPhases== phaseMapIDList[cnt+1]) && (m == phaseMapIDList[cnt+4])) //if mapID and order number matches
	{


		phaseID=phaseMapIDList[cnt+2];//phaseID
		for(int j=1;j<totalNoOfPhasesInMapID;j++)
		{
		if(phaseID==currentPlanPhases[cntr1+5])
		{
			/*----color array hold the color of side13 and side24 of all the phases in current plan-------*/
			Color[cntr2]=m;
			Color[cntr2+1]=currentPlanPhases[cntr1+12]; //side 13
			Color[cntr2+2]=currentPlanPhases[cntr1+13]; //side24
			Color[cntr2+3]=phaseID;
			cntr2=cntr2+4;
			break;
		}
		cntr1=cntr1+18;
		}
//		if(phaseID==currentPlanPhases[cntr1+5])
////		break;
//		m++;
	}
	cnt=cnt+6;
	if(phaseID==currentPlanPhases[cntr1+5])
//		break;
		m++;
//	if(cnt > 200)
//		break;
	}

//	while(1){
//		sideChange();
//	}
	findSide(Color[1],Color[2]);
//if(Color[1]==0x38) // green
//{
//	Disp[0]=planS1GT;
//	Disp[1]=planS1GT+planA1GT;
//	Disp[2]=planS1GT+planA1GT+planS2GT+planA2GT;
//	Disp[3]=planS1GT+planA1GT+planS2GT+planA2GT+planS3GT+planA3GT;
//	Disp[28]=planS1GT;
//	Disp[4]=Color[1];
//	Disp[5]=Color[2];
//	phase_ID=Color[3];
//}
//else
//{ //yellow
//			Disp[28]=planA1GT;
//			Disp[4]=Color[1];
//			Disp[5]=Color[2];
//			phase_ID=Color[3];
//}
    phaseNo=1;
	clearDispBuffer();
	phase_No=1;
	countDown();
	extractSlaveInfo();
	phaseInfoData(planNo,phaseNo);
	if(isReprogrammed==1)
		return 1;
    if(returnMode==1)
    	return 1;




}
//phaseNo=1;
int phaseInfoData(uint8_t planNo,uint8_t phaseNo){

	uint32_t AddressOfPhase1=0;
	uint8_t side13Last,side24Last;




while(1){
//	clearFlashDataBuffer();

//    clearReadBytes();


//	AddressOfPhase=test1[planNo][phaseNo][phaseNo];
//	SDcardReadSeek("phase.txt", 15, AddressOfPhase);

//		for (int i = 0; i < 14; i++) {
//			Flash_Data[i] = *(__IO uint8_t*) AddressOfPhase;
//			AddressOfPhase = AddressOfPhase + 4;
//			//		dataToWrite++;
//		}



//		AddressOfPhase = AddressOfPhase + 4;
//		if(phaseNo==1){
	/*------------for ground and server actions---------------*/
	checkServerJumpExtend=0;
	extendCnt=0;
	extendCnt1=0;
	clearenceMode=1;
	clearenceModeLast=1;
    lSec=10;
    lsSec=10;
	clearenceMode=1;
    pin_HighLast=0;
	pinExtend_HighLast=0;


//	Disp[0] = readBytes[3+AddressOfPhase1];//side1
//	Disp[1] = readBytes[4+AddressOfPhase1];//side2
//	Disp[2] = readBytes[5+AddressOfPhase1];//side3
//	Disp[3] = readBytes[6+AddressOfPhase1];//side4
//	Disp[4] = readBytes[8+AddressOfPhase1];//side13
//	Disp[5] = readBytes[9+AddressOfPhase1]; //side24
//	Disp[6] = readBytes[3+AddressOfPhase1];//side
//	Disp[7] = readBytes[4+AddressOfPhase1];//side
//	Disp[8] = readBytes[5+AddressOfPhase1];
//	Disp[9] = readBytes[6+AddressOfPhase1];
//	Disp[10] = 1;//slaveNo;
//	Disp[11] = 1;
//	Disp[12] = 1;
//	Disp[13] = 1;
//	Disp[14] = 1;
//	Disp[15] = 1;
//	Disp[16] = 1;
//	Disp[17] = 1;
//	Disp[18] = 1;
//	Disp[19] = 1;
//	Disp[25]=readBytes[0+AddressOfPhase1]; //plan Number
//	Disp[26]=readBytes[1+AddressOfPhase1]; //plan mode
//	Disp[27]=readBytes[12+AddressOfPhase1]; //padestrian time
//    Disp[28]=readBytes[2+AddressOfPhase1]; //phase time

//		}
//		else
//		{
//		Disp[4]=0x83;
//		Flash_Data[8]=0x88;
//		Disp[5]=0x88;
//		Flash_Data[9]=0x88;
//    count=100;

    count=Disp[28];
/*-----------------------*/

		while(1){
			 HAL_UART_Receive_IT(&huart3, (uint8_t *)aRxBuffer3,1);//For ESP
			 HAL_UART_Receive_IT(&huart6, (uint8_t *)aRxBuffer,1);//for slave through LORA
			 HAL_UART_Receive_IT(&huart2, (uint8_t *)aRxBuffer4,1);//For slave through RS485
			 HAL_UART_Receive_IT(&huart1, (uint8_t *)aRxBuffer1,1);//For BLE

			HAL_RTC_GetDate(&hrtc, &sDate, FORMAT_BIN);
			 HAL_RTC_GetTime(&hrtc, &sTime, FORMAT_BIN);

//      if(!(secLast == sTime.Seconds))
//			 if((slave1Rsp==0)||(slave2Rsp==0)||(slave3Rsp==0)||(millisec1>50)){
//
//				 function8();
//			 }
//    	  function6_A(); //master to slave

      if(HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_5))
      {
    	  BLECommunication();
      }

    	  espCommunication();

    	  if(isReprogrammed==1)
    	  {
    		  return 1;
    	  }

    	  sendMsgToSlave();//through uart2 and uart6
//    	  functionTransmitToSlave((uint8_t *)Disp,19);
    	  slaveResponse();
    	  populatePrimaryHVSecondaryHV();
//    	  slaveResponseLORA();

//    		 if(millisec1>50){
//
//    	    	  				 function8();
//    	    	  			 }

//			if (slaveNo == noOfSides + 1) {
//				function8();
//			}
//HAL_Delay(1000);
//if(!(secLast == sec1))

    	  if(!(secLast == sec1))
//    	  if(sec1 > 1)
  {
//    		  sec1=0;
//    		  HAL_Delay(15000);
//    		  count=Disp[28];
    		  checkServerFieldAction();
    		  function8();
//    		  espCommunication();
//         if(Disp[28]==0)
    		  if(clearenceMode==1)
    		 if(count==0)
       	     break;

//    	  Disp[0] =Disp[0] -1;
//    	  Disp[1] =Disp[1] -1;
//    	  Disp[2] =Disp[2] -1;
//    	  Disp[3] =Disp[3] -1;


//    	  Disp[28]=Disp[28]-1; //readBytes[2] is phase time

//    	  slave2Rsp=0;

//        if(Flash_Data[2]==0)
//        	break;

//	     secLast=sTime.Seconds;
//    		  count=count-1;
    	  secLast=sec1;
       }
//    	  clearanceModeAction();
//    	  espCommunication();

    	  //------------------chnage mode command is given from server---------------------//
    		if(changeMode==1){
    			changeMode=0;
    			blinker();
    			}


		}
		phaseNo++;
		phase_No=phaseNo;
		AddressOfPhase1=AddressOfPhase1+4;
		if(phaseNo==Color[AddressOfPhase1])
		{
			countDown();
			side13Last=Disp[4];
			side24Last=Disp[5];
			Disp[4]=Color[AddressOfPhase1+1];  //side13
			Disp[5]=Color[AddressOfPhase1+2];  //side24
			phase_ID=Color[AddressOfPhase1+3]; //PhaseID
	        sideChange(side13Last,Disp[4],side24Last,Disp[5]);
//	        isReprogrammed=1;
		}



		if(phaseNo >totalPhase )
		{//totalPhase
			phaseNo=1;
			phase_No=phaseNo;
			clearDispBuffer() ;
			countDown();
//			AddressOfPhase1=AddressOfPhase;
			AddressOfPhase1=0;
			findSide(Color[1],Color[2]);
//			if(Color[1]==0x38) // green
//			{
//				Disp[0]=planS1GT;
//				Disp[1]=planS1GT+planA1GT;
//				Disp[2]=planS1GT+planA1GT+planS2GT+planA2GT;
//				Disp[3]=planS1GT+planA1GT+planS2GT+planA2GT+planS3GT+planA3GT;
//
//				Disp[28]=planS1GT;
//				Disp[4]=Color[1];
//				Disp[5]=Color[2];
//			}
//			else
//			{ //yellow
//						Disp[28]=planA1GT;
//						Disp[4]=Color[1];
//						Disp[5]=Color[2];
//
//			}


		}



			HAL_RTC_GetTime(&hrtc, &sTime, FORMAT_BIN);
			/*---------------Update RTC from GNSS Module-------begin------*/
			if(!(sDate.Date == DateLast))
			{
					getDateAndTimeFromGPS();

			}
			/*----------------Update RTC from GNSS Module-------- end-------- */





			     if (sTime.Hours==planOffHr)
			    	 if(sTime.Minutes>planOffM)
			    	 {
			    		returnMode=1;
			    		 return 1;
			    	 }

		        if (sTime.Hours>planOffHr){
		        	returnMode=1;
			return 1;
		        }

}




}

void countDown()
{

	if (planMode==2) //signal with without pedestrian
	     {
		switch(phase_No)
		{
		case 1:

			Disp[0]=planS1GT ;
			Disp[1]=Disp[0]+planA1GT;
			Disp[2]=Disp[1]+planA2GT+planS2GT;
			Disp[3]=Disp[2]+planA3GT+planS3GT;
			Disp[6]=Disp[3]+planA4GT+planS4GT;
			Disp[7]=0x8  ;
			break;

		case 2:

			Disp[0]=planA1GT ;
			Disp[1]=planA1GT;
			break;

		case 3:

			Disp[0]=planS2GT+planS3GT+planS4GT+planS5GT+planA2GT+planA3GT+planA4GT+planA5GT+padestarianTime;
			Disp[1]=planS2GT;
			break;

		case 4:
			Disp[1]=planA2GT ;
//			Disp[2]=planA2GT;
			Disp[7]=0x08  ;
	        break;

		case 5:

			Disp[1]=planS3GT+planS4GT+planS5GT+planA3GT+planA4GT+planA5GT+padestarianTime+planS1GT+planA1GT;
			Disp[2]=planS3GT;
		    Disp[7]=0x08  ;
		    break;

		case 6:
			Disp[2]=planA3GT ;
//			Disp[3]=planA3GT;
			Disp[7]=0x08 ;
			break;

		case 7:

			Disp[2]=planS4GT+planS5GT+planA4GT+planA5GT+planS1GT+planA1GT+planA2GT+planS2GT+padestarianTime ;
			Disp[3]=planS4GT;
			Disp[7]=0x08  ;
			break;

		case 8:
			Disp[3]=planA4GT ;
//			Disp[0]=planA4GT;
			Disp[7]=0x08  ;
			break;

		case 9:

			Disp[3]=planS5GT+planA5GT+padestarianTime+planA1GT+planS1GT+planA2GT+planS2GT
			+planA3GT+planS3GT;
			Disp[6]=planS5GT ;
			Disp[7]=0x03  ;
			break;

		}



		 }



	if (planMode==3) //signal with pedestrian
     {
//        if(noOfSides==4)
		switch(phase_No)
		{
	case 1: //side1 green

		Disp[0]=planS1GT ;
		Disp[1]=Disp[0]+planA1GT;
		Disp[2]=Disp[1]+planA2GT+planS2GT;
		Disp[3]=Disp[2]+planA3GT+planS3GT;
		Disp[6]=Disp[3]+planA4GT+planS4GT;
		Disp[7]=0x8  ;
		break;

	case 2: //side1 yellow

		Disp[0]=planA1GT ;
		Disp[1]=planA1GT;
		break;

	case 3: //side 2 green

		Disp[0]=planS2GT+planS3GT+planS4GT+planS5GT+planA2GT+planA3GT+planA4GT+planA5GT+padestarianTime ;
		Disp[1]=planS2GT;
		break;

	case 4:  //side2 yellow
		Disp[1]=planA2GT ;
		Disp[2]=planA2GT;

		Disp[7]=0x08  ;
        break;

	case 5: //side3 green
//		Disp[0]=Disp[0]+padestarianTime;
		Disp[1]=planS3GT+planS4GT+planS5GT+planA3GT+planA4GT +planA5GT+padestarianTime+padestarianTime;
		Disp[2]=planS3GT;
	    Disp[7]=0x08  ;
	    break;

	case 6: //side3 yellow
		Disp[2]=planA3GT ;
		Disp[3]=planA3GT;
		Disp[7]=0x08 ;
		break;

	case 7:

		Disp[2]=planS1GT+planS2GT+planS4GT+planS5GT+planA1GT+planA2GT+planA4GT+planA5GT+padestarianTime ;
		Disp[3]=planS4GT;
		Disp[7]=0x08  ;
		break;

	case 8:
		Disp[3]=planA4GT ;
//		Disp[0]=planA4GT;
		Disp[7]=0x08  ;
		break;

	case 9:

//		if(Disp[0]==0)
//		{
//			Disp[0]=padestarianTime;
//			Disp[1]=padestarianTime;
//			Disp[2]=padestarianTime;
//		}
		Disp[3]=planS1GT+planS2GT+planS3GT+planA1GT+planA2GT+planA3GT +planS5GT+planA5GT+padestarianTime ;
		Disp[6]=planS5GT ;
		Disp[7]=0x03  ;
		break;





	 }
	}

}



void clearanceModeAction(){

//-----------------------------jump-------------------------//
	if (clearenceMode==4)

		if (!((Disp[4]==0x84)||(Disp[4]==0x48)||(Disp[5]==0x84)||(Disp[5]==0x48)))
					{
						if(Disp[28] > 5){
							Disp[28] =Disp[28]-5;
							Disp[0] =Disp[0]-Disp[28]  ;
	       Disp[1] = Disp[1]-Disp[28]  ;
	       Disp[2] = Disp[2]-Disp[28] ;
	       Disp[3] = Disp[3]-Disp[28] ;
	       Disp[6] = Disp[6]-Disp[28];
	       Disp[28] =5;
						}
		//				count=5;
				 clearenceModeLast=1 ;
					clearenceMode=1;
	//	return ;
						}

						else
							{
				 clearenceModeLast=1 ;
					clearenceMode=1;

							}
//-------------------------------------extend-----------------------------------//
	if (clearenceMode==6)
		{
	    if((Disp[28]<20) && (Disp[28]>10))
			{
//				if(extendCnt <3 )
//					{
			Disp[0] = Disp[0] + 4 ;
	       Disp[1] = Disp[1] + 4 ;
	       Disp[2] = Disp[2] + 4 ;
	       Disp[3] = Disp[3] + 4 ;
	       Disp[28] = Disp[28] + 4 ;
			 clearenceModeLast=1 ;
					clearenceMode=1;
//			extendCnt++;
//				}
//					else{
//
//
//					}
			}
		}
//----------------------------------clear----------------------------------//

	if 	(clearenceModeLast==2)
	if (clearenceMode==1)
		{
	   Disp[0] = Disp[30]  ;
       Disp[1] = Disp[31]  ;
       Disp[2] = Disp[32] ;
       Disp[3] = Disp[33]  ;
       Disp[4] = Disp[34] ;
	   Disp[5] = Disp[35]  ;
       Disp[6] = Disp[36]  ;
       Disp[7] = Disp[37] ;
	clearenceModeLast=1 ;
					}
	if (clearenceMode==2)
						{
		   Disp[30] = Disp[0]  ;
	       Disp[31] = Disp[1]  ;
	       Disp[32] = Disp[2] ;
	       Disp[33] = Disp[3]  ;
	       Disp[34] = Disp[4] ;
		   Disp[35] = Disp[5]  ;
	       Disp[36] = Disp[6]  ;
	       Disp[37] = Disp[7] ;
		     clearenceModeLast=2 ;
//			secLast =RTC_TimeStructure.RTC_Seconds ;
		     Disp[28]=1 ;
	       Disp[0] = 1 ;
	       Disp[1] = 1 ;
	       Disp[2] = 1 ;
	       Disp[3] = 1 ;
	       Disp[6] = 1 ;
	switch (clearenceSide)
		{
	case 1 :
		Disp[4] =0x38 ;
		Disp[5] =0x88 ;
		Disp[7]=Disp[7]| 0x80 ;

		break ;
	case 2 :
		Disp[4] =0x88 ;
		Disp[5] =0x38 ;
		Disp[7]=Disp[7]| 0x80 ;

		break ;
	case 3 :
		Disp[4] =0x83 ;
		Disp[5] =0x88 ;
		Disp[7]=Disp[7]| 0x80 ;

		break ;
	case 4 :
		Disp[4] =0x88 ;
		Disp[5] =0x83 ;
		Disp[7]=Disp[7]| 0x80 ;

		break ;
	case 5 :
		Disp[4] =0x88 ;
		Disp[5] =0x88 ;
		Disp[7]=Disp[7]| 0x03 ;

		break ;
	}
						}



}


//int transmitData(int phaseTime){
//
//	if (!(planMode==1)){
//
//		if(changeMode==1){
//
//		return;
//		}
//
////readInputPin();
//RTC_GetDate(RTC_Format_BIN, &RTC_DateStructure);
//RTC_GetTime(RTC_Format_BIN, &RTC_TimeStructure);
//if (secLast !=RTC_TimeStructure.RTC_Seconds )
//{
//	secLast =RTC_TimeStructure.RTC_Seconds ;
//
//
//
//	//------------------------------ field action-------------------//
//
//	checkFieldAction();
//
//
////----------------------------extend--//
//
//
//if (clearenceMode==6)
//{
//if(!((count>10) && (count<20)))
//	{
//clearenceMode=1;
//
//}
//
//}
//if(fieldActionFlag==0)//request is not coming from field
//if(checkServerJumpExtend==0){//request is not from server
//if((extendCnt==3)||(extendCnt >3)){
//clearenceMode=1;
//extendCnt1=1;
//
//}
//}
//else{
//extendCnt=0;
//
//}
//
//
//	if (clearenceMode==4)
//{
//if(count<6){
//clearenceMode=1;
//
//}
//
//}
//if (clearenceMode==1)
//	{
//		Disp[19]=0;
//	count-- ;
//   Disp[0] = Disp[0] - 1 ;
//   Disp[1] = Disp[1] - 1 ;
//   Disp[2] = Disp[2] - 1 ;
//   Disp[3] = Disp[3] - 1 ;
//   Disp[6] = Disp[6] - 1 ;
//  if(lSec<9)
//		lSec=lSec-1;
//		if(lSec==0)
//		{
//lSec=10;
//clearenceMode=4;
//		 pin_HighLast=0;
//}
////------------------for extend--------------//
//
//  if(lsSec<9)
//		lsSec=lsSec-1;
//		if(lsSec==0)
//		{
//lsSec=10;
//clearenceMode=6;
//		 pinExtend_HighLast=0;
//}
//
//
//byteToIntegerVal(&Disp[0],0);
//byteToIntegerVal(&Disp[4],4);
////	byteToIntegerVal(&Disp[8],8);      1
//CRCValue = CRC_CalcBlockCRC((uint32_t *)stringInt, 8);
//intToByte(CRCValue);
//CRC_ResetDR();
//
//if(extendCnt1==1)
//{
////clearenceMode=6;
//extendCnt1=0;
//}
//	}
////		puts3(&Disp[0]);
//	msgCount++;
//	Delay(175);
////		function8();
//// 	if (!(programVersionNoLast==programVersionNo))
//// 		return ;
////		 		readInputPin();
//	//if(fieldActionFlag==0)//request is not coming from field
//	if((checkServerJumpExtend==0)&&(fieldActionFlag==0))// request is not coming from server and field
//		{
//		laser(); //request is coming from camera
//	extend();
//
//	}
//	else //request is coming from server or field
//		{
//		lsSec=10;
//		lSec=10;
//		extendCnt=0;
//
//
//	}
////		 checkGreenSide();
////		if(!(greenSide==greenSideLast)){
////  	//extend();
////			if(extendCnt >2)
////				{
////		greenSideLast	= greenSide;
////			extendCnt=0;
////			}
////			else{
////	//				extendCnt++;
////				extend();
//////				if(pinExtend_High==0)
//////					{
//////						greenSideLast	= greenSide;
//////				}
////			}
////		}else{
////
////		extendCnt=10;
////		}
//	if 	(!(clearenceModeLast==clearenceMode))
//	{
//	if 	(clearenceModeLast==2)
//if (clearenceMode==1)
//	{
//     Disp[0] = Disp[10]  ;
//   Disp[1] = Disp[11]  ;
//   Disp[2] = Disp[12] ;
//   Disp[3] = Disp[13]  ;
//   Disp[4] = Disp[14] ;
//     Disp[5] = Disp[15]  ;
//   Disp[6] = Disp[16]  ;
//   Disp[7] = Disp[17] ;
//clearenceModeLast=1 ;
//				}
//if (clearenceMode==2)
//				{
//     Disp[10] = Disp[0]  ;
//   Disp[11] = Disp[1]  ;
//   Disp[12] = Disp[2] ;
//   Disp[13] = Disp[3]  ;
//   Disp[14] = Disp[4] ;
//     Disp[15] = Disp[5]  ;
//   Disp[16] = Disp[6]  ;
//   Disp[17] = Disp[7] ;
//     clearenceModeLast=2 ;
//	secLast =RTC_TimeStructure.RTC_Seconds ;
//	count=1 ;
//   Disp[0] = 1 ;
//   Disp[1] = 1 ;
//   Disp[2] = 1 ;
//   Disp[3] = 1 ;
//   Disp[6] = 1 ;
//switch (clearenceSide)
//{
//case 1 :
//Disp[4] =0x38 ;
//Disp[5] =0x88 ;
//Disp[7]=Disp[7]| 0x80 ;
//
//break ;
//case 2 :
//Disp[4] =0x88 ;
//Disp[5] =0x38 ;
//Disp[7]=Disp[7]| 0x80 ;
//
//break ;
//case 3 :
//Disp[4] =0x83 ;
//Disp[5] =0x88 ;
//Disp[7]=Disp[7]| 0x80 ;
//
//break ;
//case 4 :
//Disp[4] =0x88 ;
//Disp[5] =0x83 ;
//Disp[7]=Disp[7]| 0x80 ;
//
//break ;
//case 5 :
//Disp[4] =0x88 ;
//Disp[5] =0x88 ;
//Disp[7]=Disp[7]| 0x03 ;
//
//break ;
//}
//
//				}
////-------------------------------------jump ----------------------//
//if (clearenceMode==4)
//{
//if (!((Disp[4]==0x84)||(Disp[4]==0x48)||(Disp[5]==0x84)||(Disp[5]==0x48)))
//			{
//				if(count > 5){
//					count =count-5;
//					Disp[0] =Disp[0]-count  ;
//   Disp[1] = Disp[1]-count  ;
//   Disp[2] = Disp[2]-count ;
//   Disp[3] = Disp[3]-count ;
//   Disp[6] = Disp[6]-count;
//				count =5;
//				}
////				count=5;
//		 clearenceModeLast=1 ;
//			clearenceMode=1;
////	return ;
//				}
//	}
//				else
//					{
//		 clearenceModeLast=1 ;
//			clearenceMode=1;
//
//					}
////--------------------------------extend----------------------//
//if (clearenceMode==6)
//{
//if((count<20) && (count>10))
//	{
//		if(extendCnt <3 )
//			{
//	Disp[0] = Disp[0] + 4 ;
//   Disp[1] = Disp[1] + 4 ;
//   Disp[2] = Disp[2] + 4 ;
//   Disp[3] = Disp[3] + 4 ;
//		 count = count + 4 ;
//	 clearenceModeLast=1 ;
//			clearenceMode=1;
//	extendCnt++;
//		}
//			else{
//
//
//			}
//	}
//}
////---------------------------- time mismatch--------------------//
//if (clearenceMode==9)
//{
//Disp[4] =0x00 ;
//Disp[5] =0x00 ;
//	 clearenceModeLast=9 ;
//}
//	if (clearenceMode==1)
//		clearenceModeLast=1 ;
//}
//	function8();
//
////		Delay(100);
//}
//}
//
//
//
//
//
//}




void phaseInfoAddress(){

//addressInfo = 0x08007000;
int add=0;

	for (int i=1 ;i<noOfPlans+1;i++){
//		getPhase(i);
		getPhaseSD(i);
		for(int j=1;j<noOfPhase+1;j++){

//			test1[i][j][j]= (__IO uint32_t*) addressInfo;
			test1[i][j][j]= add;
			add=add+15;
//			addressInfo =addressInfo + 60;






		}

//		addressInfo =addressInfo + 12;
		a[9][9][9]=a[1][1][1];


	}


	SDcardReadSeek("phase.txt",350, 0);


}
void sendMsgToSlave(){
   	//-------------------------------every 50 millisec transmitting the data to slave-------------------------//
//		 	   	       	if(millisec1>50)
//	 	   	       		if((slave1Rsp==1)||(slave2Rsp==1)||(slave3Rsp==1)||(slave4Rsp==1)||(millisec1>60))
//	                    if((slave4Rsp==1)||(millisec1>150))
//	                    if((slave1Rsp==1)||(slave2Rsp==1)||(slave3Rsp==1)||(millisec1>70))
						if(millisec1>150)
	 	   	       	{
//		 	   	       		if(slaveNo>3)
//		 	   	       		{
//		 	   	       			slaveNo=1;
//
//		 	   	       		}

		if (slaveNo == 1) {
			if (slave1Transmit == 1) {
				if (slave1Rsp == 1) {
//						communicationStatus = 0x01;
					communicationStatus = communicationStatus | 0x01;
				} else {
//						communicationStatus = 0x00;
					communicationStatus = communicationStatus & 0x06;
				}
				slave1Transmit=0;
				slaveNo++;//incrementing the value of slave
			}
		}
		if (slaveNo == 2) {
			if (slave2Transmit == 1) {
				if (slave2Rsp == 1) {
//						communicationStatus = 0x02;
					communicationStatus = communicationStatus | 0x02;
				} else {
//						communicationStatus = 0x00;
					communicationStatus = communicationStatus & 0x05;
				}
				slave2Transmit=0;
				slaveNo++;//incrementing the value of slave
			}
		}

		if (slaveNo == 3) {
			if (slave3Transmit == 1) {
				if (slave3Rsp == 1) {
//						communicationStatus = 0x04;
								communicationStatus = communicationStatus | 0x04;
				} else {
//						communicationStatus = 0x00;
					communicationStatus = communicationStatus & 0x03;
				}
				slave3Transmit = 0;
				slaveNo++;		 	   	   //incrementing the value of slave
			}
		}
		if (slaveNo == 4) {
				if (slave4Transmit == 1) {
					if (slave4Rsp == 1) {
	//						communicationStatus = 0x04;
									communicationStatus = communicationStatus | 0x08;
					} else {
	//						communicationStatus = 0x00;
						communicationStatus = communicationStatus & 0x07;
					}
					slave4Transmit = 0;
					slaveNo++;		 	   	   //incrementing the value of slave
				}
			}

//		RecMsg4[0]=communicationStatus;
//		RecMsg4[1]=0x0D;
//		RecMsg4[2]=0x0A;
//		HAL_UART_Transmit (&huart4, (uint8_t*)RecMsg4,3,500) ;


//			if(communicationStatus == 0x00)
//			{
//				communicationStatus = 6;
//			}

//		if (slaveNo == noOfSides + 1) {
//						function8();
//					}



//		                           if(slaveNo>noOfSides+1)

//		                        	   if(slaveNo==noOfSides)
		                         if(noOfSides != 3)
 	                             if(slaveNo>4)

				 	   	       		{
				 	   	       			slaveNo=1;

				 	   	       		}
		                         if(noOfSides==3)
		                         {
		                        	 if(slaveNo>3)
		                        	 {
		                        		 slaveNo=1;
		                        	 }
		                         }

//		                 if (!(slaveNo == noOfSides + 1)){

	 	   	       		function6_A(); //Master to slave1

//		                 }


	 	   	       		if(slaveNo==1)
	 	   	       		{
	 	   	       		slave1Transmit=1;
//		 	   	         	slave2Transmit=0;

		                 }
	                   	if (slaveNo == 2) {
//		                   	slave1Transmit=0;
	                   	slave2Transmit=1;

		                 }
	                   	if (slaveNo == 3) {
	                   	//		                   	slave1Transmit=0;
	                   	slave3Transmit=1;

	                   	}
	                	if (slaveNo == 4) {
	            		//		                   	slave1Transmit=0;
		            	slave4Transmit = 1;

		                }

                        /*----------all slave response status to 0-------------*/
	                   	slave1Rsp=0;
	                   	slave2Rsp=0;
	                   	slave3Rsp=0;
	                	slave4Rsp=0;
//	 	   	       		msgTx++;
//		 	   	       		slaveNo++;//incrementing the value of slave
	                   	millisec1=0;
	 	   	       		//commFlag++;
	 	   	       	}
}
void slaveResponse(){



		/*uart2 PC13 PD5*/
//	       	if(SDCardMsg==0)
//			  	if(msgUnPrcd==1)
	if(msgUnPrcd4==1)
	{


					functionRec=0;
//					  		 signVal=msgParse((uint8_t *)RecMsg2,"}",0); //for slave
					signVal=msgParse((uint8_t *)RecMsg4,"}",0); //for slave

//					  		signVal=msgParse((uint8_t *)RecMsg2,"~~~~",0);  //for master
					  		if(!(signVal==0))
					  		{
					  			 signVal=signVal-6;
					  			transferRecValuesToData(signVal);
//						  			transferRecValuesToData(signVal);
//					              transferRecValuesToData(0);
					  		  byteToIntegerVal(&Data[0],0);
					  		CRCValue = HAL_CRC_Calculate(&hcrc,(uint32_t *)stringInt, 8);
					  		  crcbits =	CRCValue;

					  		  crcstring[0] = crcbits & 0xFF;

					  		  crcstring[1] = (crcbits >> 8) & 0xFF;

					  		  crcstring[2] = (crcbits >> 16) & 0xFF;

					  		  crcstring[3] = (crcbits >> 24) & 0xFF;
//					  		CRC_ResetDR();
					  		  /*-------------------------slave side-----------------------------------*/
//					  		if(RecMsg2[10] == crcstring[3])
//					  		{
//					  		if(RecMsg2[11] == crcstring[2])
//					  		{
//					  		if(RecMsg2[12] == crcstring[1])
//					  		{
//					  		if(RecMsg2[13] == crcstring[0])
					  		  /*-------------------------master side----------------------------------*/
						  		if(RecMsg4[10] == crcstring[3])
						  		{
						  		if(RecMsg4[11] == crcstring[2])
						  		{
						  		if(RecMsg4[12] == crcstring[1])
						  		{
						  		if(RecMsg4[13] == crcstring[0]){
                                    /*-------------------Side 1----------------------------------*/
						  			if(RecMsg4[5]== 1)//comparing the receive msg with side
						  			{
						  				if(RecMsg4[0] == 0xFF)
						  					primaryByte[1]=0x00;
						  				else
						  				primaryByte[1]=RecMsg4[0];
						  				if(RecMsg4[1] == 0xFF)
						  					secondaryByte[1]=0x00;
						  				else
						  					secondaryByte[1]=RecMsg4[1];
//						  				secondaryByte[1]=RecMsg4[1];
						  				hundredPlaceSegment[1]=RecMsg4[2];
						  				tenPlaceSegment[1]=RecMsg4[3];
						  				unitPlaceSegment[1]=RecMsg4[4];
						  				HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_3);
						  			slave1Rsp=1;
						  			}
						  			/*-------------------Side 2----------------------------------*/
						  			if(RecMsg4[5]== 2){

								    if (RecMsg4[0] == 0xFF)
								    	primaryByte[2] = 0x00;
								    else
								    	primaryByte[2] = RecMsg4[0];
								    if (RecMsg4[1] == 0xFF)
								    	secondaryByte[2] = 0x00;
								    else
								    	secondaryByte[2] = RecMsg4[1];
//						  				primaryByte[2]=RecMsg4[0];
//						  				secondaryByte[2]=RecMsg4[1];
								        hundredPlaceSegment[2] = RecMsg4[2];
								        tenPlaceSegment[2] = RecMsg4[3];
								        unitPlaceSegment[2] = RecMsg4[4];
								        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_3);
						  			slave2Rsp=1;
						  			}
						  			/*-------------------Side 3----------------------------------*/
						  			if(RecMsg4[5]== 3){

									    if (RecMsg4[0] == 0xFF)
									    	primaryByte[3] = 0x00;
									    else
									    	primaryByte[3] = RecMsg4[0];
									    if (RecMsg4[1] == 0xFF)
									    	secondaryByte[3] = 0x00;
									    else
									    	secondaryByte[3] = RecMsg4[1];

//						  				primaryByte[3]=RecMsg4[0];
//						                secondaryByte[3]=RecMsg4[1];
							         	hundredPlaceSegment[3] = RecMsg4[2];
								        tenPlaceSegment[3] = RecMsg4[3];
								        unitPlaceSegment[3] = RecMsg4[4];
								        HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_2);
						            slave3Rsp=1;
						  			}
						  			/*-------------------Side 4----------------------------------*/
						  			if(RecMsg4[5]== 4){

									    if (RecMsg4[0] == 0xFF)
									    	primaryByte[3] = 0x00;
									    else
									    	primaryByte[3] = RecMsg4[0];
									    if (RecMsg4[1] == 0xFF)
									    	secondaryByte[3] = 0x00;
									    else
									    	secondaryByte[3] = RecMsg4[1];


//						  				primaryByte[4]=RecMsg4[0];
//						  				secondaryByte[4]=RecMsg4[1];
						  				hundredPlaceSegment[4] = RecMsg4[2];
						  				tenPlaceSegment[4] = RecMsg4[3];
						  				unitPlaceSegment[4] = RecMsg4[4];
						  				HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_3);
						  				slave4Rsp=1;
						  			}
//						  			/*-------------------Side 5----------------------------------*/
//						  			if(RecMsg4[5]== 5){
//						  				primaryByte[5]=RecMsg4[0];
//						  				secondaryByte[5]=RecMsg4[1];
//						  				hundredPlaceSegment[5] = RecMsg4[2];
//						  				tenPlaceSegment[5] = RecMsg4[3];
//						  				unitPlaceSegment[5] = RecMsg4[4];
//						  				slave5Rsp=1;
//						  			}
//						  			HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_8);//master

						  			HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_3);//master
						  			analysingResponseOfSlave();
//						  			msgRec++;
//						  			commFlag++;
//							  			function6_A();//usart2
//							       		millisec1=0;

						  			//function6_A(); ///slave1
						  			/*---------master-----------*/
//						  			if(commFlag==0)
//						  			{
//						  			function6(); //master
//						  			}
//						  			if(RecMsg2[9]==0x09){
////						  				function66();
//						  				commFlag=1;
//						  			}

						  		}

					  		}
					  		}
					  		}
					  		 // clearingRecBuffer();
//						  		commFlag=1;
						  	//	sec=0;
//						  		millisec1=0;

						  		//msgUnPrcd=0;
						  		msgUnPrcd4=0;

					  				}


//		  			  	signVal=msgParse((uint8_t *)RecMsg2,"~~~~",0);
//		  			  if (!(signVal == 0 )){
//		  			  			// transferDataValues(signVal);
//		  				checkMsgLengthForUart2();
//		  			  	HAL_UART_Transmit (&huart1, (uint8_t*)RecMsg2,recCnt1,5000) ;
//		  			  		  			  		}
					clearingDataBuffer();
//			  		clearBuffer();
//			  		clearaRxBuffer();

			  		clearBuffer4();
			  		clearaRxBuffer4();
//			  		msgUnPrcd=0;
			  		msgUnPrcd4=0;
			  	//	transmit();
			  	}






}

void slaveResponseLORA(){



		/*uart6 */
//	       	if(SDCardMsg==0)
//			  	if(msgUnPrcd==1)
	if(msgUnPrcd==1)
	{


					functionRec=0;
//					  		 signVal=msgParse((uint8_t *)RecMsg2,"}",0); //for slave
					signVal=msgParse((uint8_t *)RecMsg2,"}",0); //for slave

//					  		signVal=msgParse((uint8_t *)RecMsg2,"~~~~",0);  //for master
					  		if(!(signVal==0))
					  		{
					  			 signVal=signVal-6;
					  			 transferRecValuesToDataRecMsg2(signVal);
//						  			transferRecValuesToData(signVal);
//					              transferRecValuesToData(0);
					  		  byteToIntegerVal(&Data[0],0);
					  		CRCValue = HAL_CRC_Calculate(&hcrc,(uint32_t *)stringInt, 8);
					  		  crcbits =	CRCValue;

					  		  crcstring[0] = crcbits & 0xFF;

					  		  crcstring[1] = (crcbits >> 8) & 0xFF;

					  		  crcstring[2] = (crcbits >> 16) & 0xFF;

					  		  crcstring[3] = (crcbits >> 24) & 0xFF;
//					  		CRC_ResetDR();
					  		  /*-------------------------slave side-----------------------------------*/
//					  		if(RecMsg2[10] == crcstring[3])
//					  		{
//					  		if(RecMsg2[11] == crcstring[2])
//					  		{
//					  		if(RecMsg2[12] == crcstring[1])
//					  		{
//					  		if(RecMsg2[13] == crcstring[0])
					  		  /*-------------------------master side----------------------------------*/
						  		if(RecMsg2[10] == crcstring[3])
						  		{
						  		if(RecMsg2[11] == crcstring[2])
						  		{
						  		if(RecMsg2[12] == crcstring[1])
						  		{
						  		if(RecMsg2[13] == crcstring[0]){
                                    /*-------------------Side 1----------------------------------*/
						  			if(RecMsg2[5]== 1)//comparing the receive msg with side
						  			{
						  				primaryByte[1]=RecMsg2[0];
						  				secondaryByte[1]=RecMsg2[1];
						  				hundredPlaceSegment[1]=RecMsg2[2];
						  				tenPlaceSegment[1]=RecMsg2[3];
						  				unitPlaceSegment[1]=RecMsg2[4];

						  			slave1Rsp=1;
						  			}
						  			/*-------------------Side 2----------------------------------*/
						  			if(RecMsg4[5]== 2){
						  				primaryByte[2]=RecMsg2[0];
						  				secondaryByte[2]=RecMsg2[1];
								        hundredPlaceSegment[2] = RecMsg2[2];
								        tenPlaceSegment[2] = RecMsg2[3];
								        unitPlaceSegment[2] = RecMsg2[4];
						  			slave2Rsp=1;
						  			}
						  			/*-------------------Side 3----------------------------------*/
						  			if(RecMsg4[5]== 3){
						  				primaryByte[3]=RecMsg2[0];
						                secondaryByte[3]=RecMsg2[1];
							         	hundredPlaceSegment[3] = RecMsg2[2];
								        tenPlaceSegment[3] = RecMsg2[3];
								        unitPlaceSegment[3] = RecMsg2[4];
						            slave3Rsp=1;
						  			}

//						  			HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_8);//master
						  			HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_3);//master
//						  			msgRec++;
//						  			commFlag++;
//							  			function6_A();//usart2
//							       		millisec1=0;

						  			//function6_A(); ///slave1
						  			/*---------master-----------*/
//						  			if(commFlag==0)
//						  			{
//						  			function6(); //master
//						  			}
//						  			if(RecMsg2[9]==0x09){
////						  				function66();
//						  				commFlag=1;
//						  			}

						  		}

					  		}
					  		}
					  		}
					  		 // clearingRecBuffer();
//						  		commFlag=1;
						  	//	sec=0;
//						  		millisec1=0;

						  		//msgUnPrcd=0;
						  		msgUnPrcd=0;

					  				}


//		  			  	signVal=msgParse((uint8_t *)RecMsg2,"~~~~",0);
//		  			  if (!(signVal == 0 )){
//		  			  			// transferDataValues(signVal);
//		  				checkMsgLengthForUart2();
//		  			  	HAL_UART_Transmit (&huart1, (uint8_t*)RecMsg2,recCnt1,5000) ;
//		  			  		  			  		}
					clearingDataBuffer();
//			  		clearBuffer();
//			  		clearaRxBuffer();

					 clearBuffer();
			  		clearaRxBuffer();
//			  		msgUnPrcd=0;
			  		msgUnPrcd=0;
			  	//	transmit();
			  	}






}



void analysingResponseOfSlave()
{
//Disp[4]=0x88; //side 13
//Disp[5]=0x83; //side 24
//primaryByte[1]=0x30;
//side1PoleType=3;
//side2PoleType=3;
//side3PoleType=3;
//side4PoleType=3;
/*----------------Separating the values of sides------------------*/
sideNo1= Disp[4] >> 4; // right shift 4 bit
sideNo1=sideNo1 << 4 ; //left shift 4 bit
sideNo3=  Disp[4] ^ sideNo1; //

sideNo2= Disp[5] >> 4; // right shift 4 bit
sideNo2=sideNo2 << 4 ; //left shift 4 bit
sideNo4=  Disp[5] ^ sideNo2; //

/*-------------------------checking the pole type----------------------------*/

/*-------------------------pole type = standard pole----------------------------*/
if(side1PoleType==1)//standard pole
{

	primaryByteCommand[1]=sideNo1;
	secondaryByteCommand[1]=sideNo1;
	if(primaryByteCommand[1]==primaryByte[1])
	{
		if(primaryByte[1]==0x30) ///green
		{
			if((primaryByte[2]==0x30)||(primaryByte[3]==0x30)||(primaryByte[4]==0x30)){
				return;
                      // urgent case (shut dowm the signal coz no 2 side lights can be green at a time).
			}
		}
         //working right
	}
	else{
	 checkSideColour(primaryByteCommand[1],primaryByte[1],1);

		//not working
	}
}
if(side2PoleType==1)//standard pole
{
	primaryByteCommand[2]=sideNo2;
	secondaryByteCommand[2]=sideNo2;
		if(primaryByteCommand[2]==primaryByte[2])
		{
	         //working right
		}
		else{
			//not working
		}
}
if(side3PoleType==1)//standard pole
{
	sideNo3=sideNo3 << 4; // left shit 4 bit
	primaryByteCommand[3]=sideNo3;
	secondaryByteCommand[3]=sideNo3;
		if(primaryByteCommand[3]==primaryByte[3])
		{
	         //working right
		}
		else{
			//not working
		}
}

if(side4PoleType==1)//standard pole
{
	sideNo4=sideNo4 << 4; // left shit 4 bit
	primaryByteCommand[4]=sideNo4;
	secondaryByteCommand[4]=sideNo4;
		if(primaryByteCommand[4]==primaryByte[4])
		{
	         //working right
		}
		else{
			//not working
		}
}
/*-------------------------pole type = L-cantilever pole----------------------------*/
if(side1PoleType==2)
{
	secondaryByteCommand[1]=sideNo1;
	primaryByteCommand[1]= sideNo1 >> 4; // right shift 4 bit
	primaryByteCommand[1]=primaryByteCommand[1] | secondaryByteCommand[1];


	if(primaryByteCommand[1]==primaryByte[1])
	{

         //working right
	}
	else{
	 checkSideColour(primaryByteCommand[1],primaryByte[1],1);

		//not working
	}
}

if(side2PoleType==2)
{

	secondaryByteCommand[2]=sideNo2;
	primaryByteCommand[2]= sideNo2 >> 4; // right shift 4 bit
	primaryByteCommand[2]=primaryByteCommand[2] | secondaryByteCommand[2];


	if(primaryByteCommand[1]==primaryByte[1])
	{

         //working right
	}
	else{
	 checkSideColour(primaryByteCommand[1],primaryByte[1],1);

		//not working
	}
}

if(side3PoleType==2)
{
	secondaryByteCommand[3]=sideNo3 << 4; // left shit 4 bit
//	secondaryByteCommand[3]=sideNo3;
	primaryByteCommand[3]= sideNo3 ;
	primaryByteCommand[3]=primaryByteCommand[3] | secondaryByteCommand[3];


	if(primaryByteCommand[3]==primaryByte[3])
	{

         //working right
	}
	else{
	 checkSideColour(primaryByteCommand[3],primaryByte[3],2);

		//not working
	}
}

if(side4PoleType==2)
{
	secondaryByteCommand[4]=sideNo4 << 4; // left shit 4 bit
//	secondaryByteCommand[4]=sideNo4;
	primaryByteCommand[4]= sideNo4 ;
	primaryByteCommand[4]=primaryByteCommand[4] | secondaryByteCommand[4];


	if(primaryByteCommand[4]==primaryByte[4])
	{

         //working right
	}
	else{
	 checkSideColour(primaryByteCommand[4],primaryByte[4],2);

		//not working
	}
}
/*-------------------------pole type = T-cantilever pole----------------------------*/
if(side1PoleType==3)
{

	primaryByteCommand[1]= sideNo1 >> 4; // right shift 4 bit
	primaryByteCommand[1]=primaryByteCommand[1] | sideNo1;
	secondaryByteCommand[1]=primaryByteCommand[1];

	if(primaryByteCommand[1]==primaryByte[1])
	{

         //working right
	}
	else{
	 checkSideColour(primaryByteCommand[1],primaryByte[1],1);

		//not working
	}
}

if(side2PoleType==3)
{


	primaryByteCommand[2]= sideNo2 >> 4; // right shift 4 bit
	primaryByteCommand[2]=primaryByteCommand[2] | sideNo2;
	secondaryByteCommand[2]=primaryByteCommand[2];

	if(primaryByteCommand[1]==primaryByte[1])
	{

         //working right
	}
	else{
	 checkSideColour(primaryByteCommand[1],primaryByte[1],1);

		//not working
	}
}

if(side3PoleType==3)
{
	secondaryByteCommand[3]=sideNo3 << 4; // left shit 4 bit
	primaryByteCommand[3]= sideNo3 ;
	primaryByteCommand[3]=primaryByteCommand[3] | secondaryByteCommand[3];
	secondaryByteCommand[3]=primaryByteCommand[3];

	if(primaryByteCommand[3]==primaryByte[3])
	{

         //working right
	}
	else{
	 checkSideColour(primaryByteCommand[3],primaryByte[3],2);

		//not working
	}
}

if(side4PoleType==3)
{
	secondaryByteCommand[4]=sideNo4 << 4; // left shit 4 bit
//	secondaryByteCommand[4]=sideNo4;
	primaryByteCommand[4]= sideNo4 ;
	primaryByteCommand[4]=primaryByteCommand[4] | secondaryByteCommand[4];
	secondaryByteCommand[4]=primaryByteCommand[4];


	if(primaryByteCommand[4]==primaryByte[4])
	{

         //working right
	}
	else{
	 checkSideColour(primaryByteCommand[4],primaryByte[4],2);

		//not working
	}
}










}


void checkSideColour(int aspectColor,int slaveAspectColor,int poleType){

if(poleType==1)//for standard pole
{
	switch (aspectColor)
	{
	case 0x80: // red

		switch (slaveAspectColor) {
//			case 0x40://yellow
//                      //severe
//				break;
			case 0x30://green

                      //urgent case
				break;
			case 0xF0://green+yellow+red
		                      //urgent case
			break;
			case 0xB0://red+green
                      //urgent case
			    break;
			case 0x10://G1
			                      //urgent case
			    break;
			case 0x20://G2
			                      //urgent case
		    break;
			case 0xA0://red+G1
			                      //urgent case
		    break;
			case 0x90://red+G2
			                      //urgent case
		    break;
			case 0xD0://red+yellow+G2
			                      //urgent case
		    break;
			case 0xE0://red+yellow+G1
			                      //urgent case
		    break;

			default:
				// severe case
				break;
		}
 break;
 case 0x30: // green

	 switch (slaveAspectColor) {

	 			default:
	 				// severe case
	 				break;
	 		}

	 break;

	 case 0x40: //yellow
		 switch (slaveAspectColor) {

		                case 0x30://G1+G2
		                       //urgent case
		 			    break;
		                case 0x80://red
		                       //urgent case
		                 break;
		                case 0xB0://red+green
		                       //urgent case
		                break;
		                case 0xF0://red+green+yellow
		                      //urgent case
		                break;
		                case 0xC0://red+yellow
		                     //urgent case
		                break;
		                case 0xA0://red+G1
		                    //urgent case
		                break;
		                case 0x90://red+G2
                           //urgent case
		                break;
		                case 0xE0://red+G1+Y
                          //urgent case
		                break;
		                case 0xD0://red+G2+y
		                  //urgent case
		                break;


			 			default:
			 				// severe case
			 				break;
			 		}


		 break;


}


}
if(poleType==2)//for L-cantilever pole
{
	switch (aspectColor)
	{
	case 0x80: // red

		switch (slaveAspectColor) {
//			case 0x40://yellow
//                      //severe
//				break;
			case 0x30://green

                      //urgent case
				break;
			case 0xF0://green+yellow+red
		                      //urgent case
			break;
			case 0xB0://red+green
                      //urgent case
			    break;
			default:
				// severe case
				break;
		}
 break;
 case 0x30: // green

	 switch (slaveAspectColor) {

	 			default:
	 				// severe case
	 				break;
	 		}

	 break;

	 case 0x40: //yellow
		 break;


}


}

if(poleType==3)//for T-cantilever pole
{
	switch (aspectColor)
	{
	case 0x88: // red

		switch (slaveAspectColor) {
//			case 0x40://yellow
//                      //severe
//				break;
			case 0x33://G1+G2

                      //urgent case
				break;
			case 0xFF://G1+G2+yellow+red
		                      //urgent case
			break;
			case 0xBB://red+G1+G2
                      //urgent case
			    break;
			case 0x20://G1
			          //urgent case
				break;
			case 0x10:	//G2
						//urgent case
				break;
			case 0xCC:	//R+Y
						//urgent case
				break;
//			case 0x10:	//G2
//						//urgent case
//				break;
			default:
				// severe case
				break;
		}
 break;
 case 0x33: // green

	 switch (slaveAspectColor) {

	 			default:
	 				// severe case
	 				break;
	 		}

	 break;

	 case 0x44: //yellow
		 break;


}


}




}

int espCommunication(){

	/*uart4 PA0 & PA1*/
	/*------------------For ESP8266 Communication--------------------*/
	//	       	                            if(SDCardMsg==1)
	/*-------------uart3---------------pb10 pd9---------------------*/
	if (msgUnPrcd3 == 1) {

		//function6_2();
		signVal = msgParse((uint8_t *) RecMsg3, "~~~~", 0);
//		 	   				  			  		signVal=4;
		if (!(signVal == 0)) {
			if (RecMsg3[signVal + (RecMsg3[signVal + 1]) + 2] + crcApi4(signVal)
					== 0xFF) {
				// transferDataValues(signVal);
//		 	   				  			  				  	HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_10);//master
				slave4Rsp = 1;
				if (!(RecMsg3[signVal + 3] == programVersionNo)) {
					//			 imei[29]=2;

					// 		function1();
					// 		function4();
					// 		function42();

				}

				signVal = signVal + 3;
				if (!(RecMsg3[signVal++] == programVersionNo))
					programVersionNo = RecMsg3[signVal] - 1;
				signVal = signVal + 2;

				if (RecMsg3[signVal++] == 1)
					if (RecMsg3[signVal++] == 1)
						if (RecMsg3[signVal++] == 1)
							if (RecMsg3[signVal++] == 1) {
								clearenceMode = 1;
											checkServerJumpExtend=0;
											HAL_GPIO_WritePin(GPIOE, GPIO_PIN_1, GPIO_PIN_RESET);

							}
				if (!(RecMsg3[7] == programVersionNo)) {
					program3();
										checkServerJumpExtend=0;
										isReprogrammed=1;
										return 1;
				}
				if (RecMsg3[9] == 8)
					//		clearenceMode=RxBuffer[10];
					if ((!(RecMsg3[10] == 1))) {
										checkServerJumpExtend=0;
						//----------------------------For Shutdown---------------//
						if (RecMsg3[10] == 5) {
							HAL_GPIO_WritePin(GPIOE, GPIO_PIN_1, GPIO_PIN_SET);
							clearenceMode = RecMsg3[10];
							clearenceSide = RecMsg3[11];

						} else {
							HAL_GPIO_WritePin(GPIOE, GPIO_PIN_1, GPIO_PIN_RESET);

						}
						//----------------------------For ChangeMode---------------//
						if (RecMsg3[10] == 3) {
							//GPIOA->BRR = GPIO_Pin_4;//set bit as high
							//if()
							changeMode = 1;
							if (planMode == 2)							//3)
									{
								planMode = 1;
							}
							if (planMode == 1) {
								planMode = 2;							//3;
							}
							//clearenceSide=RxBuffer[11];

						}

						//----------------------------For  extend---------------//

						if (RecMsg3[10] == 6) // extend request
								{
							clearenceMode = RecMsg3[10];
							clearenceSide = RecMsg3[11];
											checkServerJumpExtend=1;

						}

						//----------------------------For  clearance---------------//
						if (RecMsg3[10] == 2) {
							clearenceMode = RecMsg3[10];
							clearenceSide = RecMsg3[11];

						}

					}
				//----------------------------For  jump---------------//
				if (RecMsg3[10] == 4) // jump request
						{
					clearenceMode = 4;
									checkServerJumpExtend=1;

				}
				HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_2); //master

				clearBuffer3();
				clearaRxBuffer3();
				msgUnPrcd3 = 0;
//		 	   				  			  		 	   		millisec1=0;
			}
			clearBuffer3();
			clearaRxBuffer3();
			msgUnPrcd3 = 0;
//		 	   				  			  			  	millisec1=0;
			//	transmit();
		}
		msgUnPrcd3=0;
	}
//		clearBuffer4();
//		clearaRxBuffer4();
//		msgUnPrcd4 = 0;


}
 void f0Communication(){

		 /*uart1 PA10 & PA9*/
 	   		/*--------------------------------F0 to F4 communication------------------------------------*/
 	   				  				       	        if(SDCardMsg==0)
 	   				  			  				  	if(msgUnPrcd1==1)
 	   				  			  					  	{

 	   				  			  				  		signVal=msgParse((uint8_t *)RecMsg1,"~~",0);
 	   				  			  				  		if (!(signVal == 0 )){

 	   				  			  				 			checkMode();
 	   				  			  				 			if (serverMode == 1){
 	   				  			  				 				 transferDataValues(signVal);
 	   				  			  				 				 transmit();
 	   				  			  				 			}
 	   				  			  				 			else{
 	   				    /*----manually giving the command ----*/
 	   				  			  				 				transferDataValues(signVal);
// 	   				  			  				 				side1=Data[12] & 0x04;
// 	   				  			  				 				side3=Data[12] & 0x40;
// 	   				  			  				 				side2=Data[13] & 0x04;
// 	   				  			  				 				side4=Data[13] & 0x40;
 	   				  			  				 				if(!((side1==0x04)||(side2==0x04)||(side3==0x40)||(side4==0x40)))
 	   				  			  				 				{
 	   				  			  				 				checkClearenceMode();
 	   				  			  				 				}
 	   				  			  				 				function8();
 	   				  			  				 			}


 	   				  			  				  			//function6_2();
 	   				  			  				  		   }
 	   				  			  						  	clearBuffer1();
 	   				  			  					  		clearaRxBuffer1();
 	   				  			  							msgUnPrcd1=0;
 	   				  			  							//	transmit();
 	   				  			  					  	}



 }

int blinker(){
int on=0;
	while(1)
	{
		/*---------------initilize recieve IT----------------*/
//		HAL_UART_Receive_IT(&huart3, (uint8_t *) aRxBuffer3, 1);
//		HAL_UART_Receive_IT(&huart6, (uint8_t *) aRxBuffer, 1);
		 HAL_UART_Receive_IT(&huart3, (uint8_t *)aRxBuffer3,1);//For ESP
		 HAL_UART_Receive_IT(&huart6, (uint8_t *)aRxBuffer,1);//for slave through LORA
		 HAL_UART_Receive_IT(&huart2, (uint8_t *)aRxBuffer4,1);//For slave through RS485
		 HAL_UART_Receive_IT(&huart1, (uint8_t *)aRxBuffer1,1);//For BLE

		HAL_RTC_GetDate(&hrtc, &sDate, FORMAT_BIN);
		HAL_RTC_GetTime(&hrtc, &sTime, FORMAT_BIN);





	if(changeMode==1)
			{
			changeMode=0;
				signal();
			}

		espCommunication();
		sendMsgToSlave();
		slaveResponse();






	 if (!(secLast == sec1)) {

		 if(on==0){
			Disp[0] = 0x11;
			Disp[1] = Disp[0];
			Disp[2] = Disp[1];
			Disp[3] = Disp[2];
			Disp[4] = 0x44; //01000100	;
			Disp[5] = 0x44; //01000100	;
			Disp[6] = 0x0A;
			on=1;
		 }
		 else{
				Disp[0] = 0x11;
				Disp[1] = Disp[0];
				Disp[2] = Disp[1];
				Disp[3] = Disp[2];
				Disp[4] = 0x12; //00000000	;
				Disp[5] = 0x12; //00000000	;
				Disp[6] = 0x0A;
				on=0;
		 }
			function8();

			secLast = sec1;

		}







	/*----------------------get date---------------------*/
	 HAL_RTC_GetDate(&hrtc, &sDate, FORMAT_BIN);
	/*---------------Update RTC from GNSS Module-------begin------*/
//	if(!(sDate.Date == DateLast))
//	{
//			getDateAndTimeFromGPS();
//
//	}
	/*----------------Update RTC from GNSS Module-------- end-------- */
	if (sTime.Hours==(planOffHr)){
		if (sTime.Minutes>planOffM)
		{
			returnMode=1;
			return 1;
		}
	}
		if (sTime.Hours>(planOffHr))
		{
			returnMode=1;
			return 1;
		}
			if (sTime.Hours<(planOnHr))
			{
				returnMode=1;
				return 1;
			}

			if(changeMode==1){
			changeMode=0;
			signal();
			}

}




}

int crcApi4(int signval) {
	int crcValue = 0;
	int zzzz = zxx9 + RecMsg3[signval]; // have changed frame[3] from frame[5]
	int zyy9 = 0;
	int zxx9 = 4;           // have changed zxx9=4; from zxx9=6;
	signval = signval + 1;
	zzzz = zxx9 + RecMsg3[signval];
	signval = signval + 1;
	while (zxx9 < zzzz) {
		zyy9 = zyy9 + RecMsg3[signval++];
		zxx9++;
	}
	while (zyy9 > 256) {
		crcValue = zyy9 - 0xFF;
		crcValue = crcValue - 1;
		zyy9 = crcValue;
	}

	return zyy9;
}


int crcApi1(int signval) {
	int crcValue = 0;
	int zzzz = zxx9 + RecMsg1[signval]; // have changed frame[3] from frame[5]
	int zyy9 = 0;
	int zxx9 = 4;           // have changed zxx9=4; from zxx9=6;
	signval = signval + 1;
	zzzz = zxx9 + RecMsg1[signval];
	signval = signval + 1;
	while (zxx9 < zzzz) {
		zyy9 = zyy9 + RecMsg1[signval++];
		zxx9++;
	}
	while (zyy9 > 256) {
		crcValue = zyy9 - 0xFF;
		crcValue = crcValue - 1;
		zyy9 = crcValue;
	}

	return zyy9;
}


int crcApi3(int signval) {
	int crcValue = 0;
	int zzzz = zxx9 + aRxBuffer[signval]; // have changed frame[3] from frame[5]
	int zyy9 = 0;
	int zxx9 = 4;           // have changed zxx9=4; from zxx9=6;
	signval = signval + 1;
	zzzz = zxx9 + aRxBuffer[signval];
	signval = signval + 1;
	while (zxx9 < zzzz) {
		zyy9 = zyy9 + aRxBuffer[signval++];
		zxx9++;
	}
//	while (zyy9 > 256) 254
		while (zyy9 >= 255)
	{
		crcValue = zyy9 - 0xFF;
		crcValue = crcValue - 1;
		zyy9 = crcValue;
	}

	return zyy9;
}
void readJunctionAndSide(){
	int i=0;

	Address = 0x0800635C;
		for (int i = 0; i < 91; i++) {
			Flash_Data[i] = *(__IO uint8_t*) Address;
	//		frame[7+i]=Flash_Data[i];
			Address = Address + 4;
	//		dataToWrite++;
		}
	i=0;
	int count1=0;
	//while(!((Flash_Data[i] == 0x00) || (Flash_Data[i] == 0x3A )))
		while(! (Flash_Data[count1] == 0x3A )) {
	//			Flash_Data[i] = *(__IO uint8_t*) Address;
			if(Flash_Data[count1]== '\0'){
				count1++;
						}else{
				frame[8+i]=Flash_Data[count1];
				i++;
				count1++;
						}
	//			Address = Address + 4;
		//		dataToWrite++;
			}
	 count1++;
	 count=i+8;
	frame[count++]=0x3A;
	//count=count+1;
	//	for (int j = 1; j < noOfPlans + 1;j++){

	for(int j=1;j<6;j++){
	if(j<=noOfSides)
			{
			i=0;
			while(!((Flash_Data[count1] == 0x3A ))) {
			//			Flash_Data[i] = *(__IO uint8_t*) Address;
				if(Flash_Data[count1]== 0x00){
					count1++;
				}else{
						frame[count+i]=Flash_Data[count1];
						count++;
	//					i++;
						count1++;
				}
	//					Address = Address + 4;
				//		dataToWrite++;
					}
			frame[count]=0x3A;
			count1++;
				count++;
			}
	//	}


	}


}
/*---------------------------- junction name validation function --------------------------*/
int function32() {

	clearframe();
	readJunctionAndSide();
int countAddress=count;
countAddress=countAddress+10;//16;

	frame[0] = 126;
	frame[1] = 126;
	frame[2] = 00;   //byte size 1
	frame[3] = countAddress;   //byte size 2
	frame[4] = junctionId;   // 127 ;//
	frame[5] = programVersionNo;   // 127 ;//
	frame[6] = fileNo;
	frame[7] = 3;   //function no

	count=count-1;

	frame[count++] = 1;
	frame[count++] = 1;
	frame[count++] = 1;
	frame[count++] = 1;
	frame[count++] = 1;
	frame[count++] = 1;
	frame[count++] = 1;
	frame[count++] = 1;
	frame[count++] = 1;
	frame[count++] = 1;   //'1'
	frame[count++] = 1;   //'0' ; //'5' ;
	frame[count++] = 1;   // '2' ;//'9' ;//'1' ;
	frame[count++] = 0xFF - crcApi();
	frame[count++] = 125;
	frame[count++] = 125;
	//		frame[21] = 0x0D;
	HAL_UART_Transmit(&huart3, (uint8_t*) frame, count, 5000);
	HAL_UART_Receive(&huart3, (uint8_t *) aRxBuffer, 100, 0x2FFF);
	HAL_Delay(300);
	signVal = msgParse((uint8_t *) aRxBuffer, "~~~~", 0);

	if (!(signVal == 0))
		if (aRxBuffer[signVal + (aRxBuffer[signVal + 1]) + 2] + crcApi3(signVal)
				== 0xFF)
	{

	}
	return 1;
}


/*------------------------- junction Name-----------------------------------*/
int function3() {

	clearframe();
	frame[0] = 126;
	frame[1] = 126;
	frame[2] = 00;   //byte size 1
	frame[3] = 16;   //byte size 2
	frame[4] = junctionId;   // 127 ;//
	frame[5] = programVersionNo;   // 127 ;//
	frame[6] = fileNo;
	frame[7] = 3;   //function no

	frame[8] = 1;
	frame[9] = 1;
	frame[10] = 1;
	frame[11] = 1;
	frame[12] = 1;
	frame[13] = 1;
	frame[14] = 1;
	frame[15] = 1;
	frame[16] = 1;
	frame[17] = 1;   //'1'
	frame[18] = 1;   //'0' ; //'5' ;
	frame[19] = 1;   // '2' ;//'9' ;//'1' ;
	frame[20] = 0xFF - crcApi();
	frame[21] = 125;
	frame[22] = 125;
	//		frame[21] = 0x0D;
	HAL_UART_Transmit(&huart3, (uint8_t*) frame, 23, 5000);
	HAL_UART_Receive(&huart3, (uint8_t *) aRxBuffer, 100, 0x2FFF);
	HAL_Delay(900);
	signVal = msgParse((uint8_t *) aRxBuffer, "~~~~", 0);

	if (!(signVal == 0))
		if (aRxBuffer[signVal + (aRxBuffer[signVal + 1]) + 2] + crcApi3(signVal)
				== 0xFF)
	{

		//----------------------------------junction name ----------------------------------//
		signVal = signVal + 6;
		/*-----------------------transfer values to junction name-----------------------*/
		int k = 0;
		while (aRxBuffer[signVal] != ':') {
			junctionName[k] = aRxBuffer[signVal++];
			k++;
		}
		HAL_FLASH_Unlock();
		/*---------------------write in memory----------------------------------*/
		Address = Address + 4;
		for (int i = 0; i < 15; i++) {
			HAL_FLASH_Program(TYPEPROGRAM_BYTE, Address, junctionName[i]);
			Address = Address + 4;
		}
		HAL_FLASH_Program(TYPEPROGRAM_BYTE, Address, ':');
		Address = Address + 4;
		//--------------------------------side1--------------------------------//
		/*-----------------------transfer values to side1 name-----------------------*/
		if(1<=noOfSides)
		{
			signVal=signVal+1;
		k = 0;
		while (aRxBuffer[signVal] != ':') {
			side1[k] = aRxBuffer[signVal++];
			k++;
		}
		/*---------------------write in memory----------------------------------*/
//			signVal = msgParse((uint8_t *) aRxBuffer, ",", 15);

		for (int i = 0; i < 15; i++) {
			HAL_FLASH_Program(TYPEPROGRAM_BYTE, Address, side1[i]);
			Address = Address + 4;
		}
		HAL_FLASH_Program(TYPEPROGRAM_BYTE, Address, ':');
		Address = Address + 4;
		}
		//-------------------------------side2--------------------------------//
		if(2<=noOfSides)
		{
			signVal=signVal+1;
		/*-----------------------transfer values to junction name-----------------------*/
		k = 0;
		while (aRxBuffer[signVal] != ':') {
			side2[k] = aRxBuffer[signVal++];
			k++;
		}
		/*---------------------write in memory----------------------------------*/


		for (int i = 0; i < 15; i++) {
			HAL_FLASH_Program(TYPEPROGRAM_BYTE, Address, side2[i]);
			Address = Address + 4;
		}
		HAL_FLASH_Program(TYPEPROGRAM_BYTE, Address, ':');
		Address = Address + 4;
		}
		//-------------------------------side3--------------------------------//
		if(3<=noOfSides)
		{
			signVal=signVal+1;
		/*-----------------------transfer values to junction name-----------------------*/
		k = 0;
		while (aRxBuffer[signVal] != ':') {
			side3[k] = aRxBuffer[signVal++];
			k++;
		}
		/*---------------------write in memory----------------------------------*/


		for (int i = 0; i < 15; i++) {
			HAL_FLASH_Program(TYPEPROGRAM_BYTE, Address, side3[i]);
			Address = Address + 4;
		}
		HAL_FLASH_Program(TYPEPROGRAM_BYTE, Address, ':');
		Address = Address + 4;
		}
		//-------------------------------side4--------------------------------//
		if(4<=noOfSides)
		{
			signVal=signVal+1;
		/*-----------------------transfer values to junction name-----------------------*/
		k = 0;
		while (aRxBuffer[signVal] != ':') {
			side4[k] = aRxBuffer[signVal++];
			k++;
		}
		/*---------------------write in memory----------------------------------*/


		for (int i = 0; i < 15; i++) {
			HAL_FLASH_Program(TYPEPROGRAM_BYTE, Address, side4[i]);
			Address = Address + 4;
		}
		HAL_FLASH_Program(TYPEPROGRAM_BYTE, Address, ':');
		Address = Address + 4;
		}
		//-------------------------------side5--------------------------------//
		if(5<=noOfSides)
		{
			signVal=signVal+1;
		/*-----------------------transfer values to junction name-----------------------*/
		k = 0;
		while (aRxBuffer[signVal] != ':') {
			side5[k] = aRxBuffer[signVal++];
			k++;
		}
		/*---------------------write in memory----------------------------------*/


		for (int i = 0; i < 15; i++) {
			HAL_FLASH_Program(TYPEPROGRAM_BYTE, Address, side5[i]);
			Address = Address + 4;
		}
		HAL_FLASH_Program(TYPEPROGRAM_BYTE, Address, ':');
		Address = Address + 4;
		}
		HAL_FLASH_Lock();
		return 1;
	}
	else{
		return 0;
	}

}


void leftGreen1(){

	int side=0;
//	side2=1;

	if(side1==0)// side 1 green on
	{
		leftGreen=leftGreen^0x01;
	}
	if(side==0)// side 1 green off
		{
			leftGreen=leftGreen&0x01;
		}
	if(side==0)//side2 green on
		{
			leftGreen=leftGreen^0x02;
		}
	if(side==0)//side2 green off
		{
			leftGreen=leftGreen&0x02;
		}
	if(side==0)//side3 green on
		{
			leftGreen=leftGreen^0x04;
		}
	if(side==0)//side3 green off
		{
			leftGreen=leftGreen&0x04;
		}
	if(side==0)//side4 green on
		{
			leftGreen=leftGreen^0x08;
		}
	if(side==0)//side4 green off
		{
			leftGreen=leftGreen&0x08;
		}




}

void pedestrain(){

	int side=0;
//	side2=1;

	if(side1==0)// side 1 green on
	{
		pedestrainByte=pedestrainByte^0x01;
	}
	if(side==0)// side 1 green off
		{
		pedestrainByte=pedestrainByte&0x01;
		}
	if(side==0)//side2 green on
		{
		pedestrainByte=pedestrainByte^0x02;
		}
	if(side==0)//side2 green off
		{
		pedestrainByte=pedestrainByte&0x02;
		}
	if(side==0)//side3 green on
		{
		pedestrainByte=pedestrainByte^0x04;
		}
	if(side==0)//side3 green off
		{
		pedestrainByte=pedestrainByte&0x04;
		}
	if(side==0)//side4 green on
		{
		pedestrainByte=pedestrainByte^0x08;
		}
	if(side==0)//side4 green off
		{
		pedestrainByte=pedestrainByte&0x08;
		}




}


void getDateAndTimeFromGPS(){

	    uint8_t dateTimeGet=0;
	    min=0;

		diableAllString();
		HAL_Delay(1000);
		enableGNZDAString();
while(1){


	HAL_UART_Receive_IT(&huart6, (uint8_t *)aRxBuffer,1);


		if(msgUnPrcd==1)
			{


							functionRec=0;
		//					  		 signVal=msgParse((uint8_t *)RecMsg2,"}",0); //for slave
//							signVal=msgParse((uint8_t *)RecMsg2,"$GNZDA",0); //for slave
							if(strncmp((char*)RecMsg2,(char*) "$GNZDA,",6) == 0)

//							  		if(!(signVal==0))
							  		{

                                       if( RecMsg2[7] != ','){

							  			convertStringToByte();

							  			HAL_RTC_GetDate(&hrtc, &sDate, FORMAT_BIN);
							  			dateTimeGet=1;
                                       }
                                       else
                                       {
                                    	   dateTimeGet=0;
                                       }


                                       if(dateTimeGet==1 || min==2)
//							  			if(sDate.Year != 0x00)
							  				break;



							  		}
                                    clearingRecBuffer();
							  		msgUnPrcd=0;
			}

		/*---------if----------*/
		  if(min==2)
				break;







}





}
void RTC_UtcToIstSet(unsigned char uDate,unsigned char uMonth, unsigned char uYear,unsigned char uHours, unsigned char uMinutes,unsigned char uSeconds)
{
//static unsigned char LeapYear;

      if( (uDate > 31) || (uMonth > 12) || (uYear >99) || (uHours > 23) || (uMinutes > 59) || (uSeconds > 59) )
return;

//LeapYear=0;
if( (uYear % 4) == 0)
{
//LeapYear=1;
MaxDayOfMonth[2] = 29;
}

Date = 0;
Month = 0;
Year = 0;
Hours = 0;
Minutes = 0;
Seconds = 0;

Seconds = uSeconds;

Minutes = uMinutes + 30;
if(Minutes >= 60)
{
Minutes -= 60;
Hours = 1;
}

Hours += uHours+5;
if(Hours >=24)
{
Hours -= 24;
Date =1;
}

Date += uDate;
Month = uMonth;
Year = uYear;
if(Date > MaxDayOfMonth[uMonth])
{
Date=1;
Month = uMonth + 1;
if(Month > 12)
{
Month=1;
Year++;
}
}
//SetRTC(Date,Month,Year,Hours,Minutes,Seconds);
}
/*-------------------*/




void convertStringToByte(){





	/*----------day------------------*/
	RecMsg2[40] = RecMsg2[17] - 0x30;
	RecMsg2[41] = RecMsg2[40] * 10;
	RecMsg2[42] = RecMsg2[18] - 0x30;
	GPSDay = RecMsg2[41] + RecMsg2[42];

	/*----------month------------------*/
	RecMsg2[43] = RecMsg2[20] - 0x30;
	RecMsg2[44] = RecMsg2[43] * 10;
	RecMsg2[45] = RecMsg2[21] - 0x30;
	GPSMonth = RecMsg2[44] + RecMsg2[45];

	/*----------year------------------*/
	RecMsg2[46] = RecMsg2[25] - 0x30;
	RecMsg2[47] = RecMsg2[46] * 10;
	RecMsg2[48] = RecMsg2[26] - 0x30;
	GPSYear = RecMsg2[47] + RecMsg2[48];

	/*----------Hr------------------*/
	RecMsg2[49] = RecMsg2[7] - 0x30;
	RecMsg2[50] = RecMsg2[49] * 10;
	RecMsg2[51] = RecMsg2[8] - 0x30;
	GPSHr = RecMsg2[50] + RecMsg2[51];

	/*----------min------------------*/
	RecMsg2[52] = RecMsg2[9] - 0x30;
	RecMsg2[53] = RecMsg2[52] * 10;
	RecMsg2[54] = RecMsg2[10] - 0x30;
	GPSMin = RecMsg2[53] + RecMsg2[54];


 RTC_UtcToIstSet(GPSDay,GPSMonth,GPSYear,GPSHr,GPSMin,GPSSec);

//	GPSMin=GPSMin+0x1E;
//
//	if(GPSMin>0x3C){
//		GPSHr=GPSHr+0x06;
//		GPSMin=GPSMin-0x3C;
//	}
//	else{
//		GPSHr=GPSHr+0x05;
//	}  //Date,Month,Year,Hours,Minutes,Seconds


if(Date != 0 || Month != 0 || Year != 0)
{
	            sTime.Hours = Hours; // current hour
				sTime.Minutes =Minutes; // current min
				sDate.Date = Date; // current date
				sDate.Month = Month; // current month
				sDate.Year = Year;	// current year

				HAL_RTC_SetTime(&hrtc, &sTime, FORMAT_BIN);
			    HAL_RTC_SetDate(&hrtc, &sDate, FORMAT_BIN);

			    /*---------get the date and update the DateLast variable-------*/
			    HAL_RTC_GetDate(&hrtc, &sDate, FORMAT_BIN);
				DateLast=sDate.Date;
				/*---------get the date and update the DateLast variable--end-----*/
}





}


/*-------------------------------function 11---------------------------*/
/*----------------------- registration function----------------------------------*/
int function11N()   // check registration
{
	clearframe();
	frame[0] = 126;
	frame[1] = 126;
	frame[2] = 00;   //byte size 1
	frame[3] = 31;//31;   //byte size 2
	frame[4] = junctionId;   // 127 ;//
	frame[5] = programVersionNo;   // 127 ;//
	frame[6] = fileNo;
	frame[7] = 0x0B;   //function no
	frame[8] = '0';
	frame[9] = '1';
	frame[10] = '3';
	frame[11] = '7';
	frame[12] = '7';
	frame[13] = '7';
	frame[14] = '0';
	frame[15] = '0';
	frame[16] = '0';
	frame[17] = '6';
	frame[18] = '2';
	frame[19] = '0';
	frame[20] = '9';//'1';
	frame[21] = '1';//'2';
	frame[22] = '5';//'1';

	frame[23] = 1;
	frame[24] = 1;
	frame[25] = 1;
	frame[26] = 1;
	frame[27] = 1;
	frame[28] = 1;
	frame[29] = 1;
	frame[30] = 1;
	frame[31] = 1;
	frame[32] = 1;   //'1'
	frame[33] = 1;   //'0' ; //'5' ;
	frame[34] = 1;   // '2' ;//'9' ;//'1' ;
	frame[35] = 0xFF - crcApi();
	frame[36] = 125;
	frame[37] = 125;
//	frame[38] = 125;
//		frame[21] = 0x0D;
	if(programFromBLE==1)
	{
		HAL_UART_Transmit(&huart1, (uint8_t*) frame, 37, 5000);
		HAL_UART_Receive(&huart1, (uint8_t *) aRxBuffer, 30, 0x2FFF);
	}
	else
	{
	HAL_UART_Transmit(&huart3, (uint8_t*) frame, 37, 5000);
	HAL_UART_Receive(&huart3, (uint8_t *) aRxBuffer, 30, 0x2FFF);
	}
	HAL_Delay(300);
	signVal = msgParse((uint8_t *) aRxBuffer, "~~~~", 0);


	if (!(signVal == 0)){

		if (aRxBuffer[signVal + (aRxBuffer[signVal + 1]) + 2] + crcApi3(signVal)
				== 0xFF) {

			signVal = signVal + 2;
			/*-----------------flash--------------------*/

int j=0;
			for (int i = 0; i < 15; i++) {
				    bytesToWriteInSD[j]=aRxBuffer[signVal+i];
				    j++;
				    if(i==2)
				    {
				    	i=i+1;
				    }
						}
			//--------------------------SD Card Write----------------------//
//			SDcardWrite("info.txt",6,(uint8_t *)bytesToWrite);
//			 seek("info.txt",0);

			SDcardWriteSeek("infoN.txt", 14, (uint8_t *) bytesToWriteInSD, 0);
				SDcardReadSeek("infoN.txt", 15, 0);

			           junctionId = readBytes[0];
//			           junctionId = 13;
			           programVersionNo = readBytes[1];
			           fileNo = readBytes[2];

			            noOfSides = readBytes[4];

						noOfDateSlots = readBytes[5];
						noOfDaySlots = readBytes[6];
						noOfPlans=readBytes[7];

						padestarianTime = readBytes[8];

						side1PoleType= readBytes[10]; // 1= standard ,2= l Cantilever,3= T cantilever pole
						side2PoleType= readBytes[11];
						side3PoleType= readBytes[12];
						side4PoleType= readBytes[13];
						side5PoleType= readBytes[14];
						totalNoOfPhases=readBytes[9];

			/*----------------------------SD card write ends here-------------------------*/

			/*----------------------------flash write begins here ------------------------*/

//						Flash_Write( Base_Address,(uint8_t*) bytesToWriteInSD ,5);






			/*----------------------------flash write ends here ------------------------*/


						HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_4);


			clearaRxBuffer();
			clearBuffer4();
//			function1_1();
			return 1;


		}} else {
			clearBuffer4();
			clearaRxBuffer();
			return 0;
		}

}

/*-------------------------------function 12---------------------------*/
/*------------------------------------getting date info--------------------------------------*/
int function12(void) {
	int resmsg = 0;
	int seekCnt=0;
//	noOfDateSlots=1;
//	junctionId=1;

	for (int i = 1; i < noOfDateSlots + 1;) {
		if (resmsg == 1) {
			dateSlotNo = i;
			i++;
		}
		if (i == 1) {
			dateSlotNo = i;
			i++;
		}
		clearframe();
//msg_processed = 0 ;     //Raise flag to indicate a msg to be processed by main is present
//RxCount = 0 ;			// Reset msg receive counter
//
//flag  = 0 ;
//// puts1("AT+CIPSEND\r\n",11);
//// delay(9800000);
////    signVal = msgParse(RxBuffer,"T\r\r\nOK",0);
		frame[0] = 126;
		frame[1] = 126;
		frame[2] = 0; // function no
		frame[3] = 14;
		frame[4] = junctionId; // junction no
		frame[5] = programVersionNo; // junction no
		frame[6] = fileNo; // junction no
		frame[7] = 0x0C; // function no
		frame[8] = 1;  // 1 indicates it is for date slot

		frame[9] = dateSlotNo;
		frame[10] = 0;
		frame[11] = 0;
		frame[12] = 0;
		frame[13] = 0;
		frame[14] = 0;
		frame[15] = 0;
		frame[16] = 0;
		frame[17] = 0;
//		frame[18] = 0;  //'1'
//		frame[19] = 0;  //'0' ; //'5' ;
//		frame[20] = 0;  // '2' ;//'9' ;//'1' ;

		frame[18] = 0xFF - crcApi();  // junction no
		frame[19] = 125;
		frame[20] = 125;

		if(programFromBLE==1)
		{
			HAL_UART_Transmit(&huart1, (uint8_t*) frame, 20, 5000);
			HAL_UART_Receive(&huart1, (uint8_t *) aRxBuffer, 25, 0x2FFF);
		}
		else
		{

		HAL_UART_Transmit(&huart3, (uint8_t*) frame, 20, 5000);
		HAL_UART_Receive(&huart3, (uint8_t *) aRxBuffer, 40, 0x1FFF);
		}
		//		HAL_Delay(300);
//		signVal = msgParse((uint8_t *) aRxBuffer, "~~~~", 0);

//		while (!(aRxBuffer[signVal] == 126)) {
//			signVal = signVal + 1;
//			if(!(aRxBuffer[signVal] == 126))
//							break;
//		}
		HAL_Delay(900);
		signVal=5;
		if (!(signVal == 0)){
			if (aRxBuffer[signVal + (aRxBuffer[signVal + 1]) + 2]
					+ crcApi3(signVal) == 0xFF) {
//				if((aRxBuffer[signVal]==126)){
//					signVal=signVal+1;
//				}

				signVal = signVal + 2;
				if ((aRxBuffer[signVal] == junctionId))
//				if ((aRxBuffer[signVal] == 1))
				{
					signVal = signVal + 3;
					if ((aRxBuffer[signVal] == 0x0C)) //function Number
						signVal = signVal + 1;
//					if ((aRxBuffer[signVal] == planNo))

					{
						signVal=signVal+1;

						string[0] = noOfDateSlots;  //TotalDateSlot
						// 	fnData[0] = RxBuffer[6] ;// junctiond id
//						signVal = signVal + 1;
						string[1] = dateSlotNo;			// SerialNoOfDateSlot
//						if (string[1] == 0x6F)
//							string[1] = 0;
//						signVal = signVal + 1;
//						string[2] = aRxBuffer[signVal];	  // on time min
//						if (string[2] == 0x6F)
//							string[2] = 0;
//						signVal = signVal + 1;
						for (int i = 0; i < 9; i++) {
							string[2 + i] = aRxBuffer[signVal];
							signVal++;
						}

//						signVal = signVal + 1;
					string[10] = 0xFF ;//
//					byteToInteger(0);
//					eepromData[planNo*4+4]=stringInt[0];


						//-------------------------SD card write-----------------------//
						SDcardWriteSeek("date.txt", 11, (uint8_t *) string, seekCnt);
						SDcardReadSeek("date.txt", 100, 0);
						seekCnt=seekCnt+11;
//						seek("plan.txt",seekCnt);
//						SDcardWriteSeek("plan.txt",17,(uint8_t *)string);
//						//--------------------------flash write------------------------//
//						HAL_FLASH_Unlock();
////						Address = Address + 4;
//						for (int i = 0; i < 17; i++) {
////						FLASH_Erase_Sector(FLASH_SECTOR_1,FLASH_VOLTAGE_RANGE_3);
//							HAL_FLASH_Program(TYPEPROGRAM_BYTE, Address,
//									string[i]);
//							Address = Address + 4;
//
//						}
//						HAL_FLASH_Lock();
//						//--------------------------flash write------------------------//

						HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_4);
						clearaRxBuffer();
						clearBuffer4();
						resmsg = 1;
//						Address=Address+4;
//						return 1 ;


					}
				}
			}
			else {
							i = i - 1;
							resmsg = 0;
							clearaRxBuffer();
							clearBuffer4();
							return 0;
						}
		}else {
				i = i - 1;
				resmsg = 0;
				clearaRxBuffer();
				clearBuffer4();
				return 0;
			}

	}
	clearaRxBuffer();
	if(noOfDateSlots==dateSlotNo)
	return 1;
	else
	return 0;
}


/*-------------------------------function 13---------------------------*/
/*------------------------------------getting day info--------------------------------------*/
int function13(void) {
	int resmsg = 0;
	int seekCnt=0;
//	noOfDaySlots=3;
	for (int i = 1; i < noOfDaySlots + 1;) {
		if (resmsg == 1) {
			daySlotNo = i;
			i++;
		}
		if (i == 1) {
			daySlotNo = i;
			i++;
		}
		resmsg=0;
		clearframe();
//msg_processed = 0 ;     //Raise flag to indicate a msg to be processed by main is present
//RxCount = 0 ;			// Reset msg receive counter
//
//flag  = 0 ;
//// puts1("AT+CIPSEND\r\n",11);
//// delay(9800000);
////    signVal = msgParse(RxBuffer,"T\r\r\nOK",0);
		frame[0] = 126;
		frame[1] = 126;
		frame[2] = 0; // function no
		frame[3] = 14;
		frame[4] = junctionId; // junction no
		frame[5] = programVersionNo; // junction no
		frame[6] = fileNo; // junction no
		frame[7] = 0x0D; // function no
		frame[8] = 2;  // 2 indicates it is for day slot

		frame[9] = daySlotNo;
		frame[10] = 0;
		frame[11] = 0;
		frame[12] = 0;
		frame[13] = 0;
		frame[14] = 0;
		frame[15] = 0;
		frame[16] = 0;
		frame[17] = 0;
//		frame[18] = 0;  //'1'
//		frame[19] = 0;  //'0' ; //'5' ;
//		frame[20] = 0;  // '2' ;//'9' ;//'1' ;

		frame[18] = 0xFF - crcApi();  // junction no
		frame[19] = 125;
		frame[20] = 125;
		if(programFromBLE==1)
		{
			HAL_UART_Transmit(&huart1, (uint8_t*) frame, 20, 5000);
			HAL_UART_Receive(&huart1, (uint8_t *) aRxBuffer, 30, 0x2FFF);
		}
		else
		{

		HAL_UART_Transmit(&huart3, (uint8_t*) frame, 20, 5000);
		HAL_UART_Receive(&huart3, (uint8_t *) aRxBuffer, 30, 0x1FFF);
		}
//		HAL_Delay(300);
		signVal = msgParse((uint8_t *) aRxBuffer, "~~~~", 0);

//		while (!(aRxBuffer[signVal] == 126)) {
//			signVal = signVal + 1;
//			if(!(aRxBuffer[signVal] == 126))
//							break;
//		}
		HAL_Delay(900);
//		signVal=4;
		if (!(signVal == 0)){
			if (aRxBuffer[signVal + (aRxBuffer[signVal + 1]) + 2]
					+ crcApi3(signVal) == 0xFF) {
//				if((aRxBuffer[signVal]==126)){
//					signVal=signVal+1;
//				}
				clearStringBuffer();

				signVal = signVal + 2;
				if ((aRxBuffer[signVal] == junctionId))
//				if ((aRxBuffer[signVal] == 1))

				{
					signVal = signVal + 3;
					if ((aRxBuffer[signVal] == 0x0C)) //function Number
						signVal = signVal + 1;
//					if ((aRxBuffer[signVal] == planNo))

					{
                        signVal=signVal+2;
						string[0] = noOfDaySlots;  //TotalDaySlot
						// 	fnData[0] = RxBuffer[6] ;// junctiond id
//						signVal = signVal + 1;
						string[1] = daySlotNo;			// SerialNoOfDaySlot
//						if (string[1] == 0x6F)
//							string[1] = 0;
//						signVal = signVal + 1;
//						string[2] = aRxBuffer[signVal];	  // on time min
//						if (string[2] == 0x6F)
//							string[2] = 0;
//						signVal = signVal + 1;
						for (int i = 0; i < 3; i++) {
							string[2 + i] = aRxBuffer[signVal];
							signVal++;
						}

//						signVal = signVal + 1;
					string[5] = 0xFF ;//
//					byteToInteger(0);
//					eepromData[planNo*4+4]=stringInt[0];


						//-------------------------SD card write-----------------------//
						SDcardWriteSeek("day.txt", 6, (uint8_t *) string, seekCnt);
						SDcardReadSeek("day.txt", 50, 0);
						seekCnt=seekCnt+6;
//						seek("plan.txt",seekCnt);
//						SDcardWriteSeek("plan.txt",17,(uint8_t *)string);
//						//--------------------------flash write------------------------//
//						HAL_FLASH_Unlock();
////						Address = Address + 4;
//						for (int i = 0; i < 17; i++) {
////						FLASH_Erase_Sector(FLASH_SECTOR_1,FLASH_VOLTAGE_RANGE_3);
//							HAL_FLASH_Program(TYPEPROGRAM_BYTE, Address,
//									string[i]);
//							Address = Address + 4;
//
//						}
//						HAL_FLASH_Lock();
//						//--------------------------flash write------------------------//
						HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_4);
						clearaRxBuffer();
						clearBuffer4();
						resmsg = 1;
//						Address=Address+4;
//						return 1 ;

					}
				}
			}
			else {
							i = i - 1;
							resmsg = 0;
							clearaRxBuffer();
							clearBuffer4();
							return 0;
						}
		}else {
				i = i - 1;
				resmsg = 0;
				clearaRxBuffer();
				clearBuffer4();
				return 0;
			}

	}
	string[0]=0xFF;
	string[1]=0xFF;
	string[2]=0xFF;
	string[3]=0xFF;
	SDcardWriteSeek("day.txt", 3, (uint8_t *) string, seekCnt);
	SDcardReadSeek("day.txt", 50, 0);
	clearaRxBuffer();
	if(daySlotNo==noOfDaySlots)
	return 1;
	else
		return 0;
}

/*------------------------------------getting plan info--------------------------------------*/
int function14(void) {
	int resmsg = 0;
	int seekCnt=0;
//	noOfPlans=3;
//	junctionId=1;
	for (int i = 1; i < noOfPlans + 1;) {
		if (resmsg == 1) {
			planNo = i;
			i++;
		}
		if (i == 1) {
			planNo = i;
			i++;
		}
		clearframe();
//msg_processed = 0 ;     //Raise flag to indicate a msg to be processed by main is present
//RxCount = 0 ;			// Reset msg receive counter
//
//flag  = 0 ;
//// puts1("AT+CIPSEND\r\n",11);
//// delay(9800000);
////    signVal = msgParse(RxBuffer,"T\r\r\nOK",0);
		frame[0] = 126;
		frame[1] = 126;
		frame[2] = 0; // function no
		frame[3] = 17;
		frame[4] = junctionId; // junction no
		frame[5] = programVersionNo; // junction no
		frame[6] = fileNo; // junction no
		frame[7] = 0x0E; // function no
		frame[8] = planNo;  // plan no

		frame[9] = 1;
		frame[10] = 1;
		frame[11] = 1;
		frame[12] = 1;
		frame[13] = 1;
		frame[14] = 1;
		frame[15] = 1;
		frame[16] = 1;
		frame[17] = 1;
		frame[18] = 1;  //'1'
		frame[19] = 1;  //'0' ; //'5' ;
		frame[20] = 1;  // '2' ;//'9' ;//'1' ;

		frame[21] = 0xFF - crcApi();  // junction no
		frame[22] = 125;
		frame[23] = 125;

		if(programFromBLE==1)
		{
			HAL_UART_Transmit(&huart1, (uint8_t*) frame, 23, 5000);
			HAL_UART_Receive(&huart1, (uint8_t *) aRxBuffer, 45, 0x2FFF);
		}
		else
		{

		HAL_UART_Transmit(&huart3, (uint8_t*) frame, 23, 5000);
		HAL_UART_Receive(&huart3, (uint8_t *) aRxBuffer, 45, 0x1FFF);
		}
//		HAL_Delay(300);
//		signVal = msgParse((uint8_t *) aRxBuffer, "~~~~", 0);

//		while (!(aRxBuffer[signVal] == 126)) {
//			signVal = signVal + 1;
//			if(!(aRxBuffer[signVal] == 126))
//							break;
//		}
		HAL_Delay(900);
		signVal=4;
		if (!(signVal == 0)){
			if (aRxBuffer[signVal + (aRxBuffer[signVal + 1]) + 2]
					+ crcApi3(signVal) == 0xFF) {
//				if((aRxBuffer[signVal]==126)){
//					signVal=signVal+1;
//				}

				signVal = signVal + 2;
				if ((aRxBuffer[signVal] == junctionId)) {
					signVal = signVal + 3;
					if ((aRxBuffer[signVal] == 0x0E))
					{
						signVal = signVal + 1;
//					if ((aRxBuffer[signVal] == planNo))



						string[0] = aRxBuffer[signVal];  //planNoID
						signVal = signVal + 1;
						string[1] = aRxBuffer[signVal];  //planNo
						// 	fnData[0] = RxBuffer[6] ;// junctiond id
						signVal = signVal + 1;
						string[2] = aRxBuffer[signVal];			// on time hour
						if (string[2] == 0x6F)
							string[2] = 0;
						signVal = signVal + 1;
						string[3] = aRxBuffer[signVal];			// on time min
						if (string[3] == 0x6F)
							string[3] = 0;
						signVal = signVal + 1;
						for (int i = 0; i < 15; i++) {
							string[4 + i] = aRxBuffer[signVal];
							signVal++;
						}

//						signVal = signVal + 1;
					string[18] = 0xFF ;//
//					byteToInteger(0);
//					eepromData[planNo*4+4]=stringInt[0];


						//-------------------------SD card write-----------------------//
						SDcardWriteSeek("planN.txt", 19, (uint8_t *) string, seekCnt);
						SDcardReadSeek("planN.txt", 100, 0);
						seekCnt=seekCnt+19;
//						seek("plan.txt",seekCnt);
//						SDcardWriteSeek("plan.txt",17,(uint8_t *)string);
//						//--------------------------flash write------------------------//
//						HAL_FLASH_Unlock();
////						Address = Address + 4;
//						for (int i = 0; i < 17; i++) {
////						FLASH_Erase_Sector(FLASH_SECTOR_1,FLASH_VOLTAGE_RANGE_3);
//							HAL_FLASH_Program(TYPEPROGRAM_BYTE, Address,
//									string[i]);
//							Address = Address + 4;
//
//						}
//						HAL_FLASH_Lock();
//						//--------------------------flash write------------------------//
						HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_4);
						clearaRxBuffer();
						clearBuffer4();
						resmsg = 1;
//						Address=Address+4;
//						return 1 ;

					}
				}
			}
			else {
							i = i - 1;
							resmsg = 0;
							clearaRxBuffer();
							clearBuffer4();
							return 0;
						}


		}else {
				i = i - 1;
				resmsg = 0;
				clearaRxBuffer();
				clearBuffer4();
				return 0;
			}

	}
	clearaRxBuffer();
	if(planNo==noOfPlans)
	return 1;
	else
		return 0;
}

/*-------------------------------function 15---------------------------*/
/*------------------------------------getting map info for date--------------------------------------*/
int function15(void) {
	int resmsg = 1;
	int seekCnt=0;
	int seekCntWrite=0;
//	noOfDateSlots=2;
//	junctionId=1;
	for (int i = 1; i < noOfDateSlots + 1;) {
		if (resmsg == 1) {
			dateSlotNo = i;
			i++;
		}
		if (i == 1) {
			dateSlotNo = i;
			i++;
		}
		clearframe();
		for (int i = 1; i < noOfDateSlots + 1;) {
			if (resmsg == 1) {
				dateSlotNo = i;
				i++;
			}
			if (i == 1) {
				dateSlotNo = i;
				i++;
			}
			clearframe();
		/*-------------------read data from memory ---------------------------*/
		//		readMem();// for flash
		clearReadBytes();
		SDcardReadSeek("date.txt", 15, seekCnt);
		seekCnt = seekCnt + 11;
		dateID = readBytes[2];
		totalNoOfPlans = readBytes[9];
		clearReadBytes();
//		totalNoOfPlans=3;
		for(int i=1; i< totalNoOfPlans+1;i++){

//			if(!(i==1))
//			{
//				    clearReadBytes();
//					SDcardReadSeek("date.txt", 15, seekCnt);
//					seekCnt = seekCnt + 10;
//					dateID = readBytes[2];
//					totalNoOfPlans = readBytes[9];
//			}
		/*-----------send frames-------------------------*/
				frame[0] = 126;
				frame[1] = 126;
				frame[2] = 0; // function no
				frame[3] = 18;
				frame[4] = junctionId; // function no
				frame[5] = programVersionNo; // junction no
				frame[6] = fileNo; // junction no
				frame[7] = 0x0F; // function no
				frame[8] = dateID;  // plan no planOnHr
				frame[9] = i;  // plan no

				frame[10] = '1';
				frame[11] = '1';
				frame[12] = '1';
				frame[13] = '1';
				frame[14] = '1';
				frame[15] = '1';
				frame[16] = '1';
				frame[17] = '1';
				frame[18] = '1';  //'1'
				frame[19] = '1';  //'0' ; //'5' ;
				frame[20] = '1';  // '2' ;//'9' ;//'1' ;
				frame[21] = '1';  // '2' ;//'9' ;//'1' ;

				frame[22] = 0xFF - crcApi();  // junction no
				frame[23] = 125;
				frame[24] = 125;
				clearBuffer();

				if(programFromBLE==1)
				{
					HAL_UART_Transmit(&huart1, (uint8_t*) frame, 24, 5000);
					HAL_UART_Receive(&huart1, (uint8_t *) aRxBuffer, 30, 0x2FFF);
				}
				else
				{

				HAL_UART_Transmit(&huart3, (uint8_t*) frame, 24, 5000);
				HAL_UART_Receive(&huart3, (uint8_t *) aRxBuffer, 30, 0x1FFF);
				}
				HAL_Delay(300);
				signVal = msgParse((uint8_t *) aRxBuffer, "~~~~", 0);



		HAL_Delay(900);
//		signVal=4;
		if (!(signVal == 0)){
			if (aRxBuffer[signVal + (aRxBuffer[signVal + 1]) + 2]
					+ crcApi3(signVal) == 0xFF) {
//				if((aRxBuffer[signVal]==126)){
//					signVal=signVal+1;
//				}

				signVal = signVal + 2;
				if ((aRxBuffer[signVal] == junctionId))
//				if ((aRxBuffer[signVal] == 1))
				{
					signVal = signVal + 3;
					if ((aRxBuffer[signVal] == 0x0F)) //function Number
						signVal = signVal + 1;
//					if ((aRxBuffer[signVal] == planNo))

					{
//						signVal=signVal+1;

//						string[0] = dateSlotNo;  //TotalDateSlot
						// 	fnData[0] = RxBuffer[6] ;// junctiond id
//						signVal = signVal + 1;
//						string[1] = dateSlotNo;			// SerialNoOfDateSlot
//						if (string[1] == 0x6F)
//							string[1] = 0;
//						signVal = signVal + 1;
//						string[2] = aRxBuffer[signVal];	  // on time min
//						if (string[2] == 0x6F)
//							string[2] = 0;
//						signVal = signVal + 1;
						for (int i = 0; i < 6; i++) {
							string[i] = aRxBuffer[signVal];
							signVal++;
						}

//						signVal = signVal + 1;
					string[6] = 0xFF ;//
//					byteToInteger(0);
//					eepromData[planNo*4+4]=stringInt[0];


						//-------------------------SD card write-----------------------//
						SDcardWriteSeek("mapDate.txt", 7, (uint8_t *) string, seekCntWrite);
						SDcardReadSeek("mapDate.txt", 100, 0);
						seekCntWrite=seekCntWrite+7;
						seekCntForDayAndDate=seekCntWrite;
//						seek("plan.txt",seekCnt);
//						SDcardWriteSeek("plan.txt",17,(uint8_t *)string);
//						//--------------------------flash write------------------------//
//						HAL_FLASH_Unlock();
////						Address = Address + 4;
//						for (int i = 0; i < 17; i++) {
////						FLASH_Erase_Sector(FLASH_SECTOR_1,FLASH_VOLTAGE_RANGE_3);
//							HAL_FLASH_Program(TYPEPROGRAM_BYTE, Address,
//									string[i]);
//							Address = Address + 4;
//
//						}
//						HAL_FLASH_Lock();
//						//--------------------------flash write------------------------//
						HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_4);
						clearaRxBuffer();
						clearBuffer4();
						resmsg = 1;
//						Address=Address+4;
//						return 1 ;

					}
				}
				else {
								i = i - 1;
								resmsg = 0;
								clearaRxBuffer();
								clearBuffer4();
								return 0;
							}
			}
			else {
							i = i - 1;
							resmsg = 0;
							clearaRxBuffer();
							clearBuffer4();
							return 0;
						}

		}else {
				i = i - 1;
				resmsg = 0;
				clearaRxBuffer();
				clearBuffer4();
//				return 0;
			}}
	}

	}
	clearaRxBuffer();
	if(dateSlotNo==noOfDateSlots)
	return 1;
	else
		return 0;
}

/*-------------------------------function 16---------------------------*/
/*------------------------------------getting map info for day--------------------------------------*/
int function16(void) {
	int resmsg = 1;
	int seekCnt=0;
	int seekCntWrite;
	if(noOfDateSlots ==0)
		seekCntWrite=0;
	else
		seekCntWrite=seekCntForDayAndDate;
//	noOfDaySlots=3;
//	junctionId=1;
	for (int i = 1; i < noOfDaySlots + 1;) {
		if (resmsg == 1) {
			daySlotNo = i;
			i++;
		}
		if (i == 1) {
			daySlotNo = i;
			i++;
		}
		clearframe();
//		for (int i = 1; i < noOfDaySlots + 1;) {
//			if (resmsg == 1) {
//				daySlotNo = i;
//				i++;
//			}
//			if (i == 1) {
//				daySlotNo = i;
//				i++;
//			}
//			clearframe();
		/*-------------------read data from memory ---------------------------*/
		//		readMem();// for flash
		clearReadBytes();
		SDcardReadSeek("day.txt",7, seekCnt);
		seekCnt = seekCnt + 6;
		dayID = readBytes[2];
		totalNoOfPlans = readBytes[4];
		clearReadBytes();
//		totalNoOfPlans=3;
		for(int i=1; i< totalNoOfPlans+1;i++){

//			if(!(i==1))
//			{
//				    clearReadBytes();
//					SDcardReadSeek("day.txt", 15, seekCnt);
//					seekCnt = seekCnt + 10;
//					dayID = readBytes[2];
//					totalNoOfPlans = readBytes[4];
//			}
		/*-----------send frames-------------------------*/
				frame[0] = 126;
				frame[1] = 126;
				frame[2] = 0; // function no
				frame[3] = 18;
				frame[4] = junctionId; // function no
				frame[5] = programVersionNo; // junction no
				frame[6] = fileNo; // junction no
				frame[7] = 0x10; // function no
				frame[8] = dayID;  // plan no planOnHr
				frame[9] = i;  // plan no

				frame[10] = '0';
				frame[11] = '0';
				frame[12] = '0';
				frame[13] = '0';
				frame[14] = '0';
				frame[15] = '0';
				frame[16] = '0';
				frame[17] = '0';
				frame[18] = '0';  //'1'
				frame[19] = '0';  //'0' ; //'5' ;
				frame[20] = '0';  // '2' ;//'9' ;//'1' ;
				frame[21] = '0';  // '2' ;//'9' ;//'1' ;

				frame[22] = 0xFF - crcApi();  // junction no
				frame[23] = 125;
				frame[24] = 125;
				clearBuffer();

				if(programFromBLE==1)
				{
					HAL_UART_Transmit(&huart1, (uint8_t*) frame, 24, 5000);
					HAL_UART_Receive(&huart1, (uint8_t *) aRxBuffer, 35, 0x2FFF);
				}
				else
				{

				HAL_UART_Transmit(&huart3, (uint8_t*) frame, 24, 5000);
				HAL_UART_Receive(&huart3, (uint8_t *) aRxBuffer, 35, 0x1FFF);
				}

				HAL_Delay(300);
				signVal = msgParse((uint8_t *) aRxBuffer, "~~~~", 0);



		HAL_Delay(900);
		signVal=4;
		if (!(signVal == 0)){
			if (aRxBuffer[signVal + (aRxBuffer[signVal + 1]) + 2]
					+ crcApi3(signVal) == 0xFF) {
//				if((aRxBuffer[signVal]==126)){
//					signVal=signVal+1;
//				}

				signVal = signVal + 2;
				if ((aRxBuffer[signVal] == junctionId))
//				if ((aRxBuffer[signVal] == 1))
				{
					signVal = signVal + 3;
					if ((aRxBuffer[signVal] == 0x10)) //function Number
						signVal = signVal + 1;
//					if ((aRxBuffer[signVal] == planNo))

					{
//						signVal=signVal+1;

//						string[0] = dateSlotNo;  //TotalDateSlot
						// 	fnData[0] = RxBuffer[6] ;// junctiond id
//						signVal = signVal + 1;
//						string[1] = dateSlotNo;			// SerialNoOfDateSlot
//						if (string[1] == 0x6F)
//							string[1] = 0;
//						signVal = signVal + 1;
//						string[2] = aRxBuffer[signVal];	  // on time min
//						if (string[2] == 0x6F)
//							string[2] = 0;
//						signVal = signVal + 1;
						for (int i = 0; i < 6; i++) {
							string[i] = aRxBuffer[signVal];
							signVal++;
						}

//						signVal = signVal + 1;
					string[6] = 0xFF ;//
//					byteToInteger(0);
//					eepromData[planNo*4+4]=stringInt[0];


						//-------------------------SD card write-----------------------//
						SDcardWriteSeek("mapDate.txt", 7, (uint8_t *) string, seekCntWrite);
						SDcardReadSeek("mapDate.txt", 100, 0);
						seekCntWrite=seekCntWrite+7;
//						seek("plan.txt",seekCnt);
//						SDcardWriteSeek("plan.txt",17,(uint8_t *)string);
//						//--------------------------flash write------------------------//
//						HAL_FLASH_Unlock();
////						Address = Address + 4;
//						for (int i = 0; i < 17; i++) {
////						FLASH_Erase_Sector(FLASH_SECTOR_1,FLASH_VOLTAGE_RANGE_3);
//							HAL_FLASH_Program(TYPEPROGRAM_BYTE, Address,
//									string[i]);
//							Address = Address + 4;
//
//						}
//						HAL_FLASH_Lock();
//						//--------------------------flash write------------------------//
						HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_4);
						clearaRxBuffer();
						clearBuffer4();
						resmsg = 1;
//						Address=Address+4;
//						return 1 ;

					}
				}

				else {
								i = i - 1;
								resmsg = 0;
								clearaRxBuffer();
								clearBuffer4();
								return 0;
							}


			}

			else {
							i = i - 1;
							resmsg = 0;
							clearaRxBuffer();
							clearBuffer4();
							return 0;
						}



		}else {
				i = i - 1;
				resmsg = 0;
				clearaRxBuffer();
				clearBuffer4();
//				return 0;
			}}
//	}

	}
	clearaRxBuffer();
	if(noOfDaySlots ==	daySlotNo)
	return 1;
	else
	return 0;
}

/*-------------------------------function 17---------------------------*/
/*------------------------------------getting map of phases--------------------------------------*/
int function17(void) {
	int resmsg = 1;
	int seekCnt=0;
	int phaseMapID=1;
	int seekCntWrite=0;
	int totNoOfPhases=0;
	int map_ID=0;
//	noOfDaySlots=3;
//	junctionId=1;
	countNoOfMapDetails();
	for (int j = 1; j < totalNoOfMap + 1;j++) {
		clearframe();
//		for (int i = 1; i < noOfDaySlots + 1;) {
//			if (resmsg == 1) {
//				daySlotNo = i;
//				i++;
//			}
//			if (i == 1) {
//				daySlotNo = i;
//				i++;
//			}
//			clearframe();
		/*-------------------read data from memory ---------------------------*/
		//		readMem();// for flash
		clearReadBytes();
		SDcardReadSeek("mapDate.txt", 100, seekCntWrite);
//		if(j==1)
//		{
		map_ID = readBytes[4];
		totNoOfPhases = readBytes[5];
//		}
//		else{
//			map_ID = readBytes[5];
//			totNoOfPhases = readBytes[6];
//		}
		seekCntWrite=seekCntWrite+7;
		clearReadBytes();
//		totalNoOfPlans=3;
		for(int i=1; i< totNoOfPhases+1;i++){

//			if(!(i==1))
//			{
//				    clearReadBytes();
//					SDcardReadSeek("day.txt", 15, seekCnt);
//					seekCnt = seekCnt + 10;
//					dayID = readBytes[2];
//					totalNoOfPlans = readBytes[4];
//			}
		/*-----------send frames-------------------------*/
				frame[0] = 126;
				frame[1] = 126;
				frame[2] = 0; // function no
				frame[3] = 18;
				frame[4] = junctionId; // function no
				frame[5] = programVersionNo; // junction no
				frame[6] = fileNo; // junction no
				frame[7] = 0x11; // function no
				frame[8] = map_ID;  // plan no planOnHr
				frame[9] = i;  // plan no

				frame[10] = 0x01;
				frame[11] = 0x01;
				frame[12] = 0x01;
				frame[13] = 0x01;
				frame[14] = 0x01;
				frame[15] = 0x01;
				frame[16] = 0x01;
				frame[17] = 0x01;
				frame[18] = 0x01;  //'1'
				frame[19] = 0x01;  //'0' ; //'5' ;
				frame[20] = 0x01;  // '2' ;//'9' ;//'1' ;
				frame[21] = 0x01;  // '2' ;//'9' ;//'1' ;

				frame[22] = 0xFF - crcApi();  // junction no
				frame[23] = 125;
				frame[24] = 125;
				clearBuffer();

				if(programFromBLE==1)
				{
					HAL_UART_Transmit(&huart1, (uint8_t*) frame, 24, 5000);
					HAL_UART_Receive(&huart1, (uint8_t *) aRxBuffer, 40, 0x2FFF);
				}
				else
				{

				HAL_UART_Transmit(&huart3, (uint8_t*) frame, 24, 5000);
				HAL_UART_Receive(&huart3, (uint8_t *) aRxBuffer, 40, 0x1FFF);
				}

				HAL_Delay(300);
				signVal = msgParse((uint8_t *) aRxBuffer, "~~~~", 0);



		HAL_Delay(900);
		signVal=4;
		if (!(signVal == 0)){
			if (aRxBuffer[signVal + (aRxBuffer[signVal + 1]) + 2]
					+ crcApi3(signVal) == 0xFF) {
//				if((aRxBuffer[signVal]==126)){
//					signVal=signVal+1;
//				}

				signVal = signVal + 2;
				if ((aRxBuffer[signVal] == junctionId))
//				if ((aRxBuffer[signVal] == 1))
				{
					signVal = signVal + 3;
					if ((aRxBuffer[signVal] == 0x10)) //function Number
						signVal = signVal + 1;
//					if ((aRxBuffer[signVal] == planNo))

					{
//						signVal=signVal+1;

//						string[0] = dateSlotNo;  //TotalDateSlot
						// 	fnData[0] = RxBuffer[6] ;// junctiond id
//						signVal = signVal + 1;
//						string[1] = dateSlotNo;			// SerialNoOfDateSlot
//						if (string[1] == 0x6F)
//							string[1] = 0;
//						signVal = signVal + 1;
//						string[2] = aRxBuffer[signVal];	  // on time min
//						if (string[2] == 0x6F)
//							string[2] = 0;
//						signVal = signVal + 1;
						signVal=signVal+1;
						string[0]=phaseMapID;
						for (int i = 1; i < 5; i++) {
							string[i] = aRxBuffer[signVal];
							signVal++;
						}

//						signVal = signVal + 1;
					string[5] = 0xFF ;//
//					byteToInteger(0);
//					eepromData[planNo*4+4]=stringInt[0];
					phaseMapID++;

						//-------------------------SD card write-----------------------//
						SDcardWriteSeek("mapPhase.txt", 6, (uint8_t *) string, seekCnt);
						SDcardReadSeek("mapPhase.txt", 6, seekCnt);
						seekCnt=seekCnt+6;
//						seek("plan.txt",seekCnt);
//						SDcardWriteSeek("plan.txt",17,(uint8_t *)string);
//						//--------------------------flash write------------------------//
//						HAL_FLASH_Unlock();
////						Address = Address + 4;
//						for (int i = 0; i < 17; i++) {
////						FLASH_Erase_Sector(FLASH_SECTOR_1,FLASH_VOLTAGE_RANGE_3);
//							HAL_FLASH_Program(TYPEPROGRAM_BYTE, Address,
//									string[i]);
//							Address = Address + 4;
//
//						}
//						HAL_FLASH_Lock();
//						//--------------------------flash write------------------------//
						HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_4);
						clearaRxBuffer();
						clearBuffer4();
						resmsg = 1;
//						Address=Address+4;
//						return 1 ;

					}
				}
			}

			else {
							i = i - 1;
							resmsg = 0;
							clearaRxBuffer();
							clearBuffer4();
							return 0;
						}

		}else {
				i = i - 1;
				resmsg = 0;
				clearaRxBuffer();
				clearBuffer4();
				return 0;
			}}

//	}

	}
	clearaRxBuffer();
	return 1;
}


int function18(){
	int resmsg = 1;
	int seekCnt=0;
	int phaseMapID=1;
	int i;
//	int seekCntWrite=0;
//	int totNoOfPhases=0;
//	int map_ID=0;
//	noOfDaySlots=3;
//	junctionId=1;
	countNoOfMapDetails();

		clearframe();




		/*-----------send frames-------------------------*/
				frame[0] = 126;
				frame[1] = 126;
				frame[2] = 0;
				frame[3] = 14;
				frame[4] = junctionId; // function no
				frame[5] = programVersionNo; // junction no
				frame[6] = fileNo; // junction no
				frame[7] = 0x12; // function no
				frame[8] = 0x04;//noOfSides;  // plan no planOnHr

				frame[9] =  0x01;
				frame[10] = 0x01;
				frame[11] = 0x01;
				frame[12] = 0x01;
				frame[13] = 0x01;
				frame[14] = 0x01;
				frame[15] = 0x01;
				frame[16] = 0x01;
				frame[17] = 0x01;



				frame[18] = 0xFF - crcApi();  // junction no
				frame[19] = 125;
				frame[20] = 125;
				clearBuffer();

				if(programFromBLE==1)
				{
					HAL_UART_Transmit(&huart1, (uint8_t*) frame, 20, 5000);
					HAL_UART_Receive(&huart1, (uint8_t *) aRxBuffer, 50, 0x2FFF);
				}
				else
				{

				HAL_UART_Transmit(&huart3, (uint8_t*) frame, 20, 5000);
				HAL_UART_Receive(&huart3, (uint8_t *) aRxBuffer, 50, 0x1FFF);
				}

				HAL_Delay(300);
				signVal = msgParse((uint8_t *) aRxBuffer, "~~~~", 0);



		HAL_Delay(900);
//		signVal=4;
		signVal = msgParse((uint8_t *) aRxBuffer, "~~~~", 0);
		if (!(signVal == 0)){
			if (aRxBuffer[signVal + (aRxBuffer[signVal + 1]) + 2]
					+ crcApi3(signVal) == 0xFF) {
//				if((aRxBuffer[signVal]==126)){
//					signVal=signVal+1;
//				}

				signVal = signVal + 2;
				if ((aRxBuffer[signVal] == junctionId))

				{
					signVal = signVal + 3;
					if ((aRxBuffer[signVal] == 0x12)) //function Number
						signVal = signVal + 1;


					{

//						signVal=signVal+1;

						for (int i = 1; i < 26; i++) {
							string[i] = aRxBuffer[signVal];
							signVal++;
						}


					string[26] = 0xFF ;//



						//-------------------------SD card write-----------------------//
						SDcardWriteSeek("SlaveD.txt", 27, (uint8_t *) string, seekCnt);
						SDcardReadSeek("SlaveD.txt", 27, seekCnt);
//						seekCnt=seekCnt+6;
//						seek("plan.txt",seekCnt);
//						SDcardWriteSeek("plan.txt",17,(uint8_t *)string);
//						//--------------------------flash write------------------------//
//						HAL_FLASH_Unlock();
////						Address = Address + 4;
//						for (int i = 0; i < 17; i++) {
////						FLASH_Erase_Sector(FLASH_SECTOR_1,FLASH_VOLTAGE_RANGE_3);
//							HAL_FLASH_Program(TYPEPROGRAM_BYTE, Address,
//									string[i]);
//							Address = Address + 4;
//
//						}
//						HAL_FLASH_Lock();
//						//--------------------------flash write------------------------//
						HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_4);
						clearaRxBuffer();
						clearBuffer4();
						resmsg = 1;
//						Address=Address+4;
						return 1 ;

					}
				}

			}
		}

			else {
							i = i - 1;
							resmsg = 0;
							clearaRxBuffer();
							clearBuffer4();
							return 0;
						}


	clearaRxBuffer();




}








///*------------------------------function15 map function--------------------------*/
//int function15(void) {
////	Address=0x080065C8;
////	noOfPlans=3;
//	int seekCnt=0;
//	for (int i = 1; i < noOfDateSlots + 1; i++) {
//		dateSlotNo = i;
//
//		clearframe();
///*-------------------read data from memory ---------------------------*/
////		readMem();// for flash
//		clearReadBytes();
//		SDcardReadSeek("date.txt", 10, seekCnt);
//		seekCnt=seekCnt+10;
//		dateID=readBytes[2];
//		totalNoOfPlans=readBytes[2];
//		clearReadBytes();
////		for (int i = 1; i < 18;i++) {
////			Flash_Data[i]=readBytes[i];
////		}
//
///*-----------send frames-------------------------*/
//		frame[0] = 126;
//		frame[1] = 126;
//		frame[2] = 0; // function no
//		frame[3] = 32;
//		frame[4] = junctionId; // function no
//		frame[5] = programVersionNo; // junction no
//		frame[6] = fileNo; // junction no
//		frame[7] = 0x0F;; // function no
//		frame[8] = dateID;  // plan no planOnHr
//		frame[9] = totalNoOfPlans;  // plan no
//
//		frame[10] = '1';
//		frame[11] = '1';
//		frame[12] = '1';
//		frame[13] = '1';
//		frame[14] = '1';
//		frame[15] = '1';
//		frame[16] = '1';
//		frame[17] = '1';
//		frame[18] = '1';  //'1'
//		frame[19] = '1';  //'0' ; //'5' ;
//		frame[20] = '1';  // '2' ;//'9' ;//'1' ;
//
//		frame[21] = 0xFF - crcApi();  // junction no
//		frame[22] = 125;
//		frame[23] = 125;
//		clearBuffer();
//		HAL_UART_Transmit(&huart3, (uint8_t*) frame, 24, 5000);
//		HAL_UART_Receive(&huart3, (uint8_t *) aRxBuffer, 70, 0x1FFF);
//		HAL_Delay(300);
//		signVal = msgParse((uint8_t *) aRxBuffer, "~~~~", 0);
//
////signVal = msgParse(aRxBuffer,"~~~~",0);
//		while (aRxBuffer[signVal] == 126) {
//			signVal = signVal + 1;
//			if(!(aRxBuffer[signVal] == 126))
//				break;
//		}
//		signVal=4;
//		if (!(signVal == 0))
//			if (aRxBuffer[signVal + (aRxBuffer[signVal + 1]) + 2]
//					+ crcApi3(signVal) == 0xFF) {
//				signVal = signVal + 2;
//
//				if ((aRxBuffer[signVal] == junctionId))
//					if ((aRxBuffer[signVal + 3] == 4))
//						if ((aRxBuffer[signVal + 4] == planNo))
//
//						{
//							{
//
//
//
//							}
//
//						}
//				clearBuffer4();
//				clearaRxBuffer();
//			}
//		clearBuffer4();
//		clearaRxBuffer();
//	}
//	clearaRxBuffer();
//	clearBuffer4();
//	return 1;
//}





/*-------------------------------function 12_2---------------------------*/
/*------------------------------------validating date info--------------------------------------*/
/*---------------------------------------validate plan info with server----------------------------------*/
int function12_2(void) {
//	Address=0x080065C8;
//	noOfPlans=3;
	int seekCnt=0;
	for (int i = 1; i < noOfPlans + 1; i++) {
		planNo = i;

		clearframe();
/*-------------------read data from memory ---------------------------*/
//		readMem();// for flash
		clearReadBytes();
		SDcardReadSeek("date.txt", 8, seekCnt);
		seekCnt=seekCnt+8;
//		for (int i = 1; i < 18;i++) {
//			Flash_Data[i]=readBytes[i];
//		}

/*-----------send frames-------------------------*/
		frame[0] = 126;
		frame[1] = 126;
		frame[2] = 0; // function no
		frame[3] = 32;
		frame[4] = junctionId; // function no
		frame[5] = programVersionNo; // junction no
		frame[6] = fileNo; // junction no
		frame[7] = 4; // function no
		frame[8] = planNo;  // plan no planOnHr
		frame[9] = readBytes[1];  // plan no
		frame[10] = readBytes[2];  // plan no
		frame[11] = readBytes[3];  // plan no
		frame[12] = readBytes[4];  // plan no
		frame[13] = readBytes[5];  // plan no
		frame[14] = readBytes[6];  // plan no
		frame[15] = readBytes[7];  // plan no
		frame[16] = readBytes[8];  // plan no
		frame[17] = readBytes[9];  // plan no
		frame[18] = readBytes[10];// plan no
		frame[19] = readBytes[11];  // plan no
		frame[20] = readBytes[12];  // plan no
		frame[21] = readBytes[13];  // plan no
		frame[22] = readBytes[14];  // plan no
		frame[23] = readBytes[15];  // plan no

		frame[24] = readBytes[16];
		frame[25] = '1';
		frame[26] = '1';
		frame[27] = '1';
		frame[28] = '1';
		frame[29] = '1';
		frame[30] = '1';
		frame[31] = '1';
		frame[32] = '1';
		frame[33] = '1';  //'1'
		frame[34] = '1';  //'0' ; //'5' ;
		frame[35] = '1';  // '2' ;//'9' ;//'1' ;

		frame[36] = 0xFF - crcApi();  // junction no
		frame[37] = 125;
		frame[38] = 125;
		clearBuffer();
		HAL_UART_Transmit(&huart3, (uint8_t*) frame, 38, 5000);
		HAL_UART_Receive(&huart3, (uint8_t *) aRxBuffer, 70, 0x1FFF);
		HAL_Delay(300);
		signVal = msgParse((uint8_t *) aRxBuffer, "~~~~", 0);

//signVal = msgParse(aRxBuffer,"~~~~",0);
		while (aRxBuffer[signVal] == 126) {
			signVal = signVal + 1;
			if(!(aRxBuffer[signVal] == 126))
				break;
		}
		signVal=4;
		if (!(signVal == 0))
			if (aRxBuffer[signVal + (aRxBuffer[signVal + 1]) + 2]
					+ crcApi3(signVal) == 0xFF) {
				signVal = signVal + 2;

				if ((aRxBuffer[signVal] == junctionId))
					if ((aRxBuffer[signVal + 3] == 4))
						if ((aRxBuffer[signVal + 4] == planNo))

						{
							{



							}

						}
				clearBuffer4();
				clearaRxBuffer();
			}
		clearBuffer4();
		clearaRxBuffer();
	}
	clearaRxBuffer();
	clearBuffer4();
	return 1;
}

void readInputPin()
{

inputPinStatus=0;

if(!HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4))
{
	inputPinStatus=inputPinStatus | 0x01;
}
else
{
	inputPinStatus=inputPinStatus & 0xE;

}
if(!!HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5))
{
	inputPinStatus=inputPinStatus | 0x02;
}
else
{
	inputPinStatus=inputPinStatus & 0xD;

}
if(!!HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6))
{
	inputPinStatus=inputPinStatus | 0x04;
}
else
{
	inputPinStatus=inputPinStatus & 0xB;

}
if(!!HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_8))
{
	inputPinStatus=inputPinStatus | 0x08;
}
else
{
	inputPinStatus=inputPinStatus & 0x7;

}
 {
 if(!(clearenceMode==4))//for normal
 if((inputPinStatus & 0xF)==0x00)//for normal
 {
 clearenceMode=1;
 }
 if((inputPinStatus & 0xF)==0x01)//for jump
 {
 clearenceMode=4;
 }
 if((inputPinStatus & 0xF)==0x02)//for extend
 {
 clearenceMode=6;
 }
 if((inputPinStatus & 0x3)==0x03)//for clearance
 {
 clearenceMode=2;
	 if((inputPinStatus & 0xF)==0x03)
	  clearenceSide=1;

	   if((inputPinStatus & 0xF)==0x07)
	   clearenceSide=2;

	 	  if((inputPinStatus & 0xF)==0x0B)
	    clearenceSide=3;

	     if((inputPinStatus & 0xF)==0x0F)
	     clearenceSide=4;
 }




 }


}


void checkServerFieldAction(){

//------------------------------ field action-------------------//

	checkFieldAction();
	//----------------------------extend------------------------//

	if (clearenceMode == 6) {
		if (!((count > 10) && (count < 20))) {
			clearenceMode = 1;

		}

	}
	if (fieldActionFlag == 0) { //request is not coming from field
		if (checkServerJumpExtend == 0) {  //request is not from server
			if ((extendCnt == 3) || (extendCnt > 3)) {
				clearenceMode = 1;
				extendCnt1 = 1;

			}
		}
	} else {
		extendCnt = 0;

	}
	if (clearenceMode == 4) {
		if (count < 6) {
			clearenceMode = 1;

		}

	}


	if (clearenceMode==1)
		{
//			Disp[19]=0;
		count-- ;
       Disp[0] = Disp[0] - 1 ;
       Disp[1] = Disp[1] - 1 ;
       Disp[2] = Disp[2] - 1 ;
       Disp[3] = Disp[3] - 1 ;
//       Disp[6] = Disp[6] - 1 ;
      if(lSec<9)
      {
			lSec=lSec-1;
      }
			if(lSec==0)
			{
lSec=10;
clearenceMode=4;
 		 pin_HighLast=0;
}
//------------------for extend--------------//

      if(lsSec<9)
      {
			lsSec=lsSec-1;
      }
			if(lsSec==0)
			{
lsSec=10;
clearenceMode=6;
 		 pinExtend_HighLast=0;
}




if(extendCnt1==1)
{
//clearenceMode=6;
extendCnt1=0;
}
		}
if((checkServerJumpExtend==0)&&(fieldActionFlag==0))// request is not coming from server and field
				{
	 		laser(); //request is coming from camera(for jump)
			extend();//request is coming from camera

			}
			else //request is coming from server or field
				{
				lsSec=10;
				lSec=10;
				extendCnt=0;


			}

if 	(!(clearenceModeLast==clearenceMode))
	{
	if 	(clearenceModeLast==2){
if (clearenceMode==1)
	{
     Disp[0] = Disp[10]  ;
   Disp[1] = Disp[11]  ;
   Disp[2] = Disp[12] ;
   Disp[3] = Disp[13]  ;
   Disp[4] = Disp[14] ;
     Disp[5] = Disp[15]  ;
   Disp[6] = Disp[16]  ;
   Disp[7] = Disp[17] ;
clearenceModeLast=1 ;
				}
	}
if (clearenceMode==2)
				{
     Disp[10] = Disp[0]  ;
   Disp[11] = Disp[1]  ;
   Disp[12] = Disp[2] ;
   Disp[13] = Disp[3]  ;
   Disp[14] = Disp[4] ;
     Disp[15] = Disp[5]  ;
   Disp[16] = Disp[6]  ;
   Disp[17] = Disp[7] ;
     clearenceModeLast=2 ;
//	secLast =RTC_TimeStructure.RTC_Seconds ;
     secLast=sTime.Seconds;
	count=1 ;
   Disp[0] = 1 ;
   Disp[1] = 1 ;
   Disp[2] = 1 ;
   Disp[3] = 1 ;
   Disp[6] = 1 ;
switch (clearenceSide)
{
case 1 :
Disp[4] =0x38 ;
Disp[5] =0x88 ;
Disp[7]=Disp[7]| 0x80 ;

break ;
case 2 :
Disp[4] =0x88 ;
Disp[5] =0x38 ;
Disp[7]=Disp[7]| 0x80 ;

break ;
case 3 :
Disp[4] =0x83 ;
Disp[5] =0x88 ;
Disp[7]=Disp[7]| 0x80 ;

break ;
case 4 :
Disp[4] =0x88 ;
Disp[5] =0x83 ;
Disp[7]=Disp[7]| 0x80 ;

break ;
case 5 :
Disp[4] =0x88 ;
Disp[5] =0x88 ;
Disp[7]=Disp[7]| 0x03 ;

break ;
}

	HAL_Delay(50);







				}
if (clearenceMode==4)
{
if (!((Disp[4]==0x84)||(Disp[4]==0x48)||(Disp[5]==0x84)||(Disp[5]==0x48)))
			{
				if(count > 5){
					count =count-5;
					Disp[0] =Disp[0]-count  ;
   Disp[1] = Disp[1]-count  ;
   Disp[2] = Disp[2]-count ;
   Disp[3] = Disp[3]-count ;
   Disp[6] = Disp[6]-count;
				count =5;
				}
//				count=5;
		 clearenceModeLast=1 ;
			clearenceMode=1;
//	return ;
				}
}
				else
					{
//		 clearenceModeLast=1 ;
//			clearenceMode=1;

					}
if (clearenceMode==6)
{
if((count<20) && (count>10))
	{
		if(extendCnt <3 )
			{
	Disp[0] = Disp[0] + 4 ;
   Disp[1] = Disp[1] + 4 ;
   Disp[2] = Disp[2] + 4 ;
   Disp[3] = Disp[3] + 4 ;
		 count = count + 4 ;
	 clearenceModeLast=1 ;
			clearenceMode=1;
	extendCnt++;
		}
			else{


			}
	}
}
if (clearenceMode==5)
{
Disp[4] =0x00 ;
Disp[5] =0x00 ;
	 clearenceModeLast=5 ;
	 clearenceMode=5;
}
	if (clearenceMode==1)
		clearenceModeLast=1 ;
}






}


void checkFieldAction(){

	checkClearenceSide();//check clear side
		if(clearance_Side==0) //no side is clear
			{
      checkClearenceMode(); //check clearance mode
			if(clearance_Mode==3) //if clearance mode is change mode
				if(!(clearance_Mode==clearance_Mode_Last))
				{
			changeMode=1;
		if(planMode==3){
			planMode=1;
		}
			if(planMode==1)
			{
				planMode=3;
			}
//				clearance_Mode_Last=clearance_Mode;
			}
	//		clearenceMode=clearance_Mode;
		}
//		else //update the clearance mode to clear and clear side
//			{
//			clearenceMode=clearance_Mode;
//		clearenceSide=clearance_Side;
//		}

			if(((clearance_Mode==1) && (clearance_Side==0)))//field request is not  coming

		{
					fieldActionFlag=0;


		}
		else//field request is coming
			{
				fieldActionFlag=1;
			clearenceMode=clearance_Mode;
  		clearenceSide=clearance_Side;

		}

	clearance_Mode_Last=clearance_Mode;


	}


void checkClearenceSide(){
	clearance_Side=0;
//----------------------------side 1---------------------//
	if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_11))	{
		clearance_Side=1;
		}

//----------------------------side 2---------------------//
		if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_12))	{
			clearance_Side=2;
		}

//----------------------------side 3--------------------//
		if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_13))	{
			clearance_Side=3;
		}

//--------------------------side 4-----------------------//
		if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_14))	{
			clearance_Side=4;
		}
if(! (clearance_Side==0))
{
	clearance_Mode=2;

}



}

void checkClearenceMode(){
	clearance_Mode=1;
//---------------------------- for jump---------------------//
	if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_7))	{
		clearance_Mode=4;
		}

//---------------------------- for extend---------------------//
		if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_8))	{
			clearance_Mode=6;
		}

//--------------------------- for modeChange--------------------//
		if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_9))	{
			clearance_Mode=3;
		}

//-------------------------- for shutdown-----------------------//
		if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_10))	{
			clearance_Mode=5;
		}

}



void laser()
{

pin_High=0;

		 if(!HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4))
		 {
			 pin_High=1;/*flag updated if pin is high  */

		 }

if(!(pin_High==1))
{
		 laserOn =0 ;
	 pin_High=0;
	 lSec=10;
		 pin_HighLast=0;
}
if(!(pin_HighLast==1))
	 if(pin_High==1)
	 {
    lSec=1;
		 pin_HighLast=1;
		 laserOn =1 ;
}
}

void extend(){

 pinExtend_High=0;

		 if(!HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5))
		 {
			 pinExtend_High=1;/*flag updated if pin is high  */

		 }

 if(!(pinExtend_High==1))
 {
		 pinExtend_On =0 ;
	 pinExtend_High=0;
	 lsSec=10;
 		 pinExtend_HighLast=0;
}
 if(!(pinExtend_HighLast==1))
	 if(pinExtend_High==1)
	 {
     lsSec=3;
		 pinExtend_HighLast=1;
		 pinExtend_On =1 ;
}



 }


//HAL_UART_RxCpltCallback();

void countNoOfMapDetails(){
int counter=0;
	/*------------------checks the current date with dateSlot or with daySlot-------------*/
	  	/*------------------checking dateSlot---------date.txt-----*/
totalNoOfMap=0;
	  	for(int i=1;i<noOfDateSlots+1;i++)
	  	{


	  	    readDateSD(counter);
	  		counter=counter+11;

						totalNoOfMap=totalNoOfMap+readBytes[9];




	  	}

		counter=0;

		for(int i=1;i<noOfDaySlots+1;i++)
	  	{
			   readDaySD(counter);
			  	counter=counter+6;


			  	    totalNoOfMap=totalNoOfMap+readBytes[4];




	  	}


}
void currentDayAllPlan(){
int counter=0;
int cnt=0;
int enterLoop;
int ptr=0;
int mapCounter_Phase=0;
int phaseMapCnt2=0;
clearPlanDetailsArrayBuffer();
for(int i=1;i<totalNoOfMap+1;i++){
clearReadBytes();
SDcardReadSeek("mapDate.txt", 7, cnt);
cnt=cnt+7;
phaseMapCnt2=readBytes[5];
phaseMapCnt1=phaseMapCnt1+phaseMapCnt2;
/*-------if it is weekday--------------*/
if((dateID==readBytes[0])&&(dayID ==readBytes[1]))
{
planID=readBytes[2];
mapID=readBytes[4];
noOfPhases_Map=readBytes[5];
enterLoop=1;
// break;
}
else
{
/*----------if it is day or date-----------*/
if(!((dateID==0)||(dayID == 0)))
{
if((dateID==readBytes[0])||(dayID ==readBytes[1])){
planID=readBytes[2];
mapID=readBytes[4];
noOfPhases_Map=readBytes[5];
enterLoop=1;
}
}
else{
enterLoop=0;
}
}
/*transfer the current day's - dayID/dateID ,PlanID and mapID */
//if(enterLoop==1){
//	phaseMapCnt++;
//	phaseMapArray[mapCounter_Phase]=dateID;
//	phaseMapArray[mapCounter_Phase+1]=dayID;
//	phaseMapArray[mapCounter_Phase+2]=planID;
//	phaseMapArray[mapCounter_Phase+3]=mapID;
//	phaseMapArray[mapCounter_Phase+4]=0xFF;
//	mapCounter_Phase=mapCounter_Phase+5;
//
//}


if(!((planID==0x00)&&(mapID==0x00)))
{
//for(int i=1;i<noOfPlansN+1;i++)
// if((dateID==readBytes[0])||(dayID ==readBytes[1]))
	counter=0;
if(enterLoop==1)
for(int i=1;i<totalNoOfMap+1;i++)
{


//readMem();
clearReadBytes();
readPlanSD(counter);
 counter=counter+19;
/*---------if planID matches so get the plan details------------*/
if(planID==readBytes[0])
{
	/*transfer the current day's - dayID/dateID ,PlanID and mapID */
	phaseMapCnt++;
	phaseMapArray[mapCounter_Phase]=dateID;
	phaseMapArray[mapCounter_Phase+1]=dayID;
	phaseMapArray[mapCounter_Phase+2]=planID;
	phaseMapArray[mapCounter_Phase+3]=mapID;
	phaseMapArray[mapCounter_Phase+4]=noOfPhases_Map;
	phaseMapArray[mapCounter_Phase+5]=0xFF;
	mapCounter_Phase=mapCounter_Phase+6;





for(int i=0;i<19;i++){
planDetailsArray[ptr+i]=readBytes[i];
// counter++;
}
       for(int j=0;j<4;j++){
        planTime[j]= readBytes[j+2];

       }
//       counter=counter+19;
       ptr=ptr+19;
       break;
       }

}
}
counterOfPlan=ptr;
}
}
//void currentDayAllPlan(){
// int counter=0;
// int cnt=0;
// int enterLoop;
//
//	for(int i=1;i<totalNoOfMap;i++){
//
//		SDcardReadSeek("mapDate.txt", 100, cnt);
//		cnt=cnt+6;
//		if((dateID==readBytes[0])||(dayID ==readBytes[1])){
//			planID=readBytes[2];
//			mapID=readBytes[4];
//			enterLoop=1;
//	//		break;
//		}
//		else
//		{
//			enterLoop=0;
//		}
//
//
//		if(!((planID==0x00)&&(mapID==0x00)))
//		{
//		//for(int i=1;i<noOfPlansN+1;i++)
////			if((dateID==readBytes[0])||(dayID ==readBytes[1]))
//			counter=0;
//		if(enterLoop==1)
//			for(int i=1;i<noOfPlans+1;i++)
//			{
//
//
//		//readMem();
//			readPlanSD(counter);
////			counter=counter+19;
//			/*---------if planID matches so get the plan details------------*/
//			if(planID==readBytes[0])
//			{
//				for(int i=0;i<19;i++){
//					planDetailsArray[counter+i]=readBytes[i];
////					counter++;
//				}
//		        for(int j=0;j<4;j++){
//		        	 planTime[j]= readBytes[j+2];
//
//		        }
//
//	        }
//			counter=counter+19;
//		}
//		}
//
//	}
//}

void getCurrentPlanTotalNoOfPhases(){
int cnt=0;
int phaseMap;
int counterOfList=0;
int seekCnt=0;
int cnt1=0;
int phaseId=0;
int mapID=0;
uint32_t flashAdd=ADDR_FLASH_SECTOR_10;
//int ptr=0;
/*----------get the current plan's , phaseMap from mapPhase.txt file-------- */
for(int i=0;i<phaseMapCnt;i++)// current day no of plans
{
	seekCnt=0;
	cnt1=0;
	phaseMap=phaseMapArray[cnt+3];
	noOfPhasesInMapID=phaseMapArray[cnt+4];
	totalNoOfPhasesInMapID=totalNoOfPhasesInMapID+noOfPhasesInMapID;
	for (int i=0;i<phaseMapCnt1+1;i++)// total no of phases
	{
		SDcardReadSeek("mapPhase.txt", 6, seekCnt);
		seekCnt=seekCnt+6;
		if(phaseMap==readBytes[1]){
			for(int i=0;i<6;i++)
			{
				phaseMapIDList[i+counterOfList]=readBytes[i];

			}
			counterOfList=counterOfList+6;
			cnt1++;

		}
     if(noOfPhasesInMapID==cnt1)
    	 break;
	}
	cnt=cnt+6;
}
SDcardReadSeek("phase.txt", 350, 0);
/*-------get the current day's all phases with the help of mapPhase.txt from phase.txt----- */
counterOfList=0;
cnt=0;
clearReadBytes();

for(int j=0;j<totalNoOfPhasesInMapID;j++)// current day no of phases
{
	seekCnt=0;
	eepromAddress=0;
	cnt1=0;
	mapID=phaseMapIDList[cnt+1];
	phaseId=phaseMapIDList[cnt+2];
	noOfPhasesInMapID=phaseMapArray[cnt+4];

	for (int i=0;i<totalNoOfPhases;i++)// total no of phases
	{
//		/*----------read phase from SD card---------start----------*/
//		SDcardReadSeek("phase.txt", 17, seekCnt);
//		seekCnt=seekCnt+17;
//		/*----------read phase from SD card----------end-----------*/

		/*-------read phase from eeprom-------start------*/

//		EEPROM_ReadArray(readBytes,17,eepromAddress);
//		eepromAddress=eepromAddress+17;

		/*--------read phase from eeprom-------end-------*/

		/*--------read phase from flash start-----------*/
		/*--------read current day plan in flash---------*/
		  HAL_FLASH_Unlock();
		  Flash_ReadByte(flashAdd,readBytes,17);
		  flashAdd=flashAdd+17;
		  HAL_FLASH_Lock();
		 /*--------read current day plan in flash---------*/

		/*--------read phase from flash end------------*/

		if(phaseId==readBytes[3]){
			for(int i=0;i<15;i++)
			{
				phaseList[i+counterOfList]=readBytes[i];

			}
			counterOfList=counterOfList+18;
			cnt1++;
			 break;

		}

	}
	cnt=cnt+6;
}




//    /*----------get total number of phases-----------*/
//	SDcardReadSeek("phaseCnt.txt", 5, 0);
//	noOfPhaseCnt=readBytes[1];
//
//
//	/*--------incrementing the value of phase,till it reach the peak counter------  */
//	for(int i=1;i<phaseMapCnt+1;i++)
//	{
//
////		phaseMapArray
//
//	SDcardReadSeek("phase.txt", 350, cnt);
//	cnt=cnt+17;
//	/*-------if mapID matches--------------*/
//	if(mapID==readBytes[2])
//	{
//
//	enterLoop=1;
//	// break;
//	}
//	else{
//		enterLoop=0;
//	}
//
//	if(enterLoop==1)
////	for(int i=1;i<totalNoOfMap+1;i++)
//	{
//
//
//
//
//	       for(int j=0;j<16;j++){
//	        phaseData[j+counter]= readBytes[j];
//
//	       }
//	       counter=counter+16;
////	       ptr=ptr+16;
////	       break;
//
//
//	}
//
//
//	}






}


void getCurrentPlanPhases()
{


	int cnt=0;
	int cnt1=0;
	int cnt2=0;
	int counterOfList=0;
	int cnt3=0;
	uint8_t phaseMapID;



	for(int i=0;i<phaseMapCnt;i++)// current day no of plans
	{
		if(plan_ID==phaseMapArray[cnt+2])
		{
			mapIDForCurrentPhases=phaseMapArray[cnt+3];
			total_Phases=phaseMapArray[cnt+4];
			break;
		}
		cnt=cnt+6;
	}

	uint8_t loopCnt=totalNoOfPhasesInMapID;





	for (int mi=0;mi<loopCnt;mi++){

		if(mapIDForCurrentPhases==phaseMapIDList[cnt2+1])
		{

			Map_IDCurrent[cnt3]=phaseMapIDList[cnt2+2];// phaseID
			Map_IDCurrent[cnt3+1]=phaseMapIDList[cnt2+3];//phaseMapId
			cnt3=cnt3+3;
		}

		cnt2=cnt2+6;

	}






	cnt2=0;
	count=0;


	for(int j=0;j<totalNoOfPhasesInMapID;j++)// current day no of phases
	{

//		cnt1=0;
//		count=0;
		phaseMapID=Map_IDCurrent[cnt2];
		for (int k=0;k<total_Phases;k++)// total no of phases
		{

//			if(mapIDForCurrentPhases==phaseList[counterOfList+2])
			if(phaseMapID==phaseList[counterOfList+3])
			{
				for(int l=0;l<15;l++)
				{
					currentPlanPhases[l+count]=phaseList[l+counterOfList-2];

				}
				count=count+18;
				cnt1++;
				 break;

			}
			counterOfList=counterOfList+18;

//			count=count+18;
	//     if(noOfPhasesInMapID==cnt1)
	//    	 break;
		}
		cnt2=cnt2+3;
		cnt=cnt+6;
//		counterOfList=counterOfList+18;
		     if(total_Phases==cnt1)
			    	 break;
	}






}

/*----------------detect which side is being changed and which bit-----------*/
unsigned char DetectChange(unsigned char currentSide13Color,unsigned char previousSide13Color)
//		,unsigned char currentSide24Color,unsigned char previousSide24Color)
{
//
//	uint8_t sideNo1,sideNo2,sideNo3,sideNo4,color;
//
//	/*------------ for side13--------------*/
static unsigned char val,i,ChangeByte13;
ChangeByte13=0;
for(i=0;i<8;i++)
{
val = 0x01 << i;

if( (currentSide13Color & val) != (previousSide13Color & val) )
{
ChangeByte13 |= val;
}
}

///*------------ for side24--------------*/
//static unsigned char val1,j,ChangeByte24;
//ChangeByte24=0;
//for(j=0;j<8;j++)
//{
//val1 = 0x01 << j;
//
//if( (currentSide24Color & val1) != (previousSide24Color & val1) )
//{
//	ChangeByte24 |= val1;
//}
//}
///*------which side is changed and which color-------*/
//
//if(!(ChangeByte13==0))
//{
//	/*----------------seperating the values of sides------------------*/
//	sideNo1= ChangeByte13 >> 4; // right shift 4 bit
//	sideNo1=sideNo1 << 4 ; //left shift 4 bit
//	if (!(sideNo1==0)){
//       sideNo1=1;
//       color=ChangeByte13 & currentSide13Color;
//       if(color == 0x40)
//       {
//    	   break;
//       }
//       if(color == 0x30)
//       {
//           break;
//       }
//	}
//	sideNo3=  ChangeByte13 ^ sideNo1; //
//}
//
//if(!(ChangeByte24==0))
//{
//	/*----------------seperating the values of sides------------------*/
//	sideNo2= ChangeByte24 >> 4; // right shift 4 bit
//	sideNo2=sideNo2 << 4 ; //left shift 4 bit
//	sideNo4=  ChangeByte24 ^ sideNo2; //
//}





return ChangeByte13;
}

void BLECommunication(){


	/*------------------For BLE Communication--------------------*/

	/*-------------uart1---------------pb6 pb7---------------------*/
	if (msgUnPrcd1 == 1) {

		//function6_2();
		signVal = msgParse((uint8_t *) RecMsg1, "~~~~", 0);
//		 	   				  			  		signVal=4;
		if (!(signVal == 0)) {
			if (RecMsg1[signVal + (RecMsg1[signVal + 1]) + 2] + crcApi1(signVal)
					== 0xFF) {
				// transferDataValues(signVal);
//		 	   				  			  				  	HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_10);//master
				slave4Rsp = 1;
				if (!(RecMsg1[signVal + 3] == programVersionNo)) {
					//			 imei[29]=2;

					// 		function1();
					// 		function4();
					// 		function42();

				}

				signVal = signVal + 3;
				if (!(RecMsg1[signVal++] == programVersionNo))
					programVersionNo = RecMsg1[signVal] - 1;
				signVal = signVal + 2;

				if (RecMsg1[signVal++] == 1)
					if (RecMsg1[signVal++] == 1)
						if (RecMsg1[signVal++] == 1)
							if (RecMsg1[signVal++] == 1) {
								clearenceMode = 1;
											checkServerJumpExtend=0;
											HAL_GPIO_WritePin(GPIOE, GPIO_PIN_1, GPIO_PIN_RESET);

							}
				if (!(RecMsg1[7] == programVersionNo)) {
					program3();
										checkServerJumpExtend=0;
				}
				if (RecMsg1[9] == 8)
					//		clearenceMode=RxBuffer[10];
					if ((!(RecMsg1[10] == 1))) {
										checkServerJumpExtend=0;
						//----------------------------For Shutdown---------------//
						if (RecMsg1[10] == 5) {
							HAL_GPIO_WritePin(GPIOE, GPIO_PIN_1, GPIO_PIN_SET);
							clearenceMode = 9;
							clearenceSide = RecMsg3[11];

						} else {
							HAL_GPIO_WritePin(GPIOE, GPIO_PIN_1, GPIO_PIN_RESET);

						}
						//----------------------------For ChangeMode---------------//
						if (RecMsg1[10] == 3) {
							//GPIOA->BRR = GPIO_Pin_4;//set bit as high
							//if()
							changeMode = 1;
							if (planMode == 2)							//3)
									{
								planMode = 1;
							}
							if (planMode == 1) {
								planMode = 2;							//3;
							}
							//clearenceSide=RxBuffer[11];

						}

						//----------------------------For  extend---------------//

						if (RecMsg1[10] == 6) // extend request
								{
							clearenceMode = RecMsg3[10];
							clearenceSide = RecMsg3[11];
											checkServerJumpExtend=1;

						}

						//----------------------------For  clearance---------------//
						if (RecMsg1[10] == 2) {
							clearenceMode = RecMsg3[10];
							clearenceSide = RecMsg3[11];

						}

					}
				//----------------------------For  jump---------------//
				if (RecMsg1[10] == 4) // jump request
						{
					clearenceMode = 4;
									checkServerJumpExtend=1;

				}
				HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_2); //master

				clearBuffer3();
				clearaRxBuffer3();
				msgUnPrcd1 = 0;
//		 	   				  			  		 	   		millisec1=0;
			}
			clearBuffer3();
			clearaRxBuffer3();
			msgUnPrcd1 = 0;
//		 	   				  			  			  	millisec1=0;
			//	transmit();
		}
	}
//		clearBuffer4();
//		clearaRxBuffer4();
//		msgUnPrcd4 = 0;


}


void sideChange(char previousSide13Color,char currentSide13Color
		,char previousSide24Color,char currentSide24Color)
{

	/*-------- compare the color of side13 and side24 last with current------------*/
//	char currentSide13Color = 0x38;
//	char previousSide13Color = 0x48;
//	char currentSide24Color = 0x88;
//	char previousSide24Color = 0x88;
	char sideNoChanged,color;



		/*-------check side13------*/
	    changedSide =DetectChange(currentSide13Color,previousSide13Color);
	    if(currentSide13Color==0x88){
	    	changedSide=0;
	    }

		/*-----if change side13 is 0, means that there is no change on side13
		 *  check side24----------- */
//	    if(3>5)
//	    {
//	    	changedSide=1;
//	    }
//	    else
//	    {
//	    	changedSide=2;
//	    }
//	    changedSide=1;

		if(!(changedSide==0))
		{

			/*------side 1 is changed-----*/
					side= changedSide >> 4;
					if(side == 0)
					{
						sideNoChanged=3;
						color=currentSide13Color & changedSide;
					}
					else
					{  /*----- side 3 is changed-----*/
						sideNoChanged=1;
						color=currentSide13Color & changedSide;
					}

			}
		else /*-----------side13 is changed------ */
		   {
//			if(noOfSides==3){
//				Disp[39]==currentSide24Color & 0x08;
//				Disp[40]==previousSide24Color & 0x08;
//
//				currentSide24Color=Disp[39];
//				previousSide24Color=Disp[40];
//
//			}

			changedSide =DetectChange(currentSide24Color,previousSide24Color);

				/*------side 2 is changed-----*/
				side=changedSide >> 4;
				if(side == 0)
				{
					sideNoChanged=4;
					color=currentSide24Color & changedSide;
				}
				else
				{  /*----- side 4 is changed-----*/
					sideNoChanged=2;
					color=currentSide24Color & changedSide;
				}


		}
//		sideNoChanged=1;

		switch(sideNoChanged){

		case 1:
			if(color== 0x30)//for green
			{

            Disp[28]=planS1GT;


			}
			if(color== 0x40) //for yellow
			{
				Disp[28]=planA1GT ;
			}
			break;
		case 2:
			if(color== 0x30)//for green
			{
				Disp[28]=planS2GT;
			}
			if(color== 0x40) //for yellow
			{
				Disp[28]=planA2GT;
			}

			break;

		case 3:
			if(color== 0x03)//for green
			{
				Disp[28]=planS3GT;

			}
			if(color== 0x04) //for yellow
			{
				Disp[28]=planA3GT;
			}

			break;

		case 4:
			if(color== 0x03)//for green
			{
				Disp[28]=planS4GT;
			}
			if(color== 0x04) //for yellow
			{
				Disp[28]=planA4GT;
			}

			break;
		}


}


void clearPrimaryAndSecByte()
{

	int x=0;
	for(;x<6;x++)
	{
	primaryHorizontalByte[x] = 0x00;
	secondaryHorizontalByte[x] = 0x00;
	primaryVerticalByte[x] = 0x00;
	secondaryVerticalByte[x] =  0x00;

	}
}

void findSide(uint8_t side13Color,uint8_t side24Color)
{
 uint8_t side_1,side_2,side_3,side_4;
	/*----------------seperating the values of sides------------------*/
    side_1= side13Color >> 4; // right shift 4 bit
    side_1= side_1 << 4 ; //left shift 4 bit
    side_3= side13Color ^ side_1; //

    side_2= side24Color >> 4; // right shift 4 bit
    side_2=side_2 << 4 ; //left shift 4 bit
    side_4=  side24Color ^ sideNo2; //


    if(side_1==0x30) // green side1
    {
       	Disp[28]=planS1GT;
    	Disp[4]=Color[1];
    	Disp[5]=Color[2];
    	phase_ID=Color[3];
    }
    if(side_1==0x40) // yellow side1
    {
    			Disp[28]=planA1GT;
    			Disp[4]=Color[1];
    			Disp[5]=Color[2];
    			phase_ID=Color[3];
    }

    if(side_2==0x30) // green side2
     {
        Disp[28]=planS2GT;
     	Disp[4]=Color[1];
     	Disp[5]=Color[2];
     	phase_ID=Color[3];
     }
     if(side_2==0x40) // yellow side2
     {
     			Disp[28]=planA2GT;
     			Disp[4]=Color[1];
     			Disp[5]=Color[2];
     			phase_ID=Color[3];
     }
     if(side_3==0x30) // green side3
      {
         	Disp[28]=planS3GT;
      	Disp[4]=Color[1];
      	Disp[5]=Color[2];
      	phase_ID=Color[3];
      }
      if(side_3==0x40) // yellow side3
      {
      			Disp[28]=planA3GT;
      			Disp[4]=Color[1];
      			Disp[5]=Color[2];
      			phase_ID=Color[3];
      }
      if(side_4==0x30) // green side4
       {
          	Disp[28]=planS4GT;
       	Disp[4]=Color[1];
       	Disp[5]=Color[2];
       	phase_ID=Color[3];
       }
       if(side_4==0x40) // yellow side4
       {
       			Disp[28]=planA4GT;
       			Disp[4]=Color[1];
       			Disp[5]=Color[2];
       			phase_ID=Color[3];
       }








}

void resetVariables()
{

	junctionId = 111;
	noOfDateSlots=0;
	dateSlotNo=0;
	dateID=0;
	dayID=0;
	totalNoOfPlans=0;
	totalNoOfPhases=0;
	noOfDaySlots=0;
	daySlotNo=0;
	noOfSides = 0;
	noOfPlans = 0;
	noOfPhase = 0;
	programVersionNo = 0;
	programVersionNoLast = 0;
	registrationStatus = 0;
	totalPhase=0;
	padestarianTime = 10;
	phaseMapCnt=0;
	phaseMapCnt1=0;//total no of phases in phase.txt
    incCnt=0;
//	isReprogrammed=0;

}



void sendData()
{
	RecMsg3[0]='1';
	RecMsg3[1]='1';
	RecMsg3[2]='1';
	HAL_UART_Transmit(&huart3, (uint8_t*) RecMsg3, 3, 5000);
	            clearBuffer3();
				clearaRxBuffer3();
				msgUnPrcd3 = 0;


}

void extractSlaveInfo()
{

int seekCnt =0;
/*-------------------read SD card begins-------------------*/
	SDcardReadSeek("SlaveD.txt", 27, seekCnt);

   for(int i=0;i<26;i++)
   {
	  slaveDetails[i]= readBytes[i];
   }






}
void  populatePrimaryHVSecondaryHV()
{

	/*----------------Separating the values of sides------------------*/

	sideNo1= Disp[4] >> 4; // right shift 4 bit side13
	sideNo1=sideNo1 << 4 ; //left shift 4 bit
	sideNo3=  Disp[4] ^ sideNo1; //
    sideNo3=sideNo3 << 4;

	sideNo2= Disp[5] >> 4; // right shift 4 bit
	sideNo2=sideNo2 << 4 ; //left shift 4 bit
	sideNo4=  Disp[5] ^ sideNo2; //
	sideNo4=sideNo4 << 4;


//	sideNo1= Disp[4] >> 4; // right shift 4 bit // 0x83= 0x8
//	sideNo1_1=sideNo1 << 4 ; //left shift 4 bit   //0x80
//    sideNo1_1= sideNo1 | sideNo1_1;
//    primaryByte[1]=sideNo1_1;
//
//	sideNo3=  Disp[4] ^ sideNo1; //
//	sideNo3_1= sideNo3 << 4;
//	sideNo3_1=sideNo3 | sideNo3_1;
//
//	sideNo2= Disp[5] >> 4; // right shift 4 bit
//	sideNo2_1=sideNo2 << 4 ; //left shift 4 bit
//	sideNo2_1= sideNo2 | sideNo2_1;
//
//	sideNo4=  Disp[5] ^ sideNo2; //
//	sideNo4_1= sideNo4 << 4;
//	sideNo4_1=sideNo4 | sideNo4_1;


  primaryHorizontalByte[1]=sideNo1;
  primaryVerticalByte[1]=sideNo1;
  secondaryHorizontalByte[1]=sideNo3;
  secondaryVerticalByte[1]=sideNo3;

  primaryHorizontalByte[2]=sideNo2;
  primaryVerticalByte[2]=sideNo2;
  secondaryHorizontalByte[2]=sideNo4;
  secondaryVerticalByte[2]=sideNo4;

  primaryHorizontalByte[3]=sideNo3;
  primaryVerticalByte[3]=sideNo3;
  secondaryHorizontalByte[3]=sideNo1;
  secondaryVerticalByte[3]=sideNo1;


  primaryHorizontalByte[4]=sideNo4;
  primaryVerticalByte[4]=sideNo4;
  secondaryHorizontalByte[4]=sideNo2;
  secondaryVerticalByte[4]=sideNo2;





//	primaryByte[1] = 0x83;
//
//	secondaryByte[1] = 0x38;

//	/*----------------Separating the values of sides------------------*/
//	for (int i=1 ;i<6;i++)
//	{
///*--here primaryByte[1] mean 4bit for horizontalside1 and next for verticalside1
// *-- and secondaryByte[1] mean 4bit for horizontalside3 and next for verticalside3
// *-- it means that with side 1 there will be side 3 , same way with side 2 there will be side 4 */
//
//	primaryHorizontalByte[i]= primaryByte[i] >> 4; // right shift 4 bit
//	primaryHorizontalByte[i]=primaryHorizontalByte[i] << 4 ; //left shift 4 bit
//	primaryVerticalByte[i]=  primaryByte[i] ^ primaryHorizontalByte[i]; //
//	primaryVerticalByte[i] = primaryVerticalByte[i] << 4 ;
//
//	secondaryHorizontalByte[i]= secondaryByte[i] >> 4; // right shift 4 bit
//	secondaryHorizontalByte[i]= secondaryHorizontalByte[i] << 4 ; //left shift 4 bit
//	secondaryVerticalByte[i]=  secondaryByte[i] ^ secondaryHorizontalByte[i]; //
//	secondaryVerticalByte[i] = secondaryVerticalByte[i] << 4 ;
//
//	}





}


