#include <Stepper.h>

// Define passos por volta do motor 28BYJ-48
const int passosPorVolta = 2048;

// Define os pinos ligados ao ULN2003
Stepper motor(passosPorVolta, 8, 10, 9, 11);

int sensorChuva = A0;
int led = 6;

void setup() {
  Serial.begin(9600);
  motor.setSpeed(10); // Velocidade do motor
  pinMode(sensorChuva, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  int valorChuva = analogRead(sensorChuva);
  Serial.print("Sensor: ");
  Serial.println(valorChuva);

  // Condição: quanto mais molhado, menor o valor lido
  if (valorChuva < 600) {
    Serial.println("Chuva detectada! Fechando varal...");
    digitalWrite(led, HIGH); // Acende LED
    motor.step(passosPorVolta); // Gira motor para fechar
    delay(2000);
  } else {
    Serial.println("Sem chuva. Abrindo varal...");
    digitalWrite(led, LOW); // Apaga LED
    motor.step(-passosPorVolta); // Gira motor no sentido oposto
    delay(2000);
  }

  delay(1000);
}
