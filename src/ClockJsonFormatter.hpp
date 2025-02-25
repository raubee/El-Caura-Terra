#ifndef CLOCK_JSON_FORMATTER_HPP
#define CLOCK_JSON_FORMATTER_HPP

#include "JsonFormatter.hpp"
#include "RTCController.h"

class ClockJsonFormatter : public JsonFormatter
{
public:
    ClockJsonFormatter(RTCController &controller) : mClockController(controller) {}

    void appendJson(StaticJsonDocument<FULL_JSON_SIZE> &document)
    {
        document["time"] = mClockController.toString();
    }

private:
    RTCController &mClockController;
};

#endif // CLOCK_JSON_FORMATTER_HPP