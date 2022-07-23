/*
 * DIO.h
 *
 *  Created on: Mar 23, 2022
 *      Author: moham
 */

#ifndef INC_DIO_H_
#define INC_DIO_H_


void DIO_Init(void);
void DIO_ChannelWrite(unsigned char ChannelId, unsigned char Data);
void DIO_ChannelWrite_Group(unsigned char ChannelsID[], unsigned char Data[]);
void DIO_ChannelRead(unsigned char ChannelId, unsigned char *DataPtr);
unsigned int * DIO_ChannelRead_Group(unsigned char ReadChannelsId[], unsigned char ReturnedData[]);
void delay(int sec){
	for (int i=0 ; i<sec ; i++){}
}


#endif /* INC_DIO_H_ */
