
#include <PollDataClient.h>
#include <device.h>
#include <GPIO.h>

#include "stm32f4xx.h"


unsigned char button;

void init_Client(void){
	subscribe(update);

}

void update(unsigned char data){
	Handle_data(data);
}
void Handle_data(unsigned char button)
{
	if(button==0)
	{
		GPIO_WritePin(0,1,0);
	}
	else
	{
		GPIO_WritePin(0,1,1);
	}
}

