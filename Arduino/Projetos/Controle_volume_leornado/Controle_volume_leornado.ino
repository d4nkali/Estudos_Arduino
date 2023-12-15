/*

  Programa de controle de volume com arduino leornado
  Autor: d4nkali 15/12/2023 v1.0

*/

// Inclusão das bibliotecas

  #include <HID-Project.h>

// Definindo os pinos

  const int botao_mais = 8; // Define o botao de aumentar no pino 8
  const int botao_menos = 9; // Define o botao de diminuir no pino 9
  const int botao_mudo = 10; // Define o botao de mutar no pino 10

void setup() {

  pinMode(botao_mais, INPUT_PULLUP); // Coloca o botão mais como entrada
  pinMode(botao_menos, INPUT_PULLUP); // Coloca o botão menos como entrada
  pinMode(botao_mudo, INPUT_PULLUP); // Coloca o botão mudo como entrada

}

void loop() {

  if (digitalRead(botao_mais) == LOW) { // Se o botão de mais for precionado, então:

    Consumer.write(MEDIA_VOLUME_UP); // Emula a tecla de aumentar o volume
    digitalWrite(LED_BUILTIN, HIGH); // Liga o led
    delay(150); // Aguarda 150 ms
    digitalWrite(LED_BUILTIN, LOW); // Desliga o led

  }

  if (digitalRead(botao_menos) == LOW) { // Se o botão de menos for precionado, então:

    Consumer.write(MEDIA_VOLUME_DOWN); // Emula a tecla de aumentar o volume
    digitalWrite(LED_BUILTIN, HIGH);  // Liga o led
    delay(150); // Aguarda 150 ms
    digitalWrite(LED_BUILTIN, LOW); // Desliga o led

  }

  if (digitalRead(botao_mudo) == LOW) { // Se o botão de menos for precionado, então:

    Consumer.write(MEDIA_VOLUME_MUTE); // Emula a tecla de mudo
    digitalWrite(LED_BUILTIN, HIGH);  // Liga o led
    delay(500); // Aguarda 0,5 s
    digitalWrite(LED_BUILTIN, LOW); // Desliga o led

  }

}

// FIM!