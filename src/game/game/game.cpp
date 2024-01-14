//
// Created by livefish on 1/9/24.
//

#include "game_mod.h"
#include "game.h"

bool game::Game::isKeyPressed( sf::Keyboard::Scancode key ) {
  return win->keys[key];
}

void game::Game::tick() {
  if (win->isActive) {
    timer.response();
    fps.setString("FPS: " + std::to_string(timer.fps) + "; TIME: " + std::to_string(timer.time.asSeconds()));
    
    if (isKeyPressed(sf::Keyboard::Scancode::Q))
      win->win->close();
    
    world.Step(deltaTime(), 8, 3);
    
    for (auto & gameObject: gameObjects) {
      gameObject->tick(win, *this);
    }
  }
}

void game::Game::draw() {
  float rotation = mainView.getRotation();
  sf::Vector2f center = mainView.getCenter();
  mainView.setRotation(0);
  mainView.setCenter(sf::Vector2f(0, 0) + mainView.getSize() / 2.f);
  win->win->setView(mainView);
  win->win->clear(sf::Color::Black);
  win->win->draw(bg);
  win->win->draw(fps);
  
  mainView.setRotation(rotation);
  mainView.setCenter(center);
  win->win->setView(mainView);
  
  for (auto & gameObject: gameObjects) {
    gameObject->draw(win, *this);
  }
}

game::Game::~Game() = default;

game::Game & game::Game::operator<<( gameObject * toAdd ) {
  gameObjects.push_back(std::shared_ptr<gameObject>(toAdd));
  toAdd->addToWorld(world);

  return *this;
}

game::Game::Game( window * newWindow, gameSettings gameSettings ) :
        win(newWindow), world(b2Vec2_zero), settings(gameSettings) {
  fpsFont = getRes<font>("arialmt.ttf");
  fps.setFont(fpsFont);
  fps.setCharacterSize(12);
  fps.setFillColor(sf::Color::Blue);
  fps.setStyle(sf::Text::Bold | sf::Text::Underlined);
}

void game::Game::setBg( const std::string & BgFileName ) {
  bg.setTexture(getRes<texture>(BgFileName));
}

void game::Game::resize( float newW, float newH ) {
  sf::FloatRect visibleArea(0.f, 0.f, newW, newH);
  mainView = sf::View(visibleArea);
}


float game::Game::time() const {
  return timer.time.asSeconds();
}

float game::Game::deltaTime() const {
  return timer.deltaTime.asSeconds();
}




