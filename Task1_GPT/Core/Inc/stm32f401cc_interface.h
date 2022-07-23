/*
 * Author : Abdullah Drwesh
 * Date   : 17/11/2021
 * Version: 1.0.0
 */
#ifndef STM32F401CC_INTERFACE_H
#define STM32F401CC_INTERFACE_H

#include "stm32f401xc.h"

#define RCC_CR             (RCC->CR)
#define RCC_PLLCFGR        (RCC->PLLCFGR)
#define RCC_CFGR           (RCC->RCC_CFGR)
#define RCC_CIR            (RCC->CIR)
#define RCC_AHB1RSTR       (RCC->AHB1RSTR)
#define RCC_AHB2RSTR       (RCC->AHB2RSTR)
#define RCC_APB1RSTR       (RCC->APB1RSTR)
#define RCC_APB2RSTR       (RCC->APB2RSTR)
#define RCC_AHB1ENR        (RCC->AHB1ENR)
#define RCC_AHB2ENR        (RCC->AHB2ENR)



#define GPIOC_MODER        (GPIOC->MODER)
#define GPIOC_OTYPER       (GPIOC->OTYPER)
#define GPIOC_OSPEEDR      (GPIOC->OSPEEDR)
#define GPIOC_PUPDR        (GPIOC->PUPDR)
#define GPIOC_IDR          (GPIOC->IDR)
#define GPIOC_ODR          (GPIOC->ODR)
#define GPIOC_BSRR         (GPIOC->BSRR)
#define GPIOC_LCKR         (GPIOC->LCKR)
#define GPIOC_AFRL         (GPIOC->AFRL)
#define GPIOC_AFRH         (GPIOC->AFRH)


#define GPIOD_MODER        (GPIOD->MODER)
#define GPIOD_OTYPER       (GPIOD->OTYPER)
#define GPIOD_OSPEEDR      (GPIOD->OSPEEDR)
#define GPIOD_PUPDR        (GPIOD->PUPDR)
#define GPIOD_IDR          (GPIOD->IDR)
#define GPIOD_ODR          (GPIOD->ODR)
#define GPIOD_BSRR         (GPIOD->BSRR)
#define GPIOD_LCKR         (GPIOD->LCKR)
#define GPIOD_AFRL         (GPIOD->AFRL)
#define GPIOD_AFRH         (GPIOD->AFRH)




#endif /* STM32F401CC_INTERFACE_H */
