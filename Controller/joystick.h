#ifndef JOYSTICK_H 
#define JOYSTICK_H
#include "xbee_sr.h"
 
BusIn joystick_dr(p15,p12,p13,p16);

// To detect the joystick movement

int joystick_move(){    
    switch(joystick_dr) {
            case 0x1:                   // p15 is 1
                pc.printf("Forward\r\n");
                return 1;               // Return 1 for Up
                
            case 0x2:                   // p12 is 1
                pc.printf("Backward\r\n");
                return 2;               // Return 2 for down
            
            case 0x4:                   // p13 is 1
                pc.printf("Left\r\n");
                return 3;               // Return 3 for left
                
            case 0x8:                   // p16 is 1  
                pc.printf("Right\r\n");
                return 4;               // Return 4 for Right  
            
            default :
                //pc.printf("Stop\r\n");
                return 0;   
        }
        
    }

#endif