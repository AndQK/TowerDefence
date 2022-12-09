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
    if (pos_.getX() < 0 || pos_.getY() < 0 || pos_.getX() > 843 ||
        pos_.getY() > 657)
      game_->RemoveProjectile(this);
    else
      pos_ = pos_ + (direction_ * speed_);
  } else {
    game_->RemoveProjectile(this);
  }
}