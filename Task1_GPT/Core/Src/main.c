
#include "GPIO.h"
#include "TIMER.h"
#include "NIVC.h"
#include "main.h"
unsigned char Led_toggle = 0;

int main(void) {

NVIC((unsigned int)28);  /*TIM2 */

GPIO_EnableClock((unsigned char)0);	/* Port A */
GPIO_Init((unsigned char)0,(unsigned char)0,OUTPUT,PUSH_PULL); /* Pin 0 config */

TIM_Init((unsigned char)2,UP_COUNT,1000,16000); /*INIT TIM2 */
TIM_Start((unsigned char)2);	/*Interrupt Enable */

  while (1) {


	  }

}

void TIM2_IRQHandler(void){

	if (TIMx_CR1((unsigned char)2) & ((unsigned char)0x01 << (unsigned char)0)){

		Led_toggle = ~Led_toggle;
		GPIO_WritePin((unsigned char)0,(unsigned char)0,Led_toggle);

	}

	TIMx_SR((unsigned char)2) &= ~((unsigned char)0x01 << (unsigned char)0);
}
