#ifndef _UART_HPP_
#define _UART_HPP_

// Drivers import
#include <UartChannels.hpp>
#include <ClockingSystem.hpp>

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
  enum {
    // Masks
    TXE_MSK = 0x80,
    RXNE_MSK = 0x20,
    ENABLE_MSK = 0x2000,
    RECIVE_ENABLE_MSK = 0x04,
    TRANSMIT_ENABLE_MSK = 0x08,

    // Errors
    DATA_CATCH_ERROR,
    DATA_NOT_FOUND_ERROR
  };
  
  void init(UartStruct *uart, uint32_t baudRate);
  void sendByte(UartStruct *uart, uint8_t data);
  void sendPackage(UartStruct *uart, uint8_t *package, uint8_t size);
  uint8_t readPackage(UartStruct *uart, uint8_t* buffer, uint8_t size, uint16_t timeOut);
  uint8_t readByte(UartStruct *uart, uint16_t timeOut);
}

#endif /* _UART_HPP_ */