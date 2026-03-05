//# Core import
#include <CuprumCore.hpp>

/*
[=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=]
  ╔═════════╗  ╔═════════╗  ╔═════════╗  ╔═════════╗
  ██████████╝  ██████████║  ██████████║  ██████████╝
  ██║          ██║     ██║  ██╚═════██║  ██╚═══════╗
  ██║          ██║     ██║  ██████████╝  ██████████╝
  ██╚═══════╗  ██╚═════██║  ██║   ██╚═╗  ██╚═══════╗
  ██████████╝  ██████████╝  ██╝     ██╝  ██████████╝

[=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=]

File created: 09.02.2026
Author:  _Salch_
*/

namespace Core {
  void deploy() {
    MemorySystem::startup();
    ClockingSystem::startup();
  }
}

// Compiler Attributes
void *vectors[] __attribute__((section(".isr_vector"), used)) = {
  (void*)&_stackOrigin,
  (void*)&resetHandler
};
void __attribute__((naked, noreturn)) resetHandler() {
  Core::deploy(); // Deploy the cuprum core 
  main();         // Entrance to the main point
}

// System functions
void delay(uint32_t time){
  uint32_t tickTime = time * ClockingSystem::sourceFrequency * 1000;
  SysTick::reset();
  while (SysTick::getTick() < tickTime) { /* waiting */ }
}
uint8_t readBit(volatile uint32_t *reg, uint8_t mask) {
  return ((*reg) & mask) != 0;
}