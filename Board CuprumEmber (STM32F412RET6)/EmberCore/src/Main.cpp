#include <CuprumCore.hpp>

int main(void) {
  /* Setup */
  Pin led(&PB2, OUTPUT);
  Pin button(&PB6, INPUT);

  /* Loop */
  while(1) {
    if(button.read())
      led.set(HIGH);
    else
      led.set(LOW);
  }
  return 0;
}