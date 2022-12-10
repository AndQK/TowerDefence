#ifndef TOWER_DEFENSE_BOMB_TOWER
#define TOWER_DEFENSE_BOMB_TOWER

#include "Tower.hpp"

class BombTower : public Tower {
 public:
  BombTower(Coordinate place, Game* game)
      : Tower(500, 10, 3, place, 3, game, 1){};

  void Defend() { this->Shoot(bomb); }
};

#endif