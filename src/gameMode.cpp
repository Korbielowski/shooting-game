#include <fstream>

#include "gameMode.hpp"
#include "button.hpp"
#include "goalGameMode.hpp"
#include "infiniteGameMode.hpp"
#include "menu.hpp"
#include "player.hpp"

void gameMode(sf::RenderWindow &window)
{
  Button buttonGoal(
      "Goal Game Mode", 24, sf::VideoMode::getDesktopMode().width / 2,
      sf::VideoMode::getDesktopMode().height / 2, sf::Color::Magenta);
  Button buttonInfinite(
      "Infinte Game Mode", 22, sf::VideoMode::getDesktopMode().width / 2,
      sf::VideoMode::getDesktopMode().height / 2 + 110, sf::Color::Magenta);
  Button buttonLeave(
      "Back to menu", 24, sf::VideoMode::getDesktopMode().width / 2,
      sf::VideoMode::getDesktopMode().height / 2 + 220, sf::Color::Magenta);

  Player player;

  std::ifstream gameDifficultyFile("gameDifficulty.txt");
  char gameDifficulty;

  if (gameDifficultyFile.is_open())
  {
    gameDifficultyFile.get(gameDifficulty);
    gameDifficultyFile.close();
  }

  while (window.isOpen())
  {
    sf::Event event;

    while (window.pollEvent(event))
    {
      player.shapePlayer.setPosition(sf::Mouse::getPosition().x,
                                     sf::Mouse::getPosition().y);

      if (event.type == sf::Event::Closed)
      {
        window.close();
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
      {
        window.clear(sf::Color::Cyan);
        menu(window);
      }
      if (player.shapePlayer.getGlobalBounds().intersects(
              buttonInfinite.button.getGlobalBounds()) &&
          sf::Mouse::isButtonPressed(sf::Mouse::Left))
      {
        window.clear(sf::Color::Black);
        infiniteGameMode(window);
      }
      if (player.shapePlayer.getGlobalBounds().intersects(
              buttonGoal.button.getGlobalBounds()) &&
          sf::Mouse::isButtonPressed(sf::Mouse::Left))
      {
        window.clear(sf::Color::Black);
        if (gameDifficulty == '0')
          goalGameMode(40, 3, 3, window);
        else if (gameDifficulty == '1')
          goalGameMode(40, 5, 5, window);
        else if (gameDifficulty == '2')
          goalGameMode(40, 7, 7, window);
      }
      if (player.shapePlayer.getGlobalBounds().intersects(
              buttonLeave.button.getGlobalBounds()) &&
          sf::Mouse::isButtonPressed(sf::Mouse::Left))
      {
        window.clear(sf::Color::Black);
        menu(window);
      }
    }

    window.clear(sf::Color::Black);

    window.draw(buttonGoal.button);
    window.draw(buttonGoal.text);

    window.draw(buttonInfinite.button);
    window.draw(buttonInfinite.text);

    window.draw(buttonLeave.button);
    window.draw(buttonLeave.text);

    window.draw(player.shapePlayer);

    window.display();
  }
}