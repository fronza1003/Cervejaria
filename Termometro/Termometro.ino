// Import das bibliotecas
#include <OneWire.h> 
#include <DallasTemperature.h>

// Fio DATAmligado no pino 2 do Arduino
#define ONE_WIRE_BUS 2 

// Definir uma instância oneWire para se comunicar com qualquer dispositivo OneWire
OneWire oneWire(ONE_WIRE_BUS); 

// Passar a referência oneWire para Dallas Temperature (°C e °F)
DallasTemperature sensors(&oneWire);

void setup(void) 
{ 
  // iniciar porta serial 
  Serial.begin(9600); 
  Serial.println("Demo de biblioteca para controle de temperatura Dallas em circuito integrado"); 
  // iniciar a biblioteca 
  sensors.begin(); 
}

void loop(void) 
{ 
  sensors.requestTemperatures(); 
  Celcius=sensors.getTempCByIndex(0);
  Fahrenheit=sensors.toFahrenheit(Celcius);
  Serial.print(" C  ");
  Serial.print(Celcius);
  Serial.print(" F  ");
  Serial.println(Fahrenheit);
  delay(1000); 
} 
