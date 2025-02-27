#include "ASensorController.h"


void ASensorController::init() {
  Serial.print(F("[SensorController] Listen temperature on PIN "));
  Serial.print((SENSOR_PIN_TEMPERATURE));
  Serial.println();

  Serial.print(F("[SensorController] Listen humidity on PIN "));
  Serial.print((SENSOR_PIN_HUMIDITY));
  Serial.println();

  pinMode(SENSOR_PIN_TEMPERATURE, INPUT);
  pinMode(SENSOR_PIN_HUMIDITY, INPUT);

  while (!Serial) {
    ;  // wait serialization ready
  }

  mHumiditySensor.begin();
}

void ASensorController::update(bool verbose = false) {
  updateHumidity();
  updateTemperature();

  if (verbose) {
    printHumidity();
    printTemperature();
  }
}

void ASensorController::updateTemperature() {
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

void ASensorController::updateHumidity() {
  // Reading temperature or humidity takes about 250 milliseconds!
  float h = mHumiditySensor.readHumidity();

  if (isnan(h)) {
    return;
  }

  mHumidity = h;
}

void ASensorController::printTemperature() {
  Serial.print(F("Temperature: "));
  Serial.print((mTemperature));
  Serial.println(F(" C"));
}

void ASensorController::printHumidity() {
  Serial.print(F("Humidity: "));
  Serial.print((mHumidity));
  Serial.println(F(" %"));
}