#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

#include "Escornabot.h"

double angle_rad = PI/180.0;
double angle_deg = 180.0/PI;
Escornabot escornabot;



void setup(){
    escornabot.turnLED(1);
    escornabot.beep(4699, uint16_t(0.1*1000));
    while(!(escornabot.isButtonPressed("GO")))
    {
        _loop();
    }
    
}

void loop(){
    
    escornabot.move(10);
    escornabot.beep(2637, uint16_t(0.1*1000));
    escornabot.turn(90);
    escornabot.beep(4434, uint16_t(0.1*1000));
    
    _loop();
}

void _delay(float seconds){
    long endTime = millis() + seconds * 1000;
    while(millis() < endTime)_loop();
}

void _loop(){
    
}

