#include "Pepito.h"

Pepito robot(9); // 9 volts (use 3.8 if using USB power)

void setup() {
  // put your setup code here, to run once:

  // format: robot.move(direction, power/percentage, duration in milliseconds)
  robot.move(FORWARD, 10, 500);
  robot.move(REVERSE, 10, 500);
  robot.move(LEFT, 10, 500);
  robot.move(RIGHT, 10, 500);

  robot.blink(100);
  robot.beep(128,50);
}

void loop() {
  // put your main code here, to run repeatedly:

  robot.screen.clear();
  robot.screen.set2X();
  robot.screen.print("DIST: ");
  //robot.screen.println(robot.distanceX(2,4)); // alternative function
  robot.screen.println(robot.distance());  
  robot.screen.print("LTRACKER:");
  robot.screen.println(robot.leftTracker());
  robot.screen.print("RTRACKER:");
  robot.screen.println(robot.rightTracker());
  delay(500);
}
