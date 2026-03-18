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

bool Gpio::getInput(const GpioPin *gpio) {
  return (bool)(*gpio->port->IDR & (0x01 << gpio->number));
}

void Gpio::setMode(const GpioPin *gpio, uint8_t mode) {
  *gpio->port->MODER &= ~(0x3 << (gpio->number * 2)); // Clearing the bits of the current mode
  if(mode != 0x00/*INPUT*/) {
    *gpio->port->MODER |= mode << (gpio->number * 2); // Set the OUTPUT mode
  }
}

void Gpio::setPull(const GpioPin *gpio, uint8_t pull){
  *gpio->port->PUPDR &= ~(0x3 << (gpio->number * 2));  				// Clear current pull
  if(pull != NO_PULL) return;
  *gpio->port->PUPDR |= (pull << (gpio->number * 2));					// Set pull
}

void Gpio::setClocking(const GpioPort *port, uint8_t state) {
  RCC_AHB1ENR &= ~port->RccMask;
  if(state == CLOCK_ENABLE) RCC_AHB1ENR |= port->RccMask;
}

void Gpio::setSpeed(const GpioPin *gpio, uint8_t speed) {
  *gpio->port->SPEED |= speed;
}

void Gpio::setOutput(const GpioPin *gpio, uint8_t state) {
  *gpio->port->ODR &= ~(1 << gpio->number);
  if(state == 0x03 /* HIGH */) *gpio->port->ODR |=  (1 << gpio->number);
}

void Gpio::setOutputType(const GpioPin *gpio, uint8_t type) {
  *gpio->port->OTYPER &= ~type << gpio->number;	  // Clearing the bits of the current mode
  *gpio->port->OTYPER |=  type << gpio->number;	  // Set output type
}

void Gpio::setAlternativeFunction(const GpioPin *gpio, uint32_t mask) {
  uint32_t shift = (gpio->number % 8) * 4;
  
  if (gpio->number < 8) {
    *gpio->port->AFRL &= ~(0xF << shift);
    *gpio->port->AFRL |= (mask << shift);
  } else {
    *gpio->port->AFRH &= ~(0xF << shift); 
    *gpio->port->AFRH |= (mask << shift);
  }
}

#endif /* _GPIO_CPP_ */