#ifndef _I2C_CHANNELS_HPP_
#define _I2C_CHANNELS_HPP_

//# I2c import
#include <Gpio.hpp>
#include <stdint.h>

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

//# Gpio channel struct
typedef struct {
  volatile uint32_t* RCC;
  volatile uint32_t* CR1;
  volatile uint32_t* CR2;
  volatile uint32_t* CCR;
  volatile uint32_t* TRISE;
  GpioStruct *sdaGpio;
  GpioStruct *sclGpio;
  uint32_t RCC_MASK;
  uint32_t ALTERNATIVE_FUNCTION;
} I2cStruct;

extern I2cStruct I2C1;

#endif /* _I2C_CHANNELS_HPP_ */