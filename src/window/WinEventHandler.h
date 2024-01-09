//
// Created by livefish on 1/9/24.
//

#ifndef SFML_TANK_BATTLEROYALE_WINEVENTHANDLER_H
#define SFML_TANK_BATTLEROYALE_WINEVENTHANDLER_H

#include "SFML/Graphics.hpp"

class WinEventHandler {
private:
  sf::RenderWindow *window;

public:
  WinEventHandler() = delete;

  explicit WinEventHandler( sf::RenderWindow *newWindow ) : window(newWindow) {}

  void handleNewEvents() {
    sf::Event event{};

    while (window->pollEvent(event)) {
      switch (event.type) {
        case sf::Event::Closed:
          window->close();
          break;

        default:
          break;
      }
    }
  }
};


#endif //SFML_TANK_BATTLEROYALE_WINEVENTHANDLER_H
