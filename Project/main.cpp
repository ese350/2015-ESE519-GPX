// To notify the Distress Call from Room

#include "mbed.h"
#include <string>
#include "xbee_sr.h"
#include "joystick.h"
#include<stdio.h>


int main()
{
    xbee.baud(19200);
    send_button.rise(&press);           // Detect the joystick press
    pc.printf("Press Joystick to send request.\r\n");
    while(1) {
        receive();              // Receiver funtion        

    }
}
