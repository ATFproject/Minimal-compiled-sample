//
// Created by livefish on 1/9/24.
//

#ifndef SFML_TANK_BATTLEROYALE_GAME_H
#define SFML_TANK_BATTLEROYALE_GAME_H

#include "game objects/Block.h"
#include "game objects/Tank.h"
#include "Timer.h"

#include "window.h"

namespace game {
  class Game {
  private:
    window * win;
    game::Timer timer;
    sf::Sprite bg;
    sf::Text fps;
    sf::Font fpsFont;

    bool isKeyPressed( sf::Keyboard::Scancode key );

  public:
    Game() = delete;
    std::vector<GameObject *> gameObjects;

    virtual ~Game();

    explicit Game( window * NewWin );

    void setBg( const std::string & BgFileName ) {
      bg.setTexture(*game::resourceHandler.LoadTexture(BgFileName));
    }

    Game & operator<<( GameObject * toAdd );

    void tick();

    void draw();
  };
}

#endif //SFML_TANK_BATTLEROYALE_GAME_H
