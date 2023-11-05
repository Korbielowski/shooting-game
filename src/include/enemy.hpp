#pragma once

class Enemy {
 public:
  int radiusEnemy;
  float xVelocity, yVelocity;
  sf::CircleShape shapeEnemy;
  sf::Sprite spriteEnemy;
  // dżwięk obrażeń
  sf::SoundBuffer bufferDamage;
  sf::Sound soundDamage;

  Enemy(int radiusEnemy, float xVelocity, float yVelocity);
};