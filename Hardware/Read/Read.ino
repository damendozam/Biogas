#include <Wire.h>

#include "SparkFunBME280.h"
BME280 sensorHumTempPress; //Uses default I2C address 0x77

// MQ 135
double varAMQ135 = -0.3513615;
double varBMQ135 = -0.0025928;
double varCMQ135 = -0.0010671;
double varDMQ135 = 0.8343359;

// MQ 4
double varAMQ4 = -0.3532477;
double varBMQ4 = -0.0014940;
double varCMQ4 = -0.00136591;
double varDMQ4 = 1.17718719;

//RL
double varRL = 20; //valor en kOhm

double varR0MQ135=0;
double varR0MQ4=0;

void setup()
{
  Serial.begin(9600);
  Wire.begin();
  double varRLMQ135 = analogRead(A2);
  double varRLMQ4   = analogRead(A1); 
  double varVC      = analogRead(A0);

  double varRSMQ135 = (varVC*varRL/varRLMQ135) - varRL;
  double varRSMQ4   =  (varVC*varRL/varRLMQ4) - varRL;

  varR0MQ135 = varRSMQ135/3.6016140772527665;
  varR0MQ4   = varRSMQ4/4.4366873309786135;

  
  sensorHumTempPress.setI2CAddress(0x76); //Connect to a second sensor
  if(sensorHumTempPress.beginI2C() == false) Serial.println("Sensor connect failed");

  /*Serial.println(varRLMQ135);
  Serial.println(varRLMQ4);
  Serial.println(varVC);*/
}

void loop()
{

  double varZMQ135 = sensorHumTempPress.readTempC();
  double varZMQ4 = sensorHumTempPress.readTempC();

  double varUMQ135 = sensorHumTempPress.readFloatHumidity();
  double varUMQ4 = sensorHumTempPress.readFloatHumidity();

  double varRLMQ135 = analogRead(A2);
  double varRLMQ4   = analogRead(A1); 
  double varVC      = analogRead(A0);
  
  double varRSMQ135 = (varVC*varRL/varRLMQ135) - varRL;
  double varRSMQ4   =  (varVC*varRL/varRLMQ4) - varRL;

  double varYMQ135 = varRSMQ135/varR0MQ135;  //Sensibilidad [Ohm/Ohm]
  //double varZMQ135 = 20; //Temperatura [°C]
  //double varUMQ135 = 65; //Humedad [%]

  double varYMQ4 = varRSMQ4/varR0MQ4;  //Sensibilidad [Ohm/Ohm]
  //double varZMQ4 = 20; //Temperatura [°C]
  //double varUMQ4 = 65; //Humedad [%]

   

  double varXMQ135 = pow(varYMQ135 * pow(10,-(varBMQ135 * varZMQ135 + varCMQ135 * varUMQ135 + varDMQ135)),1/varAMQ135);  //Concentración MQ 135 [ppm]
  /*Serial.print("MQ 135: ");
  Serial.print(varXMQ135);
  Serial.print("\t,\t");*/

  double varXMQ4 = pow(varYMQ4 * pow(10,-(varBMQ4 * varZMQ4 + varCMQ4 * varUMQ4 + varDMQ4)),1/varAMQ4);  //Concentración MQ 4 [ppm]
  /*Serial.print("MQ 4: ");
  Serial.println(varXMQ4);*/

  Serial.print(varRLMQ135*5000/1023);
  Serial.print(",");
  Serial.print(varRLMQ4*5000/1023);
  Serial.print(",");
  Serial.print(varYMQ135);
  Serial.print(",");
  Serial.print(varYMQ4);
  Serial.print(",");
  Serial.print(varXMQ135);
  Serial.print(",");
  Serial.print(varXMQ4);
  Serial.print(",");
  Serial.print(varZMQ135);
  Serial.print(",");
  Serial.print(varUMQ135);
  Serial.println();

}