#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Enemy
{
public:
  int radiusEnemy;
  float xVelocity, yVelocity;
  sf::CircleShape shapeEnemy;
  sf::Sprite spriteEnemy;
  // Damage sound
  sf::SoundBuffer bufferDamage;
  sf::Sound soundDamage;

  Enemy(int radiusEnemy, float xVelocity, float yVelocity);
};