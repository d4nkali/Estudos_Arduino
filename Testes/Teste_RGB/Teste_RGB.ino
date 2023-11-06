// Teste LED RGB

// Criando as variaveis

  const int pinVerde = 12; // Verde no pino 12
  const int pinVermelho = 11; // Vermelho no pino 11
  const int pinAzul = 10; // Azul no pino 10

void setup() {

  pinMode(pinVerde, OUTPUT); // Pino verde como saida
  pinMode(pinAzul, OUTPUT); // Pino Azul como saida
  pinMode(pinVermelho, OUTPUT); // Pino vermelho como saida

}

void loop() {

  digitalWrite(pinVermelho, HIGH); // Liga o pino vermelho
  delay(1000); // Aguarda 1 segundo
  digitalWrite(pinVermelho, LOW); // Desliga o pino vermelho
  digitalWrite(pinVerde, HIGH); // Liga o pino verde
  delay(1000); // Aguarda 1 segundo
  digitalWrite(pinVerde, LOW); // Desliga o pino verde
  digitalWrite(pinAzul, HIGH); // Liga o pino azul
  delay(1000); // Aguarda 1 segundo
  digitalWrite(pinAzul, LOW);  // Desliga o pino azul

}

// FIM!