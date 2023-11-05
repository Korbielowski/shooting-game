#include "button.hpp"
#include "player.hpp"
#include "menu.hpp"

void options()
{
    Button buttonEasy("Easy", 24, sf::VideoMode::getDesktopMode().width / 2, sf::VideoMode::getDesktopMode().height / 2 - 110, sf::Color::Magenta);
    Button buttonNormal("Normal", 24, sf::VideoMode::getDesktopMode().width / 2, sf::VideoMode::getDesktopMode().height / 2, sf::Color::Magenta);
    Button buttonHard("Hard", 24, sf::VideoMode::getDesktopMode().width / 2, sf::VideoMode::getDesktopMode().height / 2 + 110, sf::Color::Magenta);
    Button buttonLeave("Powrot do menu", 22, sf::VideoMode::getDesktopMode().width / 2, sf::VideoMode::getDesktopMode().height / 2 + 220, sf::Color::Magenta);

    Player player;

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            player.shapePlayer.setPosition(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);

            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
            {
                window.clear(sf::Color::Cyan);
                menu();
            }
            if (player.shapePlayer.getGlobalBounds().intersects(buttonEasy.button.getGlobalBounds()) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                state = 0;
            }
            if (player.shapePlayer.getGlobalBounds().intersects(buttonNormal.button.getGlobalBounds()) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                state = 1;
            }
            if (player.shapePlayer.getGlobalBounds().intersects(buttonHard.button.getGlobalBounds()) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                state = 2;
            }
            if (player.shapePlayer.getGlobalBounds().intersects(buttonLeave.button.getGlobalBounds()) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                window.clear(sf::Color::Black);
                menu();
            }
        }
        window.clear(sf::Color::Black);

        window.draw(buttonEasy.button);
        window.draw(buttonEasy.text);

        window.draw(buttonNormal.button);
        window.draw(buttonNormal.text);

        window.draw(buttonHard.button);
        window.draw(buttonHard.text);

        window.draw(buttonLeave.button);
        window.draw(buttonLeave.text);

        window.draw(player.shapePlayer);

        window.display();
    }
}