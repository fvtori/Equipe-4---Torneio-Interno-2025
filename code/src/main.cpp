#include <Arduino.h>
#include <Bluepad32.h>

//Cria uma lista para armazenar os controles conectados
ControllerPtr myControllers[BP32_MAX_GAMEPADS];

// Define os pinos dos Motores
// A definição dos pinos não tá pronta, esse é só um exemplo temporário
int ENA = 12;  // Velocidade Motor Esquerdo (PMW)
int IN1 = 26;  // Motor Esquerdo - Frente
int IN2 = 17;  // Motor Esquerdo - Trás
int ENB = 33;  // Velocidade Motor Direito (PMW)
int IN3 = 14;  // Motor Direito - Frente
int IN4 = 12;  // Motor Direito - Trás
int BUZZER = 34;



//Funções da Biblioteca
void processGamepad(ControllerPtr ctl) {
    //Define que usará o Joystick Direito pra andar
    int RStickX = ctl->axisRX();
    int RStickY = -ctl->axisRY();

    // Zona morta para evitar trepidação
    if (abs(RStickX) < 20) RStickX = 0;
    if (abs(RStickY) < 20) RStickY = 0;

    //Re-mapea os valores do Joystick
    int pwmEsquerda  = constrain(map(RStickY + RStickX, -1023, 1023, -255, 255), -255, 255);
    int pwmDireita = constrain(map(RStickY - RStickX, -1023, 1023, -255, 255), -255, 255);

    
    //Comandos de Direção
    if (pwmDireita >= 85) 
    {
      frente();
    }
  else if (pwmDireita <= -85) 
    {
      tras();
    }
    else if (pwmEsquerda >= 85) 
    {
      esquerda();
    }
    else if (pwmEsquerda <= -85)
    {
      direita();
    }
    else 
    {
      parar();
    }
  }

  void onConnectedController(ControllerPtr ctl) {
    for (int i = 0; i < BP32_MAX_GAMEPADS; i++) {
        if (myControllers[i] == nullptr) {
            myControllers[i] = ctl;
            Serial.printf("Controle conectado! Slot %d\n", i);
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



void setup() 
{ 
  //Configuração dos pinos e ponte H
  Serial.begin(115200);
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  //Testa a conexão do Controle
  BP32.setup(&onConnectedController, &onDisconnectedController);
  BP32.forgetBluetoothKeys();
}

void loop() 
{
  if (BP32.update()) {
        for (auto ctl : myControllers) {
            if (ctl && ctl->isConnected() && ctl->hasData()) {
                processGamepad(ctl);
            }
        }
    }

    delay(20);
}



//Funções das Direções
void parar()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

void frente()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
}

void tras()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
}

void esquerda()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
}

void direita()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
}