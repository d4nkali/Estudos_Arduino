//Teste de acionamento de um push button

//Definindo os componentes

 const int pin_botao = 13; //porta digital 13 sera o botao
 const int pin_led = 2; //porta digital 2 sera o led

void setup(){ //Progrmação inicial

 pinMode(pin_botao, INPUT_PULLUP); //inicializa o botao como entrada de informação
 pinMode(pin_led, OUTPUT); //inicializa o led como saida
  
}

void loop() { //Programação principal
  
 if (digitalRead(pin_botao) == LOW) { // Se o botão estiver apertado:
 
   digitalWrite(pin_led, HIGH); //Ligar led
   
 }
 
  else{ //Senão
    
   digitalWrite(pin_led, LOW); //Desliga o led
    
  }  
  
}

//FIM