#include "DIO_Cfg.h"
#include "stm32f4xx.h"
#include <stdint.h>


#define NUM_OF_PORTS ((unsigned char)4)
#define WriteChannelArraySize ((unsigned char)3)
#define ReadChannelArraySize ((unsigned char)3)



GPIO_TypeDef * Ports[NUM_OF_PORTS] =
{GPIOA,
 GPIOB,
 GPIOC,
 GPIOD};


void DIO_Init(void)
 {
     unsigned char Loop;

     for(Loop = (unsigned char)0; Loop < DIO_NUM_OF_CHANNELS; Loop++)
     {
         unsigned char PortId;
         /*read the port Id from link time configuration*/
         PortId = DIO_ConfigParam[Loop].PortId;

         /*verify Port Id*/
         if(PortId < NUM_OF_PORTS)
         {
        	 /*Enable clock*/
        	 RCC->AHB1ENR |= (1<<PortId);
        	 GPIO_TypeDef * GPIOx =Ports[PortId];
        	 unsigned char PinNumber = DIO_ConfigParam[Loop].PinNum;
             /*this  bit always = 0 in input or output mode */
        	 GPIOx->MODER &= ~(1<<(PinNumber*2+1));

        	 /*if output*/
             if(DIO_ConfigParam[Loop].PortDirection)
             {
            	 /*if output type open drain*/
            	 GPIOx->MODER |= (1<<(PinNumber*2));
            	 if(DIO_ConfigParam[Loop].OutputType)
            	 {
            		 GPIOx->OTYPER |= (1<<(PinNumber));
            	 }
            	 /*if output type push-pull*/
            	 else
            	 {
            		 GPIOx->OTYPER &= ~(1<<(PinNumber));
            	 }

             }
             /*if input*/
             else
             {
            	 GPIOx->MODER &= ~(1<<(PinNumber*2));
            	 /*pull up */
            	 if(DIO_ConfigParam[Loop].PuPd == 1u)
            	 {
            		 GPIOx->PUPDR |= (1<<(PinNumber*2));
            		 GPIOx->PUPDR &= ~(1<<(PinNumber*2+1));
            	 }
            	 /*pull down */
            	 else if(DIO_ConfigParam[Loop].PuPd == 2u)
				 {
            		 GPIOx->PUPDR |= (1<<(PinNumber*2+1));
            		 GPIOx->PUPDR &= ~(1<<(PinNumber*2));
				 }
            	 /* No pull-up, pull-down */
            	 else
            	 {
            		 GPIOx->PUPDR &= ~(1<<(PinNumber*2));
            		 GPIOx->PUPDR &= ~(1<<(PinNumber*2+1));

            	 }
             }

         }
         else
         {
             /*invalid port*/
             break;
         }
     }
 }


void DIO_ChannelWrite(unsigned char ChannelId, unsigned char Data)
{
   /*Add your code*/
	if (ChannelId<DIO_NUM_OF_CHANNELS)
	{
		unsigned char PortId;
		PortId = DIO_ConfigParam[ChannelId].PortId;
		if(DIO_ConfigParam[ChannelId].PortDirection)
		{
			GPIO_TypeDef * GPIOx =Ports[PortId];
			GPIOx->ODR|=(1<<(DIO_ConfigParam[ChannelId].PinNum));
		}
		else
		{
			GPIO_TypeDef * GPIOx =Ports[PortId];
			GPIOx->ODR &= ~(1<<(DIO_ConfigParam[ChannelId].PinNum));
		}

	}
}
void DIO_ChannelWrite_Group(unsigned char ChannelsID[WriteChannelArraySize], unsigned char Data[WriteChannelArraySize])
{

  for(unsigned char i=0 ; i < WriteChannelArraySize ; i++)
	{
	  if(ChannelsID[i]<DIO_NUM_OF_CHANNELS){
		   unsigned char PortId;
		   PortId = DIO_ConfigParam[ChannelsID[i]].PortId;
		   if(DIO_ConfigParam[ChannelsID[i]].PortDirection)
		   {
			   GPIO_TypeDef * GPIOx =Ports[PortId];
			   if(Data[i]){
				   GPIOx->ODR|=(1<<(DIO_ConfigParam[ChannelsID[i]].PinNum));
			   }

		       else
		       {
			     GPIOx->ODR &= ~(1<<(DIO_ConfigParam[ChannelsID[i]].PinNum));
		       }
		   }
	  }

	}
}


void DIO_ChannelRead(unsigned char ChannelId, unsigned char *DataPtr)
{
	/*Add your code*/
	if (ChannelId<DIO_NUM_OF_CHANNELS)
		{
			unsigned char PortId;
			PortId = DIO_ConfigParam[ChannelId].PortId;
			if(!DIO_ConfigParam[ChannelId].PortDirection)
			{
				GPIO_TypeDef * GPIOx =Ports[PortId];
				*DataPtr = ((1<<(DIO_ConfigParam[ChannelId].PinNum))&GPIOx->IDR)?1:0;
			}

		}

}

unsigned int * DIO_ChannelRead_Group(unsigned char ReadChannelsId[ReadChannelArraySize], unsigned char ReturnedData[ReadChannelArraySize])
{
	  for(int i=0 ; i < ReadChannelArraySize ; i++)
		{
		  if(ReadChannelsId[i]<DIO_NUM_OF_CHANNELS){
			  unsigned char PortId;
			  PortId = DIO_ConfigParam[ReadChannelsId[i]].PortId;
			  if(!DIO_ConfigParam[ReadChannelsId[i]].PortDirection)
			  {
				  GPIO_TypeDef * GPIOx =Ports[PortId];
				  ReturnedData[i] = ((1<<(DIO_ConfigParam[ReadChannelsId[i]].PinNum))&GPIOx->IDR)?1:0;
			  }

		  }

    }
	  return ReturnedData;
}


