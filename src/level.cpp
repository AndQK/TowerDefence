#include <level.hpp>

Level::Level(int initial_money, int initial_lives, int enemies_killed, Map &Map,
             std::vector<int> enemy)
    : initial_money_(initial_money),
      initial_lives_(initial_lives),
      enemies_killed_(enemies_killed),
      enemy_(enemy) {}

int Level::initial_money() const { return initial_money_; }

int Level::initial_lives() const { return initial_lives_; }

int Level::enemies_killed() const { return enemies_killed_; }

std::vector<int> Level::killing_enemies(int time) {
  std::vector<int> enemies = {};
  auto size = enemy_.size();
  for (int i = enemies_killed_; i < size; ++i) {
    auto t = enemy_[i];
    // if (t.first < time) {
    //     enemies.push_back(t.second);
    //     enemies_killed_++;
    // } else
    //     break;
  }
  return enemies;
}

bool Level::done() { return enemies_killed_ == enemy_.size(); }