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
    
    
    for (auto & gameObject: gameObjects) {
      gameObject->tick(win, *this);
    }
  }
}

void game::Game::draw() {
  float rotation = mainView.getRotation();
  
  mainView.setRotation(0);
  win->win->setView(mainView);
  win->win->clear(sf::Color::Black);
  win->win->draw(bg);
  win->win->draw(fps);
  
  mainView.setRotation(rotation);
  win->win->setView(mainView);
  
  for (auto & gameObject: gameObjects) {
    gameObject->draw(win, *this);
  }
}

game::Game::~Game() {
  for (auto & gameObject: gameObjects) {
    delete gameObject;
  }
}

game::Game & game::Game::operator<<( GameObject * toAdd ) {
  gameObjects.push_back(toAdd);
  return *this;
}

game::Game::Game( window * newWindow ) : win(newWindow) {
  // TODO: Manage font as a resource
  if (!fpsFont.loadFromFile("../resources/fonts/arialmt.ttf")) {
    std::cerr << "FAILED TO LOAD ARIAL FONT!" << std::endl;
    exit(50);
  }
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




