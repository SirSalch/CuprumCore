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

// Gpio port A
const GpioPort GpioA = {
  .RccMask = 0x01,
  .ODR = &GPIOA_ODR,
  .IDR = &GPIOA_IDR,
  .MODER = &GPIOA_MODER,
  .OTYPER = &GPIOA_OTYPER,
  .AFRH = &GPIOA_AFRH,
  .AFRL = &GPIOA_AFRL,
  .PUPDR = &GPIOA_PUPDR,
  .SPEED = &GPIOA_OSPEEDR
};
// Gpio port B
const GpioPort GpioB = {
  .RccMask = 0x02,
  .ODR = &GPIOB_ODR,
  .IDR = &GPIOB_IDR,
  .MODER = &GPIOB_MODER,
  .OTYPER = &GPIOB_OTYPER,
  .AFRH = &GPIOB_AFRH,
  .AFRL = &GPIOB_AFRL,
  .PUPDR = &GPIOB_PUPDR,
  .SPEED = &GPIOB_OSPEEDR
};
// Gpio port C
const GpioPort GpioC = {
  .RccMask = 0x03,
  .ODR = &GPIOC_ODR,
  .IDR = &GPIOC_IDR,
  .MODER = &GPIOC_MODER,
  .OTYPER = &GPIOC_OTYPER,
  .AFRH = &GPIOC_AFRH,
  .AFRL = &GPIOC_AFRL,
  .PUPDR = &GPIOC_PUPDR,
  .SPEED = &GPIOC_OSPEEDR
};


// Pins port A
const GpioPin PA0  { .number = 0,  .port = &GpioA };
const GpioPin PA1  { .number = 1,  .port = &GpioA };
const GpioPin PA2  { .number = 2,  .port = &GpioA };
const GpioPin PA3  { .number = 3,  .port = &GpioA };
const GpioPin PA5  { .number = 5,  .port = &GpioA };
const GpioPin PA9  { .number = 9,  .port = &GpioA };
const GpioPin PA10{ .number = 10, .port = &GpioA };
// Pins port B
const GpioPin PB2  { .number = 2,  .port = &GpioB };
const GpioPin PB6  { .number = 6,  .port = &GpioB };
const GpioPin PB7  { .number = 7,  .port = &GpioB };

#endif /* _GPIO_CHANNELS_CPP_ */