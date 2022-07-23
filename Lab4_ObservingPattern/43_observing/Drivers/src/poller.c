
#include <PollDataClient.h>
#include "poller.h"
#include "device.h"
#include "main.h"

int polling_enabled= 1;
int polling_counter= 1;
int counter = 0 ;

void Poll_getter(void)
{
	Get_Data();
}

void Poll_setter(void)
{

	if(polling_enabled && (!counter))
	{
		notify();
	}
	counter++;
	counter = counter%polling_counter;
}

void StartPolling(void)
{
	polling_enabled=1;
}

void StopPolling(void)
{
	polling_enabled=0;
}

void SetPollingTime(int polling_time)
{
	polling_counter = polling_time/100;
}


