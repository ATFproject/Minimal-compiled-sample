//
// Created by livefish on 1/08/24.
//

#include <thread>
#include "WinRenderThread.h"

int main() {
  sf::RenderWindow win(sf::VideoMode(800, 600), "Livefish-Example tanks game!");
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