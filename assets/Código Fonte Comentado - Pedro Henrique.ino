// =====================================================
// PROJETO: SEMÁFORO SIMPLES COM ARDUINO
// Linguagem: C++ (Arduino)
// Profº Paulo Camargo
// Aluno: Pedro Henrique Prandwiski Borges Nº22
// =====================================================

// CONFIGURAÇÃO DOS PINOS
int pinVERMELHO1 = 11;
int pinAMARELO1  = 12;
int pinVERDE1    = 13;
int pinVERMELHO2 = 7;
int pinAMARELO2  = 6;
int pinVERDE2    = 5;

void setup()
{
    // Define os pinos como saída (executado apenas uma vez)
    pinMode(pinVERDE1, OUTPUT);
    pinMode(pinAMARELO1, OUTPUT);
    pinMode(pinVERMELHO1, OUTPUT);
     pinMode(pinVERDE2, OUTPUT);
    pinMode(pinAMARELO2, OUTPUT);
    pinMode(pinVERMELHO2, OUTPUT);
}

void loop()
{
    // FASE 1: VERDE (4 segundos)
    digitalWrite(pinVERDE1, HIGH);
      digitalWrite (pinVERMELHO2 , HIGH);
    delay(4000);
    digitalWrite(pinVERDE1, LOW);
      digitalWrite(pinVERMELHO2, LOW);

    // FASE 2: AMARELO (1 segundo)
    digitalWrite(pinAMARELO1, HIGH);
      digitalWrite(pinAMARELO2, HIGH);
    delay(1000);
    digitalWrite(pinAMARELO1, LOW);
      digitalWrite(pinAMARELO2, LOW);

    // FASE 3: VERMELHO (6 segundos)
    digitalWrite(pinVERMELHO1, HIGH);
      digitalWrite(pinVERDE2, HIGH);
    delay(6000);
    digitalWrite(pinVERMELHO1, LOW);
      digitalWrite(pinVERDE2, LOW);
}