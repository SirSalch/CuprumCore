#!/bin/bash

LOG="Log:> "
ERROR="Error:>>> "
SUCCESS="Success:>> "

# Exit to project directory
cd ..
cd ..

printLogo() {
  echo "[=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═]"
  echo " ╔═════════╗  ╔═╗      ╔═╗  ╔═════════╗  ╔═════════╗  ╔═╗      ╔═╗  ╔═╗     ╔═╗"
  echo " ██████████╝  ██║      ██║  ██████████║  ██████████║  ██║      ██║  ██╚═╗  ╔██║"
  echo " ██║          ██║      ██║  ██╚═════██║  ██╚═════██║  ██║      ██║  ████╚═████║"
  echo " ██║          ██║      ██║  ██████████╝  ██████████╝  ██║      ██║  ██║ ██╝ ██║"
  echo " ██╚═══════╗  ██╚══════██║  ██║          ██║   ██╚═╗  ██╚══════██║  ██║     ██║"
  echo " ██████████╝  ███████████╝  ██╝          ██╝     ██╝  ███████████╝  ██╝     ██╝"
  echo " "
  echo "[=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═]"
}

printBuildInfo() {
  echo " "
  echo "=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═="
  arm-none-eabi-size  Project.elf
  echo "=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═="
  echo " " 
}

buildProject() {
  echo "${LOG}Building project..."
  arm-none-eabi-g++ -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 \
  -std=gnu++14 \
  -Os \
  -ffunction-sections -fdata-sections \
  -fno-exceptions -fno-rtti -fno-use-cxa-atexit \
  -I"cuprum_core/core" \
  -I"cuprum_core/core/registers" \
  -I"cuprum_core/core/clocking/sys_tick" \
  -I"cuprum_core/interfaces/gpio" \
  -I"cuprum_core/interfaces/gpio/channels" \
  -I"cuprum_core/interfaces/timer" \
  -I"cuprum_core/interfaces/timer/channels" \
  -I"cuprum_core/interfaces/i2c" \
  -I"cuprum_core/interfaces/i2c/channels" \
  -I"standart_libraries/pin" \
  -I"standart_libraries/pwm" \
  -T"cuprum_core/build/Linker.ld" \
  -Wl,-Map="Project.map" -Wl,--gc-sections \
  cuprum_core/core/CuprumCore.cpp \
  cuprum_core/core/clocking/sys_tick/SysTick.cpp \
  src/Main.cpp cuprum_core/build/Startup.cpp \
  cuprum_core/interfaces/gpio/Gpio.cpp \
  cuprum_core/interfaces/gpio/channels/GpioChannels.cpp \
  cuprum_core/interfaces/timer/Timer.cpp \
  cuprum_core/interfaces/timer/channels/TimerChannels.cpp \
  cuprum_core/interfaces/i2c/I2c.cpp \
  cuprum_core/interfaces/i2c/channels/I2cChannels.cpp \
  standart_libraries/pin/Pin.cpp \
  standart_libraries/pwm/Pwm.cpp \
  -o Project.elf

  if [ $? -eq 0 ]; then
    echo "${LOG}Build done"
  else
    echo "${ERROR}Build Failed!"
    exit
  fi

  echo "${LOG}Сreating a binary file"
  arm-none-eabi-objcopy -O binary Project.elf Project.bin
}

printLogo
buildProject
printBuildInfo

echo "${LOG}Programming MCU..."
st-flash erase

if st-flash --reset write Project.bin 0x8000000 > /dev/null; then
  echo "${SUCCESS}Programming done"
else
  echo "${ERROR}St-Link programm failed!"
fi

rm -f Project.elf Project.bin Project.map