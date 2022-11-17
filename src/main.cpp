#ifndef TOWER_DEFENSE_MAIN
#define TOWER_DEFENSE_MAIN

#include <iostream>

#include "test.cpp"

int main(int, char**) {
  auto t = test();
  t.testEnemies();
  t.testMap();
  t.testPlayer();
  // t.testGame();
  // t.testGraphics();
  t.testEnemyMovement();
  return 0;
}

#endif