#ifndef _CUPRUM_CORE_H_
#define _CUPRUM_CORE_H_

//# Header import
#include <Registers.hpp>
#include <SysTick.hpp>
#include <Gpio.hpp>
#include <GpioChannels.hpp>
#include <Timer.hpp>
#include <TimerChannels.hpp>
#include <I2c.hpp>
#include <I2cChannels.hpp>

extern unsigned int _originInitdata;
extern unsigned int _originData;
extern unsigned int _endData;
extern unsigned int _originBss;
extern unsigned int _endBss;

extern void *_stackOrigin;
extern int main();

/*
[=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═]
  ╔═════════╗  ╔═╗      ╔═╗  ╔═════════╗  ╔═════════╗  ╔═╗      ╔═╗  ╔═╗     ╔═╗        ╔═════════╗  ╔═════════╗  ╔═════════╗  ╔═════════╗
  ██████████╝  ██║      ██║  ██████████║  ██████████║  ██║      ██║  ██╚═╗   ██║        ██████████╝  ██████████║  ██████████║  ██████████╝
  ██║          ██║      ██║  ██╚═════██║  ██╚═════██║  ██║      ██║  ████╚═████║        ██║          ██║     ██║  ██╚═════██║  ██╚═══════╗
  ██║          ██║      ██║  ██████████╝  ██████████╝  ██║      ██║  ██║ ██  ██║        ██║          ██║     ██║  ██████████╝  ██████████╝
  ██╚═══════╗  ██╚══════██║  ██║          ██║   ██╚═╗  ██╚══════██║  ██║     ██║        ██╚═══════╗  ██╚═════██║  ██║   ██╚═╗  ██╚═══════╗
  ██████████╝  ███████████╝  ██╝          ██╝     ██╝  ███████████╝  ██╝     ██╝        ██████████╝  ██████████╝  ██╝     ██╝  ██████████╝

[=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═]

File created: 09.02.2026
Author: _Salch_
*/

//# Functions for the compiler
extern "C" {
  void resetHandler(void);
}

//=═=═=═=═=═=═=═=═=═=═=<< The Core >>═=═=═=═=═=═=═=═=═=═=
namespace Core {
  void startUp();

  //# Settings
  void setSourceClocking();

  //# Proprietary functions
  void __initMemory();
  void __initClcokingSystem();
}
//<<=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═>>

//# Standart system funtions
void delay(uint32_t time);		                        // System waiting in milliseconds
uint8_t readBit(volatile uint32_t *reg, uint8_t mask);   // Read bit from the register

#endif //_CUPRUM_CORE_H_