#ifndef TOWER_DEFENSE_GAME
#define TOWER_DEFENSE_GAME

#include <unistd.h>

#include <chrono>
#include <vector>

#include "Enemy.hpp"
#include "Map.hpp"
#include "Player.hpp"
#include "Projectile.hpp"
#include "Tower.hpp"
#include "level.hpp"

class Game {
 public:
  // Initialize a new game.
  Game(const std::string& name, const Map& map);

  // Default constructor
  Game();

  ~Game();

  // Starting the game, the main loop is in this function
  void StartGame();

  // Adds enemy to the current game
  void AddEnemy(Enemy* enemy);

  void AddTower(Tower* tower);

  void AddProjectile(Projectile* projectile);

  void SetLevel(Level& level);

  void sustainFramerate(std::chrono::steady_clock::time_point beg,
                        std::chrono::steady_clock::time_point end);

  // Update enemies, projectiles and towers in the game.
  void Update();

  // Gets the current player
  Player& GetPlayer();

  // Gets the current map the game is played on
  Map GetMap() const;

  Map GetLevel() const;

  // Gets the enemies currently in the game.
  std::vector<Enemy*> GetEnemies();

  void RemoveProjectile(Projectile* projectile);

  void RemoveEnemy(Enemy* enemy);

  std::vector<Tower*> GetTowers();

  std::vector<Projectile*> GetProjectiles();

 private:
  Player player_;
  Map map_;
  Level level_ = Level(100, this);

  int FPS = 100;

  // Vector of enemies currently in game.
  std::vector<Enemy*> enemies_;
  std::vector<Tower*> towers_;
  std::vector<Projectile*> projectiles_;
};

#endif