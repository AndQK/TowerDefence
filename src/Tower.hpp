#ifndef TOWER_DEFENSE_TOWER
#define TOWER_DEFENSE_TOWER

#include <chrono>
#include <vector>

#include "Coordinate.hpp"
#include "Enemy.hpp"
#include "Projectile.hpp"

class Game;

class Tower {
 public:
  Tower(int cost, int speed, int damage, Coordinate place, int range,
        Game* game, int type);

  // Attacks the enemies in its range.
  void Attack(Enemy& e);

  // Slows down the enemy.
  void Slow(Enemy& e);

  // Tower defends its ground by attacking or slowing enemies.
  virtual void Defend() = 0;

  // Shoot towards enemy with correct projectile type
  void Shoot(ProjectileType type);

  // Enables the player to move the tower during the game.
  void Move(Coordinate c);

  // Get the cost of buying the tower.
  const int& GetCost() const;

  // Get the speed the tower shoots enemies at.
  const int& GetSpeed() const;

  // Get the amount of damage the tower deals to enemies it hits.
  const int& GetDamage() const;

  // Gets the place the tower is located at.
  const Coordinate& GetPlace() const;

  // Gets the range in which the tower can shoots enemies in.
  const int& GetRange() const;

  Game* GetGame() const;

 private:
  // The cost of buying the tower.
  int cost_;

  // The speed the tower shoots enemies at. (Projectiles per second)
  int speed_;

  // Time since last shoot
  std::chrono::steady_clock::time_point lastShot =
      std::chrono::steady_clock::now();

  // The amount of damage the tower deals to hit enemies.
  int damage_;

  // The place on the map the tower is on.
  Coordinate place_;

  // The radius of the circular area that the tower can shoot enemies in.
  int range_;

  int type_;

  Game* game_;
};

#endif
