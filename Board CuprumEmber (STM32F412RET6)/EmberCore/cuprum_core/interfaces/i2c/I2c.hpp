#ifndef _I2C_HPP_
#define _I2C_HPP_

//# Librarys import
#include <stdint.h>
#include <Gpio.hpp>
#include <I2cChannels.hpp>
#include <SysTick.hpp>

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
    SB_MSK = 0x01,
    ACK_MSK = 0x400,
    TXE_MSK = 0x80,
    ADDR_MSK = 0x02,
    STOP_MSK = 0x200,
    START_MSK = 0x100,
    ACK_FAIL_MSK = 0x400,
    I2C_ENABLE_MSK = 0x01,

    //# Standart settings
    TIMEOUT_STANDART = 3000,
    BUS_STANDART_FREQUENCY = 16/*mHz*/,
    SCL_STANDART_FREQUENCY = 100/*kHz*/,
    TRISE_STANDART = 1000,/*nanoSeconds*/

    //# Errors
    NOT_READY_ERROR = 0x01,
    NOT_FOUNDED_ADRESS_DEVICE = 0x01,
    TRANSMIT_ERROR = 0x03,

    // Others
    SUCCESS = 0x00,
  };

  void init(I2cStruct *i2c);
  uint8_t send(I2cStruct *i2c, uint8_t adress, uint8_t data);
  void setup(I2cStruct *i2c, uint16_t busFrequency/*mHz*/, uint16_t sclFrequency/*kHz*/, uint16_t trise/*nanoSeconds*/);
}

#endif /* _I2C_HPP_ */