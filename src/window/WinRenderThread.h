//
// Created by livefish on 1/9/24.
//

#ifndef SFML_TANK_BATTLEROYALE_WINRENDERTHREAD_H
#define SFML_TANK_BATTLEROYALE_WINRENDERTHREAD_H

#include <cmath>
#include <vector>
#include <cmath>

#include "WinEventHandler.h"
#include "../game/game objects/Block.h"
#include "../game/Timer.h"

class WinRenderThread {
private:
  sf::RenderWindow * window;
  sf::Sprite bg;
  sf::Text fps;
  sf::Font fpsFont;

  game::Timer timer;

  void drawFrame() {
    window->draw(bg);
    window->draw(fps);
    for (auto & gameObject: gameObjects) {
      gameObject->tick(window);
    }
    for (auto & gameObject: gameObjects) {
      gameObject->draw(window);
    }
  }

public:
  std::vector<GameObject *> gameObjects; // TODO: make class game and put game objects and timer there

  WinRenderThread() = delete;

  ~WinRenderThread() {
    for (auto & gameObject: gameObjects) {
      delete gameObject;
    }
  }

  explicit WinRenderThread( sf::RenderWindow * window ) : window(window) {
    gameObjects.push_back(new game::Block(sf::Vector2f(100, 50), "block.png"));
    gameObjects.push_back(new game::Block(sf::Vector2f(100, 150), "block 2.png"));

    bg.setTexture(*game::resourceHandler.LoadTexture("bg.png"));

    if (!fpsFont.loadFromFile("../resources/fonts/arialmt.ttf")) {
      std::cerr << "FAILED TO LOAD ARIAL FONT!" << std::endl;
      exit(50);
    }
    fps.setFont(fpsFont);
    fps.setCharacterSize(24);
    fps.setFillColor(sf::Color::Blue);
    fps.setStyle(sf::Text::Bold | sf::Text::Underlined);
  }

  void startRendering() {
    window->setActive(true);
    WinEventHandler eventHandler(window);

    while (window->isOpen()) {
      eventHandler.handleNewEvents();
      timer.response();
      fps.setString("FPS: " + std::to_string(timer.fps) + "; TIME: " + std::to_string(timer.time.asSeconds()));

      drawFrame();
      window->display();
    }
  }
};

#endif //SFML_TANK_BATTLEROYALE_WINRENDERTHREAD_H
