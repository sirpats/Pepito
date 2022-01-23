#include "Arduino.h"
#include "Pepito.h"
#include "SSD1306Ascii.h"
#include "SSD1306AsciiAvrI2c.h"

//constructor
Pepito::Pepito(float power)
{

  // default/initial pin assignments
  led 		= 15; //A1
  speaker 	= 3;
  lTracker 	= 16; //A2
  rTracker	= 17; //A3
  lMotorA	= 5;
  lMotorB	= 9;
  rMotorA	= 6;
  rMotorB	= 10; 

  // default geared motor rating
  maxMotorPower = 6; // volts
  minMotorPower = 3; // volts

  // power refers to the power supplied to the 
  // robot in volts
  _totalPower = power;	

  setDefaults();

  stop();

  // initializa oled screen
  #if RST_PIN >= 0
  	screen.begin(&Adafruit128x64, I2C_ADDRESS, RST_PIN);
  #else // RST_PIN >= 0
  	screen.begin(&Adafruit128x64, I2C_ADDRESS);
  #endif // RST_PIN >= 0
  // Call screen.setI2cClock(frequency) to change from the default frequency.

  screen.setFont(Adafruit5x7);


 // display power setting
 screen.clear();
 screen.set1X();
 screen.println("POWER SUPPLY SETTING ");
 screen.println();
 screen.set2X();
 screen.print(_totalPower);
 screen.println(" volts");
 screen.set1X();
 screen.println();
 screen.println("Is this correct?");
}

//destructor
Pepito::~Pepito()
{
	// nothing to destruct
}

void Pepito::setDefaults() {
  

  // set secondary default values/setting

  pinMode(led, OUTPUT);
  pinMode(speaker, OUTPUT);
  pinMode(lTracker, INPUT);
  pinMode(rTracker, INPUT);
  pinMode(lMotorA, OUTPUT);
  pinMode(lMotorB, OUTPUT);
  pinMode(rMotorA, OUTPUT);
  pinMode(rMotorB, OUTPUT);

  // set power limits
  if (_totalPower>maxMotorPower) {
   _maxPower =   (float(maxMotorPower)/float(_totalPower))*100.0;
  } else {
   _maxPower = 100;
  }

   _minPower =  (float(minMotorPower)/float(_totalPower))*100.0;
   if (_minPower<100) ++_minPower;
}


void Pepito::setAuxillary(byte Led, byte Speaker) {
 led = Led;
 speaker = Speaker;
}

void Pepito::setTrackers(byte leftTracker, byte rightTracker) {
 lTracker = leftTracker;
 rTracker = rightTracker;
}

void Pepito::setMotors(byte leftMotorA, byte leftMotorB, byte rightMotorA, byte rightMotorB) {
 lMotorA = leftMotorA;
 lMotorB = leftMotorB;
 rMotorA = rightMotorA;
 rMotorB = rightMotorB;
}

void Pepito::setMotorRating(float min, float max) {
 minMotorPower = min;
 maxMotorPower = max;
}

void Pepito::ledOn() {
  digitalWrite(led, HIGH);
}

void Pepito::ledOff() {
  digitalWrite(led, LOW);
}

void Pepito::blink(int duration) {
     ledOn();
     delay(duration);
     ledOff();
}

void Pepito::speakerOn() {
  digitalWrite(speaker, HIGH);
}

void Pepito::speakerOff() {
  digitalWrite(speaker, LOW);
}

void Pepito::beep(int power, int duration) {
     analogWrite(speaker, power);
     delay(duration);
     speakerOff();
}

int Pepito::leftTracker() {
    return digitalRead(lTracker);
}

int Pepito::rightTracker() {
    return digitalRead(rTracker);
}

int Pepito::maxPower() {
    return _maxPower;
}

int Pepito::minPower() {
    return _minPower;
}

float Pepito::distance(int trigPin, int echoPin) {
   long duration;
   pinMode(trigPin, OUTPUT);
   pinMode(echoPin, INPUT);

   digitalWrite(trigPin, LOW);
   delayMicroseconds(2);
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin, LOW);
   duration=pulseIn(echoPin, HIGH);
   return (duration/2)/29.15; 
}


void Pepito::setLeftMotor(int power) {
     byte p=map(abs(power), 1, 100, _minPower, _maxPower);
     if (power==0) p=0;
     p = p*2.55;

     if (power<0) {
         analogWrite(lMotorA, 0);
         analogWrite(lMotorB, p);
     } else {
         analogWrite(lMotorA, p);
         analogWrite(lMotorB, 0);
     }
}

void Pepito::setRightMotor(int power) {     
     byte p=map(abs(power), 1, 100, _minPower, _maxPower);
     if (power==0) p=0;
     p = p*2.55;

     if (power<0) {
         analogWrite(rMotorA, 0);
         analogWrite(rMotorB, p);
     } else {
         analogWrite(rMotorA, p);
         analogWrite(rMotorB, 0);
     }    
}

void Pepito::stop() {
    setLeftMotor(0);
    setRightMotor(0);
}


void Pepito::move(byte direction, byte power, int duration) {
    switch (direction) {
   	case 1:
      		setLeftMotor(power);
      		setRightMotor(power);
		break;
	case 2: 
		setLeftMotor(0-power);
     		setRightMotor(0-power);
		break;
	case 3:
		setLeftMotor(0-power);
     		setRightMotor(power);
		break;
	case 4:
		setLeftMotor(power);
     		setRightMotor(0-power);	
		break;
    }
    delay(duration);
    if (duration>0) stop();
}

