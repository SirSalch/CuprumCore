//# Core import
#include <CuprumCore.hpp>

/*
[=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═]
  ╔═════════╗  ╔═╗      ╔═╗  ╔═════════╗  ╔═════════╗  ╔═╗      ╔═╗  ╔═╗     ╔═╗        ╔═════════╗  ╔═════════╗  ╔═════════╗  ╔═════════╗
  ██████████╝  ██║      ██║  ██████████║  ██████████║  ██║      ██║  ██╚═╗   ██║        ██████████╝  ██████████║  ██████████║  ██████████╝
  ██║          ██║      ██║  ██╚═════██║  ██╚═════██║  ██║      ██║  ████╚═████║        ██║          ██║     ██║  ██╚═════██║  ██╚═══════╗
  ██║          ██║      ██║  ██████████╝  ██████████╝  ██║      ██║  ██║ ██  ██║        ██║          ██║     ██║  ██████████╝  ██████████╝
  ██╚═══════╗  ██╚══════██║  ██║          ██║   ██╚═╗  ██╚══════██║  ██║     ██║        ██╚═══════╗  ██╚═════██║  ██║   ██╚═╗  ██╚═══════╗
  ██████████╝  ███████████╝  ██╝          ██╝     ██╝  ███████████╝  ██╝     ██╝        ██████████╝  ██████████╝  ██╝     ██╝  ██████████╝

[=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═]

File created: 09.02.2026
Author:  _Salch_
*/

namespace Core {
  void startUp() {
    __initMemory();
    __initClcokingSystem();
  }

  //# Proprietary functions
  void __initMemory() {
    unsigned int *src = &_originInitdata;
    unsigned int *dst = &_originData;
    unsigned int *end = &_endData;

    while (dst < end) {
      *dst++ = *src++;
    }

    dst = &_originBss;
    end = &_endBss;

    while (dst < end) {
      *dst++ = 0;
    }
  }

  void __initClcokingSystem() {
    //# SysTick init
    SysTick::setLoad(0xFFFFFF);
    SysTick::setClockingSource(SysTick::PROCESSOR_CLOCKING_SOURCE);
    SysTick::enable();
  }
}

//# Compiler Attributes
void *vectors[] __attribute__((section(".isr_vector"), used)) = {
  (void*)&_stackOrigin,
  (void*)&resetHandler
};

void __attribute__((naked, noreturn)) resetHandler() {
  Core::startUp();
  main();
}

//# System functions
void delay(uint32_t time){
  uint32_t tickTime = time * (16000000 / 1000);
  SysTick::reset();
  while (SysTick::getTick() < tickTime) { /* waiting */ }
}

uint8_t readBit(volatile uint32_t *reg, uint8_t mask) {
  return ((*reg) & mask) != 0;
}