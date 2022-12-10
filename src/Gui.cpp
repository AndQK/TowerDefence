#include "Gui.hpp"

Gui::Gui(Game *game) {
  if (!level_1_Texture_.loadFromFile("graphics/Level1.png")) {
    std::cout << "unable to load texture from file" << std::endl;
    exit(-1);
  }

  if (!level_2_Texture_.loadFromFile("graphics/Level2.png")) {
    std::cout << "unable to load texture from file" << std::endl;
    exit(-1);
  }

  if (!level_3_Texture_.loadFromFile("graphics/Level3.png")) {
    std::cout << "unable to load texture from file" << std::endl;
    exit(-1);
  }

  if (!mainMenuTexture_.loadFromFile("graphics/mainMenu.png")) {
    std::cout << "unable to load texture form file" << std::endl;
    exit(-1);
  }

  if (!turretTowerTexture_.loadFromFile("graphics/turret.png")) {
    std::cout << "unable to load tower texture from file" << std::endl;
    exit(-1);
  }

  if (!rocketTowerTexture_.loadFromFile("graphics/rocketGreen.png")) {
    std::cout << "unable to load tower texture from file" << std::endl;
    exit(-1);
  }

  if (!iceTowerTexture_.loadFromFile("graphics/iceTower.png")) {
    std::cout << "unable to load tower texture from file" << std::endl;
    exit(-1);
  }

  if (!greenTurtle_.loadFromFile("graphics/greenTurtle.png")) {
    std::cout << "unable to load enemy texture from file" << std::endl;
    exit(-1);
  }
  if (!brownTurtle_.loadFromFile("graphics/brownTurtle.png")) {
    std::cout << "unable to load enemy texture from file" << std::endl;
    exit(-1);
  }

  if (!font_.loadFromFile("graphics/ARLRDBD.TTF")) {
    std::cout << "unable to load font from file" << std::endl;
    exit(-1);
  }
  if (!bulletTexture_.loadFromFile("graphics/bullet.png")) {
    std::cout << "unable to load bullet texture from file" << std::endl;
    exit(-1);
  }
  if (!rocketTexture_.loadFromFile("graphics/rocket.png")) {
    std::cout << "unable to load rocket texture from file" << std::endl;
    exit(-1);
  }
  if (!iceTexture_.loadFromFile("graphics/ice.png")) {
    std::cout << "unable to load ice texture from file" << std::endl;
  }

  // by default:
  currentScreen_ = Screens::gameMenu;
  currentLevel_ = level_3_Texture_;

  window_ =
      new sf::RenderWindow(sf::VideoMode(level_1_Texture_.getSize().x / 2 + 200,
                                         level_1_Texture_.getSize().y / 2),
                           "TowerDefence");
  window_->setPosition(sf::Vector2(50, 50));
  window_->setFramerateLimit(100);

  game_ = game;

  towerTextures_.push_back(turretTowerTexture_);
  towerTextures_.push_back(rocketTowerTexture_);
  towerTextures_.push_back(iceTowerTexture_);
  // set ups coordinates for buttons
  setUpCoordinates();
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

void Gui::createAndDrawGameScreen() {
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

  // draw the level
  window_->draw(mapSprite);

  // draw the panel
  window_->draw(panel);

  for (unsigned int i = 0; i < buttons_.size(); i++) {
    btnSizes.push_back(sf::Vector2f(50, 50));
  }
  for (unsigned int i = 0; i < buttons_.size(); i++) {
    createAndDrawTowerBtn(buttons_[i], btnSizes[i], towerTextures_[i]);
  }
}

void Gui::run() {
  // a variable that stores information of tower bought by the player
  bool isBought = false;

  int whichTower = -1;  // no tower is selected by default

  // coordinates for the tower
  int towerX = 0;
  int towerY = 0;

  while (window_->isOpen()) {
    window_->clear();
    switch (currentScreen_) {
      case gameMenu:  // main menu:
        createAndDrawGameMenu();
        break;
      case gameScreen:  // game screen:
        createAndDrawGameScreen();
        createAndDrawPlayerInfo(game_->GetPlayer().GetHealth(),
                                game_->GetLevel().getCurrentWave(),
                                game_->GetPlayer().GetMoney());
        drawEnemies();
        drawTowers();
        drawProjectiles();
        game_->GetLevel().update();
        game_->Update();
        std::cout << game_->GetProjectiles().size() << std::endl;
        break;
      case gameEndScreen:  // Game Over screen
        drawGameOver();
        break;
      default:
        break;
      case gameEndScreen:  // Game Over screen
        drawGameOver();
        break;
      default:
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
            case gameScreen:
              if (!isBought) {
                whichTower = towerButtonPoller(x, y);
                isBought = customPollListener(whichTower);
              } else {
                isBought = createTower(whichTower, x, y);
              }
              break;
            case gameEndScreen:
              break;
            default:
              break;
          }
        }
      }
    }
    window_->display();
  }
}

void Gui::drawEnemies() {
  for (auto enemy : game_->GetEnemies()) {
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

void Gui::drawTowers() {
  for (auto tower : game_->GetTowers()) {
    sf::Sprite towerSprite;
    switch (tower->GetType()) {
      case iceTower:
        towerSprite.setTexture(iceTowerTexture_);
        towerSprite.setOrigin(iceTowerTexture_.getSize().x / 2,
                              iceTowerTexture_.getSize().y / 2);
        break;
      case rocketGreen:
        towerSprite.setTexture(rocketTowerTexture_);
        towerSprite.setOrigin(rocketTowerTexture_.getSize().x / 2,
                              rocketTowerTexture_.getSize().y / 2);
        break;
      case turret:
        towerSprite.setTexture(turretTowerTexture_);
        towerSprite.setOrigin(turretTowerTexture_.getSize().x / 2,
                              turretTowerTexture_.getSize().y / 2);
        break;
      default:
        break;
    }

    towerSprite.setScale(0.09f, 0.09f);
    towerSprite.setPosition(tower->GetPlace().getX(), tower->GetPlace().getY());

    window_->draw(towerSprite);
  }
}

void Gui::setUpCoordinates() {
  int x = window_->getSize().x - 200;
  buttons_.push_back(sf::Vector2f(x + 15, 300));
  buttons_.push_back(sf::Vector2f(x + 75, 300));
  buttons_.push_back(sf::Vector2f(x + 135, 300));
}

int Gui::towerButtonPoller(int x, int y) {
  for (size_t i = 0; i < buttons_.size(); ++i) {
    auto button = buttons_[i];
    if ((x >= button.x && x <= button.x + 50) &&
        (y >= button.y && y <= button.y + 50)) {
      return i;
    }
  }
  return -1;
}

bool Gui::customPollListener(int button) {
  switch (button) {
    case turret:
      if (game_->GetPlayer().Pay(200)) {
        return true;
      }
      break;
    case rocketGreen:
      if (game_->GetPlayer().Pay(500)) {
        return true;
      }
      break;
    case iceTower:
      if (game_->GetPlayer().Pay(300)) {
        return true;
      }
      break;
    default:
      return false;
      break;
  }
}

bool Gui::createTower(int whatTower, int x, int y) {
  switch (whatTower) {
    case turret:
      game_->AddTower(new BasicTower(Coordinate(x, y), game_));
      break;
    case rocketGreen:
      game_->AddTower(new BombTower(Coordinate(x, y), game_));
      break;
    case iceTower:
      game_->AddTower(new SlowingTower(Coordinate(x, y), game_));
      break;
    default:
      // don't create a tower
      break;
  }
  return false;
}

void Gui::drawProjectiles() {
  for (auto proj : game_->GetProjectiles()) {
    sf::Sprite projectileSprite;
    switch (proj->GetType()) {
      case ProjectileType::normal:
        projectileSprite.setTexture(bulletTexture_);
        projectileSprite.setOrigin(bulletTexture_.getSize().x / 2,
                                   bulletTexture_.getSize().y / 2);
        break;
      case ProjectileType::bomb:
        projectileSprite.setTexture(rocketTexture_);
        projectileSprite.setOrigin(rocketTexture_.getSize().x / 2,
                                   rocketTexture_.getSize().y / 2);
        break;
      case ProjectileType::slow:
        projectileSprite.setTexture(iceTexture_);
        projectileSprite.setOrigin(iceTexture_.getSize().x / 2,
                                   iceTexture_.getSize().y / 2);
        break;
      default:
        break;
    }
    projectileSprite.setPosition(proj->GetPosition().getX(),
                                 proj->GetPosition().getY());
    projectileSprite.setScale(0.1f, 0.1f);
    projectileSprite.setRotation(proj->getAngle());
    window_->draw(projectileSprite);
  }
}

void Gui::drawGameOver() {
  // width and height of the window
  float width = window_->getSize().x;
  float height = window_->getSize().y;

  // Initialize the screen to black
  sf::RectangleShape gameOverBox;
  gameOverBox.setFillColor(sf::Color::Black);
  gameOverBox.setSize(sf::Vector2f(width, height));

  // create text
  sf::Text gameOverText("Game Over", font_, 50);
  gameOverText.setFillColor(sf::Color::White);
  gameOverText.setStyle(sf::Text::Bold);

  // set Text's position so that the text is at the center of the screen
  auto size = gameOverText.getGlobalBounds();

  gameOverText.setOrigin(size.width / 2, size.height / 2);
  gameOverText.setPosition(width / 2, height / 2);

  std::vector<sf::Drawable *> drawables;
  drawables.push_back(&gameOverBox);
  drawables.push_back(&gameOverText);
  drawDrawables(drawables);
}