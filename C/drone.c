
#include "BluetoothSerial.h"

#define u8bit unsigned char

// Definir pinos de entrada e saída

u8bit MOTOR_NO = 0;
u8bit MOTOR_NE = 1;
u8bit MOTOR_SO = 2;
u8bit MOTOR_SE = 3;

// Hélices = +, -, -, + (+hor, -ant)

u8bit BOTAO_W = 4; // Frente
u8bit BOTAO_A = 5; // Esquerda
u8bit BOTAO_S = 6; // Trás 
u8bit BOTAO_D = 7; // Direita

u8bit BOTAO_I =  8; // Cima
u8bit BOTAO_J =  9; // Anti-Horário
u8bit BOTAO_K = 10; // Baixo
u8bit BOTAO_L = 11; // Horário

u8bit lerBotao(void)
{
  if(digitalRead(BOTAO_W) != HIGH) return  3;
  if(digitalRead(BOTAO_A) != HIGH) return  5;
  if(digitalRead(BOTAO_S) != HIGH) return 12;
  if(digitalRead(BOTAO_D) != HIGH) return 10;

  if(digitalRead(BOTAO_I) != HIGH) return 15;
  if(digitalRead(BOTAO_J) != HIGH) return  9;
  if(digitalRead(BOTAO_K) != HIGH) return  0;
  if(digitalRead(BOTAO_L) != HIGH) return  6;
}

void girarMotor(u8bit faixa)
{
  switch(faixa)
  {
    case 15:
      digitalWrite(MOTOR_NO, HIGH);
      digitalWrite(MOTOR_NE, HIGH);
      digitalWrite(MOTOR_SO, HIGH);
      digitalWrite(MOTOR_SE, HIGH); break;

    case 12:
      digitalWrite(MOTOR_NO, HIGH);
      digitalWrite(MOTOR_NE, HIGH);
      digitalWrite(MOTOR_SO,  LOW);
      digitalWrite(MOTOR_SE,  LOW); break;

    case 10:
      digitalWrite(MOTOR_NO, HIGH);
      digitalWrite(MOTOR_NE,  LOW);
      digitalWrite(MOTOR_SO, HIGH);
      digitalWrite(MOTOR_SE,  LOW); break;

    case 9:
      digitalWrite(MOTOR_NO, HIGH);
      digitalWrite(MOTOR_NE,  LOW);
      digitalWrite(MOTOR_SO,  LOW);
      digitalWrite(MOTOR_SE, HIGH); break;

    case 6:
      digitalWrite(MOTOR_NO,  LOW);
      digitalWrite(MOTOR_NE, HIGH);
      digitalWrite(MOTOR_SO, HIGH);
      digitalWrite(MOTOR_SE,  LOW); break;

    case 5:
      digitalWrite(MOTOR_NO,  LOW);
      digitalWrite(MOTOR_NE, HIGH);
      digitalWrite(MOTOR_SO,  LOW);
      digitalWrite(MOTOR_SE, HIGH); break;

    case 3:
      digitalWrite(MOTOR_NO,  LOW);
      digitalWrite(MOTOR_NE,  LOW);
      digitalWrite(MOTOR_SO, HIGH);
      digitalWrite(MOTOR_SE, HIGH); break;

    case 0:
      digitalWrite(MOTOR_NO, LOW);
      digitalWrite(MOTOR_NE, LOW);
      digitalWrite(MOTOR_SO, LOW);
      digitalWrite(MOTOR_SE, LOW); break;

    default: break;
  }
}

BluetoothSerial SerialBT;

void setup()
{
  pinMode(MOTOR_NO, OUTPUT);
  pinMode(MOTOR_NE, OUTPUT);
  pinMode(MOTOR_SO, OUTPUT);
  pinMode(MOTOR_SE, OUTPUT);

  pinMode(BOTAO_W, INPUT);
  pinMode(BOTAO_A, INPUT);
  pinMode(BOTAO_S, INPUT);
  pinMode(BOTAO_D, INPUT);

  pinMode(BOTAO_I, INPUT);
  pinMode(BOTAO_J, INPUT);
  pinMode(BOTAO_K, INPUT);
  pinMode(BOTAO_L, INPUT);

  Serial.begin(9600);
  SerialBT.begin("Drone");

  delay(5000);
}

void loop()
{
  if (SerialBT.available() > 0) Serial.println(SerialBT.read());

  girarMotor(lerBotao());

  delay(10);
}
