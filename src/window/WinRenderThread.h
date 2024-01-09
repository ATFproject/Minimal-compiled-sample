//
// Created by livefish on 1/9/24.
//

#ifndef SFML_TANK_BATTLEROYALE_WINRENDERTHREAD_H
#define SFML_TANK_BATTLEROYALE_WINRENDERTHREAD_H

#include <cmath>
#include <vector>
#include <cmath>

#include "../game/game.h"

#include "WinEventHandler.h"

class WinRenderThread {
private:
  window * win;
  game::Game game;

  void drawFrame() {
    game.tick();
    game.draw();
  }

public:
  WinRenderThread() = delete;

  explicit WinRenderThread( window * newWindow ) : win(newWindow), game(newWindow->win) {
    game << new game::Block(sf::Vector2f(100, 50), "block.png")
         << new game::Block(sf::Vector2f(100, 150), "block 2.png");

    game.setBg("bg.png");
  }

  void startRendering() {
    win->win->setActive(true);
    WinEventHandler eventHandler(win);

    while (win->win->isOpen()) {
      eventHandler.handleNewEvents();
      drawFrame();
      win->win->display();
    }
  }
};

#endif //SFML_TANK_BATTLEROYALE_WINRENDERTHREAD_H
