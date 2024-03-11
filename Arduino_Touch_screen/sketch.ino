#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <Adafruit_FT6206.h>

const int TFT_CS  = 10;
const int TFT_DC  = 9;
const int TFT_RST = 8;
const int LED_PIN = 2;
//Расположение кнопок в точках x и y
const int BTN_GRN_X = 10;
const int BTN_GRN_Y = 30;
const int BTN_RED_X = 133;
const int BTN_RED_Y = 30;

bool isLEDOn = false;

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);
Adafruit_FT6206 ts = Adafruit_FT6206();

void setup() {
  Serial.begin(9600);
  tft.begin();
  //Угол поворота
  tft.setRotation(180);
  ts.begin();
  pinMode(LED_PIN, OUTPUT);
  drawButton(BTN_GRN_X, BTN_GRN_Y, "ON ", 0x07E0);
  drawButton(BTN_RED_X, BTN_RED_Y, "OFF", 0xF800);
  tft.setTextSize(3);
  tft.setTextColor(ILI9341_BLUE);
  //Расположение в точках x и y
  tft.setCursor(60, 165); 
  tft.print("LED OFF");
  Serial.println("Ready");
}

void loop() {
  //Получаем координаты с экрана
  TS_Point p = getTouchPoint();
  if (p.z > 0)  {
    //Переверните его, чтоб соответствовал экрану *
    p.x = map(p.x, 0, 240, 240, 0); //*
    p.y = map(p.y, 0, 320, 320, 0); //*
    //Отображение координат
    displayTouchCoordinates(p);
    //Если нажата зелёная кнопка
    if (isButtonPressed(p, BTN_GRN_X, BTN_GRN_Y)) {
      handleButtonPress(BTN_GRN_X, BTN_GRN_Y, "LED ON ", HIGH, 0x07E0);
      Serial.println("Green");
    }
    //Если нажата красная кнопка
    else {
      handleButtonPress(BTN_RED_X, BTN_RED_Y, "LED OFF", LOW, 0xF800);
      Serial.println("Red");
    }
  }
}

//Считывание координат с экрана 
TS_Point getTouchPoint() {
  TS_Point p;
  if (ts.touched()) {
    p = ts.getPoint();
  } else {
    p = TS_Point(0, 0, 0);
  }
  return p;
}

//Отображение координат
void displayTouchCoordinates(TS_Point p) {
  tft.setTextSize(2);
  tft.setTextColor(ILI9341_RED, ILI9341_BLACK);
  tft.setCursor(0, 235);
  tft.print("X: ");
  tft.print(p.x);
  tft.print("  ");
  tft.setCursor(0, 265);
  tft.print("Y: ");
  tft.print(p.y);
  tft.print("  ");
  tft.setCursor(0, 295);
  tft.print("Z: ");
  tft.print(p.z);
  tft.print("  "); 
  tft.setCursor(0, 210);
  tft.print("--------------------");
  tft.setCursor(228, 235);
  tft.print("|");
  tft.setCursor(228, 265);
  tft.print("|");
  tft.setCursor(228, 295);
  tft.print("|");
  tft.setCursor(0, 312);
  tft.print("--------------------");
  Serial.print("("); Serial.print(p.x);
  Serial.print(", "); Serial.print(p.y);
  Serial.println(")");
}

//Если нажата кнопка
bool isButtonPressed(TS_Point p, int btnY, int btnX) {
  return (p.x > btnX && p.x < (btnX + 95) && p.y > btnY && p.y < (btnY + 95));
}

//Обработка нажатия кнопки
void handleButtonPress(int btnX, int btnY, const char* message, int ledState, uint16_t buttonColor) {
  tft.setTextSize(3);
  tft.setTextColor(ILI9341_BLUE, ILI9341_BLACK);
  tft.setCursor(60, 165);
  tft.print(message);
  digitalWrite(LED_PIN, ledState);
  //Имитация эффекта нажатия 
  tft.fillRoundRect(btnX, btnY, 95, 95, 10, 0xFFFFF); //Цвет фона 0x18E30 (?)
  delay(50);
  drawButton(btnX, btnY, message, buttonColor);
}

//Изображение кнопок
void drawButton(int xp, int yp, const char* label, uint16_t color) {
  tft.fillRoundRect(xp, yp, 95, 95, 10, 0xFFFFF); //0x18E30
  tft.fillRoundRect(xp + 2, yp + 2, 95, 95, 10, color);
  tft.setCursor(xp + 8, yp + 40);
  tft.setTextSize(2);
  tft.setTextColor(ILI9341_WHITE);
  tft.println(label);
}