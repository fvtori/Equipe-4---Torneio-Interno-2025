#include <Arduino.h>
#include <Bluepad32.h>

// Notas para o Robo Tocar
#define NOTE_C5  523
#define NOTE_D5  587
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_G5  784
#define NOTE_A5  880
#define NOTE_AS5 932
#define REST 0

int tempo = 140;

int melody[] = {
  NOTE_C5,4,
  NOTE_F5,4, NOTE_F5,8, NOTE_G5,8, NOTE_F5,8, NOTE_E5,8,
  NOTE_D5,4, NOTE_D5,4, NOTE_D5,4,
  NOTE_G5,4, NOTE_G5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,
  NOTE_E5,4, NOTE_C5,4, NOTE_C5,4,
  NOTE_A5,4, NOTE_A5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8,
  NOTE_F5,4, NOTE_D5,4, NOTE_C5,8, NOTE_C5,8
};

int notes = sizeof(melody) / sizeof(melody[0]) / 2;
int wholenote = (60000 * 4) / tempo;
int divider, noteDuration;

bool tocarMusica = false;

//Conectar o Controle e Configurações
ControllerPtr myControllers[BP32_MAX_GAMEPADS];


// Definição dos Pinos
int ENA = 23;  // PWM Motor Esquerdo
int IN1 = 18;  // Esquerdo Frente
int IN2 = 19;  // Esquerdo Trás
int ENB = 22;  // PWM Motor Direito
int IN3 = 17;  // Direito Frente
int IN4 = 16;  // Direito Trás
int BUZZER = 32;


// Controle do Gamepad do Robõ
void processGamepad(ControllerPtr ctl) {
    int RT = ctl->brake();      // Frente
    int LT = ctl->throttle();   // Frente
    bool RB = ctl->r1();        // Trás
    bool LB = ctl->l1();        // Trás

    // Frente
    int pwmRT = map(RT, 0, 1023, 0, 255);
    int pwmLT = map(LT, 0, 1023, 0, 255);

    // Trás
    int pwmRB = RB ? 200 : 0;   // RB só liga / desliga
    int pwmLB = LB ? 200 : 0;   // LB só liga / desliga

    if (RT > 10 || LT > 10) {
        moverF(pwmRT, pwmLT);
    }
    else if (RB || LB) {
        moverT(pwmRB, pwmLB);
    }
    else {
        parar();
    }
}


// Se Controle conectado sinaliza e toca música
void onConnectedController(ControllerPtr ctl) {
    for (int i = 0; i < BP32_MAX_GAMEPADS; i++) {
        if (myControllers[i] == nullptr) {
            myControllers[i] = ctl;

            Serial.printf("Controle conectado! Slot %d\n", i);

            // Ao ligar toca a música
            for (int n = 0; n < notes * 2; n += 2) {

              divider = melody[n + 1];

              if (divider > 0) noteDuration = wholenote / divider;
              else noteDuration = (wholenote / abs(divider)) * 1.5;

              tone(BUZZER, melody[n], noteDuration * 0.9);
              delay(noteDuration);
              noTone(BUZZER);
              }
            delay(noteDuration);
            return;
        }
    }
}
// Se não...
void onDisconnectedController(ControllerPtr ctl) {
    for (int i = 0; i < BP32_MAX_GAMEPADS; i++) {
        if (myControllers[i] == ctl) {
            myControllers[i] = nullptr;

            Serial.printf("Controle desconectado! Slot %d liberado\n", i);
            return;
        }
    }
}



// Funções da Movimentação do Robô
void moverF(int pwmRT, int pwmLT) {
    // Motor esquerdo
    if (pwmRT > 10) {
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        analogWrite(ENA, pwmRT);
    }
    else {
        analogWrite(ENA, 0);
    }

    // Motor direito
    if (pwmLT > 10) {
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        analogWrite(ENB, pwmLT);
    }
    else {
        analogWrite(ENB, 0);
    }
}
void moverT(int pwmRB, int pwmLB) {
    // Motor esquerdo
    if (pwmRB > 10) {
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        analogWrite(ENA, pwmRB);
    }
    else {
        analogWrite(ENA, 0);
    }

    // Motor direito
    if (pwmLB > 10) {
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        analogWrite(ENB, pwmLB);
    }
    else {
        analogWrite(ENB, 0);
    }
}

void parar() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, 0);
    analogWrite(ENB, 0);
}


// Musica de Natal
int mIndex = 0;
unsigned long mTimer = 0;

void tocarMusicaAoConectar() {
    if (!tocarMusica) return;
    if (mIndex >= notes * 2) {
        tocarMusica = false;
        noTone(BUZZER);
        return;
    }

    if (millis() >= mTimer) {
        int nota = melody[mIndex];
        int div = melody[mIndex + 1];

        int duracao = (div > 0)
                      ? wholenote / div
                      : (wholenote / abs(div)) * 1.5;

        if (nota == 0) noTone(BUZZER);
        else tone(BUZZER, nota, duracao * 0.9);

        mTimer = millis() + duracao;
        mIndex += 2;
    }
}




// Setup e Loop
void setup() {
  Serial.begin(115200);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  parar();

  // Inicia os Controles
  BP32.setup(&onConnectedController, &onDisconnectedController);
  BP32.forgetBluetoothKeys();
}

void loop() {
  tocarMusicaAoConectar();
  
  if (BP32.update()) {
      for (auto ctl : myControllers) {
          if (ctl && ctl->isConnected() && ctl->hasData()) {
                processGamepad(ctl);
            }
        }
    }

    delay(20);
}