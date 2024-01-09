//
// Created by livefish on 1/9/24.
//

#include "WinEventHandler.h"

#include <iostream>

void WinEventHandler::handleNewEvents() const {
  sf::Event event{};
  sf::RenderWindow * rw = win->win;

  while (rw->pollEvent(event)) {
    switch (event.type) {
      case sf::Event::Closed:
        rw->close();
        break;

      case sf::Event::LostFocus:
        win->isActive = false;
        std::cout << "Lost focus" << std::endl;
        break;

      case sf::Event::GainedFocus:
        win->isActive = true;
        std::cout << "Gained focus" << std::endl;
        break;

      case sf::Event::Resized:
        win->size.x = event.size.width;
        win->size.y = event.size.height;
        std::cout << "Resized: " << event.size.width << ", " << event.size.height << std::endl;
        break;

      default:
        break;
    }
  }
}
