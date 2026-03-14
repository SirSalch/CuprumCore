#ifndef _CUPRUM_CORE_H_
#define _CUPRUM_CORE_H_

//# Systems import
#include <Registers.hpp>
#include <ClockingSystem.hpp>
#include <MemorySystem.hpp>
#include <SysTick.hpp>

//# Drivres import
#include <Gpio.hpp>
#include <GpioChannels.hpp>
#include <Timer.hpp>
#include <TimerChannels.hpp>
#include <I2c.hpp>
#include <I2cChannels.hpp>
#include <Uart.hpp>
#include <UartChannels.hpp>

extern int main();

/*
[=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=]
  ╔═════════╗  ╔═════════╗  ╔═════════╗  ╔═════════╗
  ██████████╝  ██████████║  ██████████║  ██████████╝
  ██║          ██║     ██║  ██╚═════██║  ██╚═══════╗
  ██║          ██║     ██║  ██████████╝  ██████████╝
  ██╚═══════╗  ██╚═════██║  ██║   ██╚═╗  ██╚═══════╗
  ██████████╝  ██████████╝  ██╝     ██╝  ██████████╝

[=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=]

File created: 09.02.2026
Author: _Salch_
*/

//# Functions for the compiler
extern "C" {
  void resetHandler(void);
}

namespace Core {
  void deploy();
}

//# Standart system funtions
void delay(uint32_t time);		                        // System waiting in milliseconds
uint8_t readBit(volatile uint32_t *reg, uint8_t mask);   // Read bit from the register

#endif //_CUPRUM_CORE_H_