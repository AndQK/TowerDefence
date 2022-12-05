#ifndef TOWER_DEFENSE_SLOWING_TOWER
#define TOWER_DEFENSE_SLOWING_TOWER

#include "Tower.hpp"

class SlowingTower : public Tower {
 public:
  SlowingTower(Coordinate place, Game* game)
      : Tower(100, 5, 1, place, 250, game){};

  void Defend() {
    Game* game = this->GetGame();
    std::vector<Enemy*> e = game->GetEnemies();
    std::vector<Enemy*> inRange;

    for (auto i : e) {
      auto a = i->GetCoord();
      auto b = this->GetPlace();
      auto dist = (a - b).getLength();
      // auto distance = ((i->GetCoord()) - place_).getLength();
      // std::cout << dist;
      if (dist < this->GetRange()) inRange.push_back(i);
    }
    std::sort(inRange.begin(), inRange.end());

    if (!inRange.empty()) {
      auto enemy = inRange.front();
      auto a = enemy->GetCoord();
      auto b = this->GetPlace();
      auto dist = (a - b).getLength();
      auto dir = (a - b) / dist;
      std::cout << dist << std::endl;
      auto proj =
          Projectile(3, this->GetDamage(), this->GetPlace(), dir, slow, this->GetGame());

      game->AddProjectile(proj); //does not work
    }
  };
};

#endif