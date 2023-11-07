#include "include/menu.hpp"
#include "include/options.hpp"
#include "include/gameMode.hpp"
#include "button.hpp"
#include "player.hpp"

void menu(sf::RenderWindow &window)
{
    Button buttonPlay("Play", 24, sf::VideoMode::getDesktopMode().width / 2, sf::VideoMode::getDesktopMode().height / 2, sf::Color::Magenta);
    Button buttonOptions("Options", 24, sf::VideoMode::getDesktopMode().width / 2, sf::VideoMode::getDesktopMode().height / 2 + 110, sf::Color::Magenta);
    Button buttonLeave("Exit", 24, sf::VideoMode::getDesktopMode().width / 2, sf::VideoMode::getDesktopMode().height / 2 + 220, sf::Color::Magenta);
    Player player;

    // Menu background
    // sf::Texture texture;
    // texture.loadFromFile("tlo.jpg");
    // sf::Sprite sprite(texture);
    // sprite.setScale(sf::Vector2f(2, 2));

    while (window.isOpen())
    {
        sf::Event event;
        player.shapePlayer.setPosition(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (player.shapePlayer.getGlobalBounds().intersects(buttonPlay.button.getGlobalBounds()) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                window.clear(sf::Color::Black);
                gameMode(window);
            }
            if (player.shapePlayer.getGlobalBounds().intersects(buttonOptions.button.getGlobalBounds()) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                window.clear(sf::Color::Black);
                options(window);
            }
            if (player.shapePlayer.getGlobalBounds().intersects(buttonLeave.button.getGlobalBounds()) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                window.close();
            }
        }

        window.clear(sf::Color::Black);

        // window.draw(sprite);

        window.draw(buttonPlay.button);
        window.draw(buttonPlay.text);

        window.draw(buttonOptions.button);
        window.draw(buttonOptions.text);

        window.draw(buttonLeave.button);
        window.draw(buttonLeave.text);

        window.draw(player.shapePlayer);

        window.display();
    }
}
