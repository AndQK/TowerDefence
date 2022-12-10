#include <algorithm>
#include <level.hpp>

#include "Game.hpp"

Wave::Wave(float spawnRate, Game* game)
    : spawnRate_(spawnRate), game_(game), enemyAmount(0) {
  lastSpawn_ = std::chrono::steady_clock::now();
}

void Wave::addEnemy(Enemy* e) {
  enemies_.push_back(e);
  enemyAmount += 1;
}

bool Wave::started() { return started_; }

void Wave::startWave() { started_ = true; }

void Wave::updateLastSpawn() { lastSpawn_ = std::chrono::steady_clock::now(); }

void Wave::update() {
  auto elapsedTimeInSeconds =
      1.0f *
      std::chrono::duration_cast<std::chrono::microseconds>(
          std::chrono::steady_clock::now() - lastSpawn_)
          .count() /
      1000000.0f;

  // if enough time passed spawn new enemy and add it to the game_.
  if (elapsedTimeInSeconds > 1.0f / spawnRate_) {
    // HOX: take if out
    if (enemies_.size() > enemiesSpawned) {
      game_->AddEnemy(enemies_.at(enemiesSpawned));
      updateLastSpawn();
      enemiesSpawned++;
    }
  }
}

bool Wave::ended() { return enemiesSpawned == enemyAmount; }

Level::Level() : initial_money_(100), game_(nullptr), currentWave_(0) {}

Level::Level(int initial_money, Game* game)
    : initial_money_(initial_money), game_(game), currentWave_(0) {
  float spawnRate = 0.3f;
  float hpFactor = 1;
  int enemiesPerWave = 3;
  int amountOfWaves = 100;
  while (amountOfWaves > 0) {
    auto w1 = new Wave(spawnRate, game);
    int i = enemiesPerWave;
    while (i > 0) {
      auto e1 = new EasyEnemy(game_->GetMap().GetNode(0), 1, game_);
      auto e2 = new HardEnemy(game_->GetMap().GetNode(0), 10 * hpFactor, game_);
      auto e3 =
          new SplittingEnemy(game_->GetMap().GetNode(0), 40 * hpFactor, game_);
      w1->addEnemy(e1);
      w1->addEnemy(e2);
      w1->addEnemy(e3);
      i -= 3;
    }
    waves_.push_back(w1);
    hpFactor *= 1.1;
    spawnRate *= 1.1;
    enemiesPerWave++;
    amountOfWaves--;
  }
  waves_.size();
}

Level::~Level() {
  for (auto w : waves_) {
    delete w;
  }
}

void Level::update() {
  bool waveActive = false;
  for (auto wave : waves_) {
    if (wave->ended()) {
      std::cout << "wave ended" << std::endl;
      removeWave(wave);
    } else if (wave->started()) {
      waveActive = true;
      wave->update();
    }
  }

  if (!waveActive) {
    if (currentWave_ < waves_.size()) {
      waves_.at(currentWave_)->updateLastSpawn();
      waves_.at(currentWave_)->startWave();
    }
    currentWave_++;
  }
}

void Level::removeWave(Wave* w) {
  auto remove = std::find_if(waves_.begin(), waves_.end(),
                             [&](Wave* wave) { return w == wave; });
  delete (*remove);
  waves_.erase(remove);
}

int Level::getCurrentWave() { return currentWave_; }

int Level::initial_money() const { return initial_money_; }