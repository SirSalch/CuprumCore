#ifndef _I2C_CPP_
#define _I2C_CPP_

//# Heade import
#include <I2c.hpp>

/*
[=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═]
 ╔═════════╗  ╔═╗      ╔═╗  ╔═════════╗  ╔═════════╗  ╔═╗      ╔═╗  ╔═╗     ╔═╗
 ██████████╝  ██║      ██║  ██████████║  ██████████║  ██║      ██║  ██╚═╗   ██║
 ██║          ██║      ██║  ██╚═════██║  ██╚═════██║  ██║      ██║  ████╚═████║
 ██║          ██║      ██║  ██████████╝  ██████████╝  ██║      ██║  ██║ ██  ██║
 ██╚═══════╗  ██╚══════██║  ██║          ██║   ██╚═╗  ██╚══════██║  ██║     ██║
 ██████████╝  ███████████╝  ██╝          ██╝     ██╝  ███████████╝  ██╝     ██╝

[=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═]

 File created: 21.02.2026
 Author: _Salch_
*/

namespace I2c {
  void init(I2cStruct *i2c) {
    //# Enable I2c clocking
    *i2c->RCC |= i2c->RCC_MASK;
    
    //# Setup SCL
    Gpio::setClocking(i2c->sclGpio->port, Gpio::CLOCK_ENABLE);
    Gpio::setMode(i2c->sclGpio, Gpio::ALERNATIVE_FUNCTIONAL);
    Gpio::setOutputType(i2c->sclGpio, Gpio::OPEN_DRAIN);
    Gpio::setSpeed(i2c->sclGpio, Gpio::HIGH_SPEED);
    Gpio::setPull(i2c->sclGpio, Gpio::NO_PULL);
    Gpio::setAlternativeFunction(i2c->sclGpio, i2c->ALTERNATIVE_FUNCTION);

    //# Setup SDA
    Gpio::setClocking(i2c->sdaGpio->port, Gpio::CLOCK_ENABLE);
    Gpio::setMode(i2c->sdaGpio, Gpio::ALERNATIVE_FUNCTIONAL);
    Gpio::setOutputType(i2c->sdaGpio, Gpio::OPEN_DRAIN);
    Gpio::setSpeed(i2c->sdaGpio, Gpio::HIGH_SPEED);
    Gpio::setPull(i2c->sdaGpio, Gpio::NO_PULL);
    Gpio::setAlternativeFunction(i2c->sdaGpio, i2c->ALTERNATIVE_FUNCTION);

    //# Setup standart clocking settings
    setup(i2c, BUS_STANDART_FREQUENCY, SCL_STANDART_FREQUENCY, TRISE_STANDART);

    //# Enable I2C
    *i2c->CR1 |= I2C_ENABLE_BIT;
  }

  /* TODO: algorithm for sending data */
  void send(I2cStruct *i2c, uint8_t adress, uint8_t data) {
    *i2c->CR1 &= ~ACK_BIT;  // Clear ACK bit
    *i2c->CR1 |= START_BIT; // Start I2c transmit
  }

  void setup(I2cStruct *i2c, uint16_t busFrequency/*mHz*/, uint16_t sclFrequency/*kHz*/, uint16_t trise/*nanoSeconds*/) {
    *i2c->CR2 = busFrequency/*mHz*/;
    *i2c->CCR = busFrequency/*mHz*/ / (2 * sclFrequency/*kHz*/);
    *i2c->TRISE = trise/*nanoSeconds*/ * busFrequency /*mHz*/ + 1;
  }
}

#endif /* _I2C_CPP_ */