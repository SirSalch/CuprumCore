#ifndef _REGISTERS_HPP_
#define _REGISTERS_HPP_

// Library import
#include <cstdint>

/*
[=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═]
 ╔═════════╗  ╔═╗      ╔═╗  ╔═════════╗  ╔═════════╗  ╔═╗      ╔═╗  ╔═╗     ╔═╗
 ██████████╝  ██║      ██║  ██████████║  ██████████║  ██║      ██║  ██╚═╗   ██║
 ██║          ██║      ██║  ██╚═════██║  ██╚═════██║  ██║      ██║  ████╚═████║
 ██║          ██║      ██║  ██████████╝  ██████████╝  ██║      ██║  ██║ ██  ██║
 ██╚═══════╗  ██╚══════██║  ██║          ██║   ██╚═╗  ██╚══════██║  ██║     ██║
 ██████████╝  ███████████╝  ██╝          ██╝     ██╝  ███████████╝  ██╝     ██╝

[=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═]

File created: 6.02.2026
Author: _Salch_
*/

// SysTick
#define SYST_CTRL     (*(volatile uint32_t*)0xE000E010)
#define SYST_RVR      (*(volatile uint32_t*)0xE000E014)
#define SYST_CVR      (*(volatile uint32_t*)0xE000E018)

// Clocking system
#define RCC_CR        (*(volatile uint32_t*)0x40023800)
#define RCC_CFGR      (*(volatile uint32_t*)0x40023808)
#define RCC_PLLCFGR   (*(volatile uint32_t*)0x40023804)

// Bus clocking
#define RCC_AHB1ENR   (*(volatile uint32_t*)0x40023830)
#define RCC_APB1ENR   (*(volatile uint32_t*)0x40023840)
#define RCC_APB2ENR   (*(volatile uint32_t*)0x40023844)

// Gpio-A
#define GPIOA_MODER   (*(volatile uint32_t*)0x40020000)
#define GPIOA_OTYPER  (*(volatile uint32_t*)0x40020004)
#define GPIOA_ODR     (*(volatile uint32_t*)0x40020014)
#define GPIOA_IDR	  (*(volatile uint32_t*)0x40020010)
#define GPIOA_PUPDR   (*(volatile uint32_t*)0x4002000c)
#define GPIOA_AFRL    (*(volatile uint32_t*)0x40020020)
#define GPIOA_AFRH    (*(volatile uint32_t*)0x40020024)
#define GPIOA_OSPEEDR (*(volatile uint32_t*)0x40020008)

// Gpio-B
#define GPIOB_MODER   (*(volatile uint32_t*)0x40020400)
#define GPIOB_OTYPER  (*(volatile uint32_t*)0x40020404)
#define GPIOB_ODR     (*(volatile uint32_t*)0x40020414)
#define GPIOB_IDR	  (*(volatile uint32_t*)0x40020410)
#define GPIOB_PUPDR   (*(volatile uint32_t*)0x4002040c)
#define GPIOB_AFRL    (*(volatile uint32_t*)0x40020420)
#define GPIOB_AFRH    (*(volatile uint32_t*)0x40020424)
#define GPIOB_OSPEEDR (*(volatile uint32_t*)0x40020408)

// Gpio-C
#define GPIOC_MODER   (*(volatile uint32_t*)0x40020800)
#define GPIOC_OTYPER  (*(volatile uint32_t*)0x40020804)
#define GPIOC_ODR     (*(volatile uint32_t*)0x40020814)
#define GPIOC_IDR	  (*(volatile uint32_t*)0x40020810)
#define GPIOC_PUPDR   (*(volatile uint32_t*)0x4002080c)
#define GPIOC_AFRL    (*(volatile uint32_t*)0x40020820)
#define GPIOC_AFRH    (*(volatile uint32_t*)0x40020824)
#define GPIOC_OSPEEDR (*(volatile uint32_t*)0x40020808)

// Timer 2
#define TIMER2_PSC    (*(volatile uint32_t*)0x40000028)
#define TIMER2_ARR    (*(volatile uint32_t*)0x4000002c)
#define TIMER2_CCMR1  (*(volatile uint32_t*)0x40000018)
#define TIMER2_CCMR2  (*(volatile uint32_t*)0x4000001c)
#define TIMER2_CCER   (*(volatile uint32_t*)0x40000020)
#define TIMER2_CR1    (*(volatile uint32_t*)0x40000000)
#define TIMER2_CCR1   (*(volatile uint32_t*)0x40000034)
#define TIMER2_CCR2   (*(volatile uint32_t*)0x40000038)
#define TIMER2_CCR3   (*(volatile uint32_t*)0x4000003c)
#define TIMER2_CCR4   (*(volatile uint32_t*)0x40000040)

// Timer 3
#define TIMER2_PSC    (*(volatile uint32_t*)0x40000028)
#define TIMER2_ARR    (*(volatile uint32_t*)0x4000002c)
#define TIMER2_CCMR1  (*(volatile uint32_t*)0x40000018)
#define TIMER2_CCMR2  (*(volatile uint32_t*)0x4000001c)
#define TIMER2_CCER   (*(volatile uint32_t*)0x40000020)
#define TIMER2_CR1    (*(volatile uint32_t*)0x40000000)
#define TIMER2_CCR1   (*(volatile uint32_t*)0x40000034)
#define TIMER2_CCR2   (*(volatile uint32_t*)0x40000038)
#define TIMER2_CCR3   (*(volatile uint32_t*)0x4000003c)
#define TIMER2_CCR4   (*(volatile uint32_t*)0x40000040)

// I2C1
#define I2C1_CR1      (*(volatile uint32_t*)0x40005400)
#define I2C1_CR2      (*(volatile uint32_t*)0x40005404)
#define I2C1_OAR1     (*(volatile uint32_t*)0x40005408)
#define I2C1_OAR2     (*(volatile uint32_t*)0x4000540c)
#define I2C1_DR       (*(volatile uint32_t*)0x40005410)
#define I2C1_SR1      (*(volatile uint32_t*)0x40005414)
#define I2C1_SR2      (*(volatile uint32_t*)0x40005418)
#define I2C1_CCR      (*(volatile uint32_t*)0x4000541c)
#define I2C1_TRISE    (*(volatile uint32_t*)0x40005420)

// UART1
#define UART1_BRR     (*(volatile uint32_t*)0x40011008)
#define UART1_CR1     (*(volatile uint32_t*)0x4001100c)
#define UART1_CR2     (*(volatile uint32_t*)0x40011010)
#define UART1_CR3     (*(volatile uint32_t*)0x40011014)
#define UART1_DR      (*(volatile uint32_t*)0x40011004)
#define UART1_SR      (*(volatile uint32_t*)0x40011000)
#define UART1_GTPR    (*(volatile uint32_t*)0x40011018)

#endif /* _REGISTERS_HPP_ */