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
float tempProjetada = 0;
int anguloAtual = 0;
int minutos = 0;
int TempAlvo = 0;
int tempo = 0;

boolean iniciado = 0;

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
    } else if (tempAtual > tempAlvo) {
        if (anguloAtual > 0) {
          anguloAtual = anguloAtual - 10;
          servo.write(anguloAtual);
          }
      }
  }
}

//delay em segundos
void atraso(int segundos) {
  segundos = segundos * 1000;
  delay(segundos);
}

//Ler botão iniciar, pegar temperatura e tempo
//TempAlvo e minutos devem ser iguais aos valores da tela, estão com valores arbitrários
void iniciar() {
  iniciado = 1;
  TempAlvo = 20;
  minutos = 5;
  
  //tempo em segundos
  tempo = minutos * 60;  
}

void lerTela() {
  //TODO
  //Ler botão iniciar, pegar temperatura e tempo
}

  


void loop(void) {
  sensors.requestTemperatures();   
  tempAtual=sensors.getTempCByIndex(0);
  tempProjetada = tempAlvo - 10;

  
  //TODO
  //Ler botão iniciar, pegar temperatura e tempo
  

  sensors.requestTemperatures();
  tempAtual=sensors.getTempCByIndex(0);

  lerTela();

  if (iniciado = 1)  {
    alterarTemp();
  }
     
  //manter a temperatuxa por x segundos  
  if ((tempo * 60) < minutos) {
    tempo--;
    atraso(1);
  }

  // Apresenta a temperatura atual na tela
  Serial.print(tempAtual);
  Serial.print(tempo);
  
  atraso(1);  
}
