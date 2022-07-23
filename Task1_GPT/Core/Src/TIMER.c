#include<TIMER.h>
#include<GPIO.h>



void TIM_Init(unsigned char id,unsigned char counterMode,unsigned long prescaler,unsigned long ARR_value){

	*RCC_APB1ENR |= ((unsigned int)0x01 << (unsigned int)(id -2));  /*Enable Timer clock*/

	TIMx_PSC(id) = prescaler - 1;	    /*prescale value */

	TIMx_ARR(id) = ARR_value;	       /*ARR value*/

	TIMx_CR1(id) |= ((unsigned int)0x01 << (unsigned int)0);         /*Enable counter*/

	TIMx_CR1(id) &= ~((unsigned int)0x02 << (unsigned int)5);		/*Counts up or down*/

	TIMx_CR1(id) |= ((unsigned int)counterMode << (unsigned int)4); /*Direction of counting*/

	while ( !((unsigned int)TIMx_SR(id)) & ((unsigned int)0x01 << (unsigned int)0)) ; /*waiting interrupt Flag to be set*/

	TIMx_SR(id) &= ~((unsigned int)0x01 <<(unsigned int) 0);      /*Reset flag*/
}




void TIM_Start(unsigned char id){

	TIMx_DIER(id) |= ((unsigned int)0x01 << (unsigned int)0);		/*Update interrupt enable*/

}


void TIM_Stop(unsigned char id){

	TIMx_DIER(id) &= ~((unsigned int)0x01 <<(unsigned int) 0);		/*Update interrupt disable*/

}
