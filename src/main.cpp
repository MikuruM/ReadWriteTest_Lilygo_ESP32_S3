#include <Arduino.h>
#include <SPI.h>
#include <SD.h>
#include <TFT_eSPI.h>

const int CS_PIN = 10; // CS pin for SD card, connected to GPIO10
TFT_eSPI tft = TFT_eSPI();
int roundCount = 0;

void setup() {
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(1);
  
  SD.begin(CS_PIN);
}

void loop() {
  roundCount += 1;
  tft.fillScreen(TFT_BLACK);

  //写入第几轮loop
  File file = SD.open("/testFile/test.txt", FILE_APPEND);
  file.println(roundCount); 
  file.close();
  //tft.setCursor(0, 0); // 把打字光标重置到屏幕左上角

  //读取文件内容
  file = SD.open("/testFile/test.txt", FILE_READ);
  String content = file.readString();
  tft.println(content); // Display on screen
  file.close();

  tft.setCursor(0, 0); // 把打字光标重置到屏幕左上角
  delay(500);
}