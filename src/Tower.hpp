#ifndef TOWER_DEFENSE_TOWER
#define TOWER_DEFENSE_TOWER

#include "Coordinate.hpp"
#include "Enemy.hpp"

class Game;

class Tower {
 public:
  explicit Tower(int cost, int speed, int damage, Coordinate place, int range);

  Tower(int cost, int speed, int damage, Coordinate place, int range,
        Game* game);

  // Attacks the enemies in its range.
  void Attack(Enemy &e);

  // Slows down the enemy.
  void Slow(Enemy &e);

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

 private:
  // The cost of buying the tower.
  int cost_;

  // The speed the tower shoots enemies at.
  int speed_;

  // The amount of damage the tower deals to hit enemies.
  int damage_;

  // The place on the map the tower is on.
  Coordinate place_;

  // The radius of the circular area that the tower can shoot enemies in.
  int range_;

  Game* game_;
};

#endif