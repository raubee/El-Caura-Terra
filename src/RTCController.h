#ifndef RTC_CONTROLLER_H
#define RTC_CONTROLLER_H

#include <DS3231.h>
#include <Wire.h>

static bool sCentury = true;
static bool sH12Flag = false;
static bool sPmFlag = false;

class RTCController
{
public:
    RTCController();

    void init();
    String toString();
    void printClock();

    uint16_t getYear() { return mClock.getYear() + 2000; }
    uint8_t getMonth() { return mClock.getMonth(sCentury); }
    uint8_t getDay() { return mClock.getDate(); }
    uint8_t getHours() { return mClock.getHour(sH12Flag, sPmFlag); }
    uint8_t getMinutes() { return mClock.getMinute(); }
    uint8_t getSeconds() { return mClock.getSecond(); }

    void setTime(DateTime date);

private:
    DS3231 mClock;
};

#endif //TC_CONTROLLER_H