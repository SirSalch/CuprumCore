#ifndef _PIN_HPP_
#define _PIN_HPP_

//# Core import
#include <CuprumCore.hpp>

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

class Pin {
  public:
    Pin(const GpioPin *initGpio, uint8_t mode);
    void set(uint8_t state);
    bool read();

  private:
    const GpioPin *_gpio;
};

#endif /* _PIN_HPP_ */