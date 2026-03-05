#ifndef _CLOCKING_SYSTEM_H_
#define _CLOCKING_SYSTEM_H_

//# Subsystem import
#include <SysTick.hpp>

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
  enum {
    // Masks
    SOURCE_MSK = 0x10001,
    PLL_ON_MSK = 0x01 << 24,

    // Clocking sources
    INNER_SOURCE = 0x01,
    EXTERNAL_QUARTZ = 0x10000,

    // System mux channels
    PLL = 0x02,
    INNER = 0x00,
    EXTERNAL = 0x01,
  };

  extern uint8_t sourceFrequency;

  // Entry
  void startup();
  void configuration();

  // System
  void setSystemMux(uint8_t channel);
  void setSourceClocking(uint32_t source, uint8_t frequency);

  // PLL
  void setupPLL(uint8_t inputDivider, uint8_t multiplier, uint8_t outputDivider, uint8_t source);
}

#endif //_CLOCKING_SYSTEM_