#ifndef _GPIO_CPP_
#define _GPIO_CPP_

//# Header import
#include <Gpio.hpp>

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

void Gpio::setMode(GpioStruct *gpio, uint8_t mode) {
  *gpio->moder &= ~(0x3 << (gpio->number * 2));   // Clearing the bits of the current mode

  switch(mode){
    case Gpio::OUTPUT:
      *gpio->moder |= mode << (gpio->number * 2); // Set the OUTPUT mode
      break;
    case Gpio::ALERNATIVE_FUNCTIONAL:
	  *gpio->moder |= mode << (gpio->number * 2);   // Set the Alternative functional mode
  }
}

void Gpio::setPull(GpioStruct *gpio, uint8_t pull){
  *gpio->pupdr &= ~(0x3 << (gpio->number * 2));  				// Clear current pull
  if(pull != Gpio::PULL_UP || pull != Gpio::PULL_DOWN) return;
  *gpio->pupdr |= (pull << (gpio->number * 2));					// Set pull
}

void Gpio::setClocking(uint8_t port, uint8_t state) {
  if(state == CLOCK_ENABLE) RCC_AHB1ENR |= port;
  else if(state == CLOCK_DISABLE) RCC_AHB1ENR &= ~port;
}

void Gpio::setSpeed(GpioStruct *gpio, uint8_t speed) {
  *gpio->speed |= speed;
}

void Gpio::setOutput(GpioStruct *gpio, uint8_t state) {
  if(state == HIGH) *gpio->odr |=  (1 << gpio->number);
  else if(state == LOW) *gpio->odr &= ~(1 << gpio->number);
}

void Gpio::setOutputType(GpioStruct *gpio, uint8_t type) {
  *gpio->otyper &= ~type << gpio->number;	  // Clearing the bits of the current mode
  *gpio->otyper |=  type << gpio->number;	  // Set output type
}

void Gpio::setAlternativeFunction(GpioStruct *gpio, uint32_t mask) {
  uint32_t shift = (gpio->number % 8) * 4;  // 4 bits per pin in AFR registers
  *gpio->afrl &= ~(0xF << shift);           // Clear previous AF
  
  if (gpio->number < 8) {
    *gpio->afrl |= (mask << shift);         // Set new AF
  } else {
    *gpio->afrh |= (mask << shift);
  }
}

#endif /* _GPIO_CPP_ */