#ifndef _GPIO_CHANNELS_HPP_
#define _GPIO_CHANNELS_HPP_

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

enum Port{
  GPIOA = 0x01,
  GPIOB = 0x02,
  GPIOC = 0x03
};

//# Gpio channel struct
typedef struct {
  uint8_t number;             // Pin number
  uint8_t port;               // Port
  volatile uint32_t* odr;     // Channel state
  volatile uint32_t* moder;   // Mode
  volatile uint32_t* otyper;  // Output type
  volatile uint32_t* afrh;    // High alternative functions register
  volatile uint32_t* afrl;    // Low alternative functions register
  volatile uint32_t* pupdr;   // Pull register
  volatile uint32_t* speed;   // Output speed
} GpioStruct;

//# Gpio channels
extern GpioStruct PA0;
extern GpioStruct PA1;
extern GpioStruct PA2;
extern GpioStruct PA3;
extern GpioStruct PA5;

extern GpioStruct PB2;
extern GpioStruct PB6;
extern GpioStruct PB7;

#endif /* _GPIO_CHANNELS_HPP_ */