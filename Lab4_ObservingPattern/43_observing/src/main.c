#include "stm32f4xx.h"
#include "PollerTimer.h"
#include "poller.h"
#include "GPIO.h"
#include "device.h"
#include "PollDataClient.h"



int main(void)
{
	GPIO_EnableClock(0);                  /*Enable port A clock*/
	GPIO_Init(0, 0, INPUT, PULL_UP);    /*configuration for pin 0(BUTTON)*/
    GPIO_Init(0, 1,OUTPUT,PUSH_PULL);  	  /*configuration for pin 1(LED)*/
    init_Client();
	StartTimer();
	EnableInterrupt();
	SetPollingTime(500);
	StartPolling();


	while(1)
	{

	}

}

void TIM2_IRQHandler(void)
{
	TIM2->SR &=~(1<<0);
	CallPollingFunction();
}



