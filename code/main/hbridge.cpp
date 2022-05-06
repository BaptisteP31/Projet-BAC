/* 
+-----------------------------------------------------------------------------------+
| * This file is part of the Projet-BAC (https://github.com/BaptisteP31/Projet-BAC).|
| * Copyright (c) 2022 Paqueriaud Baptiste.                                         |
| *                                                                                 |
| * This program is free software: you can redistribute it and/or modify            |
| * it under the terms of the GNU General Public License as published by            |
| * the Free Software Foundation, version 3.                                        |
| *                                                                                 |
| * This program is distributed in the hope that it will be useful, but             |
| * WITHOUT ANY WARRANTY; without even the implied warranty of                      |
| * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU                |
| * General Public License for more details.                                        |
| *                                                                                 |
| * You should have received a copy of the GNU General Public License               |
| * along with this program. If not, see <http://www.gnu.org/licenses/>.            |
+-----------------------------------------------------------------------------------+
                                                                                     
 */

#include "hbridge.h"
#include "buzzer_indicator.h"

#include <Arduino.h>

buzzerindicator _bz(23, 200);


//constructeur de la classe
hbridge::hbridge(int pins[], int speed) {
  _speed = speed;

  for(int i; i < 8; i++) {
	  _pins[i]=pins[i];
  }

  //définition pins en OUTPUT
  for(int i = 0; i < 8; i++)  {
    pinMode(_pins[i], OUTPUT);

    //Les pins impairs sont mis à l'état haut
    if(i%2 != 0) {
      digitalWrite(_pins[i], HIGH);  
    }
    
    //liste des pins print dans la console
    //Serial.print("Pin : ");
    //Serial.println(_pins[i]);
  
  }
  
  //PWM de tous les pins pairs à speed
  for(int i = 0; i < 8; i++) {
    if(i%2 == 0) {
      analogWrite(_pins[i], _speed);
    }
  }
}

//demarrage des moteurs 
void hbridge::start() {
  
  //PWM de tous les pins pairs à speed
  for(int i = 0; i < 8; i++) {
    if(i%2 == 0) {
      analogWrite(_pins[i], _speed);
    }
  }
}

//arrêt des moteurs
void hbridge::stop() {

  //PWM de tous les pins pairs à speed
   for(int i = 0; i < 8; i++) {
    if(i%2 == 0) {
      analogWrite(_pins[i], 0);
    }
  }
}


//augmentation de vitesse
void hbridge::vitessep() {

  //Si la vitesse est inférieure à 250
  if(_speed < 250) {
     _speed += 10;
     _bz.validated();
     
  } else {
     Serial.println("Vitesse trop haute!");
     _bz.error();
  }
  
  hbridge::start();
}

//diminution de vitesse
void hbridge::vitessem() {

  //Si la vitesse est supérieure à 80 (sinon coupure moteur)
   if(_speed > 100) {
     _speed -= 10;
     _bz.validated();

  } else {
     Serial.println("Vitesse trop basse !");
     _bz.error();
  }
  
  hbridge::start();
}

//pont en H sens avant
void hbridge::foward() {
  for(int i = 0; i < 8; i++) {
    if(i%2 != 0) {
      digitalWrite(_pins[i], HIGH);
      }
  } 
}

//pont en H sens arrière
void hbridge::backward() {
  for(int i = 0; i < 8; i++) {
    if(i%2 != 0) {
      digitalWrite(_pins[i], HIGH);
      }
  }
}

//configuration moteurs pour tourner à gauche
void hbridge::left() {
  digitalWrite(_pins[1], LOW);
  digitalWrite(_pins[3], HIGH);
  digitalWrite(_pins[5], LOW);
  digitalWrite(_pins[7], HIGH);
  hbridge::start();
  delay(200);
  hbridge::stop();

}

//configuration moteurs pour tourner à droite
void hbridge::right() {
  digitalWrite(_pins[1], HIGH);
  digitalWrite(_pins[3], LOW);
  digitalWrite(_pins[5], HIGH);
  digitalWrite(_pins[7], LOW);
  hbridge::start();
  delay(200);
  hbridge::stop();
}

//Petit pas en avant
void hbridge::step_foward() {
  hbridge::foward();
  hbridge::start();
  delay(200);
  hbridge::stop();
}

//Petit pas en arrière
void hbridge::step_backward() {
  hbridge::backward();
  hbridge::start();
  delay(200);
  hbridge::stop();
}
