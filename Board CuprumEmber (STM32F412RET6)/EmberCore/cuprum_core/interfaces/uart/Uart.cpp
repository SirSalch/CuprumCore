// Header import
#include <Uart.hpp>

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

namespace Uart {
  void init(UartStruct *uart, uint32_t baudRate) {
    RCC_APB2ENR |= 0x10;

    // Setup TX pin
    Gpio::setClocking(uart->txGpio->port, Gpio::CLOCK_ENABLE);
    Gpio::setMode(uart->txGpio, Gpio::ALERNATIVE_FUNCTIONAL);
    Gpio::setSpeed(uart->txGpio, Gpio::HIGH_SPEED);
    Gpio::setAlternativeFunction(uart->txGpio, uart->ALTERNATIVE_FUNCTION);

    // Setup RX pin
    Gpio::setClocking(uart->rxGpio->port, Gpio::CLOCK_ENABLE);
    Gpio::setMode(uart->rxGpio, Gpio::ALERNATIVE_FUNCTIONAL);
    Gpio::setSpeed(uart->rxGpio, Gpio::HIGH_SPEED);
    Gpio::setAlternativeFunction(uart->rxGpio, uart->ALTERNATIVE_FUNCTION);

    *uart->BRR = (ClockingSystem::sourceFrequency * 1000000 + baudRate / 2) / baudRate;
    *uart->CR1 |= TRANSMIT_ENABLE_MSK | ENABLE_MSK; 
  }
  void send(UartStruct *uart, uint8_t data) {
    *uart->DR = data;
  }
  void sendPackage(UartStruct *uart, uint8_t *package, uint8_t size) {
    for(uint8_t i = 0; i < size; i ++) {
      *uart->DR = package[i];
      while (readBit(uart->SR, TXE_MSK) == 0);
    }
  }
}