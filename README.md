# CuprumCore
**( 🛠 In development ) CuprumCore** is an open-source hardware and software ecosystem for developing electronic devices based on STM32 microcontrollers, providing a range of proprietary boards and a software core that combines ease of coding with high performance.

## Example syntax:
### > Led Blink
![image alt](https://github.com/SirSalch/CuprumCore/blob/6a880bd9dccb2965ef258e1fd926802a23491795/Readme%20Extensions/LedBlickDemonstration.gif)
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
```
```sh
Program weight - FLASH:936 bytes, RAM:40 bytes 
```
### > Pwm generation
![image alt](https://github.com/SirSalch/CuprumCore/blob/6a880bd9dccb2965ef258e1fd926802a23491795/Readme%20Extensions/PwmDemonstration.gif)
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
```
```sh
Program weight - FLASH:1138 bytes, RAM:104 bytes
```

## Getting Started (Ubuntu)
#### Dependencies
The toolkit for working with St-Link
  ```sh
  sudo apt install stlink-tools
  ```
The compiler for ARM microcontrollers
  ```sh
  sudo apt install gcc-arm-none-eabi
  ```
#### Project
Cloning the repository to your computer
  ```sh
  git clone https://github.com/SirSalch/CuprumCore.git
  ```
Go to the directory of the builder script
  ```sh
  cd <Your path to the repository>/'Board CuprumEmber (STM32F412RET6)'/EmberCore/cuprum_core/build
  ```
#### Launch
Allow the script to run without superuser rights
  ```sh
  sudo chmod +x Build.sh
  ```
Run the compilation and upload the firmware to the microcontroller
  ```sh
  ./Build.sh
  ```

## License
GNU General public license v3.0
