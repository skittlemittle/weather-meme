/*
 * some graffix methods for an led panel
 * skittlemittle 2021, MIT license
 */

#include <FastLED.h>
#include "display.hpp"
#include "images.hpp"

// retardation
#define COLOR_ORDER GRB
#define CHIP WS2811
#define BRIGHTNESS 16
#define LED_PIN 4

Display::Display()
{
  FastLED.addLeds<CHIP, 4, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalSMD5050);
  FastLED.setBrightness(BRIGHTNESS);
}


/**
  draws a 2 digit number to an 8x8 matrix in a 3x7 pixel font
  padded one pixel on the top
*/
void Display::drawNumber(uint8_t number)
{
  // dont look too long
  int fw = 3, fh = 7;
  int ones = number % 10;
  int tens = number / 10 % 10;

  int x = 0, y = -1;
  bool *d = digits[ones];
  for (size_t i = 0; i < fw * fh; i++) {
    x = i % fw;
    if (x == 0) y++;
    y %= fh;
    if (d[i]) leds[XYsafe((matrix_side - 1) - (x + 4), y + 1)] = CRGB::White;
  }
  x = 0;
  y = -1;
  d = digits[tens];
  for (size_t i = 0; i < fw * fh; i++) {
    x = i % fw;
    if (x == 0) y++;
    y %= fh;
    if (d[i]) leds[XYsafe((matrix_side - 1) - x, y + 1)] = CRGB::White;
  }
  FastLED.show();
}

/**
 * copies over the first size pixels from image to the leds array
 * if layer is true black pixels are treated as transparent
 */
void Display::drawImage(const unsigned long* image, int size, bool layer = false)
{
  for (size_t i = 0; i < size; i++) {
    if (layer && image[i] != 0x000000) leds[i] = image[i];
    else leds[i] = image[i];
  }
}

/**
 * fills the matrix with 2x2 colored squares, each square is colored
 * to represent how objectively (totally not biased to rain) bad / good the 
 * weather that day was.
 */
void Display::drawHistory(uint8_t days)
{
  // show todays color then history?
  clear();
  fill_gradient(leds, days, CHSV(200, 255, 255), CHSV(45, 255, 255));
  FastLED.show();
}

/** turns all the leds off */
void Display::clear()
{
  for (size_t i = 0; i < NUM_LEDS; i++)
    leds[i] = CRGB::Black;
  FastLED.show();
}

// === Animations ===
void Display::hot()
{
  drawImage(sun1, 64);
  FastLED.delay(550);
  drawImage(sun2, 64);
  FastLED.delay(350);
}

void Display::rain()
{
  // random pixel at top, scroll down y, draw blue
  // static array to track which columns we raining on?
  // that way wee have one static 8 element array
  // fadeToBlackBy(leds, NUM_LEDS, 20);
}

// === le garbag ===

uint16_t Display::XY(uint8_t x, uint8_t y)
{
  uint16_t i;
  if (y & 0x01) {
    uint8_t reverseX = (matrix_side - 1) - x;
    i = (y * matrix_side) + reverseX;
  } else {
    i = (y * matrix_side) + x;
  }
  return i;
}

uint16_t Display::XYsafe(uint8_t x, uint8_t y)
{
    if (x >= matrix_side)
        return -1;
    if (y >= matrix_side)
        return -1;
    return XY(x, y);
}

