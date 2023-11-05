#include "include/player.hpp"

Player::Player()
{
    bufferPlayer.loadFromFile("Shoot3.wav");
    soundPlayer.setBuffer(bufferPlayer);
    shapePlayer.setRadius(radiusPlayer);
    shapePlayer.setOrigin(radiusPlayer, -radiusPlayer);
    shapePlayer.setPointCount(100);
    shapePlayer.setPosition(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
    shapePlayer.setFillColor(sf::Color::Red);
}