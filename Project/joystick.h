#ifndef JOYSTICK_H 
#define JOYSTICK_H
#include "xbee_sr.h"
 

InterruptIn send_button(p14);

void press(){    
    transmit("AROOM 1E");           // A and E as start and stop characters 
    }

#endif