#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <Arduino.h>
#include <DHT.h>
#include <DHT_U.h>
#include <DS18B20.h>

#include "SensorController.hpp"

#define DHTTYPE DHT22
#define SENSOR_PIN_TEMPERATURE PIN3
#define SENSOR_PIN_HUMIDITY PIN4

class ASensorsController : SensorController {
 public:
  ASensorsController();

  void init() override;
  void update(bool verbose = false) override;

  float getTemperature() override { return mTemperature; }
  float getHumidity() override { return mHumidity; }

  void getTemperature(float value) override { mTemperature = value; }
  void getHumidity(float value) override { mHumidity = value; }

  float getTemperatureThreshold() override { return mThresholdTemperature; }
  float getHumidityThreshold() override { return mThresholdHumidity; }

  void printTemperature() override;
  void printHumidity() override;

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

#endif