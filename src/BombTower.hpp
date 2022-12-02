#ifndef TOWER_DEFENSE_BOMB_TOWER
#define TOWER_DEFENSE_BOMB_TOWER

#include "Tower.hpp"

class BombTower : public Tower {
 public:
  BombTower(Coordinate place) : Tower(200, 4, 2, place, 3){};
};

#endif