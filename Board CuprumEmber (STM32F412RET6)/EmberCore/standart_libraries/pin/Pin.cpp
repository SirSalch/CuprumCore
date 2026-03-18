#ifndef _PIN_CPP_
#define _PIN_CPP_

//# Header import
#include <Pin.hpp>

/*
[=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═]
 ╔═════════╗   ╔═════════╗   ╔═╗     ╔═╗
 ██████████║   ██████████╝   ██╚═╗   ██║
 ██╚═════██║       ██║       ████╚═╗ ██║
 ██████████╝       ██║       ██║ ██╚═██║
 ██║           ╔═══██╚═══╗   ██║   ████║
 ██╝           ██████████╝   ██╝     ██╝

[=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═]

File created: 10.02.2026
Author: _Salch_
*/

Pin::Pin(const GpioPin *initGpio, uint8_t mode) : _gpio(initGpio) {
  Gpio::setClocking(_gpio->port, Gpio::CLOCK_ENABLE);
  Gpio::setPull(_gpio, Gpio::PULL_UP);
  Gpio::setMode(_gpio, mode);
}
bool Pin::read() {
  return Gpio::getInput(_gpio);
}
void Pin::set(uint8_t state) {
  Gpio::setOutput(_gpio, state);
}

#endif /* _PIN_CPP_ */