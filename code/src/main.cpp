#include <Arduino.h>
#include <ESP32Servo.h>   //Bibliotecas ESP32
#include <analogWrite.h>
#include <ESP32Tone.h>
#include <ESP32PWM.h>

#include <BLEController.h>

#define leftMotorPin 25   //Pino Motor Esquerdo
#define rightMotorPin 26  //Pino Motor Direito

Servo MotorEsquerdo;
Servo MotorDireito;


void setup() 
{
  Serial.begin(115200);
  controller.begin();

  while(!controller.isConnected())    //Se Controle não estiver conectado vai printar isso
  {
    Serial.println("Esperando Conexão");
    delay(250);
  }

  MotorEsquerdo.attach(leftMotorPin);
  MotorDireito.attach(rightMotorPin);
  MotorEsquerdo.write(90);
  MotorDireito.write(90);

  Serial.println("Conexão Estabelecida");    //Se Controle estiver conectado vai printar isso
}

void loop() 
{
  if (controller.isConnected()) 
  {
    int RStickX = e.rightStickX;    //Vai andar ao usar o Joystick Esquerdo
    int RStickY = e.rightStickY;

    int leftMotorOutput  = constrain(map(LStickY + LStickX, -127, 127, 0, 180), 0, 180); //Mapear os valores 
    int rightMotorOutput = constrain(map(LStickY - LStickX, -127, 127, 0, 180), 0, 180);

    if (abs(LStickY) > 15 || abs(LStickX) > 15) 
    {
      MotorEsquerdo.write(leftMotorOutput);
      MotorDireito.write(rightMotorOutput);
    } 
    else 
    {
      MotorEsquerdo.write(90);
      MotorDireito.write(90);
    }
  }


  Serial.print(leftMotorOutput);    //Verificação se os valores de Saída estão corretos
  Serial.print(" ");
  Serial.println(rightMotorOutput);
}
