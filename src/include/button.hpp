#include <SFML/Graphics.hpp>

#include <string>

class Button
{
public:
       int fontSize;
       int x, y;
       std::string buttonName;
       sf::Text text;
       sf::Font font;
       sf::Color buttonColor;
       sf::RectangleShape button;

       Button(std::string buttonName, int fontSize, int x, int y,
              sf::Color buttonColor);
};
