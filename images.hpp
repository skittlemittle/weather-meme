/*
 * icons, colors, and text
 */
#pragma once

// just change the pointer and read
unsigned long rain1[] = {};
unsigned long rain2[] = {};

unsigned long hot1[] = {};
unsigned long hot2[] = {};

/** digits 0 to 9 in 3x7*/
bool n0[] = {
  true, true, true,
  true, false, true,
  true, false, true,
  true, false, true,
  true, false, true,
  true, false, true,
  true, true, true
};
bool n1[] = {
  false, true, false,
  true, true, false,
  false, true, false,
  false, true, false,
  false, true, false,
  false, true, false,
  true, true, true
};
bool n2[] = {
  true, true, true,
  false, false, true,
  false, false, true,
  true, true, true,
  true, false, false,
  true, false, false,
  true, true, true
};
bool n3[] = {
  true, true, true,
  false, false, true,
  false, false, true,
  false, true, true,
  false, false, true,
  false, false, true,
  true, true, true
};
bool n4[] = {
  true, false, true,
  true, false, true,
  true, false, true,
  true, true, true,
  false, false, true,
  false, false, true,
  false, false, true
};
bool n5[] = {
  true, true, true,
  true, false, false,
  true, false, false,
  true, true, true,
  false, false, true,
  false, false, true,
  true, true, true
};
bool n6[] = {
  true, true, true,
  true, false, false,
  true, false, false,
  true, true, true,
  true, false, true,
  true, false, true,
  true, true, true
};
bool n7[] = {
  true, true, true,
  false, false, true,
  false, false, true,
  false, false, true,
  false, true, false,
  false, true, false,
  false, true, false
};
bool n8[] = {
  true, true, true,
  true, false, true,
  true, false, true,
  true, true, true,
  true, false, true,
  true, false, true,
  true, true, true
};
bool n9[] = {
  true, true, true,
  true, false, true,
  true, false, true,
  true, true, true,
  false, false, true,
  false, false, true,
  false, false, true
};

/** 3x7 number font */
const bool (*digits[]) = {n0, n1, n2, n3, n4, n5, n6, n7, n8, n9};
/** colors for how much the weather sucked */
// use an hsv gradient and just use indexes in there
