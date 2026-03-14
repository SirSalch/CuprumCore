#ifndef _GPIO_CHANNELS_CPP_
#define _GPIO_CHANNELS_CPP_

//# Header import
#include <GpioChannels.hpp>

/*
[=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═]
 ╔═════════╗  ╔═╗      ╔═╗  ╔═════════╗  ╔═════════╗  ╔═╗      ╔═╗  ╔═╗     ╔═╗
 ██████████╝  ██║      ██║  ██████████║  ██████████║  ██║      ██║  ██╚═╗   ██║
 ██║          ██║      ██║  ██╚═════██║  ██╚═════██║  ██║      ██║  ████╚═████║
 ██║          ██║      ██║  ██████████╝  ██████████╝  ██║      ██║  ██║ ██  ██║
 ██╚═══════╗  ██╚══════██║  ██║          ██║   ██╚═╗  ██╚══════██║  ██║     ██║
 ██████████╝  ███████████╝  ██╝          ██╝     ██╝  ███████████╝  ██╝     ██╝

[=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═]

File created: 13.01.2026
Author: _Salch_
*/

//# Gpio PA0
GpioStruct PA0 = {
  .number = 0,
  .port = Port::GPIOA,
  .odr = &GPIOA_ODR,
  .moder = &GPIOA_MODER,
  .otyper = &GPIOA_OTYPER,
  .afrh = &GPIOA_AFRH,
  .afrl = &GPIOA_AFRL,
  .pupdr = &GPIOA_PUPDR,
  .speed = &GPIOA_OSPEEDR
};
//# Gpio PA1
GpioStruct PA1 = {
  .number = 1,
  .port = Port::GPIOA,
  .odr = &GPIOA_ODR,
  .moder = &GPIOA_MODER,
  .otyper = &GPIOA_OTYPER,
  .afrh = &GPIOA_AFRH,
  .afrl = &GPIOA_AFRL,
  .pupdr = &GPIOA_PUPDR,
  .speed = &GPIOA_OSPEEDR
};
//# Gpio PA2
GpioStruct PA2 = {
  .number = 2,
  .port = Port::GPIOA,
  .odr = &GPIOA_ODR,
  .moder = &GPIOA_MODER,
  .otyper = &GPIOA_OTYPER,
  .afrh = &GPIOA_AFRH,
  .afrl = &GPIOA_AFRL,
  .pupdr = &GPIOA_PUPDR,
  .speed = &GPIOA_OSPEEDR
};
//# Gpio PA3
GpioStruct PA3 = {
  .number = 3,
  .port = Port::GPIOA,
  .odr = &GPIOA_ODR,
  .moder = &GPIOA_MODER,
  .otyper = &GPIOA_OTYPER,
  .afrh = &GPIOA_AFRH,
  .afrl = &GPIOA_AFRL,
  .pupdr = &GPIOA_PUPDR,
  .speed = &GPIOA_OSPEEDR
};
//# Gpio PA5
GpioStruct PA5 = {
  .number = 5,
  .port = Port::GPIOA,
  .odr = &GPIOA_ODR,
  .moder = &GPIOA_MODER,
  .otyper = &GPIOA_OTYPER,
  .afrh = &GPIOA_AFRH,
  .afrl = &GPIOA_AFRL,
  .pupdr = &GPIOA_PUPDR,
  .speed = &GPIOA_OSPEEDR
};
//# Gpio PA9
GpioStruct PA9 = {
  .number = 9,
  .port = Port::GPIOA,
  .odr = &GPIOA_ODR,
  .moder = &GPIOA_MODER,
  .otyper = &GPIOA_OTYPER,
  .afrh = &GPIOA_AFRH,
  .afrl = &GPIOA_AFRL,
  .pupdr = &GPIOA_PUPDR,
  .speed = &GPIOA_OSPEEDR
};
//# Gpio PA10
GpioStruct PA10 = {
  .number = 10,
  .port = Port::GPIOA,
  .odr = &GPIOA_ODR,
  .moder = &GPIOA_MODER,
  .otyper = &GPIOA_OTYPER,
  .afrh = &GPIOA_AFRH,
  .afrl = &GPIOA_AFRL,
  .pupdr = &GPIOA_PUPDR,
  .speed = &GPIOA_OSPEEDR
};


//# Gpio PB2
GpioStruct PB2 = {
  .number = 2,
  .port = Port::GPIOB,
  .odr = &GPIOB_ODR,
  .moder = &GPIOB_MODER,
  .otyper = &GPIOB_OTYPER,
  .afrh = &GPIOB_AFRH,
  .afrl = &GPIOB_AFRL,
  .pupdr = &GPIOB_PUPDR,
  .speed = &GPIOB_OSPEEDR
};
//# Gpio PB6
GpioStruct PB6 = {
  .number = 6,
  .port = Port::GPIOB,
  .odr = &GPIOB_ODR,
  .moder = &GPIOB_MODER,
  .otyper = &GPIOB_OTYPER,
  .afrh = &GPIOB_AFRH,
  .afrl = &GPIOB_AFRL,
  .pupdr = &GPIOB_PUPDR,
  .speed = &GPIOB_OSPEEDR
};
//# Gpio PB7
GpioStruct PB7 = {
  .number = 7,
  .port = Port::GPIOB,
  .odr = &GPIOB_ODR,
  .moder = &GPIOB_MODER,
  .otyper = &GPIOB_OTYPER,
  .afrh = &GPIOB_AFRH,
  .afrl = &GPIOB_AFRL,
  .pupdr = &GPIOB_PUPDR,
  .speed = &GPIOB_OSPEEDR
};

#endif /* _GPIO_CHANNELS_CPP_ */