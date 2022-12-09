#include "Gui.hpp"

Gui::Gui(Game &game) {
  if (!level_1_Texture_.loadFromFile("../graphics/Level1.png")) {
    std::cout << "unable to load texture from file" << std::endl;
    exit(-1);
  }

  if (!level_2_Texture_.loadFromFile("../graphics/Level2.png")) {
    std::cout << "unable to load texture from file" << std::endl;
    exit(-1);
  }

  if (!level_3_Texture_.loadFromFile("../graphics/Level3.png")) {
    std::cout << "unable to load texture from file" << std::endl;
    exit(-1);
  }

  if (!mainMenuTexture_.loadFromFile("../graphics/mainMenu.png")) {
    std::cout << "unable to load texture form file" << std::endl;
    exit(-1);
  }

  if (!diamondTowerTexture_.loadFromFile("../graphics/diamondGun.png")) {
    std::cout << "unable to load tower texture from file" << std::endl;
    exit(-1);
  }

  if (!teslaTowerTexture_.loadFromFile("../graphics/tesla.png")) {
    std::cout << "unable to load tower texture from file" << std::endl;
    exit(-1);
  }

  if (!turretTowerTexture_.loadFromFile("../graphics/turret.png")) {
    std::cout << "unable to load tower texture from file" << std::endl;
    exit(-1);
  }

  if (!rocketTowerTexture_.loadFromFile("../graphics/rocketGreen.png")) {
    std::cout << "unable to load tower texture from file" << std::endl;
    exit(-1);
  }

  if (!iceTowerTexture_.loadFromFile("../graphics/iceRocket.png")) {
    std::cout << "unable to load tower texture from file" << std::endl;
    exit(-1);
  }

  if (!font_.loadFromFile("../graphics/ARLRDBD.TTF")) {
    std::cout << "unable to load font from file" << std::endl;
    exit(-1);
  }

  // by default:
  currentScreen_ = Screens::gameMenu;
  currentLevel_ = level_3_Texture_;

  window_ =
      new sf::RenderWindow(sf::VideoMode(level_1_Texture_.getSize().x / 2 + 200,
                                         level_1_Texture_.getSize().y / 2),
                           "TowerDefence");
  window_->setPosition(sf::Vector2(50, 50));

  game_ = game;

  towerTextures_.push_back(diamondTowerTexture_);
  towerTextures_.push_back(teslaTowerTexture_);
  towerTextures_.push_back(turretTowerTexture_);
  towerTextures_.push_back(rocketTowerTexture_);
  towerTextures_.push_back(iceTowerTexture_);
}

void Gui::createAndDrawTowerBtn(sf::Vector2f btnLocation, sf::Vector2f btnSize,
                                sf::Texture &texture) {
  std::vector<sf::Drawable *> drawables;

  sf::RectangleShape btn(btnSize);
  btn.setPosition(btnLocation);
  btn.setFillColor(sf::Color::White);

  // button's outline color will be grey
  sf::Color grey(128, 128, 128);
  btn.setOutlineColor(grey);
  btn.setOutlineThickness(3);
  drawables.push_back(&btn);

  // setting up the icon for the button.
  sf::Sprite btnSprite;
  btnSprite.setTexture(texture);
  btnSprite.setScale(0.09, 0.09);
  btnSprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
  btnSprite.setPosition(btnLocation.x + 25, btnLocation.y + 25);
  drawables.push_back(&btnSprite);

  drawDrawables(drawables);
}

void Gui::drawDrawables(std::vector<sf::Drawable *> drawables) {
  std::vector<sf::Drawable *>::iterator it = drawables.begin();
  for (; it != drawables.end(); it++) {
    window_->draw(**it);
  }
}

void Gui::createAndDrawGameMenu() {
  sf::Sprite menuSprite;
  menuSprite.setTexture(mainMenuTexture_);

  // width and height of the window
  float width = window_->getSize().x;
  float height = window_->getSize().y;

  menuSprite.setScale(width / mainMenuTexture_.getSize().x,
                      height / mainMenuTexture_.getSize().y);
  window_->draw(menuSprite);
}

void Gui::createAndDrawPlayerInfo(int health, int wave, int gold) {
  // panel's position we're drawing on
  int x = window_->getSize().x - 200;
  int y = 0;

  // storage for the drawables
  std::vector<sf::Drawable *> drawables;

  // colour for the boxes
  sf::Color darkGrey(90, 90, 90);

  // health box
  sf::RectangleShape healthBox;
  healthBox.setSize(sf::Vector2f(180, 30));
  healthBox.setFillColor(darkGrey);
  healthBox.setPosition(x + 10, y + 10);
  drawables.push_back(&healthBox);

  // gold box
  sf::RectangleShape goldBox;
  goldBox.setSize(sf::Vector2f(180, 30));
  goldBox.setFillColor(darkGrey);
  goldBox.setPosition(x + 10, y + 50);
  drawables.push_back(&goldBox);

  // wave box
  sf::RectangleShape waveBox;
  waveBox.setSize(sf::Vector2f(180, 30));
  waveBox.setFillColor(darkGrey);
  waveBox.setPosition(x + 10, y + 90);
  drawables.push_back(&waveBox);

  // convert int values to string
  std::string healthToString = std::to_string(health);
  std::string waveToString = std::to_string(wave);
  std::string goldToString = std::to_string(gold);

  // text for the health
  sf::Text healthText("Health: " + healthToString + "/15", font_, 15);
  healthText.setPosition(x + 13, y + 15);
  healthText.setFillColor(sf::Color::White);
  healthText.setStyle(sf::Text::Bold);
  drawables.push_back(&healthText);

  // text for the gold
  sf::Text goldText("Gold: " + goldToString, font_, 15);
  goldText.setPosition(x + 13, y + 55);
  goldText.setFillColor(sf::Color::White);
  goldText.setStyle(sf::Text::Bold);
  drawables.push_back(&goldText);

  // text for the wave
  sf::Text waveText("Current wave: " + waveToString, font_, 15);
  waveText.setPosition(x + 13, y + 95);
  waveText.setFillColor(sf::Color::White);
  waveText.setStyle(sf::Text::Bold);
  drawables.push_back(&waveText);

  drawDrawables(drawables);
}

std::vector<sf::Vector2f> Gui::createAndDrawGameScreen() {
  // Upper left corner
  std::vector<sf::Vector2f> btnLocations;
  // Width and height for buttons
  std::vector<sf::Vector2f> btnSizes;

  // a factor for keeping the game screen size the same with different maps.
  float dx = level_1_Texture_.getSize().x * 0.5 / currentLevel_.getSize().x;
  float dy = level_1_Texture_.getSize().y * 0.5 / currentLevel_.getSize().y;

  // initialising a map sprite with a texture
  sf::Sprite mapSprite;
  mapSprite.setTexture(currentLevel_);
  mapSprite.setScale(dx, dy);

  // panel's width and height
  int width = 200;
  int height = window_->getSize().y;

  // panel's position
  int x = window_->getSize().x - 200;
  int y = 0;

  // Create sidePanel for game buttons
  sf::RectangleShape panel;
  sf::Color darkerGrey(70, 70, 70);
  panel.setSize(sf::Vector2f(width, height));
  panel.setFillColor(darkerGrey);
  panel.setPosition(x, y);

  // Create buttons. Should be inside sidePanel area and the size is 50x50
  // pixels.
  btnLocations.push_back(sf::Vector2f(x + 15, 300));
  btnLocations.push_back(sf::Vector2f(x + 75, 300));
  btnLocations.push_back(sf::Vector2f(x + 135, 300));
  btnLocations.push_back(sf::Vector2f(x + 33, 365));
  btnLocations.push_back(sf::Vector2f(x + 116, 365));

  // draw the level
  window_->draw(mapSprite);

  // draw the panel
  window_->draw(panel);

  for (unsigned int i = 0; i < btnLocations.size(); i++) {
    btnSizes.push_back(sf::Vector2f(50, 50));
  }
  for (unsigned int i = 0; i < btnLocations.size(); i++) {
    createAndDrawTowerBtn(btnLocations[i], btnSizes[i], towerTextures_[i]);
  }
  return btnLocations;
}

void Gui::run() {
  while (window_->isOpen()) {
    window_->clear();
    switch (currentScreen_) {
      case gameMenu:  // main menu:
        createAndDrawGameMenu();
        break;
      case gameScreen:  // game screen:
        std::vector<sf::Vector2f> coordinates = createAndDrawGameScreen();
        createAndDrawPlayerInfo(0, 0, 0);
        drawEnemies(game_.GetEnemies());
        game_.Update();
        break;
    }
    sf::Event event;
    while (window_->pollEvent(event)) {
      if (sf::Event::Closed == event.type) {
        window_->close();
      }
      if (sf::Event::MouseButtonPressed == event.type) {
        if (event.mouseButton.button == sf::Mouse::Left) {
          int x = event.mouseButton.x;
          int y = event.mouseButton.y;
          switch (currentScreen_) {
            case gameMenu:

              // checking that the click happened in the right place
              if ((x >= 334 && x <= 506) && (y >= 490 && y <= 528)) {
                currentScreen_ = 2;
                std::cout << "changing screen" << std::endl;
              }
              break;
            default:
              break;
          }
        }
      }
    }
    window_->display();
    usleep(10000);
  }
}

void Gui::drawEnemies(std::vector<Enemy *> enemies) {
  for (auto enemy : enemies) {
    sf::Sprite enemySprite;
    switch ((*enemy).GetType()) {
      case greenTurtle:
        enemySprite.setTexture(greenTurtle_);
        enemySprite.setOrigin(greenTurtle_.getSize().x / 2,
                              greenTurtle_.getSize().y / 2);

        break;
      case brownTurtle:
        enemySprite.setTexture(brownTurtle_);
        enemySprite.setOrigin(brownTurtle_.getSize().x / 2,
                              brownTurtle_.getSize().y / 2);
        break;
      default:
        break;
    }

    enemySprite.setScale(0.05f, 0.05f);
    enemySprite.setPosition((*enemy).GetCoord().getX(),
                            (*enemy).GetCoord().getY());
    enemySprite.setRotation((*enemy).getAngle());

    window_->draw(enemySprite);
  }
}