#include "ASensorsController.h"

ASensorsController::ASensorsController()
    mTemperatureSensor(SENSOR_PIN_TEMPERATURE),
    mHumiditySensor(SENSOR_PIN_HUMIDITY, DHTTYPE), mTemperature(0),
    mHumidity(0), mThresholdTemperature(26.), mThresholdHumidity(80.) {}

void ASensorsController::init() {
  Serial.print(F("[SensorController] Listen temperature on PIN "));
  Serial.print((mPinTemperature));
  Serial.println();

  Serial.print(F("[SensorController] Listen humidity on PIN "));
  Serial.print((mPinHumidity));
  Serial.println();

  pinMode(mPinTemperature, INPUT);
  pinMode(mPinHumidity, INPUT);

  while (!Serial) {
    ;  // wait serialization ready
  }

  mHumiditySensor.begin();
}

void ASensorsController::update(bool verbose = false) {
  updateHumidity();
  updateTemperature();

  if (verbose) {
    printHumidity();
    printTemperature();
  }
}

void ASensorsController::updateTemperature() {
  while (mTemperatureSensor.selectNext()) {
    mTemperature = mTemperatureSensor.getTempC();
  }

  if (mTemperature == 0) {
    float t = mHumiditySensor.readTemperature();

    if (isnan(t)) {
      return;
    }

    mTemperature = t;
  }
}

void ASensorsController::updateHumidity() {
  // Reading temperature or humidity takes about 250 milliseconds!
  float h = mHumiditySensor.readHumidity();

  if (isnan(h)) {
    return;
  }

  mHumidity = h;
}

bool ASensorsController::isUpperTemperatureThreshold() {
  return mTemperature < mThresholdTemperature;
}

bool ASensorsController::isUpperHumidityThreshold() {
  return mHumidity < mThresholdHumidity;
}

void ASensorsController::printTemperature() {
  Serial.print(F("Temperature: "));
  Serial.print((mTemperature));
  Serial.println(F(" C"));
}

void ASensorsController::printHumidity() {
  Serial.print(F("Humidity: "));
  Serial.print((mHumidity));
  Serial.println(F(" %"));
}