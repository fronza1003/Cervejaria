// Import das bibliotecas
#include <OneWire.h> 
#include <DallasTemperature.h>
#include <Servo.h>

// Fio DATAmligado no pino 2 do Arduino
#define ONE_WIRE_BUS 2 

// Definir uma instância oneWire para se comunicar com qualquer dispositivo OneWire
OneWire oneWire(ONE_WIRE_BUS); 

// Passar a referência oneWire para Dallas Temperature (°C e °F)
DallasTemperature sensors(&oneWire);

Servo servo;

float tempAtual = 0;
float tempAlvo = 0;
float tempAnterior = 0;
int anguloAtual = 0;
int segundosAlvo = 0;
int segundosAtual = 0;

boolean iniciado = 0;
boolean startTimer = 0;

void setup(void) {
  servo.attach(8);
  servo.write(anguloAtual);  
  Serial.begin(9600); 
  sensors.begin();
  iniciar();
}

void serialEvent () {
  
}

void alterarTemp() {
  sensors.requestTemperatures();
  tempAtual=sensors.getTempCByIndex(0);
  if (tempAtual < tempAlvo) {
      //verifica o angulo de abertura
      if (anguloAtual < 180) {
        anguloAtual = anguloAtual + 10;
        servo.write(anguloAtual);
      }
  } if (tempAtual > tempAlvo) {
      startTimer = 1;
      if (anguloAtual > 10) {
        anguloAtual = anguloAtual - 10;
        servo.write(anguloAtual);
      }
    }
}

//Verifica se o temperatur atingiu o esperado e começa a decrementar o timer
void timer() {
  if (startTimer == 1) {
    segundosAtual--;
      if (segundosAtual == 0) {
        iniciado = 0;
      }
  }
}

//Apresenta os valores na tela
void apresenta() {
  Serial.print("Temperatura: ");
  Serial.print(tempAtual);
  Serial.print('\n');

  Serial.print("Tempo: ");
  Serial.print(segundosAtual);
  Serial.print('\n');

  Serial.print("Angulo: ");
  Serial.print(anguloAtual);
  Serial.print('\n');
}

//Enviar para a tela mensagem de término do programa
void acabou() {
  Serial.print("Etapa Concluída!");
  Serial.print('\n');
}

//TODO
//Leitura constante da tela no aguardo de novos valores
void lerTela() {
  
}

//Ler botão iniciar, pegar temperatura e tempo
//tempAlvo e minutos devem ser iguais aos valores da tela, estão com valores arbitrários
void iniciar() {
  iniciado = 1;
  //TODO
  //Ler botão iniciar, pegar temperatura e tempo
  
  tempAlvo = 30;
  segundosAlvo = 1;
  
  //tempo em segundos
  segundosAlvo = segundosAlvo * 60;
  segundosAtual = segundosAlvo;
}

void loop(void) {
  sensors.requestTemperatures();
  tempAtual=sensors.getTempCByIndex(0);

  if (iniciado == 1)  {
    alterarTemp();
    timer();
    apresenta();
  }

  if (iniciado == 0) {
    acabou();
  }

  //Delay de 1 segundo
  delay(500);

  lerTela();
}
