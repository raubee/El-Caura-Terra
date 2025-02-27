#ifndef SENSOR_CONTROLLER_HPP
#define SENSOR_CONTROLLER_HPP

class SensorController {
 public:
  virtual void init() = 0;
  virtual void update(bool verbose = false) = 0;
  virtual float getTemperature() = 0;
  virtual float getHumidity() = 0;
  virtual void getTemperature(float value) = 0;
  virtual void getHumidity(float value) = 0;
  virtual float getTemperatureThreshold() = 0;
  virtual float getHumidityThreshold() = 0;
  virtual void printTemperature() = 0;
  virtual void printHumidity() = 0;
};

#endif