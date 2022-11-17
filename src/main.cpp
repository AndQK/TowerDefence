#ifndef TOWER_DEFENSE_MAIN
#define TOWER_DEFENSE_MAIN

#include <iostream>

#include "test.cpp"

int main(int, char**) {
  auto t = test();
  t.testGraphics();
  return 0;
}

#endif