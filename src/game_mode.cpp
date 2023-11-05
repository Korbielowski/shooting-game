#include "game_mode.hpp"

#include "button.hpp"
#include "goal_game_mode.hpp"
#include "infinite_game_mode.hpp"
#include "menu.hpp"
#include "player.hpp"

void gameMode() {
  Button buttonGoal(
      "Goal Game Mode", 24, sf::VideoMode::getDesktopMode().width / 2,
      sf::VideoMode::getDesktopMode().height / 2, sf::Color::Magenta);
  Button buttonInfinite(
      "Infinte Game Mode", 22, sf::VideoMode::getDesktopMode().width / 2,
      sf::VideoMode::getDesktopMode().height / 2 + 110, sf::Color::Magenta);
  Button buttonLeave(
      "Powrot do Menu", 24, sf::VideoMode::getDesktopMode().width / 2,
      sf::VideoMode::getDesktopMode().height / 2 + 220, sf::Color::Magenta);

  Player player;

  while (window.isOpen()) {
    sf::Event event;

    while (window.pollEvent(event)) {
      player.shapePlayer.setPosition(sf::Mouse::getPosition().x,
                                     sf::Mouse::getPosition().y);

      if (event.type == sf::Event::Closed) {
        window.close();
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
        window.clear(sf::Color::Cyan);
        menu();
      }
      if (player.shapePlayer.getGlobalBounds().intersects(
              buttonInfinite.button.getGlobalBounds()) &&
          sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        window.clear(sf::Color::Black);
        infiniteGameMode();
      }
      if (player.shapePlayer.getGlobalBounds().intersects(
              buttonGoal.button.getGlobalBounds()) &&
          sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        window.clear(sf::Color::Black);
        if (state == 0)
          goalGameMode(40, 3, 3);
        else if (state == 1)
          goalGameMode(40, 5, 5);
        else if (state == 2)
          goalGameMode(40, 7, 7);
      }
      if (player.shapePlayer.getGlobalBounds().intersects(
              buttonLeave.button.getGlobalBounds()) &&
          sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        window.clear(sf::Color::Black);
        menu();
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