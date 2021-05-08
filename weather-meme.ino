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
bool user_present = false;

void setup()
{
  const int PIR = 3;

  Sense::start();
  attachInterrupt(digitalPinToInterrupt(PIR), onMovement, RISING);
  Serial.begin(9600);
  display.drawHistory(16);
}

void showStatus();
void showHistory();
void updateReadings();

void loop()
{
  if (user_present) {
    updateReadings();
    if (true) {
      showStatus();
    } else {
      showHistory();
    }
  }
}


/** saves the days color to eeprom*/
void recordDayColor()
{
  int avg_t = 0;
  int ts = sizeof t_log / sizeof t_log[0];
  for (size_t i = 0; i < ts; i++)
    avg_t += t_log[i];

  avg_t /= ts;
  // clear the previous days logs
  for (size_t i = 0; i < ts; i++)
    t_log[i] = 0;
  rain_duration = 0;
}

void showHistory()
{
  display.drawHistory(16);
  delay(10 * 1000);
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
/*
  // yes animatio
  for (int i = 0; i < 10; i++) display.animate(sun, 2);
  FastLED.delay(1000);
  display.clear();
  user_present = false;
*/
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
