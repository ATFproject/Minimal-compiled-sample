//
// Created by livefish on 1/08/24.
//

#include <thread>
#include "window/WinRenderThread.h"

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 600), "Livefish-Example tanks game!");
  window.setVerticalSyncEnabled(true);
  window.setActive(false);

  WinRenderThread renderThread(&window);
  std::thread thread(&WinRenderThread::startRendering, &renderThread);

  while (window.isOpen()) {
    // TODO: Some background stuff here later
  }

  thread.join();

  return 0;
}