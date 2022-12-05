#include "Game.hpp"

#include <unistd.h>

Game::Game(const std::string& name, const Map& map)
    : player_(Player(name)), map_(map) {}

Game::Game() : player_(Player("Default name")), map_(Map()) {}

void Game::StartGame() {
  int i = 0;
  double timeElapsed = 0;
  int microSecondsPerFrame = (1.0f / this->FPS) * 1000000;
  std::cout << "microSecondsPerFrame" << microSecondsPerFrame << std::endl;
  std::chrono::steady_clock::time_point beg = std::chrono::steady_clock::now();
  std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
  // Simulates the frames
  while (i <= 1000) {
    if (i % 100 == 0) {
      double seconds = timeElapsed / 1000000;
      std::cout << "Game running for " << seconds
                << "seconds. Current frame: " << i << "." << std::endl;
    }
    i++;

    // Update stuff related to game.
    for (auto enemy : this->enemies_) enemy->Move();
    for (auto projectile : this->projectile_) projectile->Move();

    // Calculate, how much sleep is required to hold the desired FPS
    end = std::chrono::steady_clock::now();
    auto elapsedTimeInMicroseconds =
        std::chrono::duration_cast<std::chrono::microseconds>(end - beg)
            .count();

    if (elapsedTimeInMicroseconds < microSecondsPerFrame) {
      usleep(microSecondsPerFrame - elapsedTimeInMicroseconds);
      timeElapsed += microSecondsPerFrame;
    }

    beg = std::chrono::steady_clock::now();
  }
}

void Game::AddEnemy(Enemy& enemy) { enemies_.push_back(&enemy); }

Player& Game::GetPlayer() { return player_; }

Map Game::GetMap() const {
  auto m = map_;
  return m;
}

std::vector<Enemy*> Game::GetEnemies() { return enemies_; }
