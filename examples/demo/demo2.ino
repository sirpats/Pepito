#include "Pepito.h"

Pepito robot(9); // 9 volts


void setup() {
  // put your setup code here, to run once:

  robot.screen.set2X();
  robot.screen.clear();

  /*
  robot.ledOn();robot.beep(255,50);robot.ledOff();
  robot.screen.println("THIS IS\nNORMAL");
  robot.screen.println("Press 1 to\ncontinue");
  while (robot.buttonPress()!=1) {  }

  //rotate screen display
  robot.screen.displayRemap(true);

  robot.ledOn();robot.beep(255,50);robot.ledOff();
  robot.screen.clear();
  robot.screen.println("THIS IS \nFLIPPED");
  robot.screen.println("Press 2 to \ncontinue");
  while (robot.buttonPress()!=2) {  }

  //rotate screen display
  robot.screen.displayRemap(false);

  robot.ledOn();robot.beep(255,50);robot.ledOff();
  robot.screen.clear();
  robot.screen.println("BACK TO \nNORMAL");
  robot.screen.println("Press 3 to \ncontinue");
  while (robot.buttonPress()!=3) {  }
  */
  //rotate screen display
  robot.screen.displayRemap(true);
  robot.screen.clear();
  robot.screen.set2X();

  robot.screen.println("ROBOT IS \nREADY");
  robot.screen.println("Press 1 to \ncontinue");
  while (robot.buttonPress()!=1) {  }
  robot.screen.clear();
  //robot.screen.println("SELECT AN OPTION");
  robot.screen.println("1. FORWARD");
  robot.screen.println("2. REVERSE");
  robot.screen.println("3. LEFT");
  robot.screen.println("4. RIGHT");
  //robot.screen.println("5. LED  ");

}


void loop() {
  // put your main code here, to run repeatedly:
  byte b=0;

  
    robot.screen.set2X();
    b=robot.buttonPress();

  /*
  while (b==0) {  
         b=robot.buttonPress();
         if (robot.distanceX(2,4)<5) {
            robot.beep(255,50);
            robot.screen.clear();
            robot.screen.println("OBSTRUC\nTION");
            delay(3000);
            robot.screen.clear();
            break;
         }
         if (robot.leftTracker()) {
            robot.beep(255,50);
            robot.screen.clear();
            robot.screen.println("BLACK ON \nLEFT");
            delay(3000);
            robot.screen.clear();
            break;
         }         
        if (robot.rightTracker()) {
            robot.beep(255,50);
            robot.screen.clear();
            robot.screen.println("BLACK ON \nRIGHT");
            delay(3000);
            robot.screen.clear();
            break;
         }       
  }*/

  switch (b) {
    case 1:robot.move(FORWARD, 30, 1000);
           break;
    case 2:robot.move(REVERSE, 30, 1000);
           break;       
    case 3:robot.move(LEFT, 30, 1000);
           break;
    case 4:robot.move(RIGHT, 30, 1000);
           break;
    case 5:digitalWrite(robot.led,!digitalRead(robot.led));
           robot.beep(255,500);
           break;
  }

}