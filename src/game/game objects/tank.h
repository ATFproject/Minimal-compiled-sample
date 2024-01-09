//
// Created by livefish on 1/9/24.
//

#ifndef SFML_TANK_BATTLEROYALE_TANK_H
#define SFML_TANK_BATTLEROYALE_TANK_H

#include "game_def.h"

#include "gameObject.h"

namespace game {
  class Tank : public GameObject {
  private:
    float bodyDirRad, gunDirRad;
  public:
    sf::Vector2f pos;
    sf::Vector2f bodyDir;
    sf::Vector2f gunDir;

    Tank();

    void tick( window * window, Game & game ) override;
  };
}


#endif //SFML_TANK_BATTLEROYALE_TANK_H
