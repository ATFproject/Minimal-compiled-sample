//
// Created by livefish on 1/9/24.
//

#ifndef SFML_TANK_BATTLEROYALE_TANK_H
#define SFML_TANK_BATTLEROYALE_TANK_H

#include "game_def.h"

#include "gameObject.h"

namespace game {
  class Tank : public gameObject {
  private:
    float bodyDirRad, gunDirRad;
    float rotationSpeed;
    float speed;
  public:
    sf::Vector2f pos;
    sf::Vector2f bodyDir;
    sf::Vector2f gunDir;
    
    Tank() = delete;
    
    explicit Tank( const sf::Texture & Tex, const sf::Color & Col = sf::Color::White );
    
    void tick( window * window, Game & game ) override;
  };
}


#endif //SFML_TANK_BATTLEROYALE_TANK_H
