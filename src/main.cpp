//
// Created by livefish on 1/08/24.
//

#include <thread>

#include "winRenderThread.h"

int main() {
  sf::ContextSettings winContextSettings(0, 0, 4); // set antialiasing level to 4
  sf::RenderWindow win(sf::VideoMode(800, 600), "Livefish-Example tanks game!", sf::Style::Default, winContextSettings);
  win.setVerticalSyncEnabled(true);
  win.setActive(false);

  sf::Image icon;
  icon.loadFromFile("../resources/images/icon.png");
  win.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

  window gameWindow(&win);

  WinRenderThread renderThread(&gameWindow);
  std::thread thread(&WinRenderThread::startRendering, &renderThread);

  while (win.isOpen()) {
    // TODO: Some background stuff here later
  }

  thread.join();

  return 0;
}