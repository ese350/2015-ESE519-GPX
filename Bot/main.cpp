#include "mbed.h"
#include "xbee_sr.h"
#include "keypad.h"

void initialize(){       
    xbee.baud(38400);                   // Set the baud rate of xbee 
    keypadInit();                       // Initialize the keypad
    
    }

int main() {
    initialize();      
   
    while(1) {
        bot_receive();
        
    }
}
