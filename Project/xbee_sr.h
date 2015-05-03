// Xbee Transmission and Reception

#ifndef XBEE_SR_H 
#define XBEE_SR_H

#include <string>
#define MAX 15

Serial xbee(p9, p10);   
Serial pc(USBTX, USBRX);

// Transmit the Room number 
void transmit(char tx[]){
       // Check the maximum characters sent
       if(strlen(tx)>MAX){pc.printf("Too long to send. Try Again");}
       else{
           xbee.puts(tx);       
       }    
    }

// Receive the room number   
void receive(){
       char buffer[MAX];
       char rx;

       if(xbee.readable()){//pc.printf("Reading.\r\n");
           int i = 0;          
           rx = xbee.getc();           
           if(rx == 'A'){               
               rx = xbee.getc();
               while(rx !='E'){
                   buffer[i] = rx;      // Store the room number in buffer
                   i++;                   
                   rx = xbee.getc();   
                }  
                pc.printf("%s\r\n",buffer);          
           }             
        }
}
#endif
