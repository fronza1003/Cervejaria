/********************************************************************/ 
// Import das bibliotecas
#include <OneWire.h> 
#include <DallasTemperature.h>
/********************************************************************/ 
// Fio DATAmligado no pino 2 do Arduino
#define ONE_WIRE_BUS 2 
/********************************************************************/ 
// Definir uma instância oneWire para se comunicar com qualquer dispositivo OneWire
OneWire oneWire(ONE_WIRE_BUS); 
/********************************************************************/ 
// Passar a referência oneWire para Dallas Temperature (°C e °F)
DallasTemperature sensors(&oneWire);
/********************************************************************/ 
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
 // call sensors.requestTemperatures() to issue a global temperature 
 // request to all devices on the bus 
/********************************************************************/
 Serial.print("Aguardando temperaturas..."); 
 sensors.requestTemperatures(); // envia um comando solicitando a leitura da temperatura
 Serial.println("PRONTO"); 
/********************************************************************/
 Serial.print("Temperatura: "); 
 Serial.print(sensors.getTempCByIndex(0)); // ByIndex pois podem haver multiplos sensores 
                                           // no mesmo bus, portanto 0 significa o primeiro
                                           // circuito integrado encontrado no fio
   delay(1000); 
} 
