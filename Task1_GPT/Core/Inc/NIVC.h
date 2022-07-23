
#ifndef INC_NVIC_H_
#define INC_NVIC_H_

#define NVIC_REG(PORT_ID , REG_ID)  (*((unsigned int*)((PORT_ID) + (REG_ID))))

#define NVIC_ISER0 (NVIC_REG(0xE000E100, 0))
#define NVIC_ISER1 (NVIC_REG(0xE000E100, 0x04))
#define NVIC_ISER2 (NVIC_REG(0xE000E100, 0x08))


void NVIC(unsigned int position);

#endif /* INC_NVIC_H_ */
