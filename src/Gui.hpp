#ifndef TOWER_DEFENSE_GUI
#define TOWER_DEFENSE_GUI

#include <unistd.h>

#include <iostream>
#include <vector>

#include "Coordinate.hpp"
#include "Enemy.hpp"
#include "Game.hpp"
#include "Map.hpp"
#include "SFML/Graphics.hpp"
#include "level.hpp"
#include "Tower.hpp"
#include "SlowingTower.hpp"
#include "Player.hpp"

enum Screens { gameMenu, gameLevelMenu, gameScreen, gameEndScreen };

enum Enemies { greenTurtle, brownTurtle };

enum Towers { diamondGun, tesla, turret, rocketGreen, iceTower };

class Gui {
 public:
  // Constructor
  Gui(Game *game);

  // destructor

  ~Gui() { delete window_; }

  // Main menu function.
  void createAndDrawGameMenu();

  // function for displaying player's info on the screen.
  void createAndDrawPlayerInfo(int health, int wave, int gold);

  // function for drawing all pressable buttons.
  void createAndDrawTowerBtn(sf::Vector2f btnLocation, sf::Vector2f btnSize,
                             sf::Texture &texture);

  // creates the game screen
  std::vector<sf::Vector2f> createAndDrawGameScreen();

  // draws everything that is drawable on the window.
  void drawDrawables(std::vector<sf::Drawable *> drawables);

  // runs the loop for the window.
  void run();

  // draws enemies
  void drawEnemies();

  // draws towers
  void drawTowers();

  // set ups the coordinates for the clickable buttons
  void setUpCoordinates();

  // Event poller for finding out which button was pressed
  int towerButtonPoller(int x, int y);

  // listens to user's clicks and acts accordingly
  bool customPollListener(int button);

  // calls game object to create new tower if bying was successful
  bool createTower(int whichTower, int x, int y);

  // draws projectiles

  void drawProjectiles();

 private:

  sf::RenderWindow *window_;
  sf::Texture level_1_Texture_;
  sf::Texture level_2_Texture_;
  sf::Texture level_3_Texture_;
  sf::Texture mainMenuTexture_;
  sf::Texture diamondTowerTexture_;
  sf::Texture teslaTowerTexture_;
  sf::Texture turretTowerTexture_;
  sf::Texture rocketTowerTexture_;
  sf::Texture iceTowerTexture_;
  sf::Texture greenTurtle_;
  sf::Texture brownTurtle_;
  sf::Texture bulletTexture_;
  sf::Font font_;

  Game *game_;
  sf::Texture currentLevel_;
  int currentScreen_;
  std::vector<sf::Texture> towerTextures_;

  // the locations for buttons
  std::vector<sf::Vector2f> buttons_;
};

#endif