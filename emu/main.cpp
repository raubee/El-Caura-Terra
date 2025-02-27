#include <stdlib.h>
#include <iostream>

#include "ESensorController.h"
#include "SensorController.hpp"
#include "terra.h"

int main(int argc, char **argv) {
  auto sensorController = new ESensorController();
  auto terra = new Terra(sensorController);
  terra->setup();

  while (true) {
    terra->update();
    std::cout << terra->getHumidity();
  }

  delete terra;
  delete sensorController;

  return EXIT_SUCCESS;
}