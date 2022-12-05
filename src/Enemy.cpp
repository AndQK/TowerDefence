#include "Enemy.hpp"

#include <math.h>

#include "Game.hpp"

Enemy::Enemy(float speed, int health, Coordinate place, int worth, Game* game)
    : speed_(speed),
      health_(health),
      place_(place),
      worth_(worth),
      currentNode_(0),
      game_(game) {
  auto direction_raw = game_->GetMap().GetNode(currentNode_) - place_;
  direction_ = direction_raw / direction_raw.getLength();
}

void Enemy::getHit(int amount) {
  std::cout << "Enemy has " << health_ << " health." << std::endl;
  if (health_ < amount) {
    health_ = 0;
    game_->RemoveEnemy(this);
  } else
    health_ -= amount;
}

bool operator<(const Enemy& e1, const Enemy& e2) {
  if (e2.GetDistance() == e1.GetDistance()) {
    return e1.GetDistance();
  }
  return e2.GetDistance() < e1.GetDistance();
}

bool Enemy::Move() {
  auto nextNode = (*game_).GetMap().GetNode(currentNode_);
  double distance = (nextNode - this->place_).getLength();
  // if enemy is near the node, switch to next node unless next node is the
  // last node.
  if (distance < speed_ * 1.5) {
    if (currentNode_ >= (*game_).GetMap().GetNofNodes() - 1) {
      game_->RemoveEnemy(this);
      game_->GetPlayer().reduceHealth();
      return false;
    } else {
      currentNode_++;
      auto direction_raw =
          (*game_).GetMap().GetNode(currentNode_) - this->place_;
      direction_ = direction_raw / direction_raw.getLength();
    }
  }

  // Move towards the next node with the speed_
  place_ = place_ + (direction_ * speed_);
  distance_ += speed_;
  return true;
}

void Enemy::Slow(double s) {
  auto t = s;
  if (speed_ - t > 0) speed_ -= s;
}

float Enemy::getAngle() {
  double PI = 3.1415926535;
  double y = direction_.getY();
  double x = -direction_.getX();
  double angle = 0;
  if ((std::atan2(y, x) * 180 / 3.1415926535) > 0) {
    angle = -360 + std::atan2(y, x) * 180 / 3.1415926535;
  } else {
    angle = std::atan2(y, x) * 180 / 3.1415926535;
  }
  angle = std::fmod((-angle + 270), 360);

  return angle;
}

const float& Enemy::GetSpeed() const { return speed_; }

// Get the enemy's health
const int& Enemy::GetHealth() const { return health_; }

// Get the enemy's coordinates
const Coordinate& Enemy::GetCoord() const { return place_; }

// Get the enemy's worth
const int& Enemy::GetWorth() const { return worth_; }

const int& Enemy::GetDistance() const { return distance_; }