/* 
 * This file is part of the Projet-BAC (https://github.com/BaptisteP31/Projet-BAC).
 * Copyright (c) 2022 Paqueriaud Baptiste.
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

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
