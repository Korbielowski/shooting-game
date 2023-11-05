#include "include/enemy.hpp"

Enemy::Enemy(int radiusEnemy, float xVelocity, float yVelocity)
{
    this->radiusEnemy = radiusEnemy;
    this->xVelocity = xVelocity;
    this->yVelocity = yVelocity;

    bufferDamage.loadFromFile("Death6.wav");
    soundDamage.setBuffer(bufferDamage);

    shapeEnemy.setRadius(radiusEnemy);
    shapeEnemy.setOrigin(radiusEnemy, -radiusEnemy);
    shapeEnemy.setPointCount(100);
    shapeEnemy.setPosition(400, 400);
    shapeEnemy.setFillColor(sf::Color::Cyan);
}