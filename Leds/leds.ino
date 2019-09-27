/* Programação desenvolvida pela equipe do canal Bruno Cerqueira
Com explicação adaptada para pessoas que estão iniciando.
*/

int led = 8;
// Declaração de variável, estou dizendo que led está no pino digital 8

void setup() {
pinMode (led, OUTPUT);
// Declaração de função, estou dizendo que o pino digital 8 será uma saída
}
void loop() {
digitalWrite (led, HIGH); // Significa que o LED será ligado.
Serial.println("HIGH");
delay (3000); // Espera 100 milisegundos
digitalWrite (led, LOW); // Significa que o LED será desligado
Serial.println("LOW");
delay (3000); // Espera 500 milisegundos
}
