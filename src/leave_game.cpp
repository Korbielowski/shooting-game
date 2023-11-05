#include "include/leave_game.hpp"

#include "include/menu.hpp"

// Funkcja odpowiada za ekran końcowy gry dla trybu Goal Game mode
void leave_game() {
  sf::Font font;
  font.loadFromFile("arial.ttf");
  sf::Text textEnd;
  textEnd.setFont(font);
  textEnd.setCharacterSize(30);
  textEnd.setFillColor(sf::Color::Green);

  if (j == 1) {
    textEnd.setString("Niestety przegrales :(\nSproboj jeszcze raz");
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
  if (j == 2) {
    textEnd.setString("Wygrales!!!\nGratulujemy");
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

  while (window.isOpen()) {
    sf::Event event;

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
        menu();
      }
    }

    window.clear(sf::Color::Black);
    window.draw(textEnd);
    window.display();
  }
}