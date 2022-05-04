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
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// RemoteXY select connection mode and include library 
#ifndef REMOTEXY_MODE__HARDSERIAL
#define REMOTEXY_MODE__HARDSERIAL

#include <RemoteXY.h>

// RemoteXY connection settings 
#define REMOTEXY_SERIAL Serial
#define REMOTEXY_SERIAL_SPEED 9600


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =   // 81 bytes
  { 255,7,0,0,0,74,0,16,24,0,1,0,14,31,8,8,2,31,0,1,
  0,14,45,8,8,2,31,0,1,0,21,38,8,8,2,31,0,1,0,7,
  38,8,8,2,31,0,2,0,45,3,11,5,2,26,31,31,79,78,0,79,
  70,70,0,1,0,84,46,8,8,6,31,0,1,0,84,34,8,8,1,31,
  0 };
  
// this structure defines all the variables and events of your control interface 
struct {

  // input variables
  uint8_t haut; // =1 if button pressed, else =0 
  uint8_t bas; // =1 if button pressed, else =0 
  uint8_t droite; // =1 if button pressed, else =0 
  uint8_t gauche; // =1 if button pressed, else =0 
  uint8_t switch_1; // =1 if switch ON and =0 if OFF 
  uint8_t vitesse_m; // =1 if button pressed, else =0 
  uint8_t vitesse_p; // =1 if button pressed, else =0 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

#endif