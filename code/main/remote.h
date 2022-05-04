#ifndef REMOTEXY_MODE__SOFTSERIAL
#define REMOTEXY_MODE__SOFTSERIAL
#include <SoftwareSerial.h>

#include <RemoteXY.h>

// RemoteXY connection settings 
#define REMOTEXY_SERIAL_RX 2
#define REMOTEXY_SERIAL_TX 3
#define REMOTEXY_SERIAL_SPEED 9600


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =   // 88 bytes
  { 255,7,0,0,0,81,0,16,24,0,130,1,7,32,20,20,17,1,0,14,
  33,6,6,2,31,0,1,0,14,45,6,6,2,31,0,1,0,20,39,6,
  6,2,31,0,1,0,8,39,6,6,2,31,0,2,0,45,3,11,5,2,
  26,31,31,79,78,0,79,70,70,0,1,0,84,46,8,8,6,31,0,1,
  0,84,34,8,8,1,31,0 };
  
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

#endif