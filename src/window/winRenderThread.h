//
// Created by livefish on 1/9/24.
//

#ifndef SFML_TANK_BATTLEROYALE_WINRENDERTHREAD_H
#define SFML_TANK_BATTLEROYALE_WINRENDERTHREAD_H

#include <cmath>
#include <vector>
#include <cmath>

#include "game_mod.h"
#include "winEventHandler.h"

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
  
  WinRenderThread( window * newWindow, game::gameSettings settings ) : win(newWindow), game(newWindow, settings) {
    /*game << new game::Block(sf::Vector2f(100, 50), game.getRes<game::texture>("block.png"))
         << new game::Block(sf::Vector2f(100, 150), game.getRes<game::texture>("block.png"))
         << new game::Tank(game.getRes<game::texture>("tanks/tank raw.png"));*/
    
    game << new game::Tank(game.getRes<game::texture>("tanks/tank raw.png"), sf::Color::Yellow);
    sf::Texture *tex = game.getRes<game::texture>("block.png").data.get();
    game << new game::Block(sf::Vector2f(100, 50), sf::Vector2f(64, 32), *tex);
    game.setBg("bg.png");
  }
  
  void startRendering() {
    sf::Music * music = game.resHandler.get<game::music>("The7seas.ogg");
    music->setVolume(10);
    music->play();
    
    WinEventHandler eventHandler(win);
    
    while (win->win->isOpen()) {
      eventHandler.handleNewEvents(game);
      drawFrame();
      win->win->display();
    }
  }
};

#endif //SFML_TANK_BATTLEROYALE_WINRENDERTHREAD_H
