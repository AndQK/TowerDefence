#ifndef TOWER_DEFENSE_MAIN
#define TOWER_DEFENSE_MAIN

#include <math.h>

#include <SFML/Graphics.hpp>
#include <iostream>

#include "test.cpp"

int main(int, char**) {
  auto t = test();
  t.testGui();
  return 0;
}

#endif