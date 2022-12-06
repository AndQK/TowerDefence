#ifndef TOWER_DEFENSE_PROJECTILE
#define TOWER_DEFENSE_PROJECTILE

#include "Coordinate.hpp"

enum ProjectileType { normal, bomb, slow };

class Game;
class Projectile {
 public:
  Projectile(double speed, double damage, const Coordinate& position,
             const Coordinate& direction, ProjectileType type, Game* game);

  // Gets the current position of the projectile
  Coordinate GetPosition();

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
  Game* game_;

  // The type of the projectile, etc bomb or slow
  ProjectileType type_;

  // Distance where the collision between projectiles and enemies happen.
  // Could be changed to be different with different enemies.s
  const double COLLISION_DISTANCE = 35;
};

#endif