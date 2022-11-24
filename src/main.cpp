#ifndef TOWER_DEFENSE_MAIN
#define TOWER_DEFENSE_MAIN

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

#include "test.cpp"

int main(int, char**) {
  auto t = test();
  //t.testEnemies();
  //t.testMap();
  //t.testPlayer();
  //t.testSprites();
  //t.testGame();
  //t.testGraphics();
  //t.testEnemyMovement();
  //t.testProjectiles();
  t.testTowers();
  //t.testRotate();
  return 0;
}

#endif