/*

  Modulo de temperatura e umidade DHT11 calculcando o Ponto de Orvalho
  Autor: d4nkali 26/01/24 v1.0

*/

#include "dht.h" // Incluir a biblioteca dht.h

const int pinoDHT11 = A2; // Pino analógico 2 utilizado pelo DHT11

dht DHT; // Chama as funções da biblioteca DHT

void setup() {

  Serial.begin(9600); // Inicia a comunicação serial
  delay(2000); // Atraso de 2 segundos

}

void loop() {

  float temperatura = DHT.temperature; // Ler a temperatura e armazena na variavel
  float umidade = DHT.humidity;  // Ler a umidade e armazena na variavel

  float sensacaoTermica =13.12 + 0.6215 * temperatura - 11.37 * pow(umidade, 0.16) + 0.3965 * temperatura * pow(umidade, 0.16); // Calculo da sensação termica e armazena na variavel

  DHT.read11(pinoDHT11); // Ler o sensor
  Serial.print("Umidade: "); // Imprime o texto "Umidade"
  Serial.print(umidade, 0); // Imprime a umidade
  Serial.print("%"); // Imprime "%"
  Serial.print(" / Temperatura: "); // Imprime a palavra "temperatura"
  Serial.print(temperatura, 0); // Imprime a temperatura do sensor
  Serial.print("*C"); // Imprime "*C"
  Serial.print(" / Sensação Termica: "); // Imprime a palavra "Sensação Termica"
  Serial.print(sensacaoTermica, 0); // Imprime a senssação termica 
  Serial.println("*C"); // Imprime "*C"
  delay(2000); // Intervalo de 2 segundos  
  // OBS: Não diminuir esse valor de 2 segundos

}

// FIM!