Version 1 contains basic functions that easily allow the use of 

the robot's LED, speaker, line trackers, distance sensor and motors.

The use of the OLED requires the SSD1306Ascii (https://github.com/greiman/SSD1306Ascii) library to be installed.

The connections/pin assignments and motor rating defaults may be overridden by changing the values of the following public variables:
                        
    VARIABLE            DEFAULT VALUE/PIN         DESCRIPTION
    led                 15/A1                     LED
    speaker             D3                        SPEAKER/BUZZER
    lTracker            16/A2                     LEFT LINE TRACKER
    rTracker            17/A3                     RIGHT LINE TRACKER
    lMotorA             D5                        LEFT MOTOR PIN A
    lMotorB             D9                        LEFT MOTOR PIN B
    rMotorA             D6                        RIGHT MOTOR PIN A
    rMotorB             D10                       RIGHT MOTOR PIN B
    minMotorPower       3.0                       MINIMUM VOLTAGE
    maxMotorPower       6.0                       MAXIMUM VOLTAGE
    
    Override examples:
        setAuxillary(14,3); // set new LED and speaker pins
        setTrackers(16,18); // set new left and right line tracker pins
        setMotors(5,6,9,10); // set new left (first pair) and right (second pair) motor pins
        setMotorRating(3,7); // set new motor rating (min and max)
        setDefaults(); // reset/change defaults (call the setDefaults() function to reset default values based on changes)