#ifndef TOWER_DEFENSE_GUI
#define TOWER_DEFENSE_GUI

#include <unistd.h>

#include <iostream>
#include <vector>
#include <memory>

#include "BasicTower.hpp"
#include "BombTower.hpp"
#include "Coordinate.hpp"
#include "Enemy.hpp"
#include "Game.hpp"
#include "Map.hpp"
#include "Player.hpp"
#include "SFML/Graphics.hpp"
#include "SlowingTower.hpp"
#include "Tower.hpp"
#include "level.hpp"

enum Screens { gameMenu, gameLevelMenu, gameScreen, gameEndScreen };

enum Enemies { greenTurtle, brownTurtle, bondMobile };

enum Towers { turret, rocketGreen, iceTower };

class Gui {
 public:
  // Constructor
  Gui();

  // destructor

  ~Gui() {
    delete window_;
  }

  // Main menu function.
  void createAndDrawGameMenu();

  // function for displaying player's info on the screen.
  void createAndDrawPlayerInfo(int health, int wave, int gold);

  // function for drawing all pressable buttons.
  void createAndDrawTowerBtn(sf::Vector2f btnLocation, sf::Vector2f btnSize,
                             sf::Texture &texture,
                             std::pair<std::string, std::string> &tag,
                             int &price);

  // creates the game screen
  void createAndDrawGameScreen();

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

  // calls game object to create new tower if buying was successful
  bool createTower(int whichTower, int x, int y);

  // draws projectiles
  void drawProjectiles();

  // draws "Game Over" screen
  void drawGameOver();

  // draws Level Selector screen
  void drawLevelSelector();

  //sets the gui's level variables according to the button that was clicked by the player
  void gameLevelHandler(int x, int y);

  // checks player's input and restarts the game or brings player back to main menu
  void gameOverHandler(int x, int y);

 private:
  sf::RenderWindow *window_;
  std::shared_ptr<Game> game_;
  // paths for enemies
  std::shared_ptr<Map> map1_;

  std::shared_ptr<Map> map2_;

  std::shared_ptr<Level> level_;

  // Textures for levels
  sf::Texture level_1_Texture_;
  sf::Texture level_2_Texture_;
  sf::Texture level_3_Texture_;

  sf::Texture mainMenuTexture_;

  // Textures for towers
  sf::Texture turretTowerTexture_;
  sf::Texture rocketTowerTexture_;
  sf::Texture iceTowerTexture_;

  // Textures for enemies
  sf::Texture greenTurtle_;
  sf::Texture brownTurtle_;
  sf::Texture bondMobile_;

  // Textures for projectiles
  sf::Texture bulletTexture_;
  sf::Texture rocketTexture_;
  sf::Texture iceTexture_;

  sf::Font font_;

  sf::Texture currentLevel_;
  int currentScreen_;
  std::vector<sf::Texture> towerTextures_;

  // current map in int format
  int mapToInt_;

  // the locations for buttons
  std::vector<sf::Vector2f> buttons_;

  // name-price pair for towers used when creating tags
  std::vector<std::pair<std::string, std::string>> tags_;

  // towers price in int format
  std::vector<int> prices_;

};

#endif