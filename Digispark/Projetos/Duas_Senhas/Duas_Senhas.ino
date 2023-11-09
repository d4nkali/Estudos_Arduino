/*

 Disgispark envinado duas senhas ou um usuario e uma senha quando precionar um botao

 Configuração para teclado ptbr feita por: Eduardo Gadotti - https://github.com/Gadotti

*/

// Inclusão da biblioteca
 
 #include "DigiKeyboardPtBr.h"
 
// Criação das variaveis

 #define user "user" // Define usuario
 #define senha "senha" // Define a senha
 
 #define press_longa 1000 // Define o atraso para acionar o segundo comando

 #define pin_botao_1  0 // Define o primeiro pino do botao
 #define pin_botao_2  2 // Define o segundo pino do botao


void setup() { 

  pinMode(2, OUTPUT); // Configura o pino do botao 2 como saida
  digitalWrite(2, LOW); // Configura o pino do botao 2 como baixo (0V)
  pinMode(0, INPUT_PULLUP); // Configura o pino do botao 0 como entrada

}
 
void loop() { 

  DigiKeyboard.sendKeyStroke(0); // Digita inicialmente para não dar problema em sistemas antigos
 
  if(!digitalRead(0)) { // Verifica se o botão foi apertado

    DigiKeyboard.delay(press_longa); // Aciona o delay para ver se teve o clique longo
    
    if(!digitalRead(0)) // Se o clique foi longo, então:

      DigiKeyboard.print(senha); // Digita a senha

    else // Se foi um clique curto

      DigiKeyboard.print(user); // Digita o usuario

    DigiKeyboard.delay(500); // Aguarda 500 ms

  }
 
  DigiKeyboard.delay(10); // Atraso para evitar debounce

}

// FIM!