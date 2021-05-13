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

/** measurement_ranges = {min_t, max_t, min_h, max_h, min_r, max_r}*/
const uint8_t default_ranges[] = {10, 40, 35, 74, 0, 60};

class DayQuality {
  public:
    DayQuality(uint8_t* measurement_ranges = default_ranges);

  private:
    const int num_samples = 24;
    unsigned int rain_duration; // how long it been raining today, minutes
    int* temp_log = nullptr; // temperature samples
    int* humidity_log = nullptr; // humidity samples
    uint8_t address; // eeprom address for the current day
    // min and max weather measurements
    int min_t;
    int max_t;
    unsigned int min_h;
    unsigned int max_h;
    unsigned int min_r;
    unsigned int max_r;

  public:
    void recordDayColor();
    byte calculateDayColor();
    void logWeather(WState curr_weather);
    void updateRainDuration(uint8_t d);
    uint8_t* getHistory(uint8_t* r, uint8_t days);
};
