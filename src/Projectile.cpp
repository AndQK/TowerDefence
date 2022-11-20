#include "Projectile.hpp"

Projectile::Projectile(double speed, double damage, const Coordinate& position,
                       const Coordinate& direction, ProjectileType type,
                       Game& game)
    : speed_(speed),
      damage_(damage),
      pos_(position),
      direction_(direction),
      type_(type),
      game_(game) {}

Coordinate Projectile::GetPosition() { return pos_; }

bool Projectile::hitTarget() {
  for (auto* enemy : game_.GetEnemies()) {
    if ((pos_ - enemy->GetCoord()).getLength() < COLLISION_DISTANCE) {
      enemy->getHit(damage_);
      std::cout << "Enemy hit with " << damage_ << " damage. Remove projectile."
                << std::endl;
      return true;
    }
  }
  return false;
}

void Projectile::Move() {
  if (!this->hitTarget()) {
    pos_ = pos_ + (direction_ * speed_);
  } else {
    // Remove projectile
  }
}