/*

 teste de piscar led
  
*/

void setup(){ // Programação inicial
  
 pinMode(LED_BUILTIN, OUTPUT); // Led como saida

}

void loop() { // Programação principal 
  
 digitalWrite(LED_BUILTIN, HIGH); // Liga led
 delay(1000); // Aguarda 1 segundo
 digitalWrite(LED_BUILTIN, LOW); // Desliga led
 delay(1000); // Aguarda 1 segundo

}

//FIM