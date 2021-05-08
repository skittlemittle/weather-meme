/*
 * icons, colors, and text
 * art by the_owlbio, cc-by-sa
 */
#pragma once

#include <FastLED.h>

//// images, im too lazy to figure out PROGMEM////
static const unsigned long sun1[] = {
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000,
  0x000000, 0x000000, 0xf4fe00, 0xf4fe00, 0xf4fe00, 0xf4fe00, 0x000000, 0x000000,
  0x000000, 0xf4fe00, 0xf4fe00, 0xd16002, 0xd16002, 0xf4fe00, 0xf4fe00, 0x000000,
  0x000000, 0xf4fe00, 0xd16002, 0xd16002, 0xd16002, 0xd16002, 0xf4fe00, 0x000000,
  0x000000, 0xf4fe00, 0xd16002, 0xd16002, 0xd16002, 0xd16002, 0xf4fe00, 0x000000,
  0x000000, 0xf4fe00, 0xf4fe00, 0xd16002, 0xd16002, 0xf4fe00, 0xf4fe00, 0x000000,
  0x000000, 0x000000, 0xf4fe00, 0xf4fe00, 0xf4fe00, 0xf4fe00, 0x000000, 0x000000,
  0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000,
};
static const unsigned long sun2[] = {
  0x000000, 0x000000, 0xf4fe00, 0xf4fe00, 0xf4fe00, 0xf4fe00, 0x000000, 0x000000,
  0x000000, 0xf4fe00, 0xf4fe00, 0xf4fe00, 0xf4fe00, 0xf4fe00, 0xf4fe00, 0x000000,
  0xf4fe00, 0xf4fe00, 0xf4fe00, 0xd16002, 0xd16002, 0xf4fe00, 0xf4fe00, 0xf4fe00,
  0xf4fe00, 0xf4fe00, 0xd16002, 0xd16002, 0xd16002, 0xd16002, 0xf4fe00, 0xf4fe00,
  0xf4fe00, 0xf4fe00, 0xd16002, 0xd16002, 0xd16002, 0xd16002, 0xf4fe00, 0xf4fe00,
  0xf4fe00, 0xf4fe00, 0xf4fe00, 0xd16002, 0xd16002, 0xf4fe00, 0xf4fe00, 0xf4fe00,
  0x000000, 0xf4fe00, 0xf4fe00, 0xf4fe00, 0xf4fe00, 0xf4fe00, 0xf4fe00, 0x000000,
  0x000000, 0x000000, 0xf4fe00, 0xf4fe00, 0xf4fe00, 0xf4fe00, 0x000000, 0x000000,
};
static const unsigned long (*sun[]) = {sun1, sun2};

//// digits 0 to 9 in a 3x7 font ////
static const bool n0[] = {
  true, true, true,
  true, false, true,
  true, false, true,
  true, false, true,
  true, false, true,
  true, false, true,
  true, true, true
};
static const bool n1[] = {
  false, true, false,
  true, true, false,
  false, true, false,
  false, true, false,
  false, true, false,
  false, true, false,
  true, true, true
};
static const bool n2[] = {
  true, true, true,
  false, false, true,
  false, false, true,
  true, true, true,
  true, false, false,
  true, false, false,
  true, true, true
};
static const bool n3[] = {
  true, true, true,
  false, false, true,
  false, false, true,
  false, true, true,
  false, false, true,
  false, false, true,
  true, true, true
};
static const bool n4[] = {
  true, false, true,
  true, false, true,
  true, false, true,
  true, true, true,
  false, false, true,
  false, false, true,
  false, false, true
};
static const bool n5[] = {
  true, true, true,
  true, false, false,
  true, false, false,
  true, true, true,
  false, false, true,
  false, false, true,
  true, true, true
};
static const bool n6[] = {
  true, true, true,
  true, false, false,
  true, false, false,
  true, true, true,
  true, false, true,
  true, false, true,
  true, true, true
};
static const bool n7[] = {
  true, true, true,
  false, false, true,
  false, false, true,
  false, false, true,
  false, true, false,
  false, true, false,
  false, true, false
};
static const bool n8[] = {
  true, true, true,
  true, false, true,
  true, false, true,
  true, true, true,
  true, false, true,
  true, false, true,
  true, true, true
};
static const bool n9[] = {
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

static const CHSV red = CHSV(0, 255, 255);
static const CHSV green = CHSV(100, 255, 255);
