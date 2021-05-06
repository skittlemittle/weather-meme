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

// globs
Display display;
bool user_present = false;

struct WState {
  float temperature;
  float humidity;
  bool raining;
} weather;


void setup()
{
  const int PIR = 3;

  Sense::start();
  fill_gradient(weather_scale, 10, green, red);
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

void showHistory()
{
  display.drawHistory(16);
  delay(10 * 1000);
  user_present = false;
}

void showStatus()
{
  for (int i = 0; i < 5; i++) display.hot();
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
