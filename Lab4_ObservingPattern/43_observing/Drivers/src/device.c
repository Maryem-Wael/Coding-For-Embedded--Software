#include "PollerTimer.h"
#include "stm32f4xx.h"
#include "device.h"
#include "GPIO.h"
#include "PollDataClient.h"

#define MAXFUNCTIONS (1)
void (*functionsptr[MAXFUNCTIONS])(unsigned char);

unsigned char data;

unsigned char Get_Data(void)
{
	data=GPIO_ReadPin(0,0);
	return data;
}

void subscribe(void (*ptr)(unsigned char))
{
	for (int i=0 ; i<=MAXFUNCTIONS ; i++)
	{
		if((functionsptr[i] == 0))
		{
			functionsptr[i]=ptr;
			//unsubscribe(&i);
		}
	}
}

void unsubscribe(int *Y)
{
	functionsptr[*Y]= 0;
}

void notify()
{
	//call update fn
	for (int i=0 ; i <= MAXFUNCTIONS ; i++){
		(*functionsptr[i])(data);
	}

}


