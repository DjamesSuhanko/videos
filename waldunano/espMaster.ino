unsigned long int last_time = millis(); //temporizador
uint8_t i                   = 0; //exibe na serial

void setup(){
    Serial.begin(9600); //inicia a serial
    delay(2000); //pára por 2 segundos antes do loop
}

void loop(){
    //exibe um valor a cada 3 segundos.
    if ((millis()-last_time) > 3000){
        last_time = millis();
        Serial.println(i);
        i = i>8 ? 0 : i+1;
    }
}
