#ifndef _SYS_TICK_CPP_
#define _SYS_TICK_CPP_

// Header import
#include <SysTick.hpp>

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
  // Reset counter and its parameters
  void reset() {
    SYST_CVR = 0;   // Any write clears the counter and COUNTFLAG
  }

  // Enable counter operation
  void enable() {
    SYST_CTRL |= BIT_ENABLE;
  }

  // Disable counter operation
  void disable() {
    SYST_CTRL &= ~BIT_ENABLE;
  }

  uint32_t getTick() {
    return 0xFFFFFF - SYST_CVR;
  }

  void enableInterrupt() {
    SYST_CTRL |= TICKINT_BIT;
  }

  void disableInterrupt() {
    SYST_CTRL &= ~TICKINT_BIT;
  }

  // Get count completion flag status
  uint32_t getCountFlag() {
    return SYST_CTRL & BIT_COUNT_FLAG;
  }

  // Set reload value (maximum count)
  void setLoad(uint32_t load) {
    SYST_RVR = load;
  }

  // Set clock source
  void setClockingSource(uint32_t source) {
    if (source == AHB_CLOCKING_SOURCE) SYST_CTRL &= ~BIT_CLOCKING_SOURCE;
    else if (source == PROCESSOR_CLOCKING_SOURCE) SYST_CTRL |= BIT_CLOCKING_SOURCE;
  }
}

#endif /* _SYS_TICK_CPP_ */