//Teste com LDR

const int pinled = 12; //Define o led no pino digital 12
const int pinldr = A0; //Define o ldr no pino analogico A0
int luz = 0;//Cria a variavel luz
  
void setup()
{
  
  Serial.begin(9600);//Inicia o monitor serial
  pinMode(pinldr, INPUT); //Definir o ldr como entrada
  pinMode(pinled, OUTPUT); //Definir led como saída

}

void loop()
{

  luz=analogRead(pinldr);//Lê o valor do sensor ldr e armazena na variável luz
  Serial.print("QUANTIDADE DE LUZ = ");//Imprime na serial a mensagem Quantidade de Luz
  Serial.println(luz);//Imprime na serial os dados de luz
  delay(200);
  
  if (analogRead(pinldr) < 150) { //Se ldr for menor que 150 então
    digitalWrite(pinled, HIGH); //Ligar led   
  }
  else { //Senão
    digitalWrite(pinled, LOW); //Desligar Led
  }
}
