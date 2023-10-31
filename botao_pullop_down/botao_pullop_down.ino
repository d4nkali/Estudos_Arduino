//Teste de acionamento de um push button pullop down

//Definindo os componentes

 const int pin_botao = 11; //porta digital 11 sera o botao
 const int pin_led = 13; //porta digital 13 sera o led

void setup(){ //Progrmação inicial

 pinMode(pin_botao, INPUT); //inicializa o botao como entrada de informação
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