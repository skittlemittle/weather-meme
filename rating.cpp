#include "rating.hpp"

/** measurement_ranges = {min_t, max_t, min_h, max_h, min_r, max_r}*/
DayQuality::DayQuality(uint8_t* measurement_ranges = default_ranges)
{
  temp_log = new int[num_samples]{0};
  humidity_log = new int[num_samples]{0};
  rain_duration = 0;
  min_t = measurement_ranges[0];
  max_t = measurement_ranges[1];
  min_h = measurement_ranges[2];
  max_h = measurement_ranges[3];
  min_r = measurement_ranges[4];
  max_r = measurement_ranges[5];
}

/**
 * rates the day between on a scale of 0 to 9
 * red: how hot, blue: rain duration, green: how humid
 * returns a hue value
 */
uint8_t DayQuality::calculateDayColor()
{
  // function of avg temperature and rain duration
  int8_t avg_temp = 0, avg_humidity = 0;
  for (size_t i = 0; i < num_samples; i++) {
    avg_temp += temp_log[i];
    avg_humidity += humidity_log[i];
  }

  avg_temp /= num_samples;
  avg_humidity /= num_samples;
  CRGB rgb(map(avg_temp, min_t, max_t, 0, 255), map(rain_duration, min_r, max_r, 0, 255), map(avg_humidity, min_h, max_h, 0, 255));
  CHSV r = rgb2hsv_approximate(rgb);
  return r.hue;
}

/** save a single weather sample */
void DayQuality::logWeather(WState curr_weather)
{
  static uint8_t index = 0;
  temp_log[index] = curr_weather.temperature;
  humidity_log[index] = curr_weather.humidity;
  index++;
  if (index >= num_samples) index = num_samples - 1;
}

/** add d minutes to rain_duration */
void DayQuality::updateRainDuration(uint8_t d)
{
  rain_duration += d;
  if (rain_duration > max_r) rain_duration = max_r;
}

void DayQuality::recordDayColor()
{
  // reset for the next day
  for (size_t i = 0; i < num_samples; i++) {
    temp_log[i] = 0;
    humidity_log[i] = 0;
  }
  rain_duration = 0;
}

