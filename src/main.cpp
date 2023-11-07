#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>

#include "include/menu.hpp"

// Start of the program
int main()
{

  sf::RenderWindow window(sf::VideoMode(sf::VideoMode::getDesktopMode().width,
                                        sf::VideoMode::getDesktopMode().height),
                          "Shoot The Circle");
  window.setMouseCursorVisible(false);
  window.setFramerateLimit(60);
  window.setVerticalSyncEnabled(true);

  menu(window);

  return 0;
}
