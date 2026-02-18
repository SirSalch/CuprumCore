#include <CuprumCore.hpp>
#include <Pin.hpp>
#include <Pwm.hpp>

int main(void) {
  /* Setup */
  Pin led(&PB2, Pin::OUTPUT);
  
  Pwm out(&Pwm::CH4, 100);
  out.generate(900);

  /* Loopd */
  while(1) {
    led.set(Pin::HIGH);
    delay(300);
    led.set(Pin::LOW);
    delay(300);
  }
}