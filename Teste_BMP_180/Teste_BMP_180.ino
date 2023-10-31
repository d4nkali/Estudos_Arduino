// Teste do sensor BMP180

// Inclusão das bibliotecas

 #include <Wire.h>
 #include <Adafruit_BMP085.h>

// Chama a configuração da biblioteca

 Adafruit_BMP085 bmp;

void setup() { // Programação Inicial

 if (!bmp.begin()) {
    Serial.println("Não foi possível inicializar o BMP180");
    while (1);
 }
 
  Serial.begin(9600); // Inicindo o monitor serial
  
}

void loop() { // Programação Principal

  float temperatura = bmp.readTemperature();
  float pressao = bmp.readPressure() / 100.0; // Divida por 100 para converter para hPa
  pressao *= 10; // Converter hPa para mbar

  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C");

  Serial.print("Pressão: ");
  Serial.print(pressao);
  Serial.println(" mbar");

  delay(2000);

}
