#include "Projectile.hpp"

#include "Game.hpp"

Projectile::Projectile(double speed, double damage, const Coordinate& position,
                       const Coordinate& direction, ProjectileType type,
                       Game* game)
    : speed_(speed),
      damage_(damage),
      pos_(position),
      direction_(direction),
      type_(type),
      game_(game) {}

Coordinate Projectile::GetPosition() { return pos_; }

bool Projectile::hitTarget() {
  std::vector<Enemy*> e = game_->GetEnemies();
  for (auto enemy : e) {
    if ((pos_ - enemy->GetCoord()).getLength() < COLLISION_DISTANCE) {
      enemy->getHit(damage_);
      return true;
    }
  }
  return false;
}

void Projectile::Move() {
  if (!this->hitTarget()) {
    pos_ = pos_ + (direction_ * speed_);
  } else {
    game_->RemoveProjectile(this);
  }
}

float Projectile::getAngle() {
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