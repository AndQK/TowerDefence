#ifndef TOWER_DEFENSE_MAIN
#define TOWER_DEFENSE_MAIN

#include <SFML/Graphics.hpp>
#include <iostream>

#include "test.cpp"

int main(int, char**) {
  auto t = test();
  t.testEnemies();
  t.testMap();
  t.testPlayer();
  // t.testGame();
  // t.testGraphics();
  //t.testEnemyMovement();
  t.testSprites();
  return 0;
}

#endif