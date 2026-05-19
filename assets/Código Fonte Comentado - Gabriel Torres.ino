// =====================================================
// PROJETO: SEMÁFORO DE DUAS VIAS COM ARDUINO 
// Aula 28 - IOT | SENAI "A. Jacob Lafer"
// =====================================================

// CONFIGURAÇÃO DOS PINOS - VIA 1
int pinVERMELHO1 = 13;
int pinAMARELO1  = 12;
int pinVERDE1    = 11;

// CONFIGURAÇÃO DOS PINOS - VIA 2
int pinVERMELHO2 = 7;
int pinAMARELO2  = 6;
int pinVERDE2    = 5;

void setup() {
  pinMode(pinVERMELHO1, OUTPUT);
  pinMode(pinAMARELO1,  OUTPUT);
  pinMode(pinVERDE1,    OUTPUT);

  pinMode(pinVERMELHO2, OUTPUT);
  pinMode(pinAMARELO2,  OUTPUT);
  pinMode(pinVERDE2,    OUTPUT);
}

void loop() {
  // FASE 1: VIA 1 VERDE | VIA 2 VERMELHO (5 segundos)
  digitalWrite(pinVERDE1, HIGH);
  digitalWrite(pinVERMELHO2, HIGH);
  delay(5000);
  digitalWrite(pinVERDE1, LOW);
  digitalWrite(pinVERMELHO2, LOW);

  // FASE 2: AMBOS AMARELO (2 segundos)
  digitalWrite(pinAMARELO1, HIGH);
  digitalWrite(pinAMARELO2, HIGH);
  delay(2000);
  digitalWrite(pinAMARELO1, LOW);
  digitalWrite(pinAMARELO2, LOW);

  // FASE 3: VIA 1 VERMELHO | VIA 2 VERDE (5 segundos)
  digitalWrite(pinVERMELHO1, HIGH);
  digitalWrite(pinVERDE2,    HIGH);
  delay(5000);
  digitalWrite(pinVERMELHO1, LOW);
  digitalWrite(pinVERDE2,    LOW);

  // FASE 4: AMBOS AMARELO (2 segundos) 
  digitalWrite(pinAMARELO1, HIGH);
  digitalWrite(pinAMARELO2, HIGH);
  delay(2000);
  digitalWrite(pinAMARELO1, LOW);
  digitalWrite(pinAMARELO2, LOW);
}