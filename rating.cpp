#include "rating.hpp"

DayQuality::DayQuality()
{
  temp_log = new int[12]{0};
  rain_duration = 0;
  fill_gradient(weather_scale, 10, green, red);
}

/** rates the day between on a scale of red to green, red: bad, green: pog*/
CRGB DayQuality::calculateDayColor()
{
  // function of avg temperature and rain duration
  int8_t avg_temp = 0;
  size_t tl_size = sizeof temp_log / sizeof temp_log[0];
  for (size_t i = 0; i < tl_size; i++)
    avg_temp += temp_log[i];

  avg_temp /= tl_size;
  // these criteria are entirely objective and not biased in any way
  // lowest: 40c, no rain = -40
  // highest: 15c, 1 hour of rain = 45
  uint8_t r = 2 * rain_duration - avg_temp;
  return weather_scale[map(r, -40, 45, 0, 9)];
}

/** save a single weather sample */
void logWeather(WState curr_weather)
{
  static uint8_t t_index = 0;
  temp_log[t_index++] = curr_weather.temperature;
}

