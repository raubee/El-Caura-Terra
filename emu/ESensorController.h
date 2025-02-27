#ifndef ESENSORCONTROLLER_H
#define ESENSORCONTROLLER_H

#include "SensorController.hpp"

class ESensorController : public SensorController {
 public:
  ESensorController();
  ~ESensorController();

  void init() override {};
  void update(bool verbose = false) override {};

  float getTemperature() override { return 10; }
  float getHumidity() override { return 70; }

  void getTemperature(float value) override {}
  void getHumidity(float value) override {}

  float getTemperatureThreshold() override { return 20; }
  float getHumidityThreshold() override { return 80; }

  void printTemperature() override {};
  void printHumidity() override {};
};

ESensorController::ESensorController() {}

ESensorController::~ESensorController() {}

#endif // ESENSORCONTROLLER_H