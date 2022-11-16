#ifndef TOWER_DEFENSE_MAIN
#define TOWER_DEFENSE_MAIN

#include <iostream>

#include "test.cpp"

int main(int, char**) {
  auto t = test();
  t.test1();
  t.test2();
  t.test3();
  return 0;
}

#endif