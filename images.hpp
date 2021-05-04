/*
 * icons, colors, and text
 */
#pragma once

#include <FastLED.h>

//// images ////
static unsigned long hot1[] = {
  0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000,
  0x000, 0x000, 0xf4fe00, 0xf4f00, 0xf4fe00, 0xf4fe00, 0x000, 0x000,
  0x000, 0xf4fe00, 0xf4fe00, 0xe1cc00, 0xe1cc00, 0xf4fe00, 0xf4fe00, 0x000,
  0x000, 0xf4fe00, 0xe1cc00, 0xe1cc00, 0xe1cc00, 0xe1cc00, 0xf4fe00, 0x000,
  0x000, 0xf4fe00, 0xe1cc00, 0xe1cc00, 0xe1cc00, 0xe1cc00, 0xf4fe00, 0x000,
  0x000, 0xf4fe00, 0xf4fe00, 0xe1cc00, 0xe1cc00, 0xf4fe00, 0xf4fe00, 0x000,
  0x000, 0x000, 0xf4fe00, 0xf4f00, 0xf4fe00, 0xf4fe00, 0x000, 0x000,
  0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000,
};
static unsigned long hot2[] = {
  0x000, 0x000, 0xf4fe00, 0xf4fe00, 0xf4fe00, 0xf4fe00, 0x000, 0x000,
  0x000, 0xf4fe00, 0xf4fe00, 0xf4fe00, 0xf4fe00, 0xf4fe00, 0xf4fe00, 0x000,
  0xf4fe00, 0xf4fe00, 0xf4fe00, 0xe1cc00, 0xe1cc00, 0xf4fe00, 0xf4fe00, 0xf4fe00,
  0xf4fe00, 0xf4fe00, 0xe1cc00, 0xe1cc00, 0xe1cc00, 0xe1cc00, 0xf4fe00, 0xf4fe00,
  0xf4fe00, 0xf4fe00, 0xe1cc00, 0xe1cc00, 0xe1cc00, 0xe1cc00, 0xf4fe00, 0xf4fe00,
  0xf4fe00, 0xf4fe00, 0xf4fe00, 0xe1cc00, 0xe1cc00, 0xf4fe00, 0xf4fe00, 0xf4fe00,
  0x000, 0xf4fe00, 0xf4fe00, 0xf4fe00, 0xf4fe00, 0xf4fe00, 0xf4fe00, 0x000,
  0x000, 0x000, 0xf4fe00, 0xf4fe00, 0xf4fe00, 0xf4fe00, 0x000, 0x000,
};

//// animations ////
static const unsigned long (*hot[]) = {hot1, hot2};

//// digits 0 to 9 in 3x7 ////
static bool n0[] = {
  true, true, true,
  true, false, true,
  true, false, true,
  true, false, true,
  true, false, true,
  true, false, true,
  true, true, true
};
static bool n1[] = {
  false, true, false,
  true, true, false,
  false, true, false,
  false, true, false,
  false, true, false,
  false, true, false,
  true, true, true
};
static bool n2[] = {
  true, true, true,
  false, false, true,
  false, false, true,
  true, true, true,
  true, false, false,
  true, false, false,
  true, true, true
};
static bool n3[] = {
  true, true, true,
  false, false, true,
  false, false, true,
  false, true, true,
  false, false, true,
  false, false, true,
  true, true, true
};
static bool n4[] = {
  true, false, true,
  true, false, true,
  true, false, true,
  true, true, true,
  false, false, true,
  false, false, true,
  false, false, true
};
static bool n5[] = {
  true, true, true,
  true, false, false,
  true, false, false,
  true, true, true,
  false, false, true,
  false, false, true,
  true, true, true
};
static bool n6[] = {
  true, true, true,
  true, false, false,
  true, false, false,
  true, true, true,
  true, false, true,
  true, false, true,
  true, true, true
};
static bool n7[] = {
  true, true, true,
  false, false, true,
  false, false, true,
  false, false, true,
  false, true, false,
  false, true, false,
  false, true, false
};
static bool n8[] = {
  true, true, true,
  true, false, true,
  true, false, true,
  true, true, true,
  true, false, true,
  true, false, true,
  true, true, true
};
static bool n9[] = {
  true, true, true,
  true, false, true,
  true, false, true,
  true, true, true,
  false, false, true,
  false, false, true,
  false, false, true
};

/** 3x7 number font */
static const bool (*digits[]) = {n0, n1, n2, n3, n4, n5, n6, n7, n8, n9};

static CHSV red(0, 255, 255);
static CHSV green(100, 255, 255);
/** colors for how much the weather sucked, 0: bad, 9: good */
static const CRGB weather_scale[10];
