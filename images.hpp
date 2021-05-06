/*
 * icons, colors, and text
 * art by the_owlbio, cc-by-sa
 */
#pragma once

#include <FastLED.h>

//// images ////
static unsigned long sun1[] = {
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000,
  0x000000, 0x000000, 0xf4fe00, 0xf4fe00, 0xf4fe00, 0xf4fe00, 0x000000, 0x000000,
  0x000000, 0xf4fe00, 0xf4fe00, 0xd16002, 0xd16002, 0xf4fe00, 0xf4fe00, 0x000000,
  0x000000, 0xf4fe00, 0xd16002, 0xd16002, 0xd16002, 0xd16002, 0xf4fe00, 0x000000,
  0x000000, 0xf4fe00, 0xd16002, 0xd16002, 0xd16002, 0xd16002, 0xf4fe00, 0x000000,
  0x000000, 0xf4fe00, 0xf4fe00, 0xd16002, 0xd16002, 0xf4fe00, 0xf4fe00, 0x000000,
  0x000000, 0x000000, 0xf4fe00, 0xf4fe00, 0xf4fe00, 0xf4fe00, 0x000000, 0x000000,
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000,
};
static unsigned long sun2[] = {
  0x000000, 0x000000, 0xf4fe00, 0xf4fe00, 0xf4fe00, 0xf4fe00, 0x000000, 0x000000,
  0x000000, 0xf4fe00, 0xf4fe00, 0xf4fe00, 0xf4fe00, 0xf4fe00, 0xf4fe00, 0x000000,
  0xf4fe00, 0xf4fe00, 0xf4fe00, 0xd16002, 0xd16002, 0xf4fe00, 0xf4fe00, 0xf4fe00,
  0xf4fe00, 0xf4fe00, 0xd16002, 0xd16002, 0xd16002, 0xd16002, 0xf4fe00, 0xf4fe00,
  0xf4fe00, 0xf4fe00, 0xd16002, 0xd16002, 0xd16002, 0xd16002, 0xf4fe00, 0xf4fe00,
  0xf4fe00, 0xf4fe00, 0xf4fe00, 0xd16002, 0xd16002, 0xf4fe00, 0xf4fe00, 0xf4fe00,
  0x000000, 0xf4fe00, 0xf4fe00, 0xf4fe00, 0xf4fe00, 0xf4fe00, 0xf4fe00, 0x000000,
  0x000000, 0x000000, 0xf4fe00, 0xf4fe00, 0xf4fe00, 0xf4fe00, 0x000000, 0x000000,
};

//// digits 0 to 9 in a 3x7 font ////
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

static CHSV red = CHSV(0, 255, 255);
static CHSV green = CHSV(100, 255, 255);
/** colors for how much the weather sucked, 0: bad, 9: good */
static const CRGB weather_scale[10];
