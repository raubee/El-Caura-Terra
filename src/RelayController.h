#ifndef RELAY_CONTROLLER_H
#define RELAY_CONTROLLER_H

#include <Arduino.h>

/************** Relay outputs *******************/
#define RELAY_PIN_TEMPERATURE PIN7
#define RELAY_PIN_HUMIDITY PIN6
#define RELAY_PIN_LIGHT PIN5

class RelayController
{
public:
    RelayController();
    void init();
    void update(bool isTemperatureOn, bool isHumidityOn, bool isLightOn);

private:
    int mPinOutputTemperature;
    int mPinOutputHumidity;
    int mPinOutputLight;

    void toggleOutput(bool trigger, int pinOutput);
    void setOutputHigh(int pinOutput);
    void setOutputLow(int pinOutput);
};

#endif // RELAY_CONTROLLER_H
