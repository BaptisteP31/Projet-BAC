#include "buzzer_indicator.h"
#include <Arduino.h>

//Constructeur, pin de le led
  buzzerindicator::buzzerindicator(int pin, int delay) {
  _pin = pin; 
  _delay = delay;
  pinMode(_pin, OUTPUT);
}

//deux bips en cas d'erreur
void buzzerindicator::error() {
  for(int i; i<2; i++) {
    digitalWrite(_pin, HIGH);
    delay(_delay);
    digitalWrite(_pin, LOW);
  }
}

//un bip pour la validation
void buzzerindicator::validated() {
  digitalWrite(_pin, HIGH);
  delay(_delay);
  digitalWrite(_pin, LOW);
}
