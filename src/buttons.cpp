#include <Arduino.h>
#include <IR.h>
#include <buttons.h>

// Buttons' pins: 8-12
#define UP_BUTTON_PIN 12
#define DOWN_BUTTON_PIN 11
#define RIGHT_BUTTON_PIN 9
#define LEFT_BUTTON_PIN 8
#define OK_BUTTON_PIN 10


void initButtons(){
    pinMode(UP_BUTTON_PIN, INPUT_PULLUP);
    pinMode(DOWN_BUTTON_PIN, INPUT_PULLUP);
    pinMode(RIGHT_BUTTON_PIN, INPUT_PULLUP);
    pinMode(LEFT_BUTTON_PIN, INPUT_PULLUP);
    pinMode(OK_BUTTON_PIN, INPUT_PULLUP);
}

bool isUpButtonPressed(){
    return !digitalRead(UP_BUTTON_PIN);
}

bool isDownButtonPressed(){
    return !digitalRead(DOWN_BUTTON_PIN);
}

bool isRightButtonPressed(){
    return !digitalRead(RIGHT_BUTTON_PIN);
}

bool isLeftButtonPressed(){
    return !digitalRead(LEFT_BUTTON_PIN);
}

bool isOkButtonPressed(){
    return !digitalRead(OK_BUTTON_PIN);
}


void sendNecIfButtonActive(){
    if(isUpButtonPressed()) sendNec(SIGNAL_UP);
    else if(isDownButtonPressed()) sendNec(SIGNAL_DOWN);
    else if(isRightButtonPressed()) sendNec(SIGNAL_RIGHT);
    else if(isLeftButtonPressed()) sendNec(SIGNAL_LEFT);
    else if(isOkButtonPressed()) sendNec(SIGNAL_OK);
}