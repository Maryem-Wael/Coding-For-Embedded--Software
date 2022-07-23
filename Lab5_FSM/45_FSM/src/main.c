#include "stm32f4xx.h"
#include "PollerTimer.h"
#include "poller.h"
#include "i2c.h"
#include "ds1307.h"


int main(void)
{
	StartTimer();
	EnableInterrupt();
	SetPollingTime(500);
	StartPolling();
	// Initialize I2C1
	I2C1_INIt();

	while(1)
	{
		//call Time_ReadData function
		//void Time_ReadData(char memoryAddress,char data[],int n)
	}

}

void TIM2_IRQHandler(void)
{
	TIM2->SR &=~(1<<0);
	CallPollingFunction();
}


