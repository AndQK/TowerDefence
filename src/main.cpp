#ifndef TOWER_DEFENSE_MAIN
#define TOWER_DEFENSE_MAIN

#include <iostream>

#include "test.cpp"

int main(int, char**) {
  auto t = test();
  t.test1();
  t.testPlayer();
  t.testEnemies();
  t.test3();
  return 0;
}

#endif