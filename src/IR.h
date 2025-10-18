#pragma once
#include <Arduino.h>

enum Signals{
    SIGNAL_OK = 0xAF,
    SIGNAL_UP = 0xFD,
    SIGNAL_DOWN = 0xD3,
    SIGNAL_RIGHT = 0xF1,
    SIGNAL_LEFT = 0xC3
};

void initIrModules();
void sendNec(uint16_t command, uint16_t address = 0xFF);
bool checkForSignal();
bool checkForSignal();
void handleCommand(uint16_t command);
uint16_t getSignalCommand();
void resumeReceiver();
bool checkForRepeatingSignals();
