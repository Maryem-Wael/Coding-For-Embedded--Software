#include "i2c.h"
#include "ds1307.h"

char sAddres = 0x44;
char *Time_DataReadBuffer;
char ReadStartAddress;
char ReadDataLength;
unsigned char Time_IsReadRequested;

void Time_ReadData(char memoryAddress,char data[],int n)
{
	Time_DataReadBuffer =&data;
	ReadStartAddress = memoryAddress;
	ReadDataLength = n;
	Time_IsReadRequested = (unsigned char)1;
}

void Time_ManageDataRead(void)
{
	switch(StateVariable)
	
	{
	case IDLE:
	
		//Do Nothing
		break;
		
	// Time_ReadData called
	case Time_IsReadRequested:
	
		I2C1_READ(sAddres,ReadStartAddress,Time_DataReadBuffer,ReadDataLength);
		StateVariable=Notification;
		break;
		
	case Notification:
		client_notification_function();
		break;
		
}
