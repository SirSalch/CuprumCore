#include <CuprumCore.hpp>

// Entry point of the program
int main(void) {
  /* Setup */


  /* Loop */
  while(1) {

    
  }
  return 0;
}

// Configuration clock system of the microcontroller
void ClockingSystem::configuration() {
  setSourceClocking(EXTERNAL_QUARTZ, 8 /*mHz*/);
  setSystemMux(EXTERNAL);  // Connect system frequrency to external quartz
}
