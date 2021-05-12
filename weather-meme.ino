/*
 * weather station that draws a color plot of how much the weather over the past
 * few days sucked.
 * Also shows you the weather.
 * "how much the weather sucked" is calculated based on some totally unbiased criteria.
 *
 * skittlemittle 2021, MIT license
*/

#include "sense.hpp"
#include "display.hpp"
#include "images.hpp"
#include "rating.hpp"

// globs
Display display;
WState weather;
DayQuality quality;
bool user_present = false;

void setup()
{
  const int PIR = 3;

  Sense::start();
  attachInterrupt(digitalPinToInterrupt(PIR), onMovement, RISING);
  Serial.begin(9600);

  WState tw;
  tw.temperature = 28;
  tw.humidity = 0;
  for (int i = 0; i < 12; i++)
    quality.logWeather(tw);

  quality.updateRainDuration(0);
/*

  quality.recordDayColor();
  uint8_t hist[1];
  quality.getHistory(hist, 1);
*/
}

void showStatus();
void showHistory(uint8_t days = 64);
void updateReadings();

void loop()
{
  if (user_present) {
    updateReadings();
    if (Sense::isUserClose()) {
      showStatus();
    } else {
      showHistory();
    }
  }
}

void showHistory(uint8_t days = 64)
{
  uint8_t h[days];
  display.drawHistory(quality.getHistory(h, days), days);
  delay(10 * 1000);
  display.clear();
  user_present = false;
}

void showStatus()
{
  // whatever just show them some numbers or smth
  const int text_delay = 2500;
  display.clear();
  display.drawNumber(weather.temperature / 1, CRGB(96, 100, 0));
  delay(text_delay);
  display.clear();
  display.drawNumber(weather.humidity / 1, CRGB(0, 170, 255));
  delay(text_delay);
  display.clear();
  user_present = false;
}

void updateReadings()
{
  TempHumidity th = Sense::readTH();
  weather.temperature = th.temperature;
  weather.humidity = th.humidity;
  weather.raining = Sense::isRaining();
}

void onMovement()
{
  //TODO: only wake up if its been x minutes
  user_present = true;
}
