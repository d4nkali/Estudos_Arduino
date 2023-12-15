/*

 Programa de medição de luz(LDR) e Umidade com temperatura(DHT11) 
 Autor: d4nkali 01/02/2023 ver: 0.1

*/ 

// Inclusão das bibliotecas

 #include "dht.h" //Incluir a biblioteca dht.h

// Definir os pinos

 const int pinDHT11 = A2; //Pino A2 sera o do sensor de temperatura
 const int pinLDR = A0; //Pino A0 sera o do sensor de luminozidade
 int luz = 0; //Cria a variavel luz
 
// Traz a variavel da biblioteca

 dht DHT; 

void setup(){ // Programação inicial

  Serial.begin(9600); //Inicia a comunicação serial
  pinMode(pinLDR, INPUT); //Coloca o LDR como entrada de informação
  delay(2000); // Aguarda de 2 segundos para carregar as informações
  
}

void loop(){ // Programação principal

  DHT.read11(pinDHT11); // Lê as informações do sensor de temperatura
  Serial.print("Umidade: ");  // Imprime o texto "Umidade"
  Serial.print(DHT.humidity); // Imprime no monitor o valor de umidade medido
  Serial.print("%");  // Imprime o "%"
  Serial.print(" / Temperatura: ");  // Imprime o texto "Temperatura"
  Serial.print(DHT.temperature, 0); // Imprime no monitor o valor de temperatura medido e remove a parte decimal
  Serial.print("*C"); // Imprime o "*C"
  luz=analogRead(pinLDR); // Lê as informações do sensor de luminozidade
  Serial.print(" / Luz: "); // Imprime o texto "luz"
  Serial.print(luz); // Ler e imprime o valor do LDR
  Serial.println("L"); // Imprime o "L"
  delay(2000); // Intervalo de 2 segundos. 
  //OBS: Não diminuir esse valor até 2000

}

// FIM!