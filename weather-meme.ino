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
bool user_present = true;

void setup()
{
  const int PIR = 3;
  Sense::start();
  attachInterrupt(digitalPinToInterrupt(PIR), onMovement, RISING);
}

void showStatus();
void showHistory(uint8_t days = 64);
void updateReadings();

void loop()
{
  // ===========night detection stuff, dark for 30 min = night===========
  static bool check_dark = true;
  // time weather logging and night checking
  static unsigned long t_night = 0, t_log = 0;
  static bool is_night = false;
  static const int dark_threshold = 5;
  static bool dark_count = 0;

  if (check_dark && !is_night) {
    if (Sense::isDark())
      dark_count++;
    else
      dark_count = 0;

    if (dark_count >= dark_threshold) {
      quality.recordDayColor();
      is_night = true;
    }
    check_dark = false;
  } else if (check_dark && !Sense::isDark()) {
    is_night = false;
    check_dark = false;
  }

  // check dark every 5 mins
  unsigned long t2 = millis();
  if (!check_dark && t2 - t_night > 300000) {
    check_dark = true;
    t_night = t2;
  }
  // log the weather every hour
  if (t2 - t_log > 3600000) {
    updateReadings();
    quality.logWeather(weather);
  }

  // ===========ui stuff===========
  if (user_present) {
    updateReadings();
    if (Sense::isUserClose(30)) {
      showStatus();
    } else {
      showHistory();

      bool done = false;
      unsigned long proximity_time = millis();
      while (!done && millis() - proximity_time < 10000) {
        if (Sense::isUserClose()) {
          showStatus();
          done = true;
        }
      }
      display.clear();
    }
    user_present = false;
  }
}

void showHistory(uint8_t days = 64)
{
  uint8_t h[days];
  display.drawHistory(quality.getHistory(h, days), days);
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
}

void updateReadings()
{
  WeatherReadings th = Sense::readTH();
  weather.temperature = th.temperature;
  weather.humidity = th.humidity;
  weather.raining = Sense::isRaining();

  static unsigned long tr1 = 0;
  if (weather.raining) {
    if (tr1 == 0) tr1 = millis();
    unsigned long tr2 = millis();
    quality.updateRainDuration((uint8_t)((tr2 - tr1) / 60000));
    tr1 = tr2;
  }
}

void onMovement()
{
  user_present = true;
}
