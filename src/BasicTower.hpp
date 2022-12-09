#ifndef TOWER_DEFENSE_BASIC_TOWER
#define TOWER_DEFENSE_BASIC_TOWER

#include "Tower.hpp"

class BasicTower : public Tower {
 public:
  BasicTower(Coordinate place, Game* game)
      : Tower(200, 5, 1, place, 150, game, 0){};

  void Defend() { this->Shoot(normal); }
};

#endif