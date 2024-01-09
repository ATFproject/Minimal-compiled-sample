//
// Created by livefish on 1/9/24.
//

#ifndef SFML_TANK_BATTLEROYALE_GAME_H
#define SFML_TANK_BATTLEROYALE_GAME_H

#include "game_def.h"

#include "timer.h"

namespace game {
  class Game {
  private:
    window * win;
    sf::Sprite bg;
    sf::Font fpsFont;
    sf::Text fps;

  public:
    game::Timer timer;

    Game() = delete;

    std::vector<GameObject *> gameObjects;

    virtual ~Game();

    explicit Game( window * NewWin );

    void setBg( const std::string & BgFileName );

    bool isKeyPressed( sf::Keyboard::Scancode key );

    Game & operator<<( GameObject * toAdd );

    void tick();

    void draw();
  };
}

#endif //SFML_TANK_BATTLEROYALE_GAME_H
