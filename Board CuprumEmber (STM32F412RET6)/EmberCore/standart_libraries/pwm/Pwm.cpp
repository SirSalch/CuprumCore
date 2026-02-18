#ifndef _PWM_CPP_
#define _PWM_CPP_

//# Header import
#include <Pwm.hpp>

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

Pwm::Pwm(PwmChannelStruct *channel, uint32_t prescaler) : _channel(channel) {
  Timer::setClocking(_channel->timer, Timer::CLOCK_ENABLE);
  Timer::setPrescaler(_channel->timer, prescaler);
  Timer::setAutoReload(_channel->timer, 1000);
  Timer::setGpio(_channel->timer, _channel->gpio);
}

void Pwm::generate(uint16_t fill) {
  Timer::setFill(_channel->timer, _channel->timerChannel, fill + 1);
  Timer::setMode(_channel->timer, Timer::PWM_GENERATION, _channel->timerChannel);
  Timer::enableChannel(_channel->timer, _channel->timerChannel);
  Timer::start(_channel->timer);
}

PwmChannelStruct Pwm::CH1 = {
  &TIMER2,
  Timer::CH1,
  &PA0
};

PwmChannelStruct Pwm::CH2 = {
  &TIMER2,
  Timer::CH2,
  &PA1
};

PwmChannelStruct Pwm::CH3 = {
  &TIMER2,
  Timer::CH3,
  &PA2
};

PwmChannelStruct Pwm::CH4 = {
  &TIMER2,
  Timer::CH4,
  &PA3
};


#endif /* _PWM_CPP_ */