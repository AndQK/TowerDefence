#include "Tower.hpp"

#include <algorithm>
#include <vector>

#include "Game.hpp"

Tower::Tower(int cost, int speed, int damage, Coordinate place, int range,
             Game* game, int type)
    : cost_(cost),
      speed_(speed),
      damage_(damage),
      place_(place),
      range_(range),
      game_(game),
      type_(type) {}

void Tower::Attack(Enemy& e) { e.getHit(damage_); }

void Tower::Slow(Enemy& e) { e.Slow(); }

void Tower::Move(Coordinate c) { place_ = c; }

void Tower::Shoot(ProjectileType type) {
  // time since last shot.
  auto elapsedTimeInMicroseconds =
      1.0f * std::chrono::duration_cast<std::chrono::microseconds>(
                 std::chrono::steady_clock::now() - this->lastShot)
                 .count();
  // Check if enough time elapsed since last shot.
  if (elapsedTimeInMicroseconds / 1000000 < (1.0f / speed_)) {
    return;
  }

  lastShot = std::chrono::steady_clock::now();
  Game* game = this->GetGame();
  std::vector<Enemy*> e = game->GetEnemies();
  std::vector<Enemy*> inRange;

  for (auto i : e) {
    auto a = i->GetCoord();
    auto b = this->GetPlace();
    auto dist = (a - b).getLength();
    if (dist < this->GetRange()) inRange.push_back(i);
  }

  // std::sort(inRange.begin(), inRange.end());

  if (!inRange.empty()) {
    Coordinate c;
    float maxDist = 0.0;

    for (auto e : inRange) {
      if (maxDist < e->GetDistance()) {
        maxDist = e->GetDistance();
        c = e->GetCoord();
      }
    }

    /**auto enemy = inRange.front();
    std::cout << std::endl;
    auto a = enemy->GetCoord(); */
    for (auto i : inRange) {
      std::cout << i->GetDistance() << ", ";
    }
    std::cout << std::endl;
    std::cout << maxDist << std::endl;
    if (maxDist > 100000) {
      std::cout << "error" << std::endl;
    }

    auto b = this->GetPlace();
    auto dist = (c - b).getLength();
    auto dir = (c - b) / dist;
    auto proj = new Projectile(5, this->GetDamage(), this->GetPlace(), dir,
                               type, this->GetGame());
    game->AddProjectile(proj);
  }
}

const int& Tower::GetCost() const { return cost_; }

const int& Tower::GetSpeed() const { return speed_; }

const int& Tower::GetDamage() const { return damage_; }

const Coordinate& Tower::GetPlace() const { return place_; }

const int& Tower::GetRange() const { return range_; }

Game* Tower::GetGame() const { return game_; }

const int& Tower::GetType() const { return type_; }