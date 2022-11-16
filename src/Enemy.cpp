#include "Enemy.hpp"

Enemy::Enemy(float speed, int health, Coordinate place, int worth)
    : speed_(speed), health_(health), place_(place), worth_(worth) {}

// virtual ~Vehicle() {};, do we need this?

void Enemy::getHit(int amount) {
  if (health_ < amount)
    health_ = 0;
  else
    health_ -= amount;
}

void Enemy::Move(Coordinate c) { place_ = c; }

void Enemy::Slow(double s) {
  auto t = s;
  if (speed_ - t > 0) speed_ -= s;
}

const float& Enemy::GetSpeed() const { return speed_; }

// Get the enemy's health
const int& Enemy::GetHealth() const { return health_; }

// Get the enemy's coordinates
const Coordinate& Enemy::GetCoord() const { return place_; }

// Get the enemy's worth
const int& Enemy::GetWorth() const { return worth_; }