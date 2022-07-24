/*
 * The circuit:
    SD card attached to SPI bus as follows:
 ** MOSI/DI - pin 11 on Arduino Uno/Duemilanove/Diecimila
 ** MISO/DO - pin 12 on Arduino Uno/Duemilanove/Diecimila
 ** CLK - pin 13 on Arduino Uno/Duemilanove/Diecimila
 ** CS - depends on your SD card shield or module.
    Pin 10 used here for consistency with other Arduino examples

 Connect Speaker pin to 9 pin.
 Switch/ button to 2 and 3 no of pins.
    
 */

#include "SD.h"
#define SD_ChipSelectPin 10
#include "TMRpcm.h"
#include "SPI.h"
const int sw1=2, sw2=3;

TMRpcm tmrpcm;

void setup(){
  
Serial.begin(9600);
tmrpcm.speakerPin = 9;
pinMode(sw1, INPUT_PULLUP);
pinMode(sw2, INPUT_PULLUP);
Serial.println("Serial Begin");

if (!SD.begin(SD_ChipSelectPin)) {
Serial.println("SD card fail");
return;
}
Serial.println("SD Card OK");
delay(1000);
tmrpcm.setVolume(5);
}

void loop()
{ 
  int sw1s=digitalRead(sw1);
  int sw2s=digitalRead(sw2);
  if(sw1s==LOW)
  {
    delay(10);
    sw1s=digitalRead(sw1);
    if(sw1s==HIGH)
    {
      Serial.println("1st Audio Start");
      delay(100);
      tmrpcm.play("sme1.wav");
      delay(6000);
    }
  }
  if(sw2s==LOW)
  {
    delay(10);
    sw2s=digitalRead(sw2);
    if(sw2s==HIGH)
    {
      Serial.println("2nd Audio Start");
      delay(100);
      tmrpcm.play("sme2.wav");
      delay(6000);
    }
  }  
}
