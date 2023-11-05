#include "include/button.hpp"

Button::Button(std::string buttonName, int fontSize, int x, int y, sf::Color buttonColor) : buttonName(buttonName), fontSize(fontSize), buttonColor(buttonColor)
{
    button.setSize(sf::Vector2f(200, 100));
    button.setOrigin(100, 50);
    button.setFillColor(buttonColor);
    button.setPosition(x, y);

    font.loadFromFile("arial.ttf");
    text.setFont(font);
    text.setCharacterSize(fontSize);
    text.setOrigin(100, 50);
    text.setPosition(x, y);
    text.setFillColor(sf::Color::Black);
    text.setString(buttonName);
}