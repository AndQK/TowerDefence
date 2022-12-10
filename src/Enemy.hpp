#ifndef TOWER_DEFENSE_ENEMY
#define TOWER_DEFENSE_ENEMY

#include "Coordinate.hpp"

class Game;

class Enemy {
 public:
  Enemy(float speed, int health, Coordinate place, int worth, Game* game,
        int type);

  // A tower hits the enemy and damages them decreasing their health.
  void getHit(int amount);

  bool operator<(const Enemy& e1);

  // The enemy moves to towards their next position.
  bool Move();

  // Slows the enemy down.
  void Slow();

  // Get the enemy's speed
  const float& GetSpeed() const;

  // Get the enemy's health
  const int& GetHealth() const;

  // Get the enemy's coordinates
  const Coordinate& GetCoord() const;

  // Get the enemy's worth
  const int& GetWorth() const;

  const float& GetDistance() const;

  float getAngle();

  int getCurrentNode() { return currentNode_; }

  void setCurrentNode(int node) { currentNode_ = node; }

  void setDistance(int dist) { distance_ = dist; }

  // Get the enemy's type
  const int& GetType() const;

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

  // Tracks which node on the map the enemy is currently heading towards.
  int currentNode_;

  // The current direction as an unit vector stored in Coordinate class.
  Coordinate direction_;

  // Tracks which game the enemy belongs to.
  Game* game_;

  // How far along the game the enemy is.
  float distance_;

  // the type of the enemy
  int type_;
};

class HardEnemy : public Enemy {
 public:
  HardEnemy(Coordinate place, int health, Game* game)
      : Enemy(1.5, health, place, 50, game, 1){};
};

class EasyEnemy : public Enemy {
 public:
  EasyEnemy(Coordinate place, int health, Game* game)
      : Enemy(1.0, health, place, 5, game, 0){};
};

class SplittingEnemy : public Enemy {
 public:
  SplittingEnemy(Coordinate place, int health, Game* game)
      : Enemy(0.7, health, place, 20, game, 1){};
};

#endif
