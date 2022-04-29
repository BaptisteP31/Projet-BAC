#include "led_indicator.h"
#include <Arduino.h>

//Constructeur, pin de le led
ledindicator::ledindicator(int pin, int delay) {
  _pin = pin; 
  _delay = delay;
  pinMode(_pin, OUTPUT);
  digitalWrite(_pin, HIGH);
}

//clignotement led
void ledindicator::blink() {
  for(int i; i<2; i++) {
    digitalWrite(_pin, HIGH);
    delay(_delay);
    digitalWrite(_pin, LOW);
  }
}

//led alumée
void ledindicator::still() {
  digitalWrite(_pin, HIGH);
}
