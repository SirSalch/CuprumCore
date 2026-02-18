#ifndef _TIMER_CPP_
#define _TIMER_CPP_

//# Header import
#include <Timer.hpp>

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

void Timer::setClocking(TimerStruct *timer, uint8_t state) {
  if(state == Timer::CLOCK_ENABLE) *timer->rcc |= timer->rccMask;
  else if(state == Timer::CLOCK_DISABLE) *timer->rcc &= ~timer->rccMask;
}

void Timer::stop(TimerStruct *timer) {
  *timer->cr1 &= ~0x01;
}

void Timer::start(TimerStruct *timer) {
  *timer->cr1 |= 0x01;
}

void Timer::setGpio(TimerStruct *timer, GpioStruct *gpio) {
  Gpio::setClocking(gpio->port, Gpio::CLOCK_ENABLE);
  Gpio::setMode(gpio, Gpio::ALERNATIVE_FUNCTIONAL);
  Gpio::setAlternativeFunction(gpio, timer->afrMask);
  Gpio::setSpeed(gpio, Gpio::HIGH_SPEED);
}

void Timer::setPrescaler(TimerStruct *timer, uint32_t prescaler) {
  *timer->psc = prescaler;
}

void Timer::enableChannel(TimerStruct *timer, uint16_t channel) {
  *timer->ccer |= channel;
}

void Timer::setAutoReload(TimerStruct *timer, uint16_t autoreload) {
  *timer->arr = autoreload;
}

void Timer::setFill(TimerStruct *timer, uint16_t channel, uint16_t fill) {
  switch(channel) {
    case Timer::CH1: *timer->ccr1 = fill; return;
    case Timer::CH2: *timer->ccr2 = fill; return;
    case Timer::CH3: *timer->ccr3 = fill; return;
    case Timer::CH4: *timer->ccr4 = fill; return;
  }
}

void Timer::setMode(TimerStruct *timer, uint16_t mode, uint16_t cahnnel) {
  switch(mode) {
    case Timer::PWM_GENERATION: {
      switch(cahnnel) {
        case Timer::CH1: *timer->ccmr1 |= Timer::PWM_GENERATION << 4;  break;
        case Timer::CH2: *timer->ccmr1 |= Timer::PWM_GENERATION << 12; break;
        case Timer::CH3: *timer->ccmr2 |= Timer::PWM_GENERATION << 4;  break;
        case Timer::CH4: *timer->ccmr2 |= Timer::PWM_GENERATION << 12;
      }
    }
  }
}

#endif /* _TIMER_CPP_ */