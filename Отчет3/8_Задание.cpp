#include "Adafruit_NeoPixel.h"
#define PIN 3
#define NUMPIXELS 64
#define LETTER_DELAY 2000
#define PIXEL_DELAY 50
Adafruit_NeoPixel strip(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
const uint32_t LETTER_COLOR = strip.Color(0, 0, 255);
const uint32_t BG_COLOR = strip.Color(0, 0, 0);
const uint8_t letters[6][8][8] = {
  {
    {0,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,1,0},
    {0,1,1,0,0,0,1,0},
    {0,1,0,0,1,0,1,0},
    {0,1,0,0,1,0,1,0},
    {0,1,1,0,0,0,1,0},
    {0,1,0,0,0,0,1,0},
    {0,0,0,0,0,0,0,0}
  },
  {
    {0,0,0,0,0,0,0,0},
    {0,1,1,1,1,1,0,0},
    {0,1,0,0,0,0,1,0},
    {0,1,0,0,0,0,1,0},
    {0,0,1,1,1,1,1,0},
    {0,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,0},
    {0,0,0,0,0,0,0,0}
  },
  {
    {0,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,1,0},
    {0,1,0,0,0,0,1,0},
    {0,1,1,1,1,1,1,0},
    {0,1,1,1,1,1,1,0},
    {0,1,0,0,0,0,1,0},
    {0,1,0,0,0,0,1,0},
    {0,0,0,0,0,0,0,0}
  },
  {
    {0,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,1,0},
    {0,1,1,0,0,0,1,0},
    {0,1,0,0,1,0,1,0},
    {0,1,0,0,1,0,1,0},
    {0,1,1,0,0,0,1,0},
    {0,1,0,0,0,0,1,0},
    {0,0,0,0,0,0,0,0}
  },
  {
    {0,0,0,0,0,0,0,0},
    {0,1,1,1,1,1,1,0},
    {0,1,1,1,1,1,1,0},
    {0,0,0,1,1,0,0,0},
    {0,0,0,1,1,0,0,0},
    {0,0,0,1,1,0,0,0},
    {0,0,0,1,1,0,0,0},
    {0,0,0,0,0,0,0,0}
  },
  {
    {0,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,1,0},
    {0,1,0,0,0,0,1,0},
    {0,1,1,1,1,1,1,0},
    {0,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,0},
    {0,1,1,1,1,1,0,0},
    {0,0,0,0,0,0,0,0}
  }
};
void clearMatrix() {
  for(int i = 0; i < NUMPIXELS; i++) {
    strip.setPixelColor(i, BG_COLOR);
  }
  strip.show();
}
void drawLetterWithPixelDelay(uint8_t letterIndex) {
  clearMatrix();
  int activePixels[64][2];
  int count = 0;
  for(int row = 0; row < 8; row++) {
    for(int col = 0; col < 8;col++) {
      if(letters[letterIndex][row][col]) {
        activePixels[count][0] = row;
        activePixels[count][1] = col;
        count++;
      }
    }
  }
  for(int i = 0; i < count; i++) {
    int row = activePixels[i][0];
    int col = activePixels[i][1];
    strip.setPixelColor(row * 8 + col, LETTER_COLOR);
    strip.show();
    delay(PIXEL_DELAY);
  }
}
void setup() {
  strip.begin();
  strip.setBrightness(100);
  clearMatrix();
  delay(1000);
}
void loop() {
  for(int i = 0; i < 6; i++) {
    drawLetterWithPixelDelay(i);
    delay(LETTER_DELAY);
    clearMatrix();
    delay(200);
  }
  delay(1000);
}
