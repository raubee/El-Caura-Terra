#ifndef ASENSORCONTROLLER_H
#define ASENSORCONTROLLER_H

#include <Arduino.h>
#include <DHT.h>
#include <DHT_U.h>
#include <DS18B20.h>

#include "../terra/SensorController.hpp"

#define DHTTYPE DHT22
#define SENSOR_PIN_TEMPERATURE PIN3
#define SENSOR_PIN_HUMIDITY PIN4

class ASensorController {
 public:
  ASensorController();
  ~ASensorController();

  void init();
  void update(bool verbose = false);

  float getTemperature() { return mTemperature; }
  float getHumidity() { return mHumidity; }

  void getTemperature(float value) { mTemperature = value; }
  void getHumidity(float value) { mHumidity = value; }

  float getTemperatureThreshold() { return mThresholdTemperature; }
  float getHumidityThreshold() { return mThresholdHumidity; }

  void printTemperature();
  void printHumidity();

 private:
  DS18B20 mTemperatureSensor;
  DHT mHumiditySensor;

  float mHumidity;
  float mTemperature;

  float mThresholdTemperature;
  float mThresholdHumidity;

  void updateTemperature();
  void updateHumidity();
};

ASensorController::ASensorController()
    : mTemperatureSensor(SENSOR_PIN_TEMPERATURE),
      mHumiditySensor(SENSOR_PIN_HUMIDITY, DHTTYPE),
      mTemperature(0),
      mHumidity(0),
      mThresholdTemperature(26.),
      mThresholdHumidity(80.) {}

ASensorController::~ASensorController() {}

#endif  // ASENSORCONTROLLER_H