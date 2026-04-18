#include <SPI.h>
#include <LoRa.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {

  Serial.begin(9600);

  Wire.begin(21,22);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED failed");
    while(true);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);

  display.setCursor(0,0);
  display.println("Receiver Ready");
  display.display();

  LoRa.setPins(5,14,26);  // CS, RST, DIO0

  if (!LoRa.begin(433E6)) {
    Serial.println("LoRa init failed!");
    while (1);
  }
}

void loop() {

  int packetSize = LoRa.parsePacket();

  if (packetSize) {

    String message = "";

    while (LoRa.available()) {
      message += (char)LoRa.read();
    }

    Serial.println(message);

    int comma = message.indexOf(',');

    if(comma > 0){

      String latitude = message.substring(0, comma);
      String longitude = message.substring(comma+1);

      display.clearDisplay();

      display.setCursor(0,0);
      display.println("EMERGENCY ALERT");

      display.setCursor(0,20);
      display.print("LAT: ");
      display.println(latitude);

      display.setCursor(0,40);
      display.print("LON: ");
      display.println(longitude);

      display.display();
    }
  }
}
