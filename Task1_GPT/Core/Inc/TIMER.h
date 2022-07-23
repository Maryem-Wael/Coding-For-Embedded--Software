
#ifndef TIMER_H_
#define TIMER_H_


void TIM_Init(unsigned char id,unsigned char counterMode,unsigned long prescaler,unsigned long ARR_value);
void TIM_Start(unsigned char id);
void TIM_Stop(unsigned char id);
void TIMER_IRQHandler (void);

#define UP_COUNT (0)
#define DOWN_COUNT (1)

/*MACRO FOR TIMER REGISTER */
#define TIMER_REG(TIMER_ID,REG_ID) 		 (*((unsigned int*)((TIMER_ID) + (REG_ID))))

#define TIMx_CR1(id)   (TIMER_REG(0x40000000 + 0x400 * (id - 2), 0x00))
#define TIMx_CR2(id)   (TIMER_REG(0x40000000 + 0x400 * (id - 2), 0x04))
#define TIMx_SMCR(id)  (TIMER_REG(0x40000000 + 0x400 * (id - 2), 0x08))
#define TIMx_DIER(id)  (TIMER_REG(0x40000000 + 0x400 * (id - 2), 0x0C))
#define TIMx_SR(id)    (TIMER_REG(0x40000000 + 0x400 * (id - 2), 0x10))
#define TIMx_EGR(id)   (TIMER_REG(0x40000000 + 0x400 * (id - 2), 0x14))
#define TIMx_CCMR1(id) (TIMER_REG(0x40000000 + 0x400 * (id - 2), 0x18))
#define TIMx_CCMR2(id) (TIMER_REG(0x40000000 + 0x400 * (id - 2), 0x1c))
#define TIMx_CCER(id)  (TIMER_REG(0x40000000 + 0x400 * (id - 2), 0x20))
#define TIMx_CNT(id)   (TIMER_REG(0x40000000 + 0x400 * (id - 2), 0x24))
#define TIMx_PSC(id)   (TIMER_REG(0x40000000 + 0x400 * (id - 2), 0x28))
#define TIMx_ARR(id)   (TIMER_REG(0x40000000 + 0x400 * (id - 2), 0x2C))


#endif /* INC_GPTIM_H_ */
