//
// Created by livefish on 1/9/24.
//

#include "game.h"

game::ResourceHandler game::resourceHandler;

void game::Game::tick() {
  timer.response();
  fps.setString("FPS: " + std::to_string(timer.fps) + "; TIME: " + std::to_string(timer.time.asSeconds()));



  for (auto & gameObject: gameObjects) {
    gameObject->tick(window);
  }
}

void game::Game::draw() {
  window->draw(bg);
  window->draw(fps);

  for (auto & gameObject: gameObjects) {
    gameObject->draw(window);
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

game::Game::Game( sf::RenderWindow * newWindow ) : window(newWindow) {
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

