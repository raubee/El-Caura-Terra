#include "SensorsController.h"

SensorsController::SensorsController(int pinTemp, int pinHumidity) : mPinTemperature(pinTemp),
                                         mPinHumidity(pinHumidity),
                                         mTemperatureSensor(mPinTemperature),
                                         mHumiditySensor(mPinHumidity, DHTTYPE),
                                         mTemperature(0),
                                         mHumidity(0),
                                         mThresholdTemperature(26.),
                                         mThresholdHumidity(80.)
{
}

void SensorsController::init()
{
    Serial.print(F("[SensorController] Listen temperature on PIN "));
    Serial.print((mPinTemperature));
    Serial.println();

    Serial.print(F("[SensorController] Listen humidity on PIN "));
    Serial.print((mPinHumidity));
    Serial.println();

    pinMode(mPinTemperature, INPUT);
    pinMode(mPinHumidity, INPUT);

    while(!Serial)
    {
        ; // wait serialization ready
    }
    
    mHumiditySensor.begin();
}

void SensorsController::update(bool verbose = false)
{
    updateHumidity();
    updateTemperature();

    if (verbose)
    {
        printHumidity();
        printTemperature();
    }
}

void SensorsController::updateTemperature()
{
    while (mTemperatureSensor.selectNext())
    {
        mTemperature = mTemperatureSensor.getTempC();
    }

    if (mTemperature == 0)
    {
        float t = mHumiditySensor.readTemperature();

        if (isnan(t))
        {
            return;
        }

        mTemperature = t;
    }
}

void SensorsController::updateHumidity()
{
    // Reading temperature or humidity takes about 250 milliseconds!
    float h = mHumiditySensor.readHumidity();

    if (isnan(h))
    {
        return;
    }

    mHumidity = h;
}

bool SensorsController::isUpperTemperatureThreshold()
{
    return mTemperature < mThresholdTemperature;
}

bool SensorsController::isUpperHumidityThreshold()
{
    return mHumidity < mThresholdHumidity;
}

void SensorsController::printTemperature()
{
    Serial.print(F("Temperature: "));
    Serial.print((mTemperature));
    Serial.println(F(" C"));
}

void SensorsController::printHumidity()
{
    Serial.print(F("Humidity: "));
    Serial.print((mHumidity));
    Serial.println(F(" %"));
}