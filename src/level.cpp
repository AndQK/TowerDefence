#include <algorithm>
#include <level.hpp>

Wave::Wave(int spawnRate, Game* game) : spawnRate_(spawnRate), game_(game) {
  lastSpawn_ = std::chrono::steady_clock::now();
}

void Wave::addEnemy(Enemy* e) {
  enemies_.push_back(e);
  enemyAmount += 1;
}

bool Wave::started() { return started_; }

void Wave::startWave() { started_ = true; }

void Wave::update() {
  auto elapsedTimeInMicroseconds =
      1.0f * std::chrono::duration_cast<std::chrono::microseconds>(
                 std::chrono::steady_clock::now() - lastSpawn_)
                 .count();
  // if enough time passed spawn new enemy and add it to the game_.
  if (elapsedTimeInMicroseconds > 1000000.0f / spawnRate_) {
    game_->AddEnemy(enemies_.at(enemiesSpawned));
    enemiesSpawned++;
  }
}

bool Wave::ended() { return enemiesSpawned == enemyAmount; }

Level::Level(int initial_money, Map& Map, Game* game)
    : initial_money_(initial_money), game_(game), currentWave_(0) {
  auto w1 = new Wave(1, game);
  auto e1 = new Enemy(2.0, 5.0, Coordinate(0, 0), 5.0, game_);
  auto e2 = new Enemy(2.0, 5.0, Coordinate(0, 0), 5.0, game_);
  auto e3 = new Enemy(2.0, 5.0, Coordinate(0, 0), 5.0, game_);
  w1->addEnemy(e1);
  w1->addEnemy(e2);
  w1->addEnemy(e3);
  auto w2 = new Wave(6, game);
  auto w3 = new Wave(7, game);
  waves_.push_back(w1);
  waves_.push_back(w2);
  waves_.push_back(w3);
}

void Level::update() {
  bool waveActive = false;
  for (auto wave : waves_) {
    if (wave->ended()) {
      removeWave(wave);
    } else if (wave->started()) {
      waveActive = true;
      wave->update();
    }
  }

  if (!waveActive) {
    if (currentWave_ < waves_.size()) {
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