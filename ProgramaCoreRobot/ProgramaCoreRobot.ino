#include <VirtualWire.h>

char recebido_RF_char[2]; 

//pinos ponte h primaria
int INA1 = 4;
int INA2 = 5;
int INB3 = 6;
int INB4 = 7;

//pinos ponte h secundaria
int INA21 = 8;
int INA22 = 9;
int INB23 = 10;
int INB24 = 11;

void setup(){
 
  Serial.begin(9600);
  vw_set_rx_pin(2);//Pino ligado ao pino DATA do receptor RF
  
  vw_setup(2000); //Velocidade de comunicacao (bits por segundo)
  
  vw_rx_start();  //Inicia a recepcao

 pinMode(INA1, OUTPUT);
 pinMode(INA2, OUTPUT);
 pinMode(INB3, OUTPUT);
 pinMode(INB4, OUTPUT);

 pinMode(INA21, OUTPUT);
 pinMode(INA22, OUTPUT);
 pinMode(INB23, OUTPUT);
 pinMode(INB24, OUTPUT);
}

void loop(){
  
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;
    
    if (vw_get_message(buf, &buflen)){
      
    int i;
    
        for (i = 0; i < buflen; i++){            
          recebido_RF_char[i] = char(buf[i]);//Armazena os caracteres recebidos
       }
       
       recebido_RF_char[buflen] = '\0';


    if(recebido_RF_char[0]=='f' && recebido_RF_char[1] == 't'){
      front();
    }

     if(recebido_RF_char[0]=='r' && recebido_RF_char[1] == 'g'){
      right();
    }

     if(recebido_RF_char[0]=='l' && recebido_RF_char[1] == 'f'){
      left();
    }

     if(recebido_RF_char[0]=='b' && recebido_RF_char[1] == 'd'){
      behind();
    }

    
    delay(500);
 }

  digitalWrite(INA1, HIGH);
  digitalWrite(INA2, HIGH);

 digitalWrite(INB3, HIGH);
 digitalWrite(INB4, HIGH);

 
  digitalWrite(INA21, HIGH);
  digitalWrite(INA22, HIGH);

 digitalWrite(INB23, HIGH);
 digitalWrite(INB24, HIGH);
}


void behind (){
  digitalWrite(INA1, HIGH);
  digitalWrite(INA2, LOW);

  digitalWrite(INB3, HIGH);
  digitalWrite(INB4, LOW);

   digitalWrite(INA21, HIGH);
  digitalWrite(INA22, LOW);

  digitalWrite(INB23, HIGH);
  digitalWrite(INB24, LOW);
}

void front (){

digitalWrite(INA1, LOW);
  digitalWrite(INA2, HIGH);

  digitalWrite(INB3,LOW );
  digitalWrite(INB4,HIGH );

   digitalWrite(INA21,LOW);
  digitalWrite(INA22, HIGH);

  digitalWrite(INB23, LOW);
  digitalWrite(INB24, HIGH);
  
}


void left (){
  
digitalWrite(INA1,HIGH );
  digitalWrite(INA2,LOW );

  digitalWrite(INB3,LOW );
  digitalWrite(INB4,HIGH );

   digitalWrite(INA21,HIGH);
  digitalWrite(INA22, LOW);

  digitalWrite(INB23, LOW);
  digitalWrite(INB24, HIGH);
  
}

void right (){
    
digitalWrite(INA1,LOW );
  digitalWrite(INA2,HIGH );

  digitalWrite(INB3,HIGH);
  digitalWrite(INB4, LOW );

   digitalWrite(INA21,LOW);
  digitalWrite(INA22,HIGH);

  digitalWrite(INB23, HIGH);
  digitalWrite(INB24,LOW );
}

