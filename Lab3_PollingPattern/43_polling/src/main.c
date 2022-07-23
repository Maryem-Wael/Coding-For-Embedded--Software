#include "stm32f4xx.h"
#include "PollerTimer.h"
#include "poller.h"



int main(void)
{
	/*initialize pin6 portA as output*/
	RCC->AHB1ENR |=(1<<0);

	GPIOA->MODER |=(1<<10);
	GPIOA->MODER &=~(1<<11);


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


