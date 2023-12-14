/*

 Programa de execução de atalhos para o Windows usando o Arduino Leornado 
 Autor: d4nkali 02/04/2023 ver: 1.7 (18/04/2023)

 Localização dos pinos no arduino
 
  Led = Integrado ao arduino / Pino 13
  Botão do gerenciador de tarefas = Pino 12
  Botão do cmd = Pino 11
  Botão do explorador de arquivos = Pino 10
  Botão de encerrar programas = Pino 9
  Botão do bloco de notas = Pino 8
  Botão das configurações rapidas = Pino 7
  Botão para as configurações = Pino 6
  Botão para as notificações = Pino 5
  Botão para almentar o volume = Pino 4
  Botão para as diminuir o volume = Pino 3

*/

// Inclusão da biblioteca

 #include <Keyboard.h>

// Definido os componetes

 #define led LED_BUILTIN // Define o pino digital 13 como led
 #define botao_1 12 // Define o pino digital 12 como botão 1 do gerenciador de tarefas
 #define botao_2 11 // Define o pino digital 11 como botão 2 do cmd
 #define botao_3 10 // Define o pino digital 10 como botão 3 do explorador de arquivos
 #define botao_4 9 // Define o pino digital 9 como botão 4 de encerrar programas 
 #define botao_5 8 // Define o pino digital 8 como botão 5 do bloco de notas 
 #define botao_6 7 // Define o pino digital 7 como botao 6 das configuraçoes rapidas
 #define botao_7 6 // Define o pino digital 6 como botao 7 das configuraçoes do PC
 #define botao_8 5 // Define o pino digital 5 como botao 8 as notificações do PC
 #define botao_1_p 4 // Define o pino digital 4 como botao 1 pequeno para aumentar o volume
 #define botao_2_p 3 // Define o pino digital 3 como botao 2 pequeno para diminuir o volume
 
void setup() { // Progrmação inicial
  
 pinMode(led, OUTPUT); // Configura o pino do led como saida 

 pinMode(botao_1, INPUT_PULLUP); // Configura o pino do botão 1 como entrada com resistor pull-up
 pinMode(botao_2, INPUT_PULLUP); // Configura o pino do botão 2 como entrada com resistor pull-up
 pinMode(botao_3, INPUT_PULLUP); // Configura o pino do botão 3 como entrada com resistor pull-up
 pinMode(botao_4, INPUT_PULLUP); // Configura o pino do botão 4 como entrada com resistor pull-up
 pinMode(botao_5, INPUT_PULLUP); // Configura o pino do botão 5 como entrada com resistor pull-up
 pinMode(botao_6, INPUT_PULLUP); // Configura o pino do botão 6 como entrada com resistor pull-up
 pinMode(botao_7, INPUT_PULLUP); // Configura o pino do botão 7 como entrada com resistor pull-up
 pinMode(botao_8, INPUT_PULLUP); // Configura o pino do botão 8 como entrada com resistor pull-up
 pinMode(botao_1_p, INPUT_PULLUP); // Configura o pino do botão 1 pequeno como entrada com resistor pull-up
 pinMode(botao_2_p, INPUT_PULLUP); // Configura o pino do botão 2 pequeno como entrada com resistor pull-up

 Keyboard.begin(); // Inicializa a biblioteca Keyboard
  
}

void loop() { //Progrmação Principal
  
  if (digitalRead(botao_1) == LOW) {  // Se o botão estiver pressionado, então:
  
    delay(150);  // Aguarda um curto período para evitar debounce
    digitalWrite(led, HIGH); // Liga o led  
    
    Keyboard.press(KEY_LEFT_SHIFT); // Pressiona a tecla Shift
    Keyboard.press(KEY_LEFT_CTRL); // Pressiona a tecla Ctrl
    Keyboard.press(KEY_ESC); // Pressiona a tecla Esc
    delay(100); // Aguarda um tempo para soltar as teclas
    Keyboard.releaseAll(); // Solta todas as teclas
    
    delay(3000); // Aguarda um tempo para o Gerenciador de tarefas aparecer
    digitalWrite(led, LOW); // Desliga o led

  }
  
  if (digitalRead(botao_2) == LOW) {  // Se o botão estiver pressionado, então:
  
    delay(150);  //Aguarda um curto período para evitar debounce
    digitalWrite(led, HIGH); // Liga o led
    
    Keyboard.press(KEY_LEFT_GUI);  // Pressiona a tecla Windows/Iniciar
    Keyboard.press('r');  // Pressiona a tecla R
    Keyboard.releaseAll();  // Solta todas as teclas
    
    delay(2000);  // Aguarda um tempo para a janela Executar aparecer
    
    Keyboard.print("cmd");  // Digita "cmd" na janela Executar    
    Keyboard.press(KEY_RETURN);  // Pressiona a tecla Enter para executar o comando
    Keyboard.releaseAll();  // Solta todas as teclas
        
    delay(5000);  // Aguarda um tempo para o prompt de comando aparecer
    digitalWrite(led, LOW); // Desliga o led
    
  }
  
  if (digitalRead(botao_3) == LOW) {  // Se o botão estiver pressionado, então:
  
    delay(150);  // Aguarda um curto período para evitar debounce
    digitalWrite(led, HIGH); // Liga o led
    
    Keyboard.press(KEY_LEFT_GUI);  // Pressiona a tecla Windows/Iniciar
    Keyboard.press('e');  // Pressiona a tecla E
    Keyboard.releaseAll();  // Solta todas as teclas
    
    delay(3000);  // Aguarda um tempo para a janela do Explorador aparecer
    digitalWrite(led, LOW); // Desliga o led    
    
  }
     
  if (digitalRead(botao_4) == LOW) {  // Se o botão estiver pressionado, então:
  
    delay(150);  // Aguarda um curto período para evitar debounce
    digitalWrite(led, HIGH); // Liga o led
    
    Keyboard.press(KEY_LEFT_ALT);  // Pressiona a tecla Alt
    Keyboard.press(KEY_F4);  // Pressiona a tecla F4
    Keyboard.releaseAll();  // Solta todas as teclas
    
    delay(3000);  // Aguarda um tempo para a janela fechar
    digitalWrite(led, LOW); // Desliga o led    
    
  }

  if (digitalRead(botao_5) == LOW) {  // Se o botão estiver pressionado, então:
  
    delay(150);  //Aguarda um curto período para evitar debounce
    digitalWrite(led, HIGH); // Liga o led
    
    Keyboard.press(KEY_LEFT_GUI);  // Pressiona a tecla Windows/Iniciar
    Keyboard.press('r');  // Pressiona a tecla R
    Keyboard.releaseAll();  // Solta todas as teclas
    
    delay(2000);  // Aguarda um tempo para a janela Executar aparecer
    
    Keyboard.print("notepad");  // Digita "cmd" na janela Executar    
    Keyboard.press(KEY_RETURN);  // Pressiona a tecla Enter para executar o comando
    Keyboard.releaseAll();  // Solta todas as teclas
        
    delay(5000);  // Aguarda um tempo para o prompt de comando aparecer
    digitalWrite(led, LOW); // Desliga o led
    
  }

  if (digitalRead(botao_6) == LOW) {  // Se o botão estiver pressionado, então:
  
    delay(150);  //Aguarda um curto período para evitar debounce
    digitalWrite(led, HIGH); // Liga o led
    
    Keyboard.press(KEY_LEFT_GUI);  // Pressiona a tecla Windows/Iniciar
    Keyboard.press('a');  // Pressiona a tecla A
    Keyboard.releaseAll();  // Solta todas as teclas

    delay(2000);  // Aguarda um tempo para as configurações rapidas aparecer
    digitalWrite(led, LOW); // Desliga o led
    
  }

  if (digitalRead(botao_7) == LOW) {  // Se o botão estiver pressionado, então:
  
    delay(150);  //Aguarda um curto período para evitar debounce
    digitalWrite(led, HIGH); // Liga o led
    
    Keyboard.press(KEY_LEFT_GUI);  // Pressiona a tecla Windows/Iniciar
    Keyboard.press('i');  // Pressiona a tecla I
    Keyboard.releaseAll();  // Solta todas as teclas

    delay(2000);  // Aguarda um tempo para as configurações aparecer
    digitalWrite(led, LOW); // Desliga o led
    
  }

  if (digitalRead(botao_8) == LOW) {  // Se o botão estiver pressionado, então:
  
    delay(150);  //Aguarda um curto período para evitar debounce
    digitalWrite(led, HIGH); // Liga o led
    
    Keyboard.press(KEY_LEFT_GUI);  // Pressiona a tecla Windows/Iniciar
    Keyboard.press('n');  // Pressiona a tecla N
    Keyboard.releaseAll();  // Solta todas as teclas

    delay(2000);  // Aguarda um tempo para as notificações aparecerem
    digitalWrite(led, LOW); // Desliga o led
    
  }

}

//FIM