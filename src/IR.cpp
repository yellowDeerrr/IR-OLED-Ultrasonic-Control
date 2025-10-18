#include <IR.h>
#include <ultrasonic.h>

#define DECODE_NEC

#include <IRremote.hpp>

#define IR_RECEIVER_PIN 4
#define IR_TRANSMITTER_PIN 5

void initIrModules(){
    IrReceiver.begin(IR_RECEIVER_PIN, ENABLE_LED_FEEDBACK);
    IrSender.begin(IR_TRANSMITTER_PIN);
}

void sendNec(uint16_t command, uint16_t address) {
    IrSender.sendNEC(address, command, 1);
}


bool checkForSignal(){
    return IrReceiver.decode();
}

uint16_t getSignalCommand(){
    return IrReceiver.decodedIRData.command;
}

void resumeReceiver(){
    IrReceiver.resume();
}

bool checkForRepeatingSignals(){
    return IrReceiver.decodedIRData.flags & IRDATA_FLAGS_IS_REPEAT;
}

void handleCommand(uint16_t command){
    switch (command)
    {
    case SIGNAL_OK:
        break;

    case SIGNAL_UP:
        increaseLedTrigDistanceBy10();
        break;

    case SIGNAL_DOWN:
        decreaseLedTrigDistanceBy10();
        break;

    case SIGNAL_RIGHT:
        break;

    case SIGNAL_LEFT:
        break;

    }
}
