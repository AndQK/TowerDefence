#include "Enemy.hpp"

#include <math.h>

#include "Game.hpp"

Enemy::Enemy(float speed, int health, Coordinate place, int worth, Game* game,
             int type)
    : speed_(speed),
      health_(health),
      place_(place),
      worth_(worth),
      currentNode_(0),
      game_(game),
      type_(type) {
  auto direction_raw = game_->GetMap().GetNode(currentNode_) - place_;
  direction_ = direction_raw / direction_raw.getLength();
}

void Enemy::getHit(int amount) {
  if (amount < 0)
    this->Slow();
  else if (health_ < amount) {
    health_ = 0;
    if (this->GetType() != 1) {
      game_->RemoveEnemy(this);
      this->game_->GetPlayer().AddMoney(this->GetWorth());
    } else {
      Coordinate c = this->place_;
      auto n = this->getCurrentNode();
      auto dist = this->GetDistance();
      auto a =
          new EasyEnemy(Coordinate(c.getX() + 15, c.getY() + 15), 1, game_);
      auto b = new EasyEnemy(c, 1, game_);
      auto d =
          new EasyEnemy(Coordinate(c.getX() - 15, c.getY() - 15), 1, game_);
      a->setCurrentNode(n);
      b->setCurrentNode(n);
      d->setCurrentNode(n);
      a->setDistance(dist);
      b->setDistance(dist);
      d->setDistance(dist);
      game_->AddEnemy(a);
      game_->AddEnemy(b);
      game_->AddEnemy(d);
      game_->RemoveEnemy(this);
    }
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
  if (distance_ > 10000) {
    std::cout << "Error" << std::endl;
  }
  auto nextNode = (*game_).GetMap().GetNode(currentNode_);
  double distance = (nextNode - this->place_).getLength();
  auto direction_raw = (*game_).GetMap().GetNode(currentNode_) - this->place_;
  direction_ = direction_raw / direction_raw.getLength();
  // if enemy is near the node, switch to next node unless next node is the
  // last node.
  if (distance < speed_ * 1.5) {
    if (currentNode_ >= (*game_).GetMap().GetNofNodes() - 1) {
      game_->RemoveEnemy(this);
      game_->GetPlayer().reduceHealth();
      std::cout << game_->GetPlayer().GetHealth() << std::endl;
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

  return true;
}

void Enemy::Slow() {
  speed_ *= 0.9;
  if (speed_ < 0.5) speed_ = 0.5;
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

const float& Enemy::GetDistance() const { return distance_; }

const int& Enemy::GetType() const { return type_; }