/*
  Pepito.h - Library for Pepito, the mini robot
  Created by Dennis Cesar R. Patino, January 22, 2022
  Released into the public domain
*/

#ifndef Pepito_h
#define Pepito_h

#include "Arduino.h"
#include "SSD1306Ascii.h"
#include "SSD1306AsciiAvrI2c.h"
// 0X3C+SA0 - 0x3C or 0x3D
#define I2C_ADDRESS 0x3C
// Define proper RST_PIN if required.
#define RST_PIN -1



#define FORWARD 1
#define REVERSE 2
#define LEFT 3
#define RIGHT 4


class Pepito 
{
  public:
	Pepito(float power);	// total power in volts
	~Pepito();
 	void setPower(float power);
	void ledOn();
	void ledOff();
	void blink(int duration);
	void speakerOn();
	void speakerOff();
	void beep(int power, int duration);
	int leftTracker();
	int rightTracker();
	int maxPower();
	int minPower();
	float distance(int trigPin, int echoPin);
	void setLeftMotor(int power);
	void setRightMotor(int power);
	void stop();
	void move(byte direction, byte power, int duration);
	byte led;
	byte speaker;
	byte lTracker;
	byte rTracker;
	byte lMotorA;
	byte lMotorB;
	byte rMotorA;
	byte rMotorB;
	byte maxMotorPower;
	byte minMotorPower;
	SSD1306AsciiAvrI2c screen;

  private:
	int _minPower;
	int _maxPower;
	int _totalPower;

}; // don't forget this semi-colon

#endif