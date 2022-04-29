#include "hbridge.h"
#include "led_indicator.h"
#include "buzzer_indicator.h"

//On crée un tableau contenant l'ensemble des pins relatifs aux moteurs
const int E1=3, M1=14, E2=10, M2=15, E3=11, M3=16, E4=9, M4=17; 
const int pins[8] = {E1, M1, E2, M2, E3, M3, E4, M4};

//Objets ledR, ledG de la classe ledindicator, delai de 200ms
ledindicator ledR(20, 200); ledindicator ledG(21, 200);

//Objet bz de la classe buzzerindicator
buzzerindicator bz(23, 200);

//Objet hb de la classe hbridge
hbridge hb(pins, 200);


void setup() {
  Serial.begin(9600);
  ledG.still();
}


void loop() {

  //On lit l'entrée serial et on la sauvegarde dans input
  char input = Serial.read();

  //On agit en fonction de l'input
    switch(input) {

      //indication led rouge, indication buzzer, activation moteurs
    case '1': 
      ledR.blink();
      bz.validated();
      hb.start();
      Serial.println("Avancer!");
      break;
      
    //indication led rouge, indication buzzer, arrêt moteurs
    case '0':
      ledR.blink();
      bz.validated();
      hb.stop();
      Serial.println("Stop!");
      break;
      
    //augmentation de vitesse
    case '+':
      hb.vitessep();
      ledR.blink();
      break;

    //réduction de vitesse
    case '-':
      hb.vitessem();
      ledR.blink();
      break;

    //tourne à gauche
    case 'l': //L à ne pas confondre avec 1
      hb.left();
      ledR.blink();
      bz.validated();
      Serial.println("Gauche !");
      delay(200);
      hb.stop();
      break;

    //tourne à droite
    case 'r':
      hb.right();
      ledR.blink();
      Serial.println("Droite !");
      delay(200);
      hb.stop();
      break;
    
    default:
      break;
      
    }
}