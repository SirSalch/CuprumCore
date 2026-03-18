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

// Gpio port
struct GpioPort{
  uint8_t RccMask;            // Clocking enable mask
  volatile uint32_t* ODR;     // Channel state
  volatile uint32_t* IDR;     // Channel input state
  volatile uint32_t* MODER;   // Mode
  volatile uint32_t* OTYPER;  // Output type
  volatile uint32_t* AFRH;    // High alternative functions register
  volatile uint32_t* AFRL;    // Low alternative functions register
  volatile uint32_t* PUPDR;   // Pull register
  volatile uint32_t* SPEED;   // Output speed
};
extern const GpioPort GpioA;
extern const GpioPort GpioB;
extern const GpioPort GpioC;


// Gpio Pin
struct GpioPin {
  uint8_t number;
  const GpioPort* port;
};
// Pin A
extern const GpioPin PA0;
extern const GpioPin PA1;
extern const GpioPin PA2;
extern const GpioPin PA3;
extern const GpioPin PA5;
extern const GpioPin PA9;
extern const GpioPin PA10;
// Pin B
extern const GpioPin PB2;
extern const GpioPin PB6;
extern const GpioPin PB7;

#endif /* _GPIO_CHANNELS_HPP_ */