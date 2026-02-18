#ifndef _GPIO_HPP_
#define _GPIO_HPP_

//# Librarys import
#include <stdint.h>
#include <GpioChannels.hpp>

/*
[=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═]
 ╔═════════╗  ╔═╗      ╔═╗  ╔═════════╗  ╔═════════╗  ╔═╗      ╔═╗  ╔═╗     ╔═╗
 ██████████╝  ██║      ██║  ██████████║  ██████████║  ██║      ██║  ██╚═╗   ██║
 ██║          ██║      ██║  ██╚═════██║  ██╚═════██║  ██║      ██║  ████╚═████║
 ██║          ██║      ██║  ██████████╝  ██████████╝  ██║      ██║  ██║ ██  ██║
 ██╚═══════╗  ██╚══════██║  ██║          ██║   ██╚═╗  ██╚══════██║  ██║     ██║
 ██████████╝  ███████████╝  ██╝          ██╝     ██╝  ███████████╝  ██╝     ██╝

[=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═]

 File created: 02.11.2025
 Author: _Salch_
*/

namespace Gpio { 
  enum {
    //# Operating modes
	INPUT = 0x00,
    OUTPUT = 0x01,
	ALERNATIVE_FUNCTIONAL = 0x02,

	//# Clocking state
	CLOCK_ENABLE =  0x5F,
	CLOCK_DISABLE = 0x3B,

	//# Pin pull
	PULL_UP	= 0x01,
	NO_PULL	= 0x03,
	PULL_DOWN = 0x02,

	//# Output gpio speed
	LOW_SPEED = 0x00,
	FAST_SPEED = 0x02,
	HIGH_SPEED = 0x03,
	MEDIUM_SPEED = 0x01,
    
	// Output type
	PUSH_PULL  = 0x00,   // Push-pull output
    OPEN_DRAIN = 0x01,   // Open-drain output

	//# Output state
	HIGH = 0x10,
	LOW  = 0x00,

	//# Port identifiers (bit masks for clock enable)
	GPIOA = 0x01,
	GPIOB = 0x02,
	GPIOC = 0x03
  };

  void setMode(GpioStruct *gpio, uint8_t mode);
  void setPull(GpioStruct *gpio, uint8_t pull);
  void setClocking(uint8_t port, uint8_t state);
  void setSpeed(GpioStruct *gpio, uint8_t speed);
  void setOutput(GpioStruct *gpio, uint8_t state);				// Output state (for mode OUTPUT)
  void setOutputType(GpioStruct *gpio, uint8_t type);
  void setAlternativeFunction(GpioStruct *gpio, uint32_t mask);
}

#endif /* _GPIO_HPP_ */