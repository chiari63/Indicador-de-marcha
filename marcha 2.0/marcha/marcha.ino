#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_GC9A01A.h>
#include "logo.h"  // Incluindo o arquivo logo.h com os bitmaps

#define TFT_CS 10
#define TFT_DC 9
#define TFT_RST 8

Adafruit_GC9A01A tft = Adafruit_GC9A01A(TFT_CS, TFT_DC, TFT_RST);

// Definindo os pinos dos botões
const int button1 = 2;
const int button2 = 3;
const int button3 = 4;
const int button4 = 5;
const int button5 = 6;
const int button6 = 7;

const int numFrames = 17; // Número de frames na animação

// Array de ponteiros para os bitmaps
const uint8_t* bitmaps[] = {
  epd_bitmap_1, epd_bitmap_2, epd_bitmap_3, epd_bitmap_4,
  epd_bitmap_5, epd_bitmap_6, epd_bitmap_7, epd_bitmap_8,
  epd_bitmap_9, epd_bitmap_10, epd_bitmap_11, epd_bitmap_12,
  epd_bitmap_13, epd_bitmap_14, epd_bitmap_15, epd_bitmap_16,
  epd_bitmap_17
};

void setup() {
  tft.begin();
  tft.setRotation(2); 
  tft.fillScreen(GC9A01A_BLACK);

  showAnimation(); // Exibe a animação antes de iniciar o loop

  // Exibindo a letra "N" inicial
  displayNeutral();
}

void loop() {
  if (digitalRead(button1) == LOW) {
    displayGear("1");
  } else if (digitalRead(button2) == LOW) {
    displayGear("2");
  } else if (digitalRead(button3) == LOW) {
    displayGear("3");
  } else if (digitalRead(button4) == LOW) {
    displayGear("4");
  } else if (digitalRead(button5) == LOW) {
    displayGear("5");
  } else if (digitalRead(button6) == LOW) {
    displayGear("R");
  } else {
    displayNeutral();
  }
}

void showAnimation() {
  for (int i = 0; i < numFrames; i++) {
    tft.fillScreen(GC9A01A_BLACK);  // Limpa a tela antes de desenhar o próximo frame
    tft.drawBitmap(0, 0, bitmaps[i], 128, 128, GC9A01A_WHITE); // Exibe o frame atual
    delay(100); // Controle da velocidade da animação
  }
}

void displayNeutral() {
  tft.fillScreen(GC9A01A_BLACK);
  tft.setTextColor(GC9A01A_RED);
  tft.setTextSize(6);
  tft.setCursor(30, 30); // Ajuste conforme necessário
  tft.print("N");
}

void displayGear(const char* gear) {
  tft.fillScreen(GC9A01A_BLACK);
  tft.setTextColor(GC9A01A_GREEN);
  tft.setTextSize(6);
  tft.setCursor(30, 30); // Ajuste conforme necessário
  tft.print(gear);
}