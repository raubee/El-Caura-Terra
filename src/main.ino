#include <Arduino.h>
#include "JsonFormatter.hpp"
#include "SensorsJsonFormatter.hpp"
#include "ClockJsonFormatter.hpp"
#include "CalendarJsonFormatter.hpp"
#include "RelayController.h"
#include "WebServer.h"
#include "html/index.h"

/************** Sensors inputs *******************/
#define SENSOR_PIN_TEMPERATURE PIN2
#define SENSOR_PIN_HUMIDITY PIN4

static WebServer server;
static SensorsController sensorsController(SENSOR_PIN_TEMPERATURE, SENSOR_PIN_HUMIDITY);
static RelayController relayController;
static RTCController clockController;
static Calendar lightCalendar;
static Calendar humidityCalendar;

static auto jsonSensorsFormatter = SensorsJsonFormatter(sensorsController);
static auto jsonClockFormatter = ClockJsonFormatter(clockController);
static auto jsonHumidityCalendarFormatter = CalendarJsonFormatter(humidityCalendar, "hum_");
static auto jsonLightCalendarFormatter = CalendarJsonFormatter(lightCalendar, "light_");

static String getFullStringFromJson()
{
  String result;
  StaticJsonDocument<FULL_JSON_SIZE> document;
  jsonSensorsFormatter.appendJson(document);
  jsonClockFormatter.appendJson(document);
  jsonLightCalendarFormatter.appendJson(document);
  jsonHumidityCalendarFormatter.appendJson(document);
  serializeJsonPretty(document, result);
  return result;
}

static EndpointMapping sIndexPage = {"/", "text/html", getIndexPage};
static EndpointMapping sFullPage = {"/full", "application/json", getFullStringFromJson};
static EndpointMapping sSensorPage = {"/sensors", "application/json", jsonSensorsFormatter.getStringFromJson};
static EndpointMapping sClockPage = {"/clock", "application/json", jsonClockFormatter.getStringFromJson};
static EndpointMapping sHumidityPage = {"/humidity_calendar", "application/json", jsonHumidityCalendarFormatter.getStringFromJson};
static EndpointMapping sLightPage = {"/light_calendar", "application/json", jsonLightCalendarFormatter.getStringFromJson};

#define EVERYDAY_DATE(h, m, s) DateTime(2023, 01, 01, h, m, s)

void planLightCalendar()
{
  DailyEntry entry = {// Light is on each day from 9h to 22h
                      EVERYDAY_DATE(9, 0, 0),
                      EVERYDAY_DATE(22, 0, 0)};

  lightCalendar.planDailyMeeting(entry);
}

void planWeekHumidityCalendar()
{
  DailyEntry cycle1 = {// Light is on each day from 10h to 10h00:30
                       EVERYDAY_DATE(10, 0, 0),
                       EVERYDAY_DATE(10, 0, 30)};
  humidityCalendar.planDailyMeeting(cycle1);

  DailyEntry cycle2 = {// Light is on each day from 15h to 15h01:00
                       EVERYDAY_DATE(15, 0, 0),
                       EVERYDAY_DATE(15, 1, 0)};
  humidityCalendar.planDailyMeeting(cycle2);

  DailyEntry cycle3 = {// Light is on each day from 20h to 20h00:30
                       EVERYDAY_DATE(20, 0, 0),
                       EVERYDAY_DATE(20, 0, 30)};
  humidityCalendar.planDailyMeeting(cycle3);
}

void planWeekendHumidityCalendar()
{
  const uint8_t nbDays = 5;
  uint8_t days[nbDays] = {0, 1, 2, 3, 4};
  WeeklyEntry cycle1 = {EVERYDAY_DATE(10, 0, 0),
                        EVERYDAY_DATE(10, 0, 30),
                        &days[0], nbDays};
  humidityCalendar.planDailyMeeting(cycle1);
}

void planHumidityCalendar()
{
  planWeekHumidityCalendar();
  // planWeekendHumidityCalendar();
}

bool isLightOn()
{
  return lightCalendar.isInMeeting();
}

void setup()
{
  Serial.begin(9600);
  sensorsController.init();
  relayController.init();
  clockController.init();
  // rtc->setTime(DateTime(20, 11, 21, 21, 23, 00));
  server.create();
  server.createRedirectionPage(sIndexPage);
  server.createRedirectionPage(sSensorPage);
  server.createRedirectionPage(sClockPage);
  server.createRedirectionPage(sHumidityPage);
  server.createRedirectionPage(sLightPage);
  server.createRedirectionPage(sFullPage);

  planLightCalendar();
  planHumidityCalendar();
}

void loop()
{
  sensorsController.update();
  relayController.update(sensorsController.isUpperTemperatureThreshold(),
                          sensorsController.isUpperHumidityThreshold(),
                          isLightOn());
  server.listen();
}
