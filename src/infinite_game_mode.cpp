#include "include/infinite_game_mode.hpp"

#include <fstream>
#include <iostream>

#include "include/enemy.hpp"
#include "include/menu.hpp"
#include "include/player.hpp"
#include "include/saving_high_score.hpp"

void infitnite_game_mode() {
  int points = 0;
  int highScore;
  bool isEnemyCreated = false;
  bool isPointGiven = false;
  int velX, velY;
  // int maxX = 1520;
  // int maxY = 680;

  srand(time(NULL));

  Player player;
  Enemy enemy(40, 5, 6);

  sf::Font font;
  font.loadFromFile("arial.ttf");

  sf::Text textPoints;
  textPoints.setFont(font);
  textPoints.setCharacterSize(24);
  textPoints.setFillColor(sf::Color::Green);
  textPoints.setString("Punkty: " + std::to_string(points));
  textPoints.setPosition(10, 50);

  std::ifstream loadHighScore("highScore.txt");
  if (loadHighScore.good()) {
    loadHighScore >> highScore;
  } else {
    highScore = 0;
  }
  loadHighScore.close();

  sf::Text textHighScore;
  textHighScore.setFont(font);
  textHighScore.setCharacterSize(24);
  textHighScore.setFillColor(sf::Color::Yellow);
  textHighScore.setString("High score: " + std::to_string(highScore));
  textHighScore.setPosition(10, 0);

  // pętla gry, całość logiki oraz rysowania obrazu
  while (window.isOpen()) {
    sf::Event event;

    player.shapePlayer.setPosition(sf::Mouse::getPosition().x,
                                   sf::Mouse::getPosition().y);

    // odbijanie wroga od krawędzi ekranu
    if (enemy.shapeEnemy.getPosition().x - enemy.radiusEnemy <= 0.f)
      enemy.xVelocity = 0 - enemy.xVelocity;
    if (enemy.shapeEnemy.getPosition().y - enemy.radiusEnemy <= 0.f - 80)
      enemy.yVelocity = 0 - enemy.yVelocity;
    if (enemy.shapeEnemy.getPosition().x + enemy.radiusEnemy >=
        sf::VideoMode::getDesktopMode().width)
      enemy.xVelocity = 0 - enemy.xVelocity;
    if (enemy.shapeEnemy.getPosition().y + enemy.radiusEnemy >=
        sf::VideoMode::getDesktopMode().height - 123)
      enemy.yVelocity = 0 - enemy.yVelocity;

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) player.soundPlayer.play();

    // dodawanie punktów jeśli gracz dotknie wroga przy użyciu metody
    // intersects()
    if (player.shapePlayer.getGlobalBounds().intersects(
            enemy.shapeEnemy.getGlobalBounds()) &&
        sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
      enemy.soundDamage.play();
      velX = (rand() % 12) - 6;
      velY = (rand() % 12) - 6;
      enemy.shapeEnemy.setPosition(sf::VideoMode::getDesktopMode().width / 2,
                                   sf::VideoMode::getDesktopMode().height / 2);
      enemy.xVelocity = velX;
      enemy.yVelocity = velY;

      if (isPointGiven == false) {
        points++;
        if (points > highScore) {
          highScore = points;
          textHighScore.setString("High score: " + std::to_string(highScore));
        }

        textPoints.setString("Punkty: " + std::to_string(points));
        isPointGiven = true;
      }
    } else {
      isPointGiven = false;
    }

    // poruszanie wroga
    enemy.shapeEnemy.move(enemy.xVelocity, enemy.yVelocity);

    // poruszanie się graczem oraz zamykanie okna
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        saving_high_score(highScore);
        window.close();
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
        saving_high_score(highScore);
        menu();
      }
    }

    // rysowanie gracza, wroga, punktów, High score oraz tła
    window.clear(sf::Color::Black);

    window.draw(enemy.shapeEnemy);
    window.draw(player.shapePlayer);

    window.draw(textPoints);
    window.draw(textHighScore);

    window.display();
  }
}