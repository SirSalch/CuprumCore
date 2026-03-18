#ifndef _UART_CHANNELS_HPP_
#define _UART_CHANNELS_HPP_


// Drivers import
#include <stdint.h>
#include <Gpio.hpp>

/*
[=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═]
 ╔═════════╗  ╔═╗      ╔═╗  ╔═════════╗  ╔═════════╗  ╔═╗      ╔═╗  ╔═╗     ╔═╗
 ██████████╝  ██║      ██║  ██████████║  ██████████║  ██║      ██║  ██╚═╗   ██║
 ██║          ██║      ██║  ██╚═════██║  ██╚═════██║  ██║      ██║  ████╚═████║
 ██║          ██║      ██║  ██████████╝  ██████████╝  ██║      ██║  ██║ ██  ██║
 ██╚═══════╗  ██╚══════██║  ██║          ██║   ██╚═╗  ██╚══════██║  ██║     ██║
 ██████████╝  ███████████╝  ██╝          ██╝     ██╝  ███████████╝  ██╝     ██╝

[=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═]

 File created: 06.03.2026
 Author: _Salch_
*/

typedef struct {
  const GpioPin *txGpio;
  const GpioPin *rxGpio;
  volatile uint32_t* BRR;
  volatile uint32_t* CR1;
  volatile uint32_t* CR2;
  volatile uint32_t* CR3;
  volatile uint32_t* DR;
  volatile uint32_t* SR;
  volatile uint32_t* GTPR;
  uint32_t ALTERNATIVE_FUNCTION;
} UartStruct;

extern UartStruct UART1;

#endif /* _UART_CHANNELS_HPP_ */