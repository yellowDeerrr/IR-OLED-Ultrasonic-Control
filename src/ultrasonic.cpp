#include <ultrasonic.h>
#include <Arduino.h>

#define LED_PIN 2

int ledTrigDistanceCm = 10;

#define ECHO_ULTRASONIC_PIN 6
#define TRIG_ULTRASONIC_PIN 7

int duration, distanceCm;

void initUltrasonicSensor(){
    pinMode(TRIG_ULTRASONIC_PIN, OUTPUT); 
    pinMode(ECHO_ULTRASONIC_PIN, INPUT); 
    pinMode(LED_PIN, OUTPUT);
}

int calculateDistanceCm(){
    digitalWrite(TRIG_ULTRASONIC_PIN, LOW);
    delayMicroseconds(2);

    digitalWrite(TRIG_ULTRASONIC_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite (TRIG_ULTRASONIC_PIN, LOW);

    duration = pulseIn(ECHO_ULTRASONIC_PIN, HIGH);
    distanceCm = (duration/2) / 29.1;
    return distanceCm;
}

int getDistanceCm(){
    return distanceCm;
}

int getLedTrigDistanceCm(){
    return ledTrigDistanceCm;
}

void setLedTrigDistanceCm(int value){
    ledTrigDistanceCm = value;
}

void increaseLedTrigDistanceBy10(){
    int val = getLedTrigDistanceCm();
    val += 10;
    if(val > 200) val = 200; // max distance
    setLedTrigDistanceCm(val);
}

void decreaseLedTrigDistanceBy10(){
    int val = getLedTrigDistanceCm();
    val -= 10;
    if(val < 0) val = 0; // min distance
    setLedTrigDistanceCm(val);
}

void ledOn(){
    digitalWrite(LED_PIN, HIGH);
}

void ledOff(){
    digitalWrite(LED_PIN, LOW);
}