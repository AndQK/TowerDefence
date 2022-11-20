#include "Game.hpp"

#include <unistd.h>

Game::Game(const std::string& name, const Map& map)
    : player_(Player(name)), map_(map) {}

Game::Game() : player_(Player("Default name")), map_(Map()) {}

void Game::StartGame() {
  int i = 0;
  double time_elapsed = 0;
  int SLEEP_TIME = 75000;
  // Simulates the frames
  while (i <= 30) {
    if (i % 5 == 0) {
      double seconds = time_elapsed / 1000000;
      std::cout << "Game running for " << seconds
                << "seconds. Current frame: " << i << "." << std::endl;
    }
    i++;
    // Sleeps for n microseconds (Actual game could do some math for the time)
    usleep(SLEEP_TIME);
    time_elapsed += SLEEP_TIME;
  }
}

void Game::AddEnemy(Enemy& enemy) { enemies_.push_back(&enemy); }

Player& Game::GetPlayer() { return player_; }

Map Game::GetMap() const {
  auto m = map_;
  return m;
}

std::vector<Enemy*> Game::GetEnemies() { return enemies_; }
