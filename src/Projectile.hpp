#ifndef TOWER_DEFENSE_PROJECTILE
#define TOWER_DEFENSE_PROJECTILE

#include "Coordinate.hpp"
#include "Game.hpp"

enum ProjectileType { normal, bomb, slow };

class Projectile {
 public:
  Projectile(double speed, double damage, const Coordinate& direction,
             ProjectileType type, Game& game);

  // Checks if the projectile has hit any enemies on the game.
  bool hitTarget();

  // Moves the projectiles towards direction_ with speed_.
  void Move();

 private:
  // Direction the projectile is heading.
  // Stored as a unit vector.
  Coordinate direction_;

  Coordinate pos_;
  double speed_;
  double damage_;

  // The game that the projectile belongs to.
  Game game_;

  // The type of the projectile, etc bomb or slow
  ProjectileType type_;

  const double COLLISION_DISTANCE = 50;
};

#endif