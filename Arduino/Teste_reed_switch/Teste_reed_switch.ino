// Teste com o Reed switch

// Criação das variaveis

 const int pin_reed = 8; // Reed switch no pino 8
 const int pin_led = 13; // Led no pino 13
 const int pin_som = 12; // Buzer no pino 12
 int magn = 0; // variavel magn

void setup() { // Programação Inicial

 Serial.begin(9600); // Iniciar o a comunicação serial
 pinMode(pin_reed, INPUT); // Sensor como entrada
 pinMode(pin_led, OUTPUT); // Led como saida
 pinMode(pin_som, OUTPUT); // Buzzer como saida

}

void loop() { // Programação principal

 magn=digitalRead(pin_reed); // Ler as informações do sensor para a variavel magn
 Serial.print("Magnetismo"); // Imprime o texto "magnetismo"
 Serial.println(magn); // Imprime se tem campo magnetico
 delay(2000); // Aguarde 2 segundos

  if (digitalRead(pin_reed) == HIGH){ // Se o sensor for 0 entao
    
    digitalWrite(pin_led, HIGH); // Ligar led
    tone(pin_som, 1200, 1000); // Tocar buzzer
  
  }
  
  else{ // Senão
    
    digitalWrite(pin_led, LOW); // Desligar led
    noTone(pin_som); // Desligar buzzer

  }
  
}
