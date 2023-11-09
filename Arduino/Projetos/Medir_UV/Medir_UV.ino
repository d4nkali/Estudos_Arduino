/*

  Medição dos raios UV do sol usando o sensor GUVA-S12SD

*/

// Definindo variaveis

  const int pin_uv = A1; // Define o sensor no pino A1
  int valor_uv; // Cria a variavel
  int inten_uv; // Cria a variavel

void setup() {

  Serial.begin(9600); // Inicia a comunicação serial
  pinMode(pin_uv, INPUT); // Coloca o sensor como entrada

}

void loop() {

  valor_uv = analogRead(pin_uv); // Ler o sensor e armazena na variavel
  inten_uv = map(valor_uv, 0, 1023, 0, 20); // Converter a leitura do sensor para o padrão de medição da OMS

  Serial.print("Nivel UV: "); // Imprime a frase "Nivel UV: "
  Serial.println(inten_uv); // Imprime o valor convertido
  delay(2000); // Aguarda 2 segundos

}

// FIM!