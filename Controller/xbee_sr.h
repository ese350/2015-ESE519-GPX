// For Xbee Transmission and Reception

#ifndef XBEE_SR_H 
#define XBEE_SR_H

#include "C12832.h"

Serial xbee(p9, p10);   
Serial pc(USBTX, USBRX);
C12832 lcd(p5, p7, p6, p8, p11);  

int inventory = 10;             // Set the inventory to 10. 

// Get the integer value from character 
int getnum(char key){
       return (int(key)-48);       
       }
       
// To transmit the direction to control the bot
void transmit(int direction){
        xbee.putc(direction);       
       }    
       
void receive(){
    if(xbee.readable()){
        char rx = xbee.getc();
        switch(rx){
            // Detetct the keypad input on Bot
            case 'K' :
                char key_press = xbee.getc();       
                pc.printf("%Received number : %d\r\n", getnum(key_press));
                inventory -= getnum(key_press);
                
                // To keep a check on inventory
                if (inventory <= 3 && inventory > 0){
                    lcd.cls();
                    lcd.locate(0,3);
                    lcd.printf("Refill Alert!! Count : %d",inventory);                    
                    }
                if (inventory <= 0){
                    lcd.cls();
                    lcd.locate(0,3);
                    lcd.printf("No more items.");                    
                    }
                break;
                  
            default : break;
            }        
        
        }    
    }

       
#endif

