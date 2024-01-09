//
// Created by livefish on 1/9/24.
//

#ifndef SFML_TANK_BATTLEROYALE_GAME_H
#define SFML_TANK_BATTLEROYALE_GAME_H

#include "game objects/Block.h"
#include "ResourceHandler.h"
#include "Timer.h"

namespace game {
  class Game {
  private:
    sf::RenderWindow * window;
    std::vector<GameObject *> gameObjects;
    game::Timer timer;
    sf::Sprite bg;
    sf::Text fps;
    sf::Font fpsFont;

  public:
    Game() = delete;

    virtual ~Game();

    explicit Game( sf::RenderWindow * window );

    void setBg( const std::string & BgFileName ) {
      bg.setTexture(*game::resourceHandler.LoadTexture(BgFileName));
    }

    Game & operator<<( GameObject * toAdd );

    void tick();

    void draw();
  };
}

#endif //SFML_TANK_BATTLEROYALE_GAME_H
