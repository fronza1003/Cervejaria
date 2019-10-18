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

//razão do crescimento da temperatura para cálculo da temperatura projetada
float razaoTemp 


boolean iniciado = 0;
int angulo = 5;
float anguloInicial = 0;


void setup(void) {

  servo.attach(8);
  //servo.write(angle);
  
  Serial.begin(9600); 
  sensors.begin();
}

void loop(void) {
  sensors.requestTemperatures();   
  tempAtual=sensors.getTempCByIndex(0);

  servo.write(angulo);

  //TODO
  //Ler botão iniciar, pegar temperatura e tempo

  if (iniciado = 1)  {

    sensors.requestTemperatures();
    tempAtual=sensors.getTempCByIndex(0);
    if (tempAtual < tempAlvo) {
      //TODO
      //aumentar temperatura com o movimento do servo
    } else if (tempAtual > tempAlvo) {
      //TODO
      //diminuir a temperatura com o movimento do servo motor
    } else {
      //TODO
      //manter a temperatura
    }
     
    
  } else {
          
  }

  // Apresenta a temperatura atual na tela
  Serial.print(" C  ");
  Serial.print(Celcius);



  delay(1000); 
}
