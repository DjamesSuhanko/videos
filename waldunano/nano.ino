//Esse include é necessário se for programar utilizando o PlatformIO.
#include <Arduino.h>
//Essa biblioteca é necessária para cria a comunicação serial por software.
//Prefira utilizar velocidades baixas nessa comunicação.
#include <SoftwareSerial.h>

//Defina os pinos. TX é Transmissão. Ele deve ir conectado ao RX, que é Recepção
#define SOFT_TX 3
//...e vice-versa.
#define SOFT_RX 2

//Instância de um objeto de comunicação serial, passando os pinos RX/TX como parâmetro.
//Se estiver utilizando outra placa, atente-se ao wiring.
SoftwareSerial SerialESP(SOFT_RX,SOFT_TX);

//Uma variável para guardar a leitura serial.
String values;
uint8_t number = 0;

//Quando a leitura estiver concluída, um boolean libera a impressão na serial.
bool ok = false;

void setup() {
  //inicie ambas as seriais. A serial nativa pode estar na velocidade preferida.
  Serial.begin(9600);
  //A velocidade da softwareserial deve ser a mesma utilizada no ESP-01.
  SerialESP.begin(9600);
  //inicia a string com valor nulo.
  values = "";
}

void loop() {
  /*Se houver dados advindos do ESP-01, lê até que encontre o final de linha.*/
  while (SerialESP.available()){
      
      //values = SerialESP.readStringUntil('\n');
      number = SerialESP.read();
      if (((number-48)%2) == 0 && number != '\n'){
        Serial.println("par");
        Serial.println(number-48);
      }
      else{
        Serial.println("...");
      }
      
      //quando sair desse loop, o boolean garantirá que o valor seja impresso na serial do Arduino.
      ok = true;
  }

 //Se true, o resultado é impresso na serial do Arduino e a variável é zerada.
 if (ok){
     Serial.println(values);
     values = "";
     //garanta que não seja executada essa condicional novamente.
     ok = false;
 }
     //Pode até não ter delay, ou ter um delay mínimo. Por convenção, 1s.
     delay(1000);
}
