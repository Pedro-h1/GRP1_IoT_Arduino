// =====================================================
// PROJETO: SEMÁFORO DE DUAS VIAS COM ARDUINO (CORRIGIDO)
// Aula 28 - IOT | SENAI "A. Jacob Lafer"
// =====================================================

// CONFIGURAÇÃO DOS PINOS - VIA 1
int pinVERMELHO1 = 13;
int pinAMARELO1  = 12;
int pinVERDE1    = 11;

// CONFIGURAÇÃO DOS PINOS - VIA 2
int pinVERMELHO2 = 4;
int pinAMARELO2  = 3;
int pinVERDE2    = 2;
int botao        = 9;

void setup() {
  pinMode(pinVERMELHO1, OUTPUT);
  pinMode(pinAMARELO1,  OUTPUT);
  pinMode(pinVERDE1,    OUTPUT);

  pinMode(pinVERMELHO2, OUTPUT);
  pinMode(pinAMARELO2,  OUTPUT);
  pinMode(pinVERDE2,    OUTPUT);
  
  pinMode(botao, INPUT);
}

void loop() {
  // ─── FASE 1: VIA 1 VERDE | VIA 2 VERMELHO ───
  digitalWrite(pinVERDE1, HIGH);
  digitalWrite(pinVERMELHO2, HIGH);
  
  // Em vez de delay(5000) direto, checa o botão várias vezes durante os 5 segundos
  for (int i = 0; i < 500; i++) { 
    if (digitalRead(botao) == HIGH) {
      modoAtencao(); // Se apertar o botão, vai direto para o alerta/troca
      return;        // Reinicia o loop
    }
    delay(10); //5000ms (5 segundos)
  }
  
  digitalWrite(pinVERDE1, LOW);
  digitalWrite(pinVERMELHO2, LOW);

  // ─── FASE 2: AMBAS AMARELO (2 segundos) ───────────────────
  digitalWrite(pinAMARELO1, HIGH);
  digitalWrite(pinAMARELO2, HIGH);
  delay(2000);
  digitalWrite(pinAMARELO1, LOW);
  digitalWrite(pinAMARELO2, LOW);

  // ─── FASE 3: VIA 1 VERMELHO | VIA 2 VERDE (5 segundos) ───
  digitalWrite(pinVERMELHO1, HIGH);
  digitalWrite(pinVERDE2,    HIGH);
  delay(5000);
  digitalWrite(pinVERMELHO1, LOW);
  digitalWrite(pinVERDE2,    LOW);

  // ─── FASE 4: AMBAS AMARELO (2 segundos) ───────────────────
  digitalWrite(pinAMARELO1, HIGH);
  digitalWrite(pinAMARELO2, HIGH);
  delay(2000);
  digitalWrite(pinAMARELO1, LOW);
  digitalWrite(pinAMARELO2, LOW);
}

// Função isolada para quando o botão for pressionado
void modoAtencao() {
  // Apaga tudo
  digitalWrite(pinVERDE1, LOW);
  digitalWrite(pinVERDE2, LOW);
  digitalWrite(pinVERMELHO1, LOW);
  digitalWrite(pinVERMELHO2, LOW);
  
  // Pisca o amarelo de alerta por 3 segundos
  for(int j = 0; j < 3; j++) {
    digitalWrite(pinAMARELO1, HIGH);
    digitalWrite(pinAMARELO2, HIGH);
    delay(500);
    digitalWrite(pinAMARELO1, LOW);
    digitalWrite(pinAMARELO2, LOW);
    delay(500);
  }
}
  
  
 