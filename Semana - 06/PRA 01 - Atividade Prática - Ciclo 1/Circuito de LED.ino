// Aluno: Douglas Leonel de Almeida
// Matrícula: 2110213

void setup()
{
  // Configura os pinos 10, 9 e 8 como saída
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop()
{
  // Aciona o pino 10 (HIGH, ou seja, 5V)
  digitalWrite(10, HIGH);
  // Aguarda 1 segundo
  delay(1000);
  // Desliga o pino 10 (LOW, ou seja, 0V)
  digitalWrite(10, LOW);
  
  // Repete o processo para o pino 9
  digitalWrite(9, HIGH);
  delay(1000);
  digitalWrite(9, LOW);
  
  // Repete o processo para o pino 8
  digitalWrite(8, HIGH);
  delay(1000);
  digitalWrite(8, LOW);
}

//Link do Circuito: https://www.tinkercad.com/things/aEGy6HQPNvJ-copy-of-circuito-de-led/editel?tenant=circuits
