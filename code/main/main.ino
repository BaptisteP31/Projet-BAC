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
#include "led_indicator.h"
#include "buzzer_indicator.h"
#include "remote.h"

//On crée un tableau contenant l'ensemble des pins relatifs aux moteurs
const int E1=3, M1=14, E2=10, M2=15, E3=11, M3=16, E4=9, M4=17; 
int pins[8] = {E1, M1, E2, M2, E3, M3, E4, M4};

//Objets ledR, ledG de la classe ledindicator, delai de 200ms
ledindicator ledR(13, 200); ledindicator ledG(21, 200);

//Objet bz de la classe buzzerindicator
buzzerindicator bz(23, 200);

//Objet hb de la classe hbridge
hbridge hb(pins, 200);


void setup() {
  Serial.begin(9600);
  ledG.still();
  RemoteXY_Init ();
}


void loop() {

  RemoteXY_Handler ();

    if (RemoteXY.foward) {
      
      //Petit pas en avant
      hb.step_foward();
      ledR.blink();
      
    } else if (RemoteXY.backward) {
      
      //Petit pas en arrière
      hb.step_backward();
      ledR.blink();

      
    } else if (RemoteXY.right) {

      //à droite
      hb.right();
      ledR.blink();
      
    } else if (RemoteXY.left) {

      //à gauche
      hb.left();
      ledR.blink();
      
    } else if (RemoteXY.start) {

      //Activation des moteurs
      hb.start();
      ledR.blink();

    } else if (RemoteXY.stop) {

      //arrêt des moteurs
      hb.stop();
      ledR.blink();
      
    } else if (RemoteXY.vitessem) {

      //Vitesse -10
      hb.vitessem();
      ledR.blink();
      
    } else if (RemoteXY.vitessep) {

      //Vitesse +10
      hb.vitessep();
      ledR.blink();

      
    } else if (RemoteXY.step_foward) {

      hb.step_foward();
      ledR.blink();
      
      
    } else if (RemoteXY.step_backward) {

      hb.step_backward();
      ledR.blink();
      
    }

    
    
}
