#include "Player.hpp"

Player::Player(std::string username)
    : username_(username), points_(0), money_(100), health_(15) {}

void Player::AddMoney(int a) { money_ += a; }

bool Player::Pay(int a) {
  if (a <= money_) {
    money_ -= a;
    return true;
  } else
    return false;
}

void Player::AddPoints(int a) { points_ += a; }

const int& Player::GetMoney() const { return money_; }

const int& Player::GetPoints() const { return points_; }

void Player::reduceHealth() { --health_; }

const int& Player::GetHealth() const { return health_; }