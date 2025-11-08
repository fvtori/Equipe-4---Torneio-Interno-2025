#include <Arduino.h>

#include <Bluepad32.h>

// Define os pinos dos Motores
// A definição dos pinos não tá pronta, esse é só um exemplo temporário
int IN1 = 26;  // Motor Esquerdo - Frente
int IN2 = 25;  // Motor Esquerdo - Trás
int IN3 = 33;  // Motor Direito - Frente
int IN4 = 32;  // Motor Direito - Trás
int BUZZER = 27;


void setup() 
{ 
  //Configuração dos pinos
  Serial.begin(115200);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  //Inicia o Controle
  controller.begin();

  //Testa a conexão do Controle
  while(!controller.isConnected())
  {
    Serial.println("Esperando Conexão");
    delay(250);
  }
  Serial.println("Conexão Estabelecida");
}

void loop() 
{
  if (controller.isConnected()) 
  {
    //Define que usará o Joystick Direito pra andar
    int RStickX = e.rightStickX;
    int RStickY = e.rightStickY;

    //Re-mapea os valores do Joystick
    int pwmEsquerda  = constrain(map(LStickY + LStickX, -127, 127, -255, 255), -255, 255);
    int pwmDireita = constrain(map(LStickY - LStickX, -127, 127, -255, 255), -255, 255);

    //Comandos de Direção
    if (pwmDireita >= 85) 
    {
      PS4.sendToController();
      frente();
    }
  else if (pwmDireita <= -85) 
    {
      PS4.sendToController();
      tras();
    }
    else if (pwmEsquerda >= 85) 
    {
      PS4.sendToController();
      esquerda();
    }
    else if (pwmEsquerda <= -85)
    {
      PS4.sendToController();
      direita();
    }
    else 
    {
      parar()
    }
  }

  //Verificação se os valores de Saída estão corretos
  Serial.print(leftMotorOutput);
  Serial.print(" ");
  Serial.println(rightMotorOutput);
}





//Funções das Direções
void parar()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void frente()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void tras()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void esquerda()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void direita()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
