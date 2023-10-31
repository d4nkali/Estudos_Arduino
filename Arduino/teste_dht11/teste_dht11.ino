// Teste do modulo de temperatura e umidade dht11 

#include "dht.h" // Incluir a biblioteca dht.h

const int pinoDHT11 = A2; // Pino analógico utilizado pelo dht11

dht DHT; // Chama a variavel DHT

void setup() {

  Serial.begin(9600); // Inicia a comunicação serial
  delay(2000); // Delay de 2 segundos

}

void loop() {

  DHT.read11(pinoDHT11); // Ler o sensor
  Serial.print("Umidade: "); // Imprime o texto "Umidade"
  Serial.print(DHT.humidity); // Imprime a umidade
  Serial.print("%"); // Imprime "%"
  Serial.print(" / Temperatura: "); // Imprime a palavra "temperatura"
  Serial.print(DHT.temperature, 0); // Imprime a temperatura do sensor
  Serial.println("*C"); // Imprime "*C"
  delay(2000); // Intervalo de 2 segundos  
  // OBS: Não diminuir esse valor de 2 segundos

}