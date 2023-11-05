#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>

void menu();
void options();
void gameMode();
void leaveGame();
void infiniteGameMode();
void savingHighScore(int highScore);
void goalGameMode(int r, int vx, int vy);

sf::RenderWindow window(sf::VideoMode(sf::VideoMode::getDesktopMode().width,
                                      sf::VideoMode::getDesktopMode().height),
                        "Shoot The Circle");
int state = 1;
int j = 0;

// Start programu
int main() {
  window.setMouseCursorVisible(false);
  window.setFramerateLimit(60);
  window.setVerticalSyncEnabled(true);

  menu();

  return 0;
}
