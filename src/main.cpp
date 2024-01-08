#include "SFML/Graphics.hpp"

void renderingThread(sf::RenderWindow* window)
{
  // activate the window's context
  window->setActive(true);

  // the rendering loop
  while (window->isOpen())
  {
    // draw...

    // end the current frame
    window->display();
  }
}

int main()
{
  // create the window (remember: it's safer to create it in the main thread due to OS limitations)
  sf::RenderWindow window(sf::VideoMode(800, 600), "Livefish-Example tanks game!");

  // deactivate its OpenGL context
  window.setActive(false);

  // launch the rendering thread
  sf::Thread thread(&renderingThread, &window);
  thread.launch();


  while (window.isOpen())
  {

  }

  return 0;
}