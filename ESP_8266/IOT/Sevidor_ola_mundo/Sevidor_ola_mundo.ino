/*
 
  Sevidor web na ESP-8266 

*/

// Inclusão das bibliotecas

  #include <ESP8266WiFi.h>
  #include <ESP8266WebServer.h>

// Configuração da conexão ao wifi

  const char *ssid = "MaisLink-Sem_Conexao";
  const char *password = "395853dpv";

// Chama as configurações da biblioteca

  ESP8266WebServer server(80); // Configurar a porta 80


void setup() {

  Serial.begin(115200); // Inicia a comunicação serial

  WiFi.begin(ssid, password);  // Conecta a placa ao wifi

  while (WiFi.status() != WL_CONNECTED) { // Se não conectar, repete até conectar

    delay(1000);
    Serial.println("Conectando ao Wi-Fi...");

  }

  Serial.println("Conectado ao Wi-Fi"); // Imprime dizendo que conectou no wifi
  Serial.print("Endereço IP: ");  // Imprime a frase "Endereço IP: "
  Serial.println(WiFi.localIP()); // Exibe no monitor serial o IP do dispositivo

  server.on("/", HTTP_GET, handleRoot); // Inicia todos os componetes do servidor 
  server.begin();  // Inicia o server
  Serial.println("Servidor web iniciado");  // Imprime que iniciou o server

}

void loop() {

  server.handleClient(); // Deixa o sevidor ligado

}

void handleRoot() {  // Criação da página inicial do servidor


  // Cria a página HTML

    String html = "<html><body>";
    html += "<h1>Ola, mundo</h1>";
    html += "<hr>";
    html += "</body></html>";

  // Envia a página HTML para o cliente
  server.send(200, "text/html", html);

}

// FIM!