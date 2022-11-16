#ifndef TOWER_DEFENSE_GAME
#define TOWER_DEFENSE_GAME

#include "Map.hpp"
#include "Player.hpp"

class Game {
 public:
  // Initialize a new game.
  Game();

  Player& getPlayer();

  Map getMap() const;

 private:
  Player player_;
  Map map_;
};

#endif