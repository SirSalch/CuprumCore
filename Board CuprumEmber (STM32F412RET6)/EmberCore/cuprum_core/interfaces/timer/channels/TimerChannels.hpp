#ifndef _TIMER_CHANNELS_HPP_
#define _TIMER_CHANNELS_HPP_

//# Libraries import 
#include <stdint.h>
#include <Registers.hpp>

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
Author: _Salch_
*/

//# Timer struct
typedef struct {
  uint32_t rccMask;			    // Clocking mask
  uint32_t afrMask;			    // Mask AFR(L/H)
  volatile uint32_t* rcc;	  // Rcc register
  volatile uint32_t* psc;	  // Prescaler register
  volatile uint32_t* arr;	  // Auto-reset register
  volatile uint32_t* ccmr1;	// Capture Compare Mode Register 1
  volatile uint32_t* ccmr2;	// Capture Compare Mode Register 2
  volatile uint32_t* ccer;	// Capture Compare Enable Register
  volatile uint32_t* ccr1;	// Capture Compare Register 1
  volatile uint32_t* ccr2;  // Capture Compare Register 2
  volatile uint32_t* ccr3;  // Capture Compare Register 3
  volatile uint32_t* ccr4;	// Capture Compare Register 4
  volatile uint32_t* cr1;	  // Main control register
} TimerStruct;

//# Timers
extern TimerStruct TIMER2;

#endif //_TIMER_CHANNELS_H_