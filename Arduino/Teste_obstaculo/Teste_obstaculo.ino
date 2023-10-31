/*
Teste com Sensor de obstaculo infravermelho
*/

const int pininfra = 8; //Sensor no pino 8
const int pinLed = 13; //Led no pino 13
const int pinsom = 12; //Buzer no pino 12
int obst = 0;

void setup() {
Serial.begin(9600);    
pinMode(pininfra, INPUT); //Sensor como entrada
pinMode(pinLed, OUTPUT); //Led como saida
pinMode(pinsom, OUTPUT); //buzzer como saida

}

void loop() {

obst=digitalRead(pininfra);
Serial.print("Obstaculo");
Serial.println(obst);

  if (digitalRead(pininfra) == LOW){ //Se o sensor for 0 entao
    
  digitalWrite(pinLed, HIGH); //Ligar led
  tone(pinsom, 1200, 1000); //Tocar buzzer
  
  }
  
  else{ //senão
    
 digitalWrite(pinLed, LOW); //Desligar led
 noTone(pinsom); //Desligar buzzer

  }
  
}
