#include <Arduino.h>
#include <clockDigits.h>
// #include <IRremote.hpp>


void setup(){
   Serial.begin(9600);
//    IrReceiver.begin(A1, ENABLE_LED_FEEDBACK);
}

void loop(){
    
    // Clock.setAlarm(13, 45);
    Clock.start();
}