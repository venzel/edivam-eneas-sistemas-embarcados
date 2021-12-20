#include <Arduino.h>

int pinoLed = 7;
int pinoChave = 2; 
int stateSwap = 0; 
int timeH = 2000;
int timeL = 1000; 

void setup() {
  pinMode(pinoLed, OUTPUT);
  pinMode(pinoChave, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pinoChave), blk, FALLING);                              
}                                                              

void loop(){
  digitalWrite(pinoLed, HIGH); 
  delay(timeH); 
  digitalWrite(pinoLed, LOW); 
  delay(timeL); 
}

void blk() { 
  stateSwap = !stateSwap; 
  if (stateSwap == 1) {
    timeH = 2000; 
    timeL = 1000; 
  } else {
    timeH = 5000; 
    timeL = 25000; 
  }
}