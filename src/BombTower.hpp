#ifndef TOWER_DEFENSE_BOMB_TOWER
#define TOWER_DEFENSE_BOMB_TOWER

#include "Tower.hpp"

class BombTower : public Tower {
 public:
  BombTower(Coordinate place, Game* game) : Tower(200, 4, 2, place, 3, game){};

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
      auto proj =
          Projectile(3, this->GetDamage(), this->GetPlace(), dir, bomb, game);

      game->AddProjectile(proj);
    }
  };
};

#endif