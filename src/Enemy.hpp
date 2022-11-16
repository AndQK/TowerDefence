#ifndef TOWER_DEFENSE_ENEMY
#define TOWER_DEFENSE_ENEMY

#include "Coordinate.hpp"

class Enemy {
 public:
  explicit Enemy(float speed, int health, Coordinate place,
                 int worth);  // add coordinate and image, make explicit?

  // virtual ~Vehicle() {};, do we need this?

  // A tower hits the enemy and damages them decreasing their health.
  void getHit(int amount);

  // The enemy moves to their next position.
  void Move(Coordinate c);

  //Slows the enemy down.
  void Slow(double s);

  // Get the enemy's speed
  const float& GetSpeed() const;

  // Get the enemy's health
  const int& GetHealth() const;

  // Get the enemy's coordinates
  const Coordinate& GetCoord() const;

  // Get the enemy's worth
  const int& GetWorth() const;

 private:
  // Moving speed of the enemy.
  float speed_;

  // The amount of health the enemy has.
  int health_;

  // The place the enemy is currently positioned at.
  Coordinate place_;

  /**How many points the enemy is worth.
   * Only used if we develop the game further.*/
  int worth_;

  // The image of the enemy.
  // PNG image;
};

#endif
