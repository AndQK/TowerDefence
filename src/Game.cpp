#include "Game.hpp"

#include <unistd.h>

#include <algorithm>

Game::Game(const std::string& name, const Map& map)
    : player_(Player(name)), map_(map) {}

Game::Game() : player_(Player("Default name")), map_(Map()) {}

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
  if (remove != projectiles_.end()) {
    delete (*remove);
    projectiles_.erase(remove);
  }
}

void Game::RemoveEnemy(Enemy* enemy) {
  auto remove = std::find_if(enemies_.begin(), enemies_.end(),
                             [&](Enemy* e) { return e == enemy; });
  if (remove != enemies_.end()) {
  delete (*remove);
  enemies_.erase(remove);
  }
}

Game::~Game() {
  for (auto p : projectiles_) delete p;
  for (auto e : enemies_) delete e;
  for (auto t : towers_) delete t;
}

Level& Game::GetLevel() { return level_; }

std::vector<Enemy*> Game::GetEnemies() { return enemies_; }

std::vector<Tower*> Game::GetTowers() { return towers_; }

std::vector<Projectile*> Game::GetProjectiles() { return projectiles_; }
