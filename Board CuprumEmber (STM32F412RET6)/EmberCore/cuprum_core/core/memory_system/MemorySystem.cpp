//# Header import
#include <MemorySystem.hpp>

/*
[=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=]
  ╔═════════╗  ╔═════════╗  ╔═════════╗  ╔═════════╗
  ██████████╝  ██████████║  ██████████║  ██████████╝
  ██║          ██║     ██║  ██╚═════██║  ██╚═══════╗
  ██║          ██║     ██║  ██████████╝  ██████████╝
  ██╚═══════╗  ██╚═════██║  ██║   ██╚═╗  ██╚═══════╗
  ██████████╝  ██████████╝  ██╝     ██╝  ██████████╝

[=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=]

File created: 01.03.2026
Author:  _Salch_
*/

namespace MemorySystem {
  void startup() {
    __initRAM();
  }

  void __initRAM() {
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
}