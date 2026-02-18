#ifndef _PWM_HPP_
#define _PWM_HPP_

//# Core import
#include <CuprumCore.hpp>

/*
[=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═]
 ╔═════════╗  ╔═╗     ╔═╗  ╔═╗     ╔═╗
 ██████████║  ██║     ██║  ██╚═╗  ╔██║
 ██╚═════██║  ██║ ╔═╗ ██║  ████╚═████║
 ██████████╝  ██╚═██╚═██║  ██║ ██  ██║
 ██║          ████╝ ████║  ██║     ██║
 ██╝          ██╝     ██╝  ██╝     ██╝

[=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═]

File created: 17.02.2026
Author: _Salch_
*/

typedef struct {
  TimerStruct *timer;
  uint16_t timerChannel;
  GpioStruct *gpio;
} PwmChannelStruct;

class Pwm {
  public:
    Pwm(PwmChannelStruct *channel, uint32_t prescaler);
    void generate(uint16_t fill);

    static PwmChannelStruct CH1;
    static PwmChannelStruct CH2;
    static PwmChannelStruct CH3;
    static PwmChannelStruct CH4;

  private:
    PwmChannelStruct *_channel;
};

#endif /* _PWM_HPP_ */