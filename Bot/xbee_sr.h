// To support Xbee Transmission and Reception

#ifndef XBEE_SR_H 
#define XBEE_SR_H
#include "Motor.h"

Serial xbee(p9, p10);       // Serial port for xbee communication 
Serial pc(USBTX, USBRX);

// Motors for left and right wheels on the bot

Motor m_left(p23,p5,p6);
Motor m_right(p22,p7,p8);

// Transmitter for bot

void bot_transmit(char key[]){
        pc.printf("Sending...%s\r\n",key);
        //xbee.putc(key);     
        xbee.puts(key);                         // Send the character array 
       } 
       
 
// Receiver for bot  

void bot_receive(){      
        
        if(xbee.readable()){
            int direction = xbee.getc();    // Receive the direction from the controller
            
            switch(direction){
               case 0 :             // Stop the bot
               m_left.speed(0);
               m_right.speed(0);  
               break;
               
               case 1 :             // Move the bot forward
               pc.printf("Move forward\r\n");
               m_left.speed(0.5);
               m_right.speed(0.5);      
               break;
               
               case 2 :             // Move the bot backward
               pc.printf("Move backward\r\n");
               m_left.speed(-0.5);
               m_right.speed(-0.5);
               break;
               
               case 3 :             // Take a left turn
               pc.printf("Move left\r\n");
               m_left.speed(0.2);
               m_right.speed(0.5); 
               break;
               
               case 4:               // Take a right turn
               pc.printf("Move Right\r\n");
               m_left.speed(0.5);
               m_right.speed(0.2);
               break;
               }   
            
            }    
       }
       
       
#endif

