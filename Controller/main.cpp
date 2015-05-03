#include "mbed.h"
#include "xbee_sr.h"
#include "joystick.h"

// Ticker for sending the joystick directions
Ticker send;            

// ISR for ticker 
void transmitter(){
    transmit(joystick_move());      // Transmit the direction        
    }

int main() {
    lcd.cls();
    send.attach(&transmitter,0.09);
    xbee.baud(38400);                   // Set the baud rate for xbee
    while(1) {      
        receive();                      // Receiver function
    }
}
