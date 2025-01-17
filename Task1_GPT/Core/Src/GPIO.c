

#include "GPIO.h"




unsigned int *lookuptable[2][10]={{GPIOA_MODER,GPIOA_OTYPER,GPIOA_OSPEEDR ,GPIOA_PUPDR,GPIOA_IDR,GPIOA_ODR ,GPIOA_BSRR ,GPIOA_LCKR,GPIOA_AFRL,GPIOA_AFRH},
		                          {GPIOB_MODER,GPIOB_OTYPER,GPIOB_OSPEEDR ,GPIOB_PUPDR,GPIOB_IDR,GPIOB_ODR ,GPIOB_BSRR ,GPIOB_LCKR,GPIOB_BFRL, GPIOB_BFRH}};


void GPIO_EnableClock(unsigned char PORT_ID) {

	*RCC_AHB1ENR |= ((unsigned int)0x01 << (unsigned int)PORT_ID);


}

void GPIO_Init(unsigned char PORT_ID, unsigned char PinNum, unsigned char PinMode,
               unsigned char DefaultState) {

      *lookuptable[PORT_ID][0] &= ~((unsigned int)0x03 << (unsigned int)2 * PinNum);
      *lookuptable[PORT_ID][0] |= (unsigned int)PinMode << (unsigned int)2 * PinNum;

      *lookuptable[PORT_ID][1] &= ~((unsigned int)1 << (unsigned int)PinNum);
      *lookuptable[PORT_ID][1] |= ((unsigned int)(DefaultState & _OUTTYPE_MASK) >> (unsigned int)_OUTTYPE_SHIFT) << (unsigned int)PinNum;

      *lookuptable[PORT_ID][3] &= ~((unsigned int)0x03 << (unsigned int)2 * PinNum);
      *lookuptable[PORT_ID][3] |= ((unsigned int)(DefaultState & _PUPD_MASK) >> (unsigned int)_PUPD_SHIFT) << (unsigned int)(2 * PinNum);
}

unsigned char GPIO_WritePin(unsigned char PORT_ID, unsigned char PinNum,
                            unsigned char Data) {
  unsigned char result;
      if ((((unsigned int)*lookuptable[PORT_ID][0] & ((unsigned int)0x03 << (unsigned int)2 * PinNum)) >> ((unsigned int)2 * PinNum)) == (unsigned int)1) {
        if (Data) {
        	*lookuptable[PORT_ID][5] |= ((unsigned int)1 << (unsigned int)PinNum);
        } else {
        	*lookuptable[PORT_ID][5] &= ~((unsigned int)1 << (unsigned int)PinNum);
        }
        result = OK;
      } else {
        result = NOK;
      }

  return result;
}

unsigned char GPIO_ReadPin(unsigned char PORT_ID, unsigned char PinNum) {
  unsigned char read = 0;

      read = ((unsigned int)*lookuptable[PORT_ID][4] & ((unsigned int)1 << (unsigned int)PinNum)) >> (unsigned int)PinNum;

  return read;
}
