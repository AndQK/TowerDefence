#ifndef TOWER_DEFENSE_MAIN
#define TOWER_DEFENSE_MAIN

#include <math.h>

#include <SFML/Graphics.hpp>
#include <iostream>

#include "test.cpp"

int main(int, char**) {
  auto t = test();
  // t.testEnemies();
  // t.testMap();
  // t.testPlayer();
  //t.testSprites();
  // t.testGame();
  // t.testGraphics();
  // t.testEnemyMovement();
  // t.testProjectiles();
  // t.testRotate();
  //t.testGui();
  // t.testEnemyMovement();
  // t.testProjectiles();
  // t.testRotate();
  t.testGui();
  return 0;
}

#endif