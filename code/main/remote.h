/*
   -- REMOTE --
   
   This source code of graphical user interface 
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 3.1.8 or later version 
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                   
     - for ANDROID 4.11.1 or later version;
     - for iOS 1.9.1 or later version;
    
   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

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

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// RemoteXY select connection mode and include library 
#ifndef REMOTEXY_MODE__HARDSERIAL
// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__HARDSERIAL

#include <RemoteXY.h>

// RemoteXY connection settings 
#define REMOTEXY_SERIAL Serial
#define REMOTEXY_SERIAL_SPEED 9600


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =   // 100 bytes
  { 255,8,0,0,0,93,0,16,31,0,1,0,12,26,12,12,2,31,0,1,
  0,12,45,12,12,2,31,0,1,0,1,35,12,12,2,31,0,1,0,23,
  35,12,12,2,31,0,1,0,81,26,12,12,2,31,118,105,116,101,115,115,
  101,95,112,0,1,0,81,47,12,12,2,31,118,105,116,101,115,115,101,95,
  109,0,1,0,36,3,12,12,2,31,0,1,0,51,3,12,12,2,31,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
 uint8_t haut; // =1 if button pressed, else =0 
  uint8_t bas; // =1 if button pressed, else =0 
  uint8_t gauche; // =1 if button pressed, else =0 
  uint8_t droite; // =1 if button pressed, else =0 
  uint8_t vitessep; // =1 if button pressed, else =0 
  uint8_t vitessem; // =1 if button pressed, else =0 
  uint8_t start; // =1 if button pressed, else =0 
  uint8_t stop; // =1 if button pressed, else =0 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

#endif
