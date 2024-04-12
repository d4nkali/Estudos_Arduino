// Teste de importar dados do Arduino via monitor serial para o computador por um arquivo csv

#include "dht.h" // Incluir a biblioteca dht.h

const int pinoDHT11 = A2; // Pino analógico utilizado pelo dht11

dht DHT; // Chama a variável DHT

void setup() {

  Serial.begin(9600); // Inicia a comunicação serial
  delay(2000); // Delay de 2 segundos

}

void loop() {

  DHT.read11(pinoDHT11); // Ler o sensor
  Serial.print(DHT.humidity, 0); // Imprime a umidade
  Serial.print("%"); // Imprime '%'
  Serial.print(","); // Imprime ','
  Serial.print(DHT.temperature, 0); // Imprime a temperatura
  Serial.println("*C"); // Imprime '*C'
  delay(2000); // Intervalo de 2 segundos
  // OBS: Não diminuir esse valor de 2 segundos

}
