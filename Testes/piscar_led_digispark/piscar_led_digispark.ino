/*

 teste de piscar led no Digispark
  
*/

// Comente a linha que não for da sua Digispark

 const int led = 1; // Define o led no GPIO 1
 // const int led = 0; // Define o led no GPIO 0

void setup(){ // Programação inicial
  
 pinMode(led, OUTPUT); // Led como saida

}

void loop() { // Programação principal 
  
 digitalWrite(led, HIGH); // Liga led
 delay(1000); // Aguarda 1 segundo
 digitalWrite(led, LOW); // Desliga led
 delay(1000); // Aguarda 1 segundo

}

//FIM