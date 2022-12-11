#ifndef TOWER_DEFENSE_MAIN
#define TOWER_DEFENSE_MAIN

#include <math.h>

#include <SFML/Graphics.hpp>
#include <iostream>

#include "test.cpp"

int main(int, char**) {
  auto map = Map();
  map.loadCoordinates("path3.txt");
  Game game = Game("Gargamel", map);
  Level level = Level(100, &game);
  game.SetLevel(level);
  Gui gui = Gui(&game);
  gui.run();
  return 0;
}

#endif