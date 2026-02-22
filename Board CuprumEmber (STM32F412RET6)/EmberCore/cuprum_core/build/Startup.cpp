#include <SysTick.hpp>

extern unsigned int _originInitdata;
extern unsigned int _originData;
extern unsigned int _endData;
extern unsigned int _originBss;
extern unsigned int _endBss;

extern void *_stackOrigin;
extern int main();

void resetHandler();

void *vectors[] __attribute__((section(".isr_vector"), used)) = {
  (void*)&_stackOrigin,
  (void*)&resetHandler
};

void __attribute__((naked, noreturn)) resetHandler() {
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

  //# SysTick init
  SysTick::setLoad(0xFFFFFF);
  SysTick::setClockingSource(SysTick::PROCESSOR_CLOCKING_SOURCE);
  SysTick::enable();

  main();
}
