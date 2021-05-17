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
  static uint8_t n_check = 0;
  static bool check_dark = true;
  // time weather logging and night checking
  static unsigned long t_night = 0, t_log = 0;
  static bool is_night = false;
  static const int num_light_samples = 5;
  static bool light_samples[num_light_samples];

  if (check_dark && !is_night) {
    if (Sense::isDark())
      light_samples[n_check++] = true;

    if (n_check >= num_light_samples) {
      int o = 1;
      for (int i = 0; i < num_light_samples; i++) {
        if (light_samples[i]) o--;
        else o++;
      }
      // save day color once we know its actually night
      if (o < 0) {
        quality.recordDayColor();
        is_night = true;
        for (int i = 0; i < num_light_samples; i++)
          light_samples[i] = false;
      }
      // we finna write over the garbag
      n_check = 0;
    }
    check_dark = false;
  } else if (!Sense::isDark()) {
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
    delay(500); // give em time to get close
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
