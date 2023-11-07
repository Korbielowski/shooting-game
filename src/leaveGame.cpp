#include <SFML/Audio.hpp>

#include <fstream>

#include "include/leaveGame.hpp"
#include "include/menu.hpp"

// This function is responsible for the ending screen of the Goal Game mode
void leaveGame(sf::RenderWindow &window)
{
  sf::Font font;
  font.loadFromFile("arial.ttf");
  sf::Text textEnd;
  textEnd.setFont(font);
  textEnd.setCharacterSize(30);
  textEnd.setFillColor(sf::Color::Green);

  std::ifstream leaveStateFile("leaveState.txt");
  char leaveState;

  if (leaveStateFile.is_open())
  {
    leaveStateFile.get(leaveState);
    leaveStateFile.close();
  }

  if (leaveState == '1')
  {
    textEnd.setString("Unfortunately You lost :(\nTry again");
    textEnd.setPosition(sf::VideoMode::getDesktopMode().width / 2,
                        sf::VideoMode::getDesktopMode().height / 2);
    sf::SoundBuffer buffer;
    sf::Sound sound;
    buffer.loadFromFile("loss.wav");
    sound.setBuffer(buffer);
    sound.play();
    // if(sound.Stopped)
    //     window.close();
  }
  if (leaveState == '2')
  {
    textEnd.setString("You won!!!\nCongratulations");
    textEnd.setPosition(sf::VideoMode::getDesktopMode().width / 2,
                        sf::VideoMode::getDesktopMode().height / 2);
    sf::SoundBuffer buffer;
    sf::Sound sound;
    buffer.loadFromFile("win.wav");
    sound.setBuffer(buffer);
    sound.play();
    // if(sound.Stopped)
    //     window.close();
  }

  while (window.isOpen())
  {
    sf::Event event;

    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
      {
        window.close();
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
      {
        menu(window);
      }
    }

    window.clear(sf::Color::Black);
    window.draw(textEnd);
    window.display();
  }
}