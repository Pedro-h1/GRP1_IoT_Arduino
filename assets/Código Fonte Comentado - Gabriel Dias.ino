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
  digitalWrite(pinAMARELO1, LOW);
  digitalWrite(pinVERMELHO1, LOW);
  
  digitalWrite(pinVERDE2, LOW);
  digitalWrite(pinAMARELO2, LOW);
  digitalWrite(pinVERMELHO2, HIGH);
  delay(5000);

  // FASE 2: VIA 1 AMARELO | VIA 2 VERMELHO (2 segundos)
  // (Via 1 está avisando que vai parar, Via 2 ainda espera no vermelho)
  digitalWrite(pinVERDE1, LOW);
  digitalWrite(pinAMARELO1, HIGH);
  delay(2000);

  // FASE 3: VIA 1 VERMELHO | VIA 2 VERDE (5 segundos)
  digitalWrite(pinAMARELO1, LOW);
  digitalWrite(pinVERMELHO1, HIGH); // Fecha a Via 1
  
  digitalWrite(pinVERMELHO2, LOW);
  digitalWrite(pinVERDE2, HIGH);    // Abre a Via 2
  delay(5000);

  // FASE 4: VIA 1 VERMELHO | VIA 2 AMARELO (2 segundos)
  // (Via 2 está avisando que vai parar, Via 1 ainda espera no vermelho)
  digitalWrite(pinVERDE2, LOW);
  digitalWrite(pinAMARELO2, HIGH);
  delay(2000);
}