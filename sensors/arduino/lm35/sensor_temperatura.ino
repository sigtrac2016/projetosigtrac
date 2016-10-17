//Display LCD
#include <LiquidCrystal.h> //Inclui a biblioteca do LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //Configura os pinos do Arduino para se comunicar com o LCD

//Sensor de temperatura usando o LM35
const int LM35 = A0; // Define o pino que lê a saída do LM35
float temperatura; // Variável que armazenará a temperatura medida

//Variáveis para acionar alarme sonoro e leitura do botão de cancelamento
int buzina = 0; //Alarme sonoro desligado
int botao = 0; //Inicializa a variável do botão de cancelamento do alarme

//Caractere especial "º"
byte grau[8]={
  B01110,
  B10001,
  B10001,
  B01110,
  B00000,
  B00000,
  B00000,
  B00000
};

//Função que será executada uma vez quando ligar ou resetar o Arduino
void setup() {
Serial.begin(9600); // inicializa a comunicação serial
//Saída para o alarme
pinMode(10, OUTPUT);
//Entrada do botão de cancelamento do alarme
pinMode(9, INPUT);
//Saída para o LED
pinMode(13, OUTPUT);
//Inicializa o Display LCD
lcd.begin(16, 2); //Inicia o LCD com dimensões 16x2(Colunas x Linhas)
lcd.setCursor(0, 0); //Posiciona o cursor na primeira coluna(0) e na primeira linha(0) do LCD
lcd.print("Temperatura:"); //Escreve no LCD "Olá Garagista!"
//Cria o caractere especial "º" na posição 0
lcd.createChar(1, grau);
}
 
//Função que será executada continuamente
void loop() {
//Converte a leitura analógica do sensor LM35 em temperatura (ºC)
temperatura = (float(analogRead(LM35))*5/(1023))/0.01;
//Saída para o terminal - apenas para debugar o código
Serial.print("Temperatura: ");
Serial.println(temperatura);
Serial.print("Botao: ");
Serial.println(botao);
Serial.print("Buzina: ");
Serial.println(buzina);
//Imprime a temperatura no Display LCD
lcd.setCursor(0, 1); //Posiciona o cursor na décima quarta coluna(13) e na segunda linha(1) do LCD
lcd.print(temperatura); //Escreve o valor atual da variável de contagem no LCD
lcd.write(1);
lcd.print("C");
//Código a ser executado com sobretemperatura
if (temperatura > 25) {
  //Imprime "ALERTA!" no LCD
  lcd.setCursor(9, 1);
  lcd.print("ALERTA!");
  //Aciona o LED
  digitalWrite(13, HIGH);
  //Faz a leitura do botão de cancelamento
  botao = digitalRead(9);
  //Se o botão foi presionado
  if (botao == 1) {
    buzina = 2;
  }
  //Se a buzina ainda não foi acionada
  if (buzina == 0) {
    buzina = 1;
  }
  //Ativar a buzina
  if (buzina == 1) {
    digitalWrite(10, HIGH);
  //Desativar a buzina
  } else {
    digitalWrite(10, LOW);
  }
//Temperatura na faixa normal de operação
} else {
  //Desativar a buzina
  digitalWrite(10, LOW);
  //Apaga o LED
  digitalWrite(13, LOW);
  //Zerar variável da buzina
  buzina = 0;
  //Apagar "ALERTA!" do LCD
  lcd.setCursor(9, 1);
  lcd.print("        ");
}

delay(500);
}
