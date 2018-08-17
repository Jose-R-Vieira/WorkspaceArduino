#include <VirtualWire.h>

//armazena o valor do comando recebido
char recebido_RF_char[2];

//pinos ponte H1
int INH11 = 4;
int INH12 = 5;
int INH13 = 6;
int INH14 = 7;

//pinos ponte H2 secundaria
int INH21 = 8;
int INH22 = 9;
int INH23 = 10;
int INH24 = 11;

void setup() {

  Serial.begin(9600);
  
  //Pino ligado ao pino DATA do receptor RF
  vw_set_rx_pin(2);
  //Pino ligado ao pino DATA do receptor RF
  vw_setup(2000);
  //Inicia a recepcao
  vw_rx_start();  

 //setando valor dos pinos como saida de dados
 pinMode(INH11, OUTPUT);
 pinMode(INH12, OUTPUT);
 pinMode(INH13, OUTPUT);
 pinMode(INH14, OUTPUT);
 //setando o valor dos pinos como saida de dados
 pinMode(INH21, OUTPUT);
 pinMode(INH22, OUTPUT);
 pinMode(INH23, OUTPUT);
 pinMode(INH24, OUTPUT);
}

void loop() {

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
       Serial.print("F");
    }

     if(recebido_RF_char[0]=='r' && recebido_RF_char[1] == 'g'){
      right();
       Serial.print("R");
    }

     if(recebido_RF_char[0]=='l' && recebido_RF_char[1] == 'f'){
      left();
       Serial.print("L");
    }

     if(recebido_RF_char[0]=='b' && recebido_RF_char[1] == 'd'){
      behind();
      Serial.print("B");
    }
    }
      
      digitalWrite(INH11, HIGH);
      digitalWrite(INH12, HIGH);

      digitalWrite(INH13, HIGH);
      digitalWrite(INH14, HIGH);

 
      digitalWrite(INH21, HIGH);
      digitalWrite(INH22, HIGH);

      digitalWrite(INH23, HIGH);
      digitalWrite(INH24, HIGH);
      delay(2000);
}


void right (){
  
  digitalWrite(INH11,LOW );
  digitalWrite(INH12,HIGH );

  digitalWrite(INH13,LOW );
  digitalWrite(INH14, HIGH);

   digitalWrite(INH21,HIGH);
  digitalWrite(INH22, LOW);

  digitalWrite(INH23,HIGH);
  digitalWrite(INH24,LOW  );
}

void left (){
 
  digitalWrite(INH11,HIGH );
  digitalWrite(INH12,LOW );

  digitalWrite(INH13,HIGH );
  digitalWrite(INH14,LOW );

   digitalWrite(INH21,LOW);
  digitalWrite(INH22,HIGH );

  digitalWrite(INH23,LOW );
  digitalWrite(INH24, HIGH);
  
}


void behind (){
  
  digitalWrite(INH11,LOW );
  digitalWrite(INH12,HIGH );

  digitalWrite(INH13,HIGH );
  digitalWrite(INH14,LOW );

   digitalWrite(INH21,HIGH);
  digitalWrite(INH22, LOW);

  digitalWrite(INH23,LOW );
  digitalWrite(INH24, HIGH);
  
}

void front (){
  
 digitalWrite(INH11,HIGH );
  digitalWrite(INH12,LOW );

  digitalWrite(INH13,LOW );
  digitalWrite(INH14,HIGH );

   digitalWrite(INH21,LOW);
  digitalWrite(INH22, HIGH);

  digitalWrite(INH23, HIGH);
  digitalWrite(INH24, LOW);
}

