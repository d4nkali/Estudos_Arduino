/*

  Modulo de temperatura e umidade DHT11 calculcando o Ponto de Orvalho
  Autor: d4nkali 26/01/24 v1.0

*/

#include "dht.h" // Incluir a biblioteca dht.h

const int pinoDHT11 = A2; // Pino analógico 2 utilizado pelo DHT11

dht DHT; // Chama a configuração DHT

void setup() {

  Serial.begin(9600); // Inicia a comunicação serial
  delay(2000); // Atraso de 2 segundos

}

void loop() {

  float temperatura = DHT.temperature; // Ler a temperatura e armazena na variavel
  float umidade = DHT.humidity; // Ler a umidade e armazena na variavel

  float orvalho = temperatura - (100 - umidade) / 5; // Faz o calculo do Ponto de Orvalho e armazena na variavel

  DHT.read11(pinoDHT11); // Ler o sensor
  Serial.print("Umidade: "); // Imprime o texto "Umidade"
  Serial.print(umidade, 0); // Imprime a umidade
  Serial.print("%"); // Imprime "%"
  Serial.print(" / Temperatura: "); // Imprime a palavra "temperatura"
  Serial.print(temperatura, 0); // Imprime a temperatura 
  Serial.print("*C"); // Imprime "*C"
  Serial.print(" / Ponto de Orvalho: "); // Imprime a palavra "ponto de orvalho"
  Serial.print(orvalho, 0); // Imprime a temperatura do ponto de orvalho
  Serial.println("*C"); // Imprime "*C"
  delay(2000); // Intervalo de 2 segundos  
  // OBS: Não diminuir esse valor de 2 segundos

}

// FIM!