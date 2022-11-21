#ifndef TOWER_DEFENSE_GAME
#define TOWER_DEFENSE_GAME

#include <vector>

#include "Enemy.hpp"
#include "Map.hpp"
#include "Player.hpp"

class Game {
 public:
  // Initialize a new game.
  Game(const std::string& name, const Map& map);

  // Default constructor
  Game();

  // Starting the game, the main loop is in this function
  void StartGame();

  // Adds enemy to the current game
  void AddEnemy(Enemy& enemy);

  // Gets the current player
  Player& GetPlayer();

  // Gets the current map the game is played on
  Map GetMap() const;

  // Gets the enemies currently in the game.
  std::vector<Enemy*> GetEnemies();

 private:
  Player player_;
  Map map_;

  // Vector of enemies currently in game.
  std::vector<Enemy*> enemies_;
};

#endif