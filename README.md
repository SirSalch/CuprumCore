# CuprumCore
**( 🛠 In development ) CuprumCore** is an open-source hardware and software ecosystem for developing electronic devices based on STM32 microcontrollers, providing a range of proprietary boards and a software core that combines ease of coding with high performance.

At the moment, the project is in the development stage, the author of the project is a simple enthusiast and will not forgive any money, instead I ask you to help in the development of the code with your ideas, found errors or new features. All who really helped the development of the project will be added to the comments of the repository files as "Edited: Your nickname".


Example syntax:
- Led Blink
 ```c++
#include <CuprumCore.hpp>
#include <Pin.hpp>

int main(void) {
  /* Setup */
  Pin led(&PB2, Pin::OUTPUT);  // Configuring the PB2 pin of the microcontroller as an output
  
  /* loop */
  while(1) {
	led.set(Pin::HIGH);  // Enable led
    delay(300);          // waiting 300 milliseconds
    led.set(Pin::LOW);   // Disable led
    delay(300);          // waiting 300 milliseconds
  }
  return 0;
}

/* Program weight - FLASH:936 bytes, RAM:40 bytes */
```
- Pwm generation
```c++
#include <CuprumCore.hpp>
#include <Pwm.hpp>

int main(void) {
  /* Setup */
  Pwm out(&Pwm::CH1, 1000); // Create the first PWM channel with a prescaler of 1000
  out.generate(500);        // Generate a PWM with a signal filling of 50%
  
  /* Loop */
  while(1) {
  
  }
  
  return 0;
}
/* Program weight - FLASH:1138 bytes, RAM:104 bytes */
```
