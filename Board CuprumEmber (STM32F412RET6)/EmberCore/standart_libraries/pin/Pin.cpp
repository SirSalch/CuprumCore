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

Pin::Pin(GpioStruct *initGpio, uint8_t mode) : _gpio(initGpio) {
  Gpio::setClocking(_gpio->port, Gpio::CLOCK_ENABLE);
  Gpio::setMode(_gpio, mode);
}

void Pin::set(uint8_t state) {
  Gpio::setOutput(_gpio, state);
}

#endif /* _PIN_CPP_ */