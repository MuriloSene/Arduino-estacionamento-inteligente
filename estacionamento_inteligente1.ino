// PROJETO UPX 1 FACENS PRIMEIRO SEMESTRE - SISTEMA DE ILUMINAÇÃO E PRESENÇA PARA AUTOMÓVEIS EM ESTACIONAMENTOS
//
//
//
int Distancia = 0;                                        // DEFINIÇÃO DA VARIÁVEL INTEIRA DE DISTANCIA INICIAL = ZERO

long readUltrasonicDistance(int triggerPin, int echoPin)  // FUNÇÃO PARA A LEITURA DO SENSOR DE DISTÂNCIA
{
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  
  // DEFINE O PINO EM "HIGH" POR 10 ms E DEPOIS VAI PRA "LOW"
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  
  // LE O "ECHO PIN" E RETORNA O TEMPO DE VIAGEM DA ONDA SONORA EM 'ms'
  return pulseIn(echoPin, HIGH);
}

void setup()                                              // VOID SETUP - DEFINIR OS OUTPUT DO LOOP
{
  pinMode(10, OUTPUT);                                    // OUTPUT - LED VERMELHO
  pinMode(12, OUTPUT);                                    // OUTPUT - LED VERDE
}

void loop()                                               // VOID LOOP - DEFINIR A REPETIÇÃO
{
  Distancia = 0.01723 * readUltrasonicDistance(6, 7);     // INPUT - ARDUINO RECEBE A INFORMAÇÃO DE DISTANCIA DO SENSOR ULTRASSONICO EM ENTRADA ANALÓGICA
  if (Distancia >= 180) {                                 // SE DISTÂNCIA = ENTRE 0 E 180cm, ENTÃO VERMELHO, SE NÃO VERDE
    digitalWrite(12, HIGH);
    digitalWrite(10, LOW);
  } else {
    digitalWrite(10, HIGH);
    digitalWrite(12, LOW);
  }
  delay(10);                                              // DELAY 10ms PARA REALIZAR A AÇÃO NOVAMENTE
}