//
// Created by livefish on 1/9/24.
//

#ifndef SFML_TANK_BATTLEROYALE_WINDOW_H
#define SFML_TANK_BATTLEROYALE_WINDOW_H

#include "SFML/Graphics.hpp"

class window {
public:
    sf::RenderWindow * win;
    sf::Vector2i size;
    bool isActive;
    bool keys[256] {false};

    window() = delete;

    explicit window(sf::RenderWindow * window) : win(window), isActive(true) {};
};

#endif //SFML_TANK_BATTLEROYALE_WINDOW_H
