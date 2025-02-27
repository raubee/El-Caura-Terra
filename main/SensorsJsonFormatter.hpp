#ifndef SENSORS_JSON_FORMATTER_HPP
#define SENSORS_JSON_FORMATTER_HPP

#include "JsonFormatter.hpp"
#include "SensorsController.h"

class SensorsJsonFormatter : public JsonFormatter
{
public:
    SensorsJsonFormatter(SensorsController &controller) : mSensorsController(controller) {}

    void appendJson(StaticJsonDocument<FULL_JSON_SIZE> &document)
    {
        document["temp"] = mSensorsController.getTemperature();
        document["hum"] = mSensorsController.getHumidity();
        document["temp_threshold"] = mSensorsController.getTemperatureThreshold();
        document["hum_threshold"] = mSensorsController.getHumidityThreshold();
    }

private:
    SensorsController &mSensorsController;
};

#endif // SENSORS_JSON_FORMATTER_HPP