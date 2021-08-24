#include "rating.hpp"
#include <EEPROM.h>

/** measurement_ranges = {min_t, max_t, min_h, max_h, min_r, max_r}*/
DayQuality::DayQuality(uint8_t* measurement_ranges = default_ranges)
{
  temp_log = new int[num_samples];
  humidity_log = new int[num_samples];
  for (size_t i = 0; i < num_samples; i++) {
    temp_log[i] = 0;
    humidity_log[1] = 0;
  }
  rain_duration = 0;
  EEPROM.get(EEPROM.length() - sizeof address, address);
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
 * returns a hue value [0, 255]
 */
byte DayQuality::calculateDayColor()
{
  int8_t avg_temp = 0, avg_humidity = 0, s = 0;
  for (size_t i = 0; i < num_samples; i++) {
    avg_temp += temp_log[i];
    avg_humidity += humidity_log[i];
    if (humidity_log[i] != 0) s++;
  }

  avg_temp /= s;
  avg_humidity /= s;
  CRGB rgb(
      map(avg_temp, min_t, max_t, 0, 255),
      map(avg_humidity, min_h, max_h, 0, 150),
      map(rain_duration, min_r, max_r, 0, 255)
  );
  if (rain_duration > 5) rgb.blue += 125; // go cry
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

/** add d minutes to rain_duration, unless its been enough rain for the day */
void DayQuality::updateRainDuration(uint8_t d)
{
  rain_duration += d;
  if (rain_duration > max_r) rain_duration = max_r;
}

/** store the days color in eeprom */
void DayQuality::recordDayColor()
{
  EEPROM.update(address, calculateDayColor());
  address++;
  // i keep the day pointer at the very end of the eeprom
  if (address == EEPROM.length() - sizeof address) address = 0;
  EEPROM.update(EEPROM.length() - sizeof address, address);

  // reset for the next day
  for (size_t i = 0; i < num_samples; i++) {
    temp_log[i] = 0;
    humidity_log[i] = 0;
  }
  rain_duration = 0;
}

/** fills r with the hues of the past `days` days */
uint8_t* DayQuality::getHistory(uint8_t* r, uint8_t days)
{
  uint8_t c_add = address;
  uint8_t address_address = EEPROM.length() - sizeof address;

  // our day colors are stored as bytes so we can just walk around eeprom in steps of 1
  for (size_t i = 0; i < days; i++) {
    EEPROM.get(c_add--, r[i]);
    if (c_add == address_address) c_add = address_address - 1;
  }
  return r;
}
