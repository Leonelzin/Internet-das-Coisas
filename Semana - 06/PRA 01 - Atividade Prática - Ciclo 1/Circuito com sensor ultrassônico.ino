// Aluno: Douglas Leonel de Almeida
// Matrícula: 2110213
// Observação: Para alterar a cor, selecione o sensor de distância inicialmente.
// Para uma melhor aprovação, selecione a distância desejada na hora de simular.
// O cálculo usará esta distância para mudar a cor do LED de acordo com os parâmetros abaixo.

float cm, duracao; // comprimento da onda

byte pinoTransmissor = 11; // trig
byte pinoReceptor = 10;  // echo

// LED RGB
const byte G = 3;
const byte B = 4;
const byte R = 5;

void setup()
{
  // LED
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  // sensor
  pinMode(pinoTransmissor, OUTPUT); // transmissor
  pinMode(pinoReceptor, INPUT);     // receptor
  // porta serial
  Serial.begin(9600);
}

void loop()
{
  cm = distancia(); // distância em centímetros
  // acende o LED de acordo com os intervalos
  if (cm > 0 && cm <= 100)
  { // acende vermelho
    red();
  }
  else if (cm > 100 && cm <= 200)
  { // acende verde
    green();
  }
  else if (cm > 200)
  { // acende azul
    blue();
  }
  else
  {
    apaga();
  }
  // distancia
  Serial.print(cm);
  Serial.println(" cm");
  delay(500);
}

// função que calcula a distância
float distancia()
{
  digitalWrite(pinoTransmissor, LOW);
  delayMicroseconds(5);
  // envio do pulso de ultrassom
  digitalWrite(pinoTransmissor, HIGH);
  // aguarda 10 microssegundos / tempo para o pulso ir e voltar para a leitura
  delayMicroseconds(10);
  // desliga o pino que envia para habilitar o pino que recebe
  digitalWrite(pinoTransmissor, LOW);
  // calcula a duração em microssegundos do pulso para ir e voltar
  duracao = pulseIn(pinoReceptor, HIGH);
  float calcDistancia = (duracao / 2) * 0.0343;
  if (calcDistancia >= 331)
  {
    calcDistancia = 0;
  }
  return calcDistancia;
}
// funções de cores do LED
void red()
{
  analogWrite(R, 255);
  analogWrite(G, 0);
  analogWrite(B, 0);
}
void green()
{
  analogWrite(R, 0);
  analogWrite(G, 255);
  analogWrite(B, 0);
}
void blue()
{
  analogWrite(R, 0);
  analogWrite(G, 0);
  analogWrite(B, 255);
}
void apaga()
{
  analogWrite(R, 0);
  analogWrite(G, 0);
  analogWrite(B, 0);
}

//Link do Circuito: https://www.tinkercad.com/things/kWUPsH3KTIw-pra1-s6-sensor-ultrassonico/editel
