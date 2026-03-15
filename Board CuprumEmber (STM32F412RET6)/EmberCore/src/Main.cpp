#include <CuprumCore.hpp>

int main(void) {
  /* Setup */
  Pin led(&PB2, OUTPUT);

  /* Loop */
  while(1) {
    led.set(HIGH);
    delay(300);
    led.set(LOW);
    delay(300);
  }
  return 0;
}