#ifndef _TIMER_CHANNELS_CPP_
#define _TIMER_CHANNELS_CPP_

//# Header import
#include <Timer.hpp>

/*
[=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═]
 ╔═════════╗  ╔═╗      ╔═╗  ╔═════════╗  ╔═════════╗  ╔═╗      ╔═╗  ╔═╗     ╔═╗
 ██████████╝  ██║      ██║  ██████████║  ██████████║  ██║      ██║  ██╚═╗   ██║
 ██║          ██║      ██║  ██╚═════██║  ██╚═════██║  ██║      ██║  ████╚═████║
 ██║          ██║      ██║  ██████████╝  ██████████╝  ██║      ██║  ██║ ██  ██║
 ██╚═══════╗  ██╚══════██║  ██║          ██║   ██╚═╗  ██╚══════██║  ██║     ██║
 ██████████╝  ███████████╝  ██╝          ██╝     ██╝  ███████████╝  ██╝     ██╝

[=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═]

File created: 13.01.2026
Author:  _Salch_
*/

TimerStruct TIMER2 = {
  .rccMask = 0x01,
  .afrMask = 0x01,
  .rcc = &RCC_APB1ENR,
  .psc = &TIMER2_PSC,
  .arr = &TIMER2_ARR,
  .ccmr1 = &TIMER2_CCMR1,
  .ccmr2 = &TIMER2_CCMR2,
  .ccer = &TIMER2_CCER,
  .ccr1 = &TIMER2_CCR1,
  .ccr2 = &TIMER2_CCR2,
  .ccr3 = &TIMER2_CCR3,
  .ccr4 = &TIMER2_CCR4,
  .cr1 = &TIMER2_CR1,
};

#endif /* _TIMER_CHANNELS_CPP_ */