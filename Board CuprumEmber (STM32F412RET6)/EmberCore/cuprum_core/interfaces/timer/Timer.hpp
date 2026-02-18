#ifndef _TIMER_HPP_
#define _TIMER_HPP_

//# Librarys import
#include <Gpio.hpp>
#include <TimerChannels.hpp>
#include <Registers.hpp>
#include <stdint.h>

/*
[=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═]
 ╔═════════╗  ╔═╗      ╔═╗  ╔═════════╗  ╔═════════╗  ╔═╗      ╔═╗  ╔═╗     ╔═╗
 ██████████╝  ██║      ██║  ██████████║  ██████████║  ██║      ██║  ██╚═╗   ██║
 ██║          ██║      ██║  ██╚═════██║  ██╚═════██║  ██║      ██║  ████╚═████║
 ██║          ██║      ██║  ██████████╝  ██████████╝  ██║      ██║  ██║ ██  ██║
 ██╚═══════╗  ██╚══════██║  ██║          ██║   ██╚═╗  ██╚══════██║  ██║     ██║
 ██████████╝  ███████████╝  ██╝          ██╝     ██╝  ███████████╝  ██╝     ██╝

[=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═]

 File created: 03.12.2025
 Author: _Salch_
*/

namespace Timer {
  enum {
    //# Clocking state
    CLOCK_ENABLE =  0x11,
    CLOCK_DISABLE = 0x31,

	  //# Timer channels
    CH1 = 0x01,
	  CH2 = 0x10,
	  CH3 = 0x100,
	  CH4 = 0x1000,

	  //# Timer modes
	  PWM_GENERATION = 0x06
  };

  void stop(TimerStruct *timer);
  void start(TimerStruct *timer);
  void setGpio(TimerStruct *timer, GpioStruct *gpio);
  void setClocking(TimerStruct *timer, uint8_t state);
  void setPrescaler(TimerStruct *timer, uint32_t prescaler);
  void enableChannel(TimerStruct *timer, uint16_t channel);
  void setAutoReload(TimerStruct *timer, uint16_t autoreload);
  void setFill(TimerStruct *timer, uint16_t channel, uint16_t fill);
  void setMode(TimerStruct *timer, uint16_t mode, uint16_t cahnnel);
}

#endif /* _TIMER_HPP_ */