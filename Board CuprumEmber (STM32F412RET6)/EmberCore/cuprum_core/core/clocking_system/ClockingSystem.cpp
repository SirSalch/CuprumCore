//# Header import
#include <ClockingSystem.hpp>

/*
[=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=]
  ╔═════════╗  ╔═════════╗  ╔═════════╗  ╔═════════╗
  ██████████╝  ██████████║  ██████████║  ██████████╝
  ██║          ██║     ██║  ██╚═════██║  ██╚═══════╗
  ██║          ██║     ██║  ██████████╝  ██████████╝
  ██╚═══════╗  ██╚═════██║  ██║   ██╚═╗  ██╚═══════╗
  ██████████╝  ██████████╝  ██╝     ██╝  ██████████╝

[=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=]

File created: 01.03.2026
Author:  _Salch_
*/

namespace ClockingSystem {
  uint8_t sourceFrequency;

  void startup() {
    configuration();
    SysTick::setLoad(0xFFFFFF);
    SysTick::setClockingSource(SysTick::PROCESSOR_CLOCKING_SOURCE);
    SysTick::enable();
  }

  // System
  void setSystemMux(uint8_t channel) {
    RCC_CFGR &= ~0x03;
    RCC_CFGR |= channel;
  }
  void setSourceClocking(uint32_t source, uint8_t frequency) {
    sourceFrequency = frequency;
    RCC_CR &= ~SOURCE_MSK;
    RCC_CR |= source;
  }

  // PLL
  void setupPLL(uint8_t inputDivider, uint8_t multiplier, uint8_t outputDivider, uint8_t source) {
    RCC_CR &= ~PLL_ON_MSK;  // Disable PLL
    sourceFrequency = sourceFrequency / inputDivider * multiplier / outputDivider;
    RCC_PLLCFGR = (inputDivider) | (multiplier << 6) | ((outputDivider / 2 - 1) << 16) | (source << 22);
    RCC_CR |= PLL_ON_MSK;   // Enable PLL
  }
}
