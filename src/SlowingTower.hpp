#ifndef TOWER_DEFENSE_SLOWING_TOWER
#define TOWER_DEFENSE_SLOWING_TOWER

#include "Tower.hpp"

class SlowingTower : public Tower {
 public:
  SlowingTower(Coordinate place, Game* game)
      : Tower(100, 10, 1, place, 250, game) {}

  void Defend() { this->Shoot(slow); }
};

#endif