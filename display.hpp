#pragma once
#include <FastLED.h>

// what follows is an unholy mess of global shit mixed in with a class
// even more sadge
const int matrix_side = 8;
const int NUM_LEDS = matrix_side * matrix_side;
static CRGB leds_safe[NUM_LEDS + 1];
static CRGB* const leds(leds_safe + 1);

class Display {
  public:
    Display();

  private:
    int num_leds;
    uint16_t XY(uint8_t x, uint8_t y);
    uint16_t XYsafe(uint8_t x, uint8_t y);

  public:
    void drawNumber(uint8_t number, CRGB color);
    void drawImage(const unsigned long* image, uint8_t size, bool layer = false);
    void drawHistory(uint8_t days);
    void clear();
    void animate(const unsigned long** anim, uint8_t num_frames);
};

