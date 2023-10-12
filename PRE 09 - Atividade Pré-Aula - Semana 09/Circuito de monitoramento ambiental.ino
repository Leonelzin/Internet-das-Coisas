// Aluno: Douglas Leonel de Almeida
// Matrícula: 2110151

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int moisturePin = A2;
const int ldrPin = A1;
const int tmpPin = A0;
const int potPin = A3;

void setup() {
  lcd.begin(16, 2);
  lcd.print("Dados Ambientais");
  Serial.begin(9600);
  delay(2000);
  lcd.clear();
}

void loop() {
  int moistureValue = analogRead(moisturePin);
  int ldrValue = analogRead(ldrPin);
  int tmpValue = analogRead(tmpPin);
  int potValue = analogRead(potPin);

  float voltage = tmpValue * 5.0 / 1023.0;
  float temperature = (voltage - 0.5) * 100.0;
  float humidity = map(moistureValue, 0, 1023, 0, 100);

  // Exibir os valores dos sensores no LCD com rolagem
  String linha1 = "Umidade: " + String(humidity) + "%  LDR: " + String(ldrValue);
  String linha2 = "Temperatura: " + String(temperature) + "°C    Ruído: " + String(potValue) + "db";

  for (int i = 0; i < linha1.length(); ++i) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(linha1.substring(i, i + 16)); // Exibir 16 caracteres de cada vez na primeira linha

    lcd.setCursor(0, 1);
    lcd.print(linha2.substring(i, i + 16)); // Exibir 16 caracteres de cada vez na segunda linha

    delay(400); // Ajustar o tempo de atraso conforme necessário
  }

  Serial.println(linha1);
  Serial.println(linha2);
}

//Link do Circuito: https://www.tinkercad.com/things/lHmnOksoaPg-copy-of-environment-data/editel?tenant=circuits
