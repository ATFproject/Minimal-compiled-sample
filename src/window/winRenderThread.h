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
  
  explicit WinRenderThread( window * newWindow ) : win(newWindow), game(newWindow) {
    game << new game::Block(sf::Vector2f(100, 50), game.getRes<game::texture>("block.png"))
         << new game::Block(sf::Vector2f(100, 150), game.getRes<game::texture>("block.png"))
        << new game::Tank(game.getRes<game::texture>("tanks/tank raw.png"));
    
    /*sf::Sound sound;
    sf::SoundBuffer sb = game.resHandler.get<game::soundBuffer>("ball.wav");
    sound.setBuffer(sb);
    sound.play();
    */
    // TODO: Open al does not work: some linux problem, loo into different libs later
    game.setBg("bg.png");
  }
  
  void startRendering() {
    WinEventHandler eventHandler(win);
    
    while (win->win->isOpen()) {
      eventHandler.handleNewEvents(game);
      drawFrame();
      win->win->display();
    }
  }
};

#endif //SFML_TANK_BATTLEROYALE_WINRENDERTHREAD_H
