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
    Gpio::setPull(i2c->sclGpio, Gpio::PULL_UP);
    Gpio::setAlternativeFunction(i2c->sclGpio, i2c->ALTERNATIVE_FUNCTION);

    //# Setup SDA
    Gpio::setClocking(i2c->sdaGpio->port, Gpio::CLOCK_ENABLE);
    Gpio::setMode(i2c->sdaGpio, Gpio::ALERNATIVE_FUNCTIONAL);
    Gpio::setOutputType(i2c->sdaGpio, Gpio::OPEN_DRAIN);
    Gpio::setSpeed(i2c->sdaGpio, Gpio::HIGH_SPEED);
    Gpio::setPull(i2c->sdaGpio, Gpio::PULL_UP);
    Gpio::setAlternativeFunction(i2c->sdaGpio, i2c->ALTERNATIVE_FUNCTION);

    //# Setup standart clocking settings
    setup(i2c, I2c::BUS_STANDART_FREQUENCY, I2c::SCL_STANDART_FREQUENCY, I2c::TRISE_STANDART);

    //# Enable I2C
    *i2c->CR1 |= I2c::I2C_ENABLE_MSK;
  }

  uint8_t send(I2cStruct *i2c, uint8_t adress, uint8_t data) {
    *i2c->CR1 |= I2c::START_MSK;  //Start I2c transmit

    //# Waiting for I2c will be ready
    SysTick::reset();
    while (readBit(i2c->SR1, I2c::SB_MSK) == 0) {
      if(SysTick::getTick() > I2c::TIMEOUT_STANDART){
        *i2c->CR1 |= I2c::STOP_MSK;   // Stop transmit
        return I2c::NOT_READY_ERROR;  // Return the error
      }
    }

    *i2c->DR = (adress << 1);  // Transmit device adress

    //# Checking the response to the sent address
    SysTick::reset();
    while (readBit(i2c->SR1, I2c::ADDR_MSK) == 0) {
      if(SysTick::getTick() > I2c::TIMEOUT_STANDART){
        *i2c->CR1 |= I2c::STOP_MSK;   // Stop transmit
        return I2c::NOT_FOUNDED_ADRESS_DEVICE;  // Return the error
      }
    }

    *i2c->SR2;        // Clearing the ADDR bit by reading SR1 register
    *i2c->DR = data;  // Transmit Data byte

    //# Waiting for data to be sent
    while (readBit(i2c->SR1, I2c::TXE_MSK) == 0) {
      //# If the device is not responding
      if(readBit(i2c->SR1, I2c::ACK_FAIL_MSK == 1)) {
        *i2c->CR1 |= I2c::STOP_MSK; // Stop trdansmit
        return I2c::TRANSMIT_ERROR; // Return the error
      }
    }

    I2C1_CR1 |= I2c::STOP_MSK;  // Stop transmit
    return I2c::SUCCESS;        // Return success transmit
  }

  void setup(I2cStruct *i2c, uint16_t busFrequency/*mHz*/, uint16_t sclFrequency/*kHz*/, uint16_t trise/*Nano Seconds*/) {
    *i2c->CR2 = busFrequency;
    *i2c->CCR = (busFrequency * 500) / sclFrequency;
    *i2c->TRISE = (trise * busFrequency) / 1000 + 1;
  }
}

#endif /* _I2C_CPP_ */