// Nome do Aluno: Douglas Leonel de Almeida
// Número de Matrícula: 2110213

// Definição dos pinos para os LEDs e o buzzer
const int ledVerde1 = 13;
const int ledVerde2 = 12;
const int ledAmarelo1 = 11;
const int ledAmarelo2 = 10;
const int ledVermelho1 = 9;
const int ledVermelho2 = 8;
const int buzzer = 3;

// Constantes para as distâncias de controle dos LEDs e buzzer
const int distancias[] = {45, 40, 30, 20, 10, 5, 0};
const int frequencias[] = {330, 330, 396, 396, 495, 550, 0};
const int duracoes[] = {1500, 1000, 500, 250, 125, 60, 0};

long microsec = 0;
float distanciaCM = 0;

// Definição dos pinos dos LEDs
const int ledPinos[] = {ledVerde1, ledVerde2, ledAmarelo1, ledAmarelo2, ledVermelho1, ledVermelho2};

// Função para medir a distância com o sensor ultrassônico
long readUltrasonicDistance(int triggerPin, int echoPin) {
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  for (int i = 0; i < 6; i++) {
    pinMode(ledPinos[i], OUTPUT);
  }
}

void loop() {
  distanciaCM = 0.01723 * readUltrasonicDistance(7, 6);
  controlaLEDs();
  Serial.print(distanciaCM);
  Serial.println(" cm");
  delay(1000);
}

void controlaLEDs() {
  digitalWrite(buzzer, LOW);

  for (int i = 0; i < 7; i++) {
    if (distanciaCM <= distancias[i]) {
      digitalWrite(ledPinos[i], HIGH);
      if (frequencias[i] > 0) {
        tone(buzzer, frequencias[i], duracoes[i]);
        delay(duracoes[i] + 100); // Adiciona um pequeno atraso para evitar interferência sonora
        noTone(buzzer);
      }
    } else {
      digitalWrite(ledPinos[i], LOW);
    }
  }
}
