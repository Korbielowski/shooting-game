#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Player
{
public:
    float radiusPlayer = 5;
    int bullets;
    sf::CircleShape shapePlayer;
    sf::Sprite spritePlayer;
    // shooting sound
    sf::SoundBuffer bufferPlayer;
    sf::Sound soundPlayer;

    Player();
};