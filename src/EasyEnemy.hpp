#ifndef TOWER_DEFENSE_EASY_ENEMY
#define TOWER_DEFENSE_EASY_ENEMY

#include "Enemy.hpp"

class EasyEnemy : public Enemy {
 public:
  EasyEnemy(Coordinate place, Game* game);
};

#endif