#ifndef TOWER_DEFENSE_LEVEL
#define TOWER_DEFENSE_LEVEL

#include <Map.hpp>
#include <chrono>
#include <string>
#include <vector>

#include "Enemy.hpp"

class Game;

class Wave {
 public:
  Wave(float spawnRate, Game* game);

  void addEnemy(Enemy* e);

  void update();

  void startWave();

  bool ended();

  bool started();

  void updateLastSpawn();

 private:
  // Enemies' spawn rate (spawns per second.)
  float spawnRate_;

  Game* game_;

  std::chrono::steady_clock::time_point lastSpawn_;

  std::vector<Enemy*> enemies_;

  int enemyAmount;

  bool started_ = false;

  int enemiesSpawned = 0;
};

class Level {
 public:
  Level(int initial_money, Game* game);

  Level();

  ~Level();

  int initial_money() const;

  // updates the level.
  void update();

  void removeWave(Wave* w);

  int getCurrentWave();

 private:
  int initial_money_;

  int currentWave_;

  Game* game_;

  std::vector<Wave*> waves_;
};
#endif