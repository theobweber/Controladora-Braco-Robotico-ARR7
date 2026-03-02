#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial bt(2, 3); // RX, TX

Servo Servo1;
Servo Servo2;
Servo Servo3;
Servo Servo4;
Servo Servo5;

int pos1 = 90;
int pos2 = 90;
int pos3 = 90;
int pos4 = 90;
int pos5 = 90;

char comandoAtual = 0;

unsigned long ultimoMovimento = 0;
const int intervalo = 15;   // velocidade do movimento
const int passo = 2;        // quanto move por vez

void setup() {

  Servo1.attach(8);
  Servo2.attach(7);
  Servo3.attach(6);
  Servo4.attach(5);
  Servo5.attach(4);

  bt.begin(9600);

  Servo1.write(pos1);
  Servo2.write(pos2);
  Servo3.write(pos3);
  Servo4.write(pos4);
  Servo5.write(pos5);
}

void loop() {

  if (bt.available()) {
    comandoAtual = bt.read();
  }

  if (millis() - ultimoMovimento >= intervalo) {

    ultimoMovimento = millis();

    switch (comandoAtual) {

      case 'F': pos1 += passo; break;
      case 'R': pos1 -= passo; break;

      case 'M': pos2 += passo; break;
      case 'N': pos2 -= passo; break;

      case 'O': pos3 += passo; break;
      case 'L': pos3 -= passo; break;

      case '.': pos4 += passo; break;
      case ',': pos4 -= passo; break;

      case 'A': pos5 += passo; break;
      case 'P': pos5 -= passo; break;
    }

    pos1 = constrain(pos1, 0, 180);
    pos2 = constrain(pos2, 0, 180);
    pos3 = constrain(pos3, 0, 180);
    pos4 = constrain(pos4, 40, 110);  // ajuste fino depois
    pos5 = constrain(pos5, 0, 180);

    Servo1.write(pos1);
    Servo2.write(pos2);
    Servo3.write(pos3);
    Servo4.write(pos4);
    Servo5.write(pos5);
  }
}