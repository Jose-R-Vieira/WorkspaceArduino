#include <VirtualWire.h>

char T_C_LED[2];         //Armazena o estado do LED
int sensorVal = 1;
  
void setup(){
  
  Serial.begin(9600);
  vw_set_tx_pin(7); // pino de dados do transmissor 
  vw_setup(2000);   // taxa de transmissao por segundo em bits

  pinMode(8, INPUT_PULLUP);  // lendo botao
  pinMode(9, INPUT_PULLUP);  // lendo botao
  pinMode(13, INPUT_PULLUP); // lendo botao
  pinMode(12, INPUT_PULLUP); // lendo botao
  
}
 
void loop(){

   sensorVal = digitalRead(12);

    while(sensorVal == 0){
     
     T_C_LED[0] = 'f';
     T_C_LED[1] = 't';
     Serial.println(T_C_LED[0]);
     Serial.println(T_C_LED[1]);
     
     send(T_C_LED);
     
     send(T_C_LED);

      sensorVal = 1;
  }
  
  sensorVal = digitalRead(8);
  
  while(sensorVal == 0){

     T_C_LED[0] = 'l';
     T_C_LED[1] = 'f';
     Serial.println(T_C_LED[0]);
     Serial.println(T_C_LED[1]);
     
     send(T_C_LED);

     sensorVal = 1;
  }
  
  sensorVal = digitalRead(9);

    while(sensorVal == 0){
      
     T_C_LED[0] = 'b';
     T_C_LED[1] = 'd';
     Serial.println(T_C_LED[0]);
     Serial.println(T_C_LED[1]);
     
     send(T_C_LED);

      sensorVal = 1;
  }
  
  sensorVal = digitalRead(13);

  while(sensorVal == 0){
     T_C_LED[0] = 'r';
     T_C_LED[1] = 'g';
     Serial.println(T_C_LED[0]);
     Serial.println(T_C_LED[1]);
     
     send(T_C_LED);
      sensorVal = 1;
  }
  
} 
 
void send (char *mensagem)
{
  vw_send((uint8_t *)T_C_LED, strlen(T_C_LED)); //Envia os dados
  vw_wait_tx(); // Aguarda o envio de dados
}
