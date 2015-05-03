// Scanning Keypad

// Column pins
DigitalOut column1(p13);
DigitalOut column2(p15);
DigitalOut column3(p16);
DigitalOut column4(p17);


// Row pins
InterruptIn row2(p11);
InterruptIn row3(p12);
InterruptIn row4(p14);
InterruptIn row1(p18);

Ticker column_scan;

volatile int row_set = 1;

bool sent = 0;              // To avoid multiple transmission of same key

// Scan the rows at 4 ms interval

void scan(){
    row_set++;
    if(row_set>4){
        row_set = 1;
        }
            
     switch(row_set){
        case 1 : 
            column1 = 0;
            column2 = 1;
            column3 = 1;
            column4 = 1; 
            break;
        case 2 : 
            column1 = 1;
            column2 = 0; 
            column3 = 1;
            column4 = 1;
            break;
        case 3 : 
            column1 = 1;
            column2 = 1; 
            column3 = 0;
            column4 = 1;
            break;
        case 4 : 
            column1 = 1;
            column2 = 1; 
            column3 = 1;
            column4 = 0;
            break;
            
        default : break;        
        }     
    
    }

//ISR for row 1 fall interrupt   
void column1_fall(){
    column_scan.detach();
    if(row_set==1 && sent == 0){        
        pc.printf("1\r\n");
        bot_transmit("K1");                 // Send K as an indication for keypad input at receiver side
        sent = 1;      
        }
    else if(row_set==2 && sent == 0){        
        pc.printf("2\r\n");
        bot_transmit("K2");
        sent = 1;        
        }
    else if(row_set==3 && sent == 0){        
        pc.printf("3\r\n");
        bot_transmit("K3"); 
        sent = 1;       
        }
    else if(row_set==4 && sent == 0){        
        pc.printf("A\r\n");
        sent = 1;        
        }    
    column1 = 1;
    column2 = 1;
    column3 = 1;
    column4 = 1; 
    
    }
    
//ISR for row 2 fall interrupt 
void column2_fall(){
    column_scan.detach();
    if(row_set==1 && sent == 0){        
        pc.printf("4\r\n");
        bot_transmit("K4");  
        sent = 1;                     
        }
    else if(row_set==2 && sent == 0){        
        pc.printf("5\r\n");
        bot_transmit("K5"); 
        sent = 1;               
        }
    else if(row_set==3 && sent == 0){        
        pc.printf("6\r\n");
        bot_transmit("K6");    
        sent = 1;          
        }
    else if(row_set==4 && sent == 0){        
        pc.printf("B\r\n");  
        sent = 1;                    
        }
    
    column1 = 1;
    column2 = 1;
    column3 = 1;
    column4 = 1; 
    
    }


//ISR for row 3 fall interrupt 
   
void column3_fall(){
    column_scan.detach();
    if(row_set==1 && sent == 0){
        pc.printf("7\r\n");
        bot_transmit("K7");   
        sent = 1;            
        }
    else if(row_set==2 && sent == 0){       
        pc.printf("8\r\n");
        bot_transmit("K8");   
        sent = 1;           
        }
    else if(row_set==3 && sent == 0){        
        pc.printf("9\r\n");
        bot_transmit("K9");  
        sent = 1;                
        }
    else if(row_set==4 && sent == 0){        
        pc.printf("C\r\n"); 
        sent = 1;               
        }
      
    column1 = 1;
    column2 = 1;
    column3 = 1;
    column4 = 1; 
    
    }


//ISR for row 4 fall interrupt 
  
void column4_fall(){
    column_scan.detach();
    if(row_set==1 && sent == 0){
        pc.printf("*\r\n");
        sent = 1;        
        }
    else if(row_set==2 && sent == 0){
        pc.printf("0\r\n");
        bot_transmit("K0"); 
        sent = 1;       
        }
    else if(row_set==3 && sent == 0){
        pc.printf("#\r\n");
        sent = 1;        
        }
    else if(row_set==4 && sent == 0){
        pc.printf("D\r\n");     
        sent = 1;   
        }
    // Set the default values again.
    column1 = 1;
    column2 = 1;
    column3 = 1;
    column4 = 1; 
    }

// To attach the ticker for rising interrupt from keypad
void column_rise(){
    column_scan.attach(&scan,0.004); 
    sent = 0;
    }
    

void keypadInit(){
    
    // Initialize the digital columns as 1
    column1 = 1;
    column2 = 1;
    column3 = 1;
    column4 = 1;

    
    //Fall scan for interrurt from keypad
    row1.fall(&column1_fall);
    row2.fall(&column2_fall);
    row3.fall(&column3_fall);
    row4.fall(&column4_fall);  
    
    //Rise scan for interrurt from keypad
    row1.rise(&column_rise);
    row2.rise(&column_rise);
    row3.rise(&column_rise);
    row4.rise(&column_rise);  
    
    column_scan.attach(&scan,0.004);        // Ticker attached for scanning columns of keypad   
    }