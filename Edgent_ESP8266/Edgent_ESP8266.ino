
// Fill-in information from your Blynk Template here
//#define BLYNK_TEMPLATE_ID           "TMPLxxxxxx"
//#define BLYNK_DEVICE_NAME           "Device"
#define BLYNK_TEMPLATE_ID "TMPLFxmhwjUL"
#define BLYNK_DEVICE_NAME "LabThang"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

#include "SoftwareSerial.h"

SoftwareSerial NodeSerial(D2, D3); // Rx | Tx

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_SPARKFUN_BLYNK_BOARD
//#define USE_NODE_MCU_BOARD
//#define USE_WITTY_CLOUD_BOARD
//#define USE_WEMOS_D1_MINI

#define BLYNK_PRINT Serial

#include "BlynkEdgent.h"

BLYNK_WRITE(V0) {
  BLYNK_PRINT.print("yes\r\n");
  NodeSerial.print("helo\r\n");
}

void setup()
{
  Serial.begin(9600);
  pinMode(D2, INPUT);
  pinMode(D3, OUTPUT);
  delay(100);
  NodeSerial.begin(9600);
  delay(100);

  BlynkEdgent.begin();
}

void loop() {
  
  delay(1000);
  char buffer[100];
  float weight;
  if (NodeSerial.available() > 0)
  {
    weight = NodeSerial.parseFloat();
    Serial.println(sprintf(buffer, "%.2f", weight));
    Blynk.virtualWrite(V1, (double) weight);
  }
  BlynkEdgent.run();
}
