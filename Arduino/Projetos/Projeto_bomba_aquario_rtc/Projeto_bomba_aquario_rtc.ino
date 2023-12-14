/*

 Programa do acionador da bomba do aquario usando o modulo RTC
 Autor: d4nkali 01/02/2023 ver.(3.0 \ 11/03/2023)

  Localização dos pinos no Arduino UNO/NANO
 
   Rele:
 
   VCC = 5V
   GND = GND
   IN = 8
 
   RTC DS1307 ou RTC 3231:

   VCC = 5V
   GND = GND
   SDA = A4 ou SDA
   SCL = A5 ou SCL
   
   Botao de emergencia:

   Pino da esquerda = 7
   Pino da direita = GND     
     
   Alimentação:

   VIN ou Pino de Alimentação e em ambos os casos alimentar entre 9 a 12V
    
  Localização dos pinos do rele:
   
   NO = Vai do rele ao motor (fase)
   COM = Vai da tomada (fase) para o rele
     
*/

// Inclusão das Bibliotecas

  #include <Wire.h>
  #include "RTClib.h"

// Criando variaveis dos componentes, dos horarios de acionamento e dos horarios para impedir o desligamento

 // Componentes
    
  const int pin_rele = 8; // Define o pino 8 para o rele
  const int botao_extra = 7; // Define o pino 7 para o botao de emergencia
  const int pin_led = 2; // Define o pino 2 para o led
  
 // Horario Manhã
  
  const int hora_ligar_1 = 8; // Define a hora que o rele ira acionar
  const int minuto_ligar_1 = 0; // Define o minuto que o rele ira acionar
  const int hora_desligar_1 = 12; // Define a hora que o rele ira desligar
  const int minuto_desligar_1 = 0; // Define o minuto que o rele ira desligar
 
 // Horario Tarde           

  const int hora_ligar_2 = 14; // Define a hora que o rele ira acionar
  const int minuto_ligar_2 = 0; // Define o minuto que o rele ira acionar
  const int hora_desligar_2 = 17; // Define a hora que o rele ira desligar
  const int minuto_desligar_2 = 0; // Define o minuto que o rele ira desligar

 // Desligamento completo
 
  const int hora_desligar_3 = 20; // Define a hora que o rele ira desligar
  const int minuto_desligar_3 = 0; // Define o minuto que o rele ira desligar

// Escolhe qual o modulo vai ser usado comentando ou descomentando

 RTC_DS1307 rtc; // Modulo rtc DS1307
 //RTC_DS3231 rtc; // Modulo rtc DS3132

void setup () { // Configurações iniciais

  Serial.begin(9600); // Inicia a comunicação serial

  Wire.begin(); // Inicia a comunicação I2C no arduino
  
  rtc.begin(); // Inicia a comunicação do modulo

  if (! rtc.isrunning()) { // Se o rtc iniciar, então:
  
    Serial.println("MODULO RTC NÃO INICIOU CORRETAMENTE!"); // Caso não inicie imprimir no serial: "MODULO RTC NÃO INICIOU CORRETAMENTE!"
    
    //rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); // Ajuste automatico do RTC
    
    //rtc.adjust(DateTime(2023, 5, 3, 19, 12, 00)); // Ajuste manual do RTC para a data e hora definida pelo usuario sendo o formato AAAA/MM/DD HH/mm/SS.
    //OBS: Quando for a primeira vez ou quando acabar a bateria, configure o RTC para data e hora atual descomentando a linha; quando terminar comnte na linha novamente
    
  }

  pinMode(pin_rele, OUTPUT); //Coloca o pino do rele como saída
  pinMode(botao_extra, INPUT_PULLUP); //Coloca o botao de emergencia como entrada
  digitalWrite(pin_rele, HIGH); //Inicia o rele como desligado
  pinMode(pin_led, OUTPUT); //Coloca o led como saída 
  
}

void loop() { // Programação central do arduino

// Impressão no monitor serial da data e hora do modulo RTC
  
  DateTime now = rtc.now(); // Ler a hora e a data do modulo para imprimir no serial
  Serial.print("Data e hora atual: ");  // Imprime a mensagem: "Data e hora atual: "
  Serial.print(now.day(), DEC); // Imprime o dia
  Serial.print('/'); // Imprime (/)
  Serial.print(now.month(), DEC); // Imprime o mes
  Serial.print('/'); // Imprime (/)
  Serial.print(now.year(), DEC);  // Imprime o ano
  Serial.print(' ');  // Da espaço
  Serial.print(now.hour(), DEC);  // Imprime a hora
  Serial.print(':');  // Imprime (:)
  Serial.print(now.minute(), DEC); // Imprime o minuto
  Serial.print(':'); // Imprime (:)
  Serial.print(now.second(), DEC);  // Imprime os segundos
  Serial.println(); // Repetir quando atualizar a hora
  delay(1000); // Esperar 1 segundo

// Programação da parte dos acionamentos dos horarios

 // Acionamento da Manhã

  if (now.hour() == hora_ligar_1 && now.minute() == minuto_ligar_1) { // Se de essa hora, então:
    
    digitalWrite(pin_rele, LOW); // Aciona o rele

  } 
  
  else if (now.hour() == hora_desligar_1 && now.minute() == minuto_desligar_1) { // Se de essa hora, então:
    
    digitalWrite(pin_rele, HIGH); // Desaciona o rele
      
  } 
  
 // Acionamento da Tarde 
  
  else if (now.hour() == hora_ligar_2 && now.minute() == minuto_ligar_2) { // Se de essa hora, então:
    
    digitalWrite(pin_rele, LOW); // Aciona o rele
      
  } 
  
  else if (now.hour() == hora_desligar_2 && now.minute() == minuto_desligar_2) { // Se de essa hora, então:
    
    digitalWrite(pin_rele, HIGH); // Desaciona o rele
      
  } 
  
 // Encerramento de emergencia
  
  else if (now.hour() == hora_desligar_3 && now.minute() == minuto_desligar_3) { // Se de essa hora, então:
    
    digitalWrite(pin_rele, HIGH); // Desaciona o rele

  }

// Acionamento do botao de emergencia para caso de queda de energia durante o horario do programa

 if(digitalRead(botao_extra) == LOW) { // Se o botao for precionado, então
  
   digitalWrite(pin_rele, LOW); // Aciona o rele
    
  }  

}

// FIM!