#pragma once

class Player
{
public:
    float radiusPlayer = 5;
    int bullets;
    sf::CircleShape shapePlayer;
    sf::Sprite spritePlayer;
    // dźwięk strzału
    sf::SoundBuffer bufferPlayer;
    sf::Sound soundPlayer;

    Player();
};