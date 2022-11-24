#include "Tower.hpp"

#include "Game.hpp"

Tower::Tower(int cost, int speed, int damage, Coordinate place, int range)
    : cost_(cost),
      speed_(speed),
      damage_(damage),
      place_(place),
      range_(range) {}

Tower::Tower(int cost, int speed, int damage, Coordinate place, int range,
             Game* game)
    : cost_(cost),
      speed_(speed),
      damage_(damage),
      place_(place),
      range_(range),
      game_(game) {}

void Tower::Attack(Enemy e) { e.getHit(damage_); }

void Tower::Slow(Enemy e) { e.Slow(damage_); }

// Towers: torneille sitten kyvyn ammuskella noita projectileja vihollisia päin

void Tower::Move(Coordinate c) { place_ = c; }

const int& Tower::GetCost() const { return cost_; }

const int& Tower::GetSpeed() const { return speed_; }

const int& Tower::GetDamage() const { return damage_; }

const Coordinate& Tower::GetPlace() const { return place_; }

const int& Tower::GetRange() const { return range_; }