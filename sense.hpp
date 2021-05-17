/*
 * does all the sensing innit
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
    static const int echo_pin;
    static const int trig_pin;
    static const int sun_pin;
    static const int rangefinder_gnd;


  public:
    static bool isRaining()
    {
      return digitalRead(rain_pin);
    }

    static bool isDark()
    {
      return digitalRead(sun_pin); // its inverted
    }

    /** returns temperature and humidity readings */
    static TempHumidity readTH()
    {
      TempHumidity r;
      r.temperature = dht.readTemperature();
      r.humidity = dht.readHumidity();
      return r;
    }

    /** returns true if something is within close cm of the rangefinder */
    static bool isUserClose(uint8_t close = 55)
    {
      digitalWrite(trig_pin, LOW);
      delayMicroseconds(2);
      digitalWrite(trig_pin, HIGH);
      delayMicroseconds(5);
      digitalWrite(trig_pin, LOW);

      // maff maffics microseconds to centimeters
      return (pulseIn(echo_pin, HIGH) / 29 / 2) <= close;
    }

    /** call this before reading any sensors */
    static void start()
    {
      dht.begin();
      pinMode(rain_pin, INPUT);
      pinMode(echo_pin, INPUT);
      pinMode(sun_pin, INPUT);
      pinMode(trig_pin, OUTPUT);
      pinMode(rangefinder_gnd, OUTPUT);
      digitalWrite(rangefinder_gnd, LOW);
    }
};

const int Sense::dht_pin = 6;
const int Sense::rain_pin = 7;
const int Sense::sun_pin = 53;
const int Sense::echo_pin = 8;
const int Sense::trig_pin = 9;
const int Sense::rangefinder_gnd = 10;
DHT Sense::dht(Sense::dht_pin, DHT11);

