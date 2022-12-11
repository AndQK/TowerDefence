#ifndef TOWER_DEFENSE_SLOWING_TOWER
#define TOWER_DEFENSE_SLOWING_TOWER

#include "Tower.hpp"

class SlowingTower : public Tower {
 public:
  SlowingTower(Coordinate place, Game* game)
      : Tower(300, 8, 2, place, 150, game, 2) {}

  void Defend() { this->Shoot(slow); }
};

#endif