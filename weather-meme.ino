#include "display.hpp"
#include "images.hpp"

Display display;
void setup()
{
  fill_gradient(weather_scale, 10, green, red);
  Serial.begin(9600);
  display.drawNumber(34);
}

void loop()
{
  delay(1000);
  display.clear();
  display.drawImage(hot1, 64);
}
