//
// Created by livefish on 1/9/24.
//

#ifndef SFML_TANK_BATTLEROYALE_TANK_H
#define SFML_TANK_BATTLEROYALE_TANK_H

#include "gameDef.h"

#include "GameObject.h"

namespace game {
  class Tank : public GameObject {
  public:
    sf::Vector2i pos;
    sf::Vector2f bodyDir;
    sf::Vector2f gunDir;

    Tank();

    void tick( window * window, Game & game ) override;

    void draw( window * window, Game & game ) override;
  };
}


#endif //SFML_TANK_BATTLEROYALE_TANK_H
