#ifndef TOWER_DEFENSE_MAIN
#define TOWER_DEFENSE_MAIN

#include <math.h>

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Gui.hpp"

int main(int, char**) {
  Gui gui = Gui();
  gui.run();
  return 0;
}

#endif