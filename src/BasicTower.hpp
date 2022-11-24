#ifndef TOWER_DEFENSE_BASIC_TOWER
#define TOWER_DEFENSE_BASIC_TOWER

#include "Tower.hpp"

class BasicTower : public Tower {
 public:
  BasicTower(Coordinate place) : Tower(150, 3, 1, place, 2){};
};

#endif