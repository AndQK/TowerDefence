#include "test.cpp"

int main(int, char**) {
  auto t = test();
  t.test1();
  t.testPlayer();
  t.testEnemies();
  return 0;
}
