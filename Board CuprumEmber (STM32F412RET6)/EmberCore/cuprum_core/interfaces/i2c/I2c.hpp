#ifndef _I2C_HPP_
#define _I2C_HPP_

//# Librarys import
#include <stdint.h>
#include <Gpio.hpp>
#include <I2cChannels.hpp>

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
  enum {
    //# Masks
    ACK_BIT = 0x400,
    STOP_BIT = 0x200,
    START_BIT = 0x100,
    I2C_ENABLE_BIT = 0x01,

    //# Standart settings
    BUS_STANDART_FREQUENCY = 16/*mHz*/,
    SCL_STANDART_FREQUENCY = 100/*kHz*/,
    TRISE_STANDART = 1000/*nanoSeconds*/
  };

  void init(I2cStruct *i2c);
  void send(I2cStruct *i2c, uint8_t adress, uint8_t data);
  void setup(I2cStruct *i2c, uint16_t busFrequency/*mHz*/, uint16_t sclFrequency/*kHz*/, uint16_t trise/*nanoSeconds*/); 
}

#endif /* _I2C_HPP_ */