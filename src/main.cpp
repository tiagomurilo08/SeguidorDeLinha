#include <Arduino.h>
//ROBO NUMERO 10
#define SENSOR1 A0
#define SENSOR2 A1
#define SENSOR3 A2
#define SENSOR4 A3
#define SENSOR5 A6
#define SENSOR6 A7
/*Motor Direito*/
#define RIGHT_PWM 9
#define RIGHT_IN2 7
#define RIGHT_IN1 8
/**Habilita a Locomoção*/
#define STBY 6 
/*Motor Esquerdo*/
#define LEFT_IN1 4
#define LEFT_IN2 5
#define LEFT_PWM 3
/*Portas Bluetooth*/
#define BLUETOOTH_TX 10
#define BLUETOOTH_RX 11


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
}


void loop() {
  // put your main code here, to run repeatedly:

  int sen4, sen5, sen6, velEsquerda;
  int sen3, sen2, sen1, velDireita;

  
  sen1 = analogRead(SENSOR1);
  sen2 = analogRead(SENSOR2);
  sen3 = analogRead(SENSOR3);
  sen4 = analogRead(SENSOR4);
  sen5 = analogRead(SENSOR5);
  sen6 = analogRead(SENSOR6);

  digitalWrite(STBY, HIGH);

  digitalWrite(RIGHT_IN1, HIGH);
  digitalWrite(RIGHT_IN2, LOW);
  digitalWrite(LEFT_IN1, LOW);
  digitalWrite(LEFT_IN2, HIGH);

  if(sen4<500 && sen3<500){
    analogWrite(RIGHT_PWM, 100);
    analogWrite(LEFT_PWM, 100);
  }else if(sen4<500 && sen3>500){
    analogWrite(RIGHT_PWM, 100);
    analogWrite(LEFT_PWM, 60);
  }else if(sen4>500 && sen3<500){
    analogWrite(RIGHT_PWM, 60);
    analogWrite(LEFT_PWM, 100);
  }else if(sen4>500 && sen3>500 && sen5<500){
    analogWrite(RIGHT_PWM, 100);
    analogWrite(LEFT_PWM, 10);
  }else if(sen4>500 && sen3>500 && sen2<500){
    analogWrite(RIGHT_PWM, 10);
    analogWrite(LEFT_PWM, 100);
  }else{
    analogWrite(RIGHT_PWM, 0);
    analogWrite(LEFT_PWM, 0);
  }
  //Serial.println(analogRead(SENSOR4));


}
