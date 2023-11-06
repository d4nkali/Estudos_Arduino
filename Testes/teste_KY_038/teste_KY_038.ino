// Teste do Sensor de som KY-038

//Definicao das variaveis e dos pinos

  const int pino_analogico = A5;  // Define pino A5 como do sensor analogico
  const int pino_digital = 7;     // Define pino 7 como do sensor digital
  const int led = 13;             // Define pino 13 como do led
  int valor_analogico = 0;  // Define a variavel valor_analogico como do sensor analogico
  int valor_digital = 0;    // Define a variavel valor_digital como do sensor digital

void setup() {  // Progrmação Inicial

  Serial.begin(9600);  // Inicia o monitor serial

  pinMode(pino_analogico, INPUT);  // Define pinos sensor analogico como entrada
  pinMode(pino_digital, INPUT);    // Define pinos sensor digital como entrada
  pinMode(led, OUTPUT);            // Define pinos do led como entrada
  digitalWrite(led, LOW);          // Coloca o led como desligado

}

void loop() {  // Programação Principal

  valor_analogico = analogRead(pino_analogico);  // Vai ler o sensor analogico e colocar as informações na variavel valor_analogico
  valor_digital = digitalRead(pino_digital);     // Vai ler o sensor digital e colocar as informações na variavel valor_digital
  Serial.print("Saida A0: ");                    // Imprime "Saida A0: " no monitor serial
  Serial.print(valor_analogico);                 // Imprime o valor do sensor analogico
  Serial.print(" Saida D0: ");                   // Imprime "Saida D0: " no monitor serial
  Serial.println(valor_digital);                 // Imprime o valor do sensor digital

  delay(500);  // Aguarda 500 ms

  if (digitalRead(pino_digital) == LOW) { // Se o pino digital detectar barulho, então:

    digitalWrite(led, HIGH);  //Ligar led

  }

  else { // Senão

    digitalWrite(led, LOW);  //Ligar led

  }
  
}

// FIM!