#ifndef TOWER_DEFENSE_MAIN
#define TOWER_DEFENSE_MAIN

#include <iostream>

#include "test.cpp"

int main(int, char**) {
  auto t = test();
  t.testMap();
  t.testPlayer();
  t.testEnemies();
  t.testGame();
  t.testGraphics();
  return 0;
}

#endif