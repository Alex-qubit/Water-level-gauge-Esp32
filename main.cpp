#include <Arduino.h>
#include <Wire.h>
#include <PCF8575.h>
#include <TFT_eSPI.h>

#define SDA_PIN 21
#define SCL_PIN 22

TFT_eSPI tft = TFT_eSPI();
TFT_eSprite img = TFT_eSprite(&tft);
TFT_eSprite spr_fps = TFT_eSprite(&tft);

TwoWire I2C_1 = TwoWire(0); // I2C 1

PCF8575 pcf8575(&I2C_1, 0x20, SDA_PIN, SCL_PIN);

void setup() {
  Serial.begin(115200);
  I2C_1.begin(SDA_PIN, SCL_PIN, 100000);
  for (int i=0; i < 16; i++){
    pcf8575.pinMode(i, INPUT);
  }
  pcf8575.begin();
  tft.init();
  tft.setRotation(0);
  tft.fillScreen(0x0000);
  img.createSprite(240, 230);
  spr_fps.createSprite(140, 80);
}

void water_level(){
  for (int i=17; i < 226; i += 19){
    img.drawLine(160, i, 140, i, 0x8430);
  }
  img.fillRect(2, 23, 141, 185, 0xBE18); // серый фон
  img.fillEllipse(72, 210, 70, 17, 0x347C); // дно
  img.fillEllipse(72, 20, 70, 17, 0xA534); //верх
  img.setTextSize(2);
  img.setTextColor(0x8430);
  img.drawString("0%", 165, 210);
  img.drawString("10%", 165, 191);
  img.drawString("20%", 165, 172);
  img.drawString("30%", 165, 153);
  img.drawString("40%", 165, 134);
  img.drawString("50%", 165, 115);
  img.drawString("60%", 165, 96);
  img.drawString("70%", 165, 77);
  img.drawString("80%", 165, 58);
  img.drawString("90%", 165, 39);
  img.drawString("100%", 165, 20);
  if (pcf8575.digitalRead(P9) == 1){
    img.setTextColor(0x07E0);
    img.drawString("100%", 165, 20);
    img.fillRect(2, 23, 141, 185, 0x5D7D); // голубой фон
    img.fillEllipse(72, 20, 70, 17, 0x23BF); // верх воды
    img.fillEllipse(72, 210, 70, 17, 0x347C); // дно
  }else 
  if (pcf8575.digitalRead(P8) == 1){
    img.setTextColor(0x07E0);
    img.drawString("90%", 165, 39);
    img.fillRect(2, 36, 141, 172, 0x5D7D); // голубой фон
    img.fillEllipse(72, 36, 70, 17, 0x23BF); // верх воды
    img.fillEllipse(72, 210, 70, 17, 0x347C); // дно
  }else
  if (pcf8575.digitalRead(P7) == 1){
    img.setTextColor(0x07E0);
    img.drawString("80%", 165, 58);
    img.fillRect(2, 55, 141, 157, 0x5D7D); // голубой фон
    img.fillEllipse(72, 55, 70, 17, 0x23BF); // верх воды
    img.fillEllipse(72, 210, 70, 17, 0x347C); // дно
  }else
  if (pcf8575.digitalRead(P6) == 1){
    img.setTextColor(0x07E0);
    img.drawString("70%", 165, 77);
    img.fillRect(2, 74, 141, 135, 0x5D7D); // голубой фон
    img.fillEllipse(72, 74, 70, 17, 0x23BF); // верх воды
    img.fillEllipse(72, 210, 70, 17, 0x347C); // дно
  }else
  if (pcf8575.digitalRead(P5) == 1){
    img.setTextColor(0x07E0);
    img.drawString("60%", 165, 96);
    img.fillRect(2, 93, 141, 115, 0x5D7D); // голубой фон
    img.fillEllipse(72, 93, 70, 17, 0x23BF); // верх воды
    img.fillEllipse(72, 210, 70, 17, 0x347C); // дно
  }else
  if (pcf8575.digitalRead(P4) == 1){
    img.setTextColor(0x07E0);
    img.drawString("50%", 165, 115);
    img.fillRect(2, 112, 141, 95, 0x5D7D); // голубой фон
    img.fillEllipse(72, 112, 70, 17, 0x23BF); // верх воды
    img.fillEllipse(72, 210, 70, 17, 0x347C); // дно
  }else
  if (pcf8575.digitalRead(P3) == 1){
    img.setTextColor(0x07E0);
    img.drawString("40%", 165, 134);
    img.fillRect(2, 131, 141, 75, 0x5D7D); // голубой фон
    img.fillEllipse(72, 131, 70, 17, 0x23BF); // верх воды
    img.fillEllipse(72, 210, 70, 17, 0x347C); // дно
  }else
  if (pcf8575.digitalRead(P2) == 1){
    img.setTextColor(0x07E0);
    img.drawString("30%", 165, 153);
    img.fillRect(2, 150, 141, 58, 0x5D7D); // голубой фон
    img.fillEllipse(72, 150, 70, 17, 0x23BF); // верх воды
    img.fillEllipse(72, 210, 70, 17, 0x347C); // дно
  }else
  if (pcf8575.digitalRead(P1) == 1){
    img.setTextColor(0x07E0);
    img.drawString("20%", 165, 172);
    img.fillRect(2, 169, 141, 38, 0x5D7D); // голубой фон
    img.fillEllipse(72, 169, 70, 17, 0x23BF); // верх воды
    img.fillEllipse(72, 210, 70, 17, 0x347C); // дно
  }else
  if (pcf8575.digitalRead(P0) == 1){
    img.setTextColor(0x07E0);
    img.drawString("10%", 165, 191);
    img.fillRect(2, 188, 141, 20, 0x5D7D); // голубой фон
    img.fillEllipse(72, 210, 70, 17, 0x347C); // дно
    img.fillEllipse(72, 188, 70, 17, 0x23BF); // верх воды
    
  }else {
    img.setTextColor(0x07E0);
    img.drawString("0%", 165, 210);
    }

}

void loop() {
  water_level();
  img.pushSprite(1, 1);
}
