#include "Game.hpp"

#include <unistd.h>

#include <algorithm>

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

    // Update the elements in the game.
    this->Update();

    // Calculate, how much sleep is required to hold the desired FPS
    end = std::chrono::steady_clock::now();
    sustainFramerate(beg, end);
    timeElapsed += microSecondsPerFrame;
    beg = std::chrono::steady_clock::now();
  }
}

// Sleeps for the correct amount
void Game::sustainFramerate(std::chrono::steady_clock::time_point beg,
                            std::chrono::steady_clock::time_point end) {
  int microSecondsPerFrame = (1.0f / this->FPS) * 1000000;
  auto elapsedTimeInMicroseconds =
      std::chrono::duration_cast<std::chrono::microseconds>(end - beg).count();
  if (elapsedTimeInMicroseconds < microSecondsPerFrame)
    usleep(microSecondsPerFrame - elapsedTimeInMicroseconds);
  else
    std::cout << "Doing under 100fps" << std::endl;
}

void Game::Update() {
  // Update stuff related to game.
  for (auto enemy : this->enemies_) enemy->Move();
  for (auto projectile : this->projectiles_) projectile->Move();
  for (auto tower : this->towers_) tower->Defend();
}

void Game::SetLevel(Level& level) { level_ = level; }

void Game::AddEnemy(Enemy* enemy) { enemies_.push_back(enemy); }

void Game::AddTower(Tower* tower) { towers_.push_back(tower); }

void Game::AddProjectile(Projectile* projectile) {
  projectiles_.push_back(projectile);
}

Player& Game::GetPlayer() { return player_; }

Map Game::GetMap() const {
  auto m = map_;
  return m;
}

void Game::RemoveProjectile(Projectile* projectile) {
  auto remove = std::find_if(projectiles_.begin(), projectiles_.end(),
                             [&](Projectile* p) { return p == projectile; });
  delete (*remove);
  projectiles_.erase(remove);
}

void Game::RemoveEnemy(Enemy* enemy) {
  auto remove = std::find_if(enemies_.begin(), enemies_.end(),
                             [&](Enemy* e) { return e == enemy; });
  delete (*remove);
  enemies_.erase(remove);
}

Game::~Game() {
  for (auto p : projectiles_) delete p;
  for (auto e : enemies_) delete e;
  for (auto t : towers_) delete t;
}

std::vector<Enemy*> Game::GetEnemies() { return enemies_; }

std::vector<Tower*> Game::GetTowers() { return towers_; }

std::vector<Projectile*> Game::GetProjectiles() { return projectiles_; }
