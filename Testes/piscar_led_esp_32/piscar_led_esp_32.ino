/*

 teste de piscar led
  
*/

void setup(){ // Programação inicial
  
 pinMode(2, OUTPUT); // Led como saida

}

void loop() { // Programação principal 
  
 digitalWrite(2, HIGH); // Liga led
 delay(1000); // Aguarda 1 segundo
 digitalWrite(2, LOW); // Desliga led
 delay(1000); // Aguarda 1 segundo

}

//FIM