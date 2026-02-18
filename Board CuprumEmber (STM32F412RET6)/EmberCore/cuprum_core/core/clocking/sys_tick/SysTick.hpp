#ifndef _SYS_TICK_HPP_
#define _SYS_TICK_HPP_

//# Core import
#include <CuprumCore.hpp>

/*
[=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═]
 ╔═════════╗  ╔═╗      ╔═╗  ╔═════════╗  ╔═════════╗  ╔═╗      ╔═╗  ╔═╗     ╔═╗
 ██████████╝  ██║      ██║  ██████████║  ██████████║  ██║      ██║  ██╚═╗   ██║
 ██║          ██║      ██║  ██╚═════██║  ██╚═════██║  ██║      ██║  ████╚═████║
 ██║          ██║      ██║  ██████████╝  ██████████╝  ██║      ██║  ██║ ██  ██║
 ██╚═══════╗  ██╚══════██║  ██║          ██║   ██╚═╗  ██╚══════██║  ██║     ██║
 ██████████╝  ███████████╝  ██╝          ██╝     ██╝  ███████████╝  ██╝     ██╝

[=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═]

File created: 17.02.2026
Author: _Salch_
*/

namespace SysTick {
  enum {
    // Bit masks
    BIT_ENABLE          = 0x01,      // Enable counter bit
    BIT_COUNT_FLAG      = 0x10000,   // Count complete flag bit
    BIT_CLOCKING_SOURCE = 0x04,      // Clock source selection bit

    // Count flag states
    COUNT_FLAG_READY    = 0x01,
    COUNT_FLAG_NOTREADY = 0x00,

    // Clock sources
    AHB_CLOCKING_SOURCE         = 0x03,   // AHB clock (typically 1/8 of processor clock)
    PROCESSOR_CLOCKING_SOURCE   = 0x04    // Processor clock (core clock)
  };

  void reset();                             // Reset counter and its parameters
  void enable();                            // Enable counter operation
  void disable();                           // Disable counter operation
  uint32_t getCountFlag();                  // Get count completion flag status
  void setLoad(uint32_t load);              // Set reload value (maximum count)
  void setClockingSource(uint32_t source);  // Set clock source
}

#endif /* _SYS_TICK_HPP_ */