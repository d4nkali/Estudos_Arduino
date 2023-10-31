/*

 Teste da ponte H L298N

*/

// Define os pinos do Arduino para controle do L298N

 const int in1 = 2;
 const int in2 = 3;
 const int in3 = 4;
 const int in4 = 5;

void setup() {

  // Define todos os pinos como saída

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

}

void loop() {

  // Gire o motor 1 e 2 para frente
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  // Gire o motor 3 e 4 para frente
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  // Aguarde por 2 segundos
  delay(2000);

  // Pare os motores
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  // Aguarde por 1 segundo
  delay(1000);


}
