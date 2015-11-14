#include "application.h"
#include "neopixel.h"
#include "game-of-life.h"

SYSTEM_MODE(AUTOMATIC);

#define TICK 100
#define SIDE 8

#define PIXEL_PIN D0
#define PIXEL_COUNT 512
#define PIXEL_TYPE WS2812B

enum CEL { GREEN, RED, BLUE, WHITE, BLACK };

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);
GameOfLife gameOfLife = GameOfLife(SIDE);

void cubeClear() {
  int x, y, z;
	for (x = 0; x < SIDE; x++) for (y = 0; y < SIDE; y++) for (z = 0; z < SIDE; z++){
    setPixel(x, y, z, BLACK);
  }
}

void setPixel(int x, int y, int z, int color) {
  int colorR = 0;
  int colorG = 0;
  int colorB = 0;

  switch(color) {
    case RED:
      colorR = 255;
      break;
    case BLUE:
      colorG = 255;
      break;
    case GREEN:
      colorB = 255;
      break;
    case WHITE:
      colorG = 255;
      colorR = 255;
      colorB = 255;
      break;
    case BLACK:
      break;
  }
  int index = (z * SIDE * SIDE) + (x * SIDE) + y;
  strip.setPixelColor(index, strip.Color(colorR, colorB, colorG));
}

/* print board state onto cube */
void print() {
  int *board = gameOfLife.getState();
  int x, y, z;
	for (x = 0; x < SIDE; x++) for (y = 0; y < SIDE; y++) for (z = 0; z < SIDE; z++) {
    setPixel(x, y, z, board[x][y][z] == 0 ? BLACK : GREEN);
  }
}

void setup() {
  strip.begin();
  cubeClear();
  strip.show();
}

void loop() {
  gameOfLife.tick();
  cubeClear();
  print();
  strip.show();
  delay(TICK);
}
