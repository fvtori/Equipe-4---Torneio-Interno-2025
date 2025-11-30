#include <Arduino.h>
#include <Bluepad32.h>

// Cria uma lista para armazenar os controles conectados
ControllerPtr myControllers[BP32_MAX_GAMEPADS];

// Define os pinos dos Motores
int ENA = 25;  // Velocidade Motor Esquerdo (PWM)
int IN1 = 26;  // Motor Esquerdo - Frente
int IN2 = 27;  // Motor Esquerdo - Trás
int ENB = 33;  // Velocidade Motor Direito (PWM)
int IN3 = 14;  // Motor Direito - Frente
int IN4 = 12;  // Motor Direito - Trás
int BUZZER = 32;

// Constantes de controle
const int DEADZONE = 120;        // zona morta radial (quanto maior, menos sensível)
const int TURN_THRESHOLD = 200;  // a partir de quanto X começa a virar de verdade
const int MIN_PWM = 80;          // PWM mínimo para o motor realmente se mover

// Protótipos das funções
void processGamepad(ControllerPtr ctl);
void onConnectedController(ControllerPtr ctl);
void onDisconnectedController(ControllerPtr ctl);
void mover(int pwmEsquerda, int pwmDireita);
void parar();



// Funções da Biblioteca //
void processGamepad(ControllerPtr ctl) {
    // Usa o joystick direito
    int RStickX = ctl->axisRX();
    int RStickY = -ctl->axisRY();   // Inverte Y para "cima = frente"

    // Zona Morta radial
    long mag2 = (long)RStickX * RStickX + (long)RStickY * RStickY;
    if (mag2 < (long)DEADZONE * DEADZONE) {
        RStickX = 0;
        RStickY = 0;
    }

    int pwmEsquerda = 0;
    int pwmDireita  = 0;

    // Movimento quase reto, usa só Y igual pros dois
    if (abs(RStickX) < TURN_THRESHOLD) {
        int pwm = constrain(map(RStickY, -1023, 1023, -255, 255), -255, 255);
        pwmEsquerda = pwm;
        pwmDireita  = pwm;
    } else {
        //Curva usa mix de tanque
        pwmEsquerda  = constrain(map(RStickY + RStickX, -1023, 1023, -255, 255), -255, 255);
        pwmDireita   = constrain(map(RStickY - RStickX, -1023, 1023, -255, 255), -255, 255);
    }

    // Se estiver bem no centro, para
    if (abs(pwmEsquerda) < 10 && abs(pwmDireita) < 10) {
        parar();
    } else {
        mover(pwmEsquerda, pwmDireita);
    }
}

void onConnectedController(ControllerPtr ctl) {
    for (int i = 0; i < BP32_MAX_GAMEPADS; i++) {
        if (myControllers[i] == nullptr) {
            myControllers[i] = ctl;
            Serial.printf("Controle conectado! Slot %d\n", i);

            // Bip no buzzer quando conecta
            digitalWrite(BUZZER, HIGH);
            delay(100);
            digitalWrite(BUZZER, LOW);

            return;
        }
    }
}

void onDisconnectedController(ControllerPtr ctl) {
    for (int i = 0; i < BP32_MAX_GAMEPADS; i++) {
        if (myControllers[i] == ctl) {
            myControllers[i] = nullptr;
            Serial.printf("Controle desconectado! Slot %d liberado\n", i);
            return;
        }
    }
}




void setup() {
    Serial.begin(115200);

    // Pinos da ponte H e buzzer
    pinMode(ENA, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(ENB, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    pinMode(BUZZER, OUTPUT);

    parar();  // Tudo parado quando iniciar

    BP32.setup(&onConnectedController, &onDisconnectedController); // Testa a conexão do controle
    BP32.forgetBluetoothKeys();   // Limpa pareamentos antigos
}

void loop() {
    if (BP32.update()) {
        for (auto ctl : myControllers) {
            if (ctl && ctl->isConnected() && ctl->hasData()) {
                processGamepad(ctl);
            }
        }
    }

    delay(20);   //Delay para suavizar leitura
}




// Funções //
void mover(int pwmEsquerda, int pwmDireita) {
    // Garante limite de 0–255 pro PWM
    int velE = constrain(abs(pwmEsquerda), 0, 255);
    int velD = constrain(abs(pwmDireita), 0, 255);

    // Aplica PWM mínimo quando há comando
    if (velE > 0 && velE < MIN_PWM) velE = MIN_PWM;
    if (velD > 0 && velD < MIN_PWM) velD = MIN_PWM;

    //Motor Esquerdo
    if (pwmEsquerda > 0) {
        // Frente
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
    } else if (pwmEsquerda < 0) {
        // Trás
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
    } else {
        // Parado
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
    }
    analogWrite(ENA, velE);

    // Motor Direito
    if (pwmDireita > 0) {
        // Frente
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
    } else if (pwmDireita < 0) {
        // Trás
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
    } else {
        // Parado
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
    }
    analogWrite(ENB, velD);
}

void parar() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, 0);
    analogWrite(ENB, 0);
}