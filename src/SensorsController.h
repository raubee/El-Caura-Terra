#ifndef SENSORS_CONTROLLER_H
#define SENSORS_CONTROLLER_H

#include <Arduino.h>
#include <DS18B20.h>
#include <DHT_U.h>
#include <DHT.h>

#define DHTTYPE DHT22

class SensorsController
{
public:
    SensorsController(int pinTemp, int pinHumidity);

    void init();
    void update(bool verbose = false);

    float getTemperature() { return mTemperature; }
    float getHumidity() { return mHumidity; }

    void getTemperature(float value) { mTemperature = value; }
    void getHumidity(float value) { mHumidity = value; }

    float getTemperatureThreshold() { return mThresholdTemperature; }
    float getHumidityThreshold() { return mThresholdHumidity; }

    bool isUpperTemperatureThreshold();
    bool isUpperHumidityThreshold();

    void printTemperature();
    void printHumidity();

private:
    DS18B20 mTemperatureSensor;
    DHT mHumiditySensor;

    int mPinTemperature;
    int mPinHumidity;

    float mHumidity;
    float mTemperature;

    float mThresholdTemperature;
    float mThresholdHumidity;

    void updateTemperature();
    void updateHumidity();
};

#endif // SENSORS_CONTROLLER_H