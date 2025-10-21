#include <Arduino.h>
#include <oled.h>
#include <IR.h>
#include <buttons.h>
#include <ultrasonic.h>

void setup(){
    Serial.begin(115200);

    if(initOled()){
        Serial.println("OLED init failed!");
        for(;;);
    };

    initUltrasonicSensor();

    initIrModules();

    initButtons();

    clearDisplay();
    delay(200);
    displayCat();
    delay(500);
    clearDisplay();
}

unsigned long now, lastButtonSend, lastDistanceDisplay, lastDistanceCalculation = 0;
unsigned int buttonCooldown = 50;

void loop(){
    now = millis();
    if(now - lastButtonSend >= buttonCooldown){
        sendNecIfButtonActive();
        lastButtonSend = now;
    }

    if(now - lastDistanceCalculation >= 50){
        calculateDistanceCm();
        lastDistanceCalculation = now;
    }

    if(now - lastDistanceDisplay >= 200){ 
        displayStdInfo();
        lastDistanceDisplay = now;
    }

    int dist = getDistanceCm();

    if(dist >= getLedTrigDistanceCm()) {
        ledOn();
    } else if(dist > 2 && dist < 200) { // filter out temporary 0 or huge spikes
        ledOff();
    }

    if(checkForSignal() && !checkForRepeatingSignals()){
        uint16_t cmd = getSignalCommand();
         Serial.print("Received: 0x");
        Serial.println(cmd, HEX);
        handleCommand(cmd);
    }

    resumeReceiver();
}