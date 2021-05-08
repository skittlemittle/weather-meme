/*
 * does all the weather measurements innit
 * skittlemittle 2021, MIT license
 */
#pragma once
#include "DHT.h"

struct TempHumidity {
  float temperature;
  float humidity;
};

class Sense {
  private:
    static const int dht_pin;
    static DHT dht;
    static const int rain_pin;

  public:
    static bool isRaining()
    {
      return digitalRead(rain_pin);
    }

    /** returns temperature and humidity readings */
    static TempHumidity readTH()
    {
      TempHumidity r;
      r.temperature = dht.readTemperature();
      r.humidity = dht.readHumidity();
      return r;
    }

    /** call this before you read the dht innit */
    static void start()
    {
      dht.begin();
    }
};

const int Sense::dht_pin = 6;
const int Sense::rain_pin = 7;
DHT Sense::dht(Sense::dht_pin, DHT11);

