/*

  Programa de controle de midia com arduino leornado
  Autor: d4nkali 20/12/2023 v1.0

*/

// Inclusão das bibliotecas

  #include <HID-Project.h>

// Definindo os pinos

  const int botao_avancar = 8; // Define o botao de avançar no pino 8
  const int botao_voltar = 9; // Define o botao de voltar no pino 9
  const int botao_pause_rep = 10; // Define o botao de reproduzir e pausar no pino 10

void setup() {

  pinMode(botao_avancar, INPUT_PULLUP); // Coloca o botão avançar como entrada
  pinMode(botao_voltar, INPUT_PULLUP); // Coloca o botão menos voltar entrada
  pinMode(botao_pause_rep, INPUT_PULLUP); // Coloca o botão reproduzir/pausar como entrada

}

void loop() {

  if (digitalRead(botao_avancar) == LOW) { // Se o botão de avançar for precionado, então:

    Consumer.write(MEDIA_NEXT); // Emula a tecla de avançar midia o volume
    digitalWrite(LED_BUILTIN, HIGH); // Liga o led
    delay(150); // Aguarda 150 ms
    digitalWrite(LED_BUILTIN, LOW); // Desliga o led

  }

  if (digitalRead(botao_voltar) == LOW) { // Se o botão de voltar for precionado, então:

    Consumer.write(MEDIA_PREVIOUS); // Emula a tecla de voltar a idia o volume
    digitalWrite(LED_BUILTIN, HIGH);  // Liga o led
    delay(150); // Aguarda 150 ms
    digitalWrite(LED_BUILTIN, LOW); // Desliga o led

  }

  if (digitalRead(botao_pause_rep) == LOW) { // Se o botão de pausar/reproduzir for precionado, então:

    Consumer.write(MEDIA_PLAY_PAUSE); // Emula a tecla de pausar/reproduzir a midia
    digitalWrite(LED_BUILTIN, HIGH);  // Liga o led
    delay(500); // Aguarda 0,5 s
    digitalWrite(LED_BUILTIN, LOW); // Desliga o led

  }

}

// FIM!