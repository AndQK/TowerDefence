#include "Projectile.hpp"

Projectile::Projectile(double speed, double damage, const Coordinate& direction,
                       ProjectileType type, Game& game)
    : speed_(speed),
      damage_(damage),
      direction_(direction),
      type_(type),
      game_(game) {}

/*
bool Projectile::hitTarget() {
  for (auto enemy : game_.getEnemies()) {
    if ((pos_ - enemy.GetCoord()).getLength() < COLLISION_DISTANCE) {
      enemy.getHit(damage_);
      std::cout << "Enemy hit with " << damage_ << " damage. Remove projectile."
                << std::endl;
      return true;
    }
  }
  return false;
}*/

void Projectile::Move() {
  pos_ = pos_ + (direction_ * speed_);
  /*if (!this->hitTarget()) {
    pos_ = pos_ + (direction_ * speed_);
  } else {
    // Remove projectile
  }*/
}