/*
 * Ranks the weather for the day and logs it
 * skittlemittle 2021, MIT license
 */

#pragma once
#include <FastLED.h>

struct WState {
  float temperature;
  float humidity;
  bool raining;
};

class DayQuality {
  public:
    DayQuality();

  private:
    unsigned int rain_duration; // how long it been raining today, minutes
    int* temp_log = nullptr; // stores the last 12 hours of temperature
    /** colors for how much the weather sucked, 0: bad, 9: good */
    const CRGB weather_scale[10];

  public:
    void recordDayColor();
    CRGB calculateDayColor();
    void logWeather(WState curr_weather);
    uint8_t* getHistory(uint8_t days = 16);
};
