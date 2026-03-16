# CuprumCore
![image alt](https://github.com/SirSalch/CuprumCore/blob/main/Repository%20images/%20LogoText.png?raw=true)
<br>
<br>
( 🛠 In development ) CuprumCore is an open-source hardware and software ecosystem for developing electronic devices based on STM32 microcontrollers, providing a range of proprietary boards and a software core that combines ease of coding with high performance.

## Example syntax:
### > Led Blink
![image alt](https://github.com/SirSalch/CuprumCore/blob/main/Repository%20images/LedBlickDemonstration.gif?raw=true)
 ```c++
#include <CuprumCore.hpp>

int main(void) {
  /* Setup */
  Pin led(&PB2, OUTPUT);  // Configuring the PB2 pin of the microcontroller as an output
  
  /* loop */
  while(1) {
	led.set(HIGH);  // Enable led
    delay(300);     // waiting 300 milliseconds
    led.set(LOW);   // Disable led
    delay(300);     // waiting 300 milliseconds
  }
  return 0;
}
```
```
Program weight - FLASH:1026 bytes, RAM:40 bytes 
```
### > Pwm generation
![image alt](https://github.com/SirSalch/CuprumCore/blob/main/Repository%20images/PwmDemonstration.png?raw=true)
```c++
#include <CuprumCore.hpp>

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
```
Program weight - FLASH:1262 bytes, RAM:104 bytes
```
### > I2C Transmit
![image alt](https://github.com/SirSalch/CuprumCore/blob/main/Repository%20images/I2cDemonstration.png?raw=true)
```c++
#include <CuprumCore.hpp>

int main(void) {
  /* Setup */
  I2c::init(&I2C1, 100/*kHz*/);

  /* Loop */
  while(1) {
    I2c::send(&I2C1, 0x27 /*Adress*/, 0x02 /*Data*/);
    delay(100);
  }
  return 0;
}
```
```
Program weight - FLASH:1388 bytes, RAM:120 bytes
```

## RoadMap of Project:
Plan for the board "CuprumEmber", based on STM32F412RET6
<br>
P.S. It will be expanded.
<br>
<br>
![image alt](https://github.com/SirSalch/CuprumCore/blob/main/Repository%20images/RoadMap.png?raw=true)

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
Allow the script to run without superuser rights
  ```sh
  sudo chmod +x Build.sh
  ```
#### Launch
Run the compilation and upload the firmware to the microcontroller
  ```sh
  ./Build.sh
  ```

## License
GNU General public license v3.0
