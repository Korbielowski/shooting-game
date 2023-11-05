void goalGameMode(int r, int vx, int vy) {
  bool isEnemyKilled = false;
  int randX, randY;
  int points = 10;
  // int maxX = sf::VideoMode::getDesktopMode().width - 400;
  // int maxY = sf::VideoMode::getDesktopMode().height - 400;

  srand(time(NULL));

  Player player;
  Enemy enemy(r, vx, vy);

  sf::Font font;
  font.loadFromFile("arial.ttf");
  sf::Text textTime;
  textTime.setFont(font);
  textTime.setCharacterSize(30);
  textTime.setPosition(20, 0);
  textTime.setFillColor(sf::Color::Green);

  sf::Text textPoints;
  textPoints.setFont(font);
  textPoints.setCharacterSize(30);
  textPoints.setPosition(20, 100);
  textPoints.setFillColor(sf::Color::Green);
  textPoints.setString("Pozostalo przeciwnikow: " + std::to_string(points));

  window.setMouseCursorVisible(false);

  sf::Clock clock;

  // pętla gry, całość logiki oraz rysowania obrazu
  while (window.isOpen()) {
    sf::Event event;
    sf::Time timer = clock.getElapsedTime();
    textTime.setString("Czas (max 10s): " +
                       std::to_string(10 - timer.asSeconds()));

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
      points--;
      textPoints.setString("Pozostalo przeciwnikow: " + std::to_string(points));
      enemy.shapeEnemy.setPosition(sf::VideoMode::getDesktopMode().width / 2,
                                   sf::VideoMode::getDesktopMode().height / 2);
      enemy.xVelocity = (rand() % vx * 2) - vx;
      enemy.yVelocity = (rand() % vy * 2) - vy;
    }

    if (points == 0 && 10 - timer.asSeconds() >= 0) {
      j = 2;
      window.clear(sf::Color::Black);
      leaveGame();
    } else if (10 - timer.asSeconds() < 0) {
      j = 1;
      leaveGame();
    }

    // poruszanie wroga
    enemy.shapeEnemy.move(enemy.xVelocity, enemy.yVelocity);

    // poruszanie się graczem oraz zamykanie okna
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
        window.clear(sf::Color::Cyan);
        menu();
      }
    }

    // rysowanie gracza, wroga, punktów, High score oraz tła
    window.clear(sf::Color::Black);

    window.draw(textTime);
    window.draw(textPoints);
    window.draw(enemy.shapeEnemy);
    window.draw(player.shapePlayer);

    window.display();
  }
}
