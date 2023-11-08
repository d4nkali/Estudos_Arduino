/*

 Exemplo de com reproduzir um video no youtube pelo Digispark

 Configuração para teclado ptbr feita por: Eduardo Gadotti - https://github.com/Gadotti

*/

//Inclusão da biblioteca

 #include "DigiKeyboardPtBr.h"

// Definindo o link do video

 const char* video = "https://youtu.be/dQw4w9WgXcQ?t=43s";

void setup() { 
  
 DigiKeyboardPtBr.delay(2000); // Aguarda 2 segundos
 DigiKeyboardPtBr.sendKeyStroke(0); // Envia um sinal de teste
 DigiKeyboardPtBr.sendKeyStroke(KEY_R, MOD_GUI_LEFT); // Preciona as teclas R+Windows
 DigiKeyboardPtBr.delay(600); // Aguarda 0,6 segundos
 DigiKeyboardPtBr.print(video); // Digita o link da variavel video
 DigiKeyboardPtBr.sendKeyStroke(KEY_ENTER); // Preciona o ENTER
 DigiKeyboardPtBr.delay(5000); // Aguarda 2 segundos

}

void loop() { 
  
 // Nada

}

// FIM!