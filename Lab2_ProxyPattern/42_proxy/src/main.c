#include "stm32f4xx.h"
#include "DIO.h"

unsigned char ChannelsID[]={1,2};  /*ChannelsID to write on*/
unsigned char Data[]={1,1};        /*Data to write on ChannelsID*/
unsigned char Clear[]={0,0};        /*To Clear ChannelsID*/
unsigned char ReadChannelsID[]={0,3}; /*ChannelsID to read from*/
unsigned char ReturnedData[]={0,0};   /*Returned Data from Read Channels*/

int main(void)
{
	DIO_Init();

	while(1)
	  {
		DIO_ChannelRead_Group(ReadChannelsID , ReturnedData);  /*Read buttons on pin 1 and 4*/
		delay(500);
		DIO_ChannelRead_Group(ReadChannelsID , ReturnedData);
		if((ReturnedData[0] == 0) && (ReturnedData[1] == 1)){ /*check if button on 1 pressed and on 4 released*/
			DIO_ChannelWrite_Group(ChannelsID,Data); /*turn on the leds*/
		}

	  }
}

