#include "RelayController.h"

RelayController::RelayController() : mPinOutputTemperature(RELAY_PIN_TEMPERATURE),
                                     mPinOutputHumidity(RELAY_PIN_HUMIDITY),
                                     mPinOutputLight(RELAY_PIN_LIGHT)
{
}

void RelayController::init()
{
    pinMode(mPinOutputTemperature, OUTPUT);
    pinMode(mPinOutputHumidity, OUTPUT);
    pinMode(mPinOutputLight, OUTPUT);
}

void RelayController::update(bool isTemperatureOn, bool isHumidityOn, bool isLightOn)
{
    toggleOutput(isTemperatureOn, mPinOutputTemperature);
    toggleOutput(isHumidityOn, mPinOutputHumidity);
    toggleOutput(isLightOn, mPinOutputLight);
}

void RelayController::toggleOutput(bool trigger, int pinOutput)
{
    if (trigger)
    {
        setOutputHigh(pinOutput);
    }
    else
    {
        setOutputLow(pinOutput);
    }
}

void RelayController::setOutputHigh(int pinOutput)
{
    digitalWrite(pinOutput, HIGH);
}

void RelayController::setOutputLow(int pinOutput)
{
    digitalWrite(pinOutput, LOW);
}