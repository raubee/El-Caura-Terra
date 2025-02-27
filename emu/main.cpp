#include <stdlib.h>

#include <iostream>
#include <memory>

#include "ESensorController.h"
#include "SensorController.hpp"
#include "terra.h"

int main(int argc, char **argv) {
  std::shared_ptr<ESensorController> sensorController =
      std::make_shared<ESensorController>();
  std::unique_ptr<Terra> terra = std::make_unique<Terra>(
      std::static_pointer_cast<SensorController>(sensorController));

  terra->setup();

  while (true) {
    terra->update();
    std::cout << terra->getHumidity();
  }

  return EXIT_SUCCESS;
}