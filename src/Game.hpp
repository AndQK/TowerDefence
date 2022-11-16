#ifndef TOWER_DEFENSE_GAME
#define TOWER_DEFENSE_GAME

#include "Map.hpp"
#include "Player.hpp"

class Game {
 public:
  // Initialize a new game.
  Game(const std::string& name);

  // Starting the game, the main loop is in this function
  void startGame();

  // Gets the current player
  Player& getPlayer();

  // Gets the current map the game is played on
  Map getMap() const;

 private:
  Player player_;
  Map map_;
};

#endif