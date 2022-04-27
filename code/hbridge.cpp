#include "hbridge.h"
#include "buzzer_indicator.h"
#include "led_indicator.h"

#include <Arduino.h>

hbridge::hbridge(int pins[], int speed) {

  buzzerindicator _bz(23, 200);
  ledindicator _ledR(20, 200); ledindicator(21, 200);

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
    Serial.print("Pin : ");
    Serial.println(_pins[i]);
  
  }
  
  //PWM de tous les pins pairs à speed
  for(int i = 0; i < 8; i++) {
    if(i%2 == 0) {
      analogWrite(_pins[i], _speed);
    }
  }
}


void hbridge::start() {
  
  //PWM de tous les pins pairs à speed
  for(int i = 0; i < 8; i++) {
    if(i%2 == 0) {
      analogWrite(_pins[i], _speed);
    }
  }
}

void hbridge::stop() {

  //PWM de tous les pins pairs à speed
   for(int i = 0; i < 8; i++) {
    if(i%2 == 0) {
      analogWrite(_pins[i], 0);
    }
  }
}


void hbridge::vitessep() {

  //Si la vitesse est inférieure à 250 (maximum du PWM)
  if(_speed < 250) {
     _speed += 10;
     Serial.print("Vitesse : ");
     Serial.println(_speed);
     //buzzer('y');
     
  } else {
     Serial.println("Vitesse trop haute!");
     //buzzer('n');
  }
  
  hbridge::start();
}


void hbridge::vitessem() {

  //Si la vitesse est supérieure à 80 (sinon coupure moteur)
   if(_speed > 100) {
     _speed -= 10;
     Serial.print("Vitesse : ");
     Serial.println(_speed);
     //buzzer('y');

  } else {
     Serial.println("Vitesse trop basse !");
     //buzzer('n');
  }
  
  hbridge::start();
}


void hbridge::avancer() {
  for(int i = 0; i < 8; i++) {
    if(i%2 != 0) {
      digitalWrite(_pins[i], HIGH);
      }
  } 
}


void hbridge::reculer() {
  for(int i = 0; i < 8; i++) {
    if(i%2 != 0) {
      digitalWrite(_pins[i], HIGH);
      }
  }
}


void hbridge::gauche() {
  digitalWrite(_pins[1], LOW);
  digitalWrite(_pins[3], HIGH);
  digitalWrite(_pins[5], LOW);
  digitalWrite(_pins[8], HIGH);
}


void hbridge::droite() {
  digitalWrite(_pins[1], HIGH);
  digitalWrite(_pins[3], LOW);
  digitalWrite(_pins[5], HIGH);
  digitalWrite(_pins[8], LOW);
}
