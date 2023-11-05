#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>

void menu();
void options();
void gameMode();
void leaveGame();
void infiniteGameMode();
void savingHighScore(int highScore);
void goalGameMode(int r, int vx, int vy);

sf::RenderWindow window(sf::VideoMode(sf::VideoMode::getDesktopMode().width,
                                      sf::VideoMode::getDesktopMode().height),
                        "Shoot The Circle");
int state = 1;
int j = 0;

// class Player
// {
//     public:
//         float radiusPlayer = 5;
//         int bullets;
//         sf::CircleShape shapePlayer;
//         sf::Sprite spritePlayer;
//         //dźwięk strzału
//         sf::SoundBuffer bufferPlayer;
//         sf::Sound soundPlayer;

//         Player()
//         {
//             bufferPlayer.loadFromFile("Shoot3.wav");
//             soundPlayer.setBuffer(bufferPlayer);
//             shapePlayer.setRadius(radiusPlayer);
//             shapePlayer.setOrigin(radiusPlayer, -radiusPlayer);
//             shapePlayer.setPointCount(100);
//             shapePlayer.setPosition(sf::Mouse::getPosition().x,
//             sf::Mouse::getPosition().y);
//             shapePlayer.setFillColor(sf::Color::Red);
//         }

// };

// class Enemy
// {
// public:
//     int radiusEnemy;
//     float xVelocity, yVelocity;
//     sf::CircleShape shapeEnemy;
//     sf::Sprite spriteEnemy;
//     // dżwięk obrażeń
//     sf::SoundBuffer bufferDamage;
//     sf::Sound soundDamage;

//     Enemy(int radiusEnemy, float xVelocity, float yVelocity)
//     {
//         this->radiusEnemy = radiusEnemy;
//         this->xVelocity = xVelocity;
//         this->yVelocity = yVelocity;

//         bufferDamage.loadFromFile("Death6.wav");
//         soundDamage.setBuffer(bufferDamage);

//         shapeEnemy.setRadius(radiusEnemy);
//         shapeEnemy.setOrigin(radiusEnemy, -radiusEnemy);
//         shapeEnemy.setPointCount(100);
//         shapeEnemy.setPosition(400, 400);
//         shapeEnemy.setFillColor(sf::Color::Cyan);
//     }
//     ~Enemy(){};
// };

// class Button
// {
// public:
//     int fontSize;
//     int x, y;
//     std::string buttonName;
//     sf::Text text;
//     sf::Font font;
//     sf::Color buttonColor;
//     sf::RectangleShape button;

//     Button(std::string buttonName, int fontSize, int x, int y, sf::Color
//     buttonColor)
//     {
//         this->buttonName = buttonName;
//         this->fontSize = fontSize;
//         this->buttonColor = buttonColor;

//         button.setSize(sf::Vector2f(200, 100));
//         button.setOrigin(100, 50);
//         button.setFillColor(buttonColor);
//         button.setPosition(x, y);

//         font.loadFromFile("arial.ttf");
//         text.setFont(font);
//         text.setCharacterSize(fontSize);
//         text.setOrigin(100, 50);
//         text.setPosition(x, y);
//         text.setFillColor(sf::Color::Black);
//         text.setString(buttonName);
//     }
// };

// Start programu
int main() {
  window.setMouseCursorVisible(false);
  window.setFramerateLimit(60);
  window.setVerticalSyncEnabled(true);

  menu();

  return 0;
}

// Funkcja odpowiadająca za menu główne, znajdują się tu rozpoczęcie gry, zasady
// gry oraz wyjście z gry void menu()
// {
//     Button buttonPlay("Graj", 24, sf::VideoMode::getDesktopMode().width / 2,
//     sf::VideoMode::getDesktopMode().height / 2, sf::Color::Magenta); Button
//     buttonOptions("Opcje", 24, sf::VideoMode::getDesktopMode().width / 2,
//     sf::VideoMode::getDesktopMode().height / 2 + 110, sf::Color::Magenta);
//     Button buttonLeave("Wyjdz", 24, sf::VideoMode::getDesktopMode().width /
//     2, sf::VideoMode::getDesktopMode().height / 2 + 220, sf::Color::Magenta);
//     Player player;

//     // tło menu
//     // sf::Texture texture;
//     // texture.loadFromFile("tlo.jpg");
//     // sf::Sprite sprite(texture);
//     // sprite.setScale(sf::Vector2f(2, 2));

//     while (window.isOpen())
//     {
//         sf::Event event;
//         player.shapePlayer.setPosition(sf::Mouse::getPosition().x,
//         sf::Mouse::getPosition().y);

//         while (window.pollEvent(event))
//         {
//             if (event.type == sf::Event::Closed)
//             {
//                 window.close();
//             }
//             if
//             (player.shapePlayer.getGlobalBounds().intersects(buttonPlay.button.getGlobalBounds())
//             && sf::Mouse::isButtonPressed(sf::Mouse::Left))
//             {
//                 window.clear(sf::Color::Black);
//                 gameMode();
//             }
//             if
//             (player.shapePlayer.getGlobalBounds().intersects(buttonOptions.button.getGlobalBounds())
//             && sf::Mouse::isButtonPressed(sf::Mouse::Left))
//             {
//                 window.clear(sf::Color::Black);
//                 options();
//             }
//             if
//             (player.shapePlayer.getGlobalBounds().intersects(buttonLeave.button.getGlobalBounds())
//             && sf::Mouse::isButtonPressed(sf::Mouse::Left))
//             {
//                 window.close();
//             }
//         }

//         window.clear(sf::Color::Black);

//         // window.draw(sprite);

//         window.draw(buttonPlay.button);
//         window.draw(buttonPlay.text);

//         window.draw(buttonOptions.button);
//         window.draw(buttonOptions.text);

//         window.draw(buttonLeave.button);
//         window.draw(buttonLeave.text);

//         window.draw(player.shapePlayer);

//         window.display();
//     }
// }

// Funkcja odpowiadająca za wybór poziomu trudności w trybie Goal Game mode
// void options()
// {
//     Button buttonEasy("Easy", 24, sf::VideoMode::getDesktopMode().width / 2,
//     sf::VideoMode::getDesktopMode().height / 2 - 110, sf::Color::Magenta);
//     Button buttonNormal("Normal", 24, sf::VideoMode::getDesktopMode().width /
//     2, sf::VideoMode::getDesktopMode().height / 2, sf::Color::Magenta);
//     Button buttonHard("Hard", 24, sf::VideoMode::getDesktopMode().width / 2,
//     sf::VideoMode::getDesktopMode().height / 2 + 110, sf::Color::Magenta);
//     Button buttonLeave("Powrot do menu", 22,
//     sf::VideoMode::getDesktopMode().width / 2,
//     sf::VideoMode::getDesktopMode().height / 2 + 220, sf::Color::Magenta);

//     Player player;

//     while (window.isOpen())
//     {
//         sf::Event event;

//         while (window.pollEvent(event))
//         {
//             player.shapePlayer.setPosition(sf::Mouse::getPosition().x,
//             sf::Mouse::getPosition().y);

//             if (event.type == sf::Event::Closed)
//             {
//                 window.close();
//             }
//             if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
//             {
//                 window.clear(sf::Color::Cyan);
//                 menu();
//             }
//             if
//             (player.shapePlayer.getGlobalBounds().intersects(buttonEasy.button.getGlobalBounds())
//             && sf::Mouse::isButtonPressed(sf::Mouse::Left))
//             {
//                 state = 0;
//             }
//             if
//             (player.shapePlayer.getGlobalBounds().intersects(buttonNormal.button.getGlobalBounds())
//             && sf::Mouse::isButtonPressed(sf::Mouse::Left))
//             {
//                 state = 1;
//             }
//             if
//             (player.shapePlayer.getGlobalBounds().intersects(buttonHard.button.getGlobalBounds())
//             && sf::Mouse::isButtonPressed(sf::Mouse::Left))
//             {
//                 state = 2;
//             }
//             if
//             (player.shapePlayer.getGlobalBounds().intersects(buttonLeave.button.getGlobalBounds())
//             && sf::Mouse::isButtonPressed(sf::Mouse::Left))
//             {
//                 window.clear(sf::Color::Black);
//                 menu();
//             }
//         }
//         window.clear(sf::Color::Black);

//         window.draw(buttonEasy.button);
//         window.draw(buttonEasy.text);

//         window.draw(buttonNormal.button);
//         window.draw(buttonNormal.text);

//         window.draw(buttonHard.button);
//         window.draw(buttonHard.text);

//         window.draw(buttonLeave.button);
//         window.draw(buttonLeave.text);

//         window.draw(player.shapePlayer);

//         window.display();
//     }
// }
// Funkcja odpowiadająca za możliwość wyboru spośród dwóch trybów gry(Infinite i
// Goal) void gameMode()
// {
//     Button buttonGoal("Goal Game Mode", 24,
//     sf::VideoMode::getDesktopMode().width / 2,
//     sf::VideoMode::getDesktopMode().height / 2, sf::Color::Magenta); Button
//     buttonInfinite("Infinte Game Mode", 22,
//     sf::VideoMode::getDesktopMode().width / 2,
//     sf::VideoMode::getDesktopMode().height / 2 + 110, sf::Color::Magenta);
//     Button buttonLeave("Powrot do Menu", 24,
//     sf::VideoMode::getDesktopMode().width / 2,
//     sf::VideoMode::getDesktopMode().height / 2 + 220, sf::Color::Magenta);

//     Player player;

//     while (window.isOpen())
//     {
//         sf::Event event;

//         while (window.pollEvent(event))
//         {
//             player.shapePlayer.setPosition(sf::Mouse::getPosition().x,
//             sf::Mouse::getPosition().y);

//             if (event.type == sf::Event::Closed)
//             {
//                 window.close();
//             }
//             if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
//             {
//                 window.clear(sf::Color::Cyan);
//                 menu();
//             }
//             if
//             (player.shapePlayer.getGlobalBounds().intersects(buttonInfinite.button.getGlobalBounds())
//             && sf::Mouse::isButtonPressed(sf::Mouse::Left))
//             {
//                 window.clear(sf::Color::Black);
//                 infiniteGameMode();
//             }
//             if
//             (player.shapePlayer.getGlobalBounds().intersects(buttonGoal.button.getGlobalBounds())
//             && sf::Mouse::isButtonPressed(sf::Mouse::Left))
//             {
//                 window.clear(sf::Color::Black);
//                 if (state == 0)
//                     goalGameMode(40, 3, 3);
//                 else if (state == 1)
//                     goalGameMode(40, 5, 5);
//                 else if (state == 2)
//                     goalGameMode(40, 7, 7);
//             }
//             if
//             (player.shapePlayer.getGlobalBounds().intersects(buttonLeave.button.getGlobalBounds())
//             && sf::Mouse::isButtonPressed(sf::Mouse::Left))
//             {
//                 window.clear(sf::Color::Black);
//                 menu();
//             }
//         }

//         window.clear(sf::Color::Black);

//         window.draw(buttonGoal.button);
//         window.draw(buttonGoal.text);

//         window.draw(buttonInfinite.button);
//         window.draw(buttonInfinite.text);

//         window.draw(buttonLeave.button);
//         window.draw(buttonLeave.text);

//         window.draw(player.shapePlayer);

//         window.display();
//     }
// }

// Funkcja odpowiadająca za rysowanie i odświeżanie ekranu, sprawdzanie warunków
// zdobywania punktów, poruszanie się graczem void infiniteGameMode()
// {
//     int points = 0;
//     int highScore;
//     bool isEnemyCreated = false;
//     bool isPointGiven = false;
//     int velX, velY;
//     // int maxX = 1520;
//     // int maxY = 680;

//     srand(time(NULL));

//     Player player;
//     Enemy enemy(40, 5, 6);

//     sf::Font font;
//     font.loadFromFile("arial.ttf");

//     sf::Text textPoints;
//     textPoints.setFont(font);
//     textPoints.setCharacterSize(24);
//     textPoints.setFillColor(sf::Color::Green);
//     textPoints.setString("Punkty: " + std::to_string(points));
//     textPoints.setPosition(10, 50);

//     std::ifstream loadHighScore("highScore.txt");
//     if (loadHighScore.good())
//     {
//         loadHighScore >> highScore;
//     }
//     else
//     {
//         highScore = 0;
//     }
//     loadHighScore.close();

//     sf::Text textHighScore;
//     textHighScore.setFont(font);
//     textHighScore.setCharacterSize(24);
//     textHighScore.setFillColor(sf::Color::Yellow);
//     textHighScore.setString("High score: " + std::to_string(highScore));
//     textHighScore.setPosition(10, 0);

//     // pętla gry, całość logiki oraz rysowania obrazu
//     while (window.isOpen())
//     {
//         sf::Event event;

//         player.shapePlayer.setPosition(sf::Mouse::getPosition().x,
//         sf::Mouse::getPosition().y);

//         // odbijanie wroga od krawędzi ekranu
//         if (enemy.shapeEnemy.getPosition().x - enemy.radiusEnemy <= 0.f)
//             enemy.xVelocity = 0 - enemy.xVelocity;
//         if (enemy.shapeEnemy.getPosition().y - enemy.radiusEnemy <= 0.f - 80)
//             enemy.yVelocity = 0 - enemy.yVelocity;
//         if (enemy.shapeEnemy.getPosition().x + enemy.radiusEnemy >=
//         sf::VideoMode::getDesktopMode().width)
//             enemy.xVelocity = 0 - enemy.xVelocity;
//         if (enemy.shapeEnemy.getPosition().y + enemy.radiusEnemy >=
//         sf::VideoMode::getDesktopMode().height - 123)
//             enemy.yVelocity = 0 - enemy.yVelocity;

//         if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
//             player.soundPlayer.play();

//         // dodawanie punktów jeśli gracz dotknie wroga przy użyciu metody
//         intersects() if
//         (player.shapePlayer.getGlobalBounds().intersects(enemy.shapeEnemy.getGlobalBounds())
//         && sf::Mouse::isButtonPressed(sf::Mouse::Left))
//         {
//             enemy.soundDamage.play();
//             velX = (rand() % 12) - 6;
//             velY = (rand() % 12) - 6;
//             enemy.shapeEnemy.setPosition(sf::VideoMode::getDesktopMode().width
//             / 2, sf::VideoMode::getDesktopMode().height / 2); enemy.xVelocity
//             = velX; enemy.yVelocity = velY;

//             if (isPointGiven == false)
//             {
//                 points++;
//                 if (points > highScore)
//                 {
//                     highScore = points;
//                     textHighScore.setString("High score: " +
//                     std::to_string(highScore));
//                 }

//                 textPoints.setString("Punkty: " + std::to_string(points));
//                 isPointGiven = true;
//             }
//         }
//         else
//         {
//             isPointGiven = false;
//         }

//         // poruszanie wroga
//         enemy.shapeEnemy.move(enemy.xVelocity, enemy.yVelocity);

//         // poruszanie się graczem oraz zamykanie okna
//         while (window.pollEvent(event))
//         {
//             if (event.type == sf::Event::Closed)
//             {
//                 savingHighScore(highScore);
//                 window.close();
//             }
//             if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
//             {
//                 savingHighScore(highScore);
//                 menu();
//             }
//         }

//         // rysowanie gracza, wroga, punktów, High score oraz tła
//         window.clear(sf::Color::Black);

//         window.draw(enemy.shapeEnemy);
//         window.draw(player.shapePlayer);

//         window.draw(textPoints);
//         window.draw(textHighScore);

//         window.display();
//     }
// }

// Funkcja odpowiadająca za tryg gry Goal Game mode
// void goalGameMode(int r, int vx, int vy) {
//   bool isEnemyKilled = false;
//   int randX, randY;
//   int points = 10;
//   // int maxX = sf::VideoMode::getDesktopMode().width - 400;
//   // int maxY = sf::VideoMode::getDesktopMode().height - 400;

//   srand(time(NULL));

//   Player player;
//   Enemy enemy(r, vx, vy);

//   sf::Font font;
//   font.loadFromFile("arial.ttf");
//   sf::Text textTime;
//   textTime.setFont(font);
//   textTime.setCharacterSize(30);
//   textTime.setPosition(20, 0);
//   textTime.setFillColor(sf::Color::Green);

//   sf::Text textPoints;
//   textPoints.setFont(font);
//   textPoints.setCharacterSize(30);
//   textPoints.setPosition(20, 100);
//   textPoints.setFillColor(sf::Color::Green);
//   textPoints.setString("Pozostalo przeciwnikow: " + std::to_string(points));

//   window.setMouseCursorVisible(false);

//   sf::Clock clock;

//   // pętla gry, całość logiki oraz rysowania obrazu
//   while (window.isOpen()) {
//     sf::Event event;
//     sf::Time timer = clock.getElapsedTime();
//     textTime.setString("Czas (max 10s): " +
//                        std::to_string(10 - timer.asSeconds()));

//     player.shapePlayer.setPosition(sf::Mouse::getPosition().x,
//                                    sf::Mouse::getPosition().y);

//     // odbijanie wroga od krawędzi ekranu
//     if (enemy.shapeEnemy.getPosition().x - enemy.radiusEnemy <= 0.f)
//       enemy.xVelocity = 0 - enemy.xVelocity;
//     if (enemy.shapeEnemy.getPosition().y - enemy.radiusEnemy <= 0.f - 80)
//       enemy.yVelocity = 0 - enemy.yVelocity;
//     if (enemy.shapeEnemy.getPosition().x + enemy.radiusEnemy >=
//         sf::VideoMode::getDesktopMode().width)
//       enemy.xVelocity = 0 - enemy.xVelocity;
//     if (enemy.shapeEnemy.getPosition().y + enemy.radiusEnemy >=
//         sf::VideoMode::getDesktopMode().height - 123)
//       enemy.yVelocity = 0 - enemy.yVelocity;

//     if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
//     player.soundPlayer.play();

//     // dodawanie punktów jeśli gracz dotknie wroga przy użyciu metody
//     // intersects()
//     if (player.shapePlayer.getGlobalBounds().intersects(
//             enemy.shapeEnemy.getGlobalBounds()) &&
//         sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
//       enemy.soundDamage.play();
//       points--;
//       textPoints.setString("Pozostalo przeciwnikow: " +
//       std::to_string(points));
//       enemy.shapeEnemy.setPosition(sf::VideoMode::getDesktopMode().width / 2,
//                                    sf::VideoMode::getDesktopMode().height /
//                                    2);
//       enemy.xVelocity = (rand() % vx * 2) - vx;
//       enemy.yVelocity = (rand() % vy * 2) - vy;
//     }

//     if (points == 0 && 10 - timer.asSeconds() >= 0) {
//       j = 2;
//       window.clear(sf::Color::Black);
//       leaveGame();
//     } else if (10 - timer.asSeconds() < 0) {
//       j = 1;
//       leaveGame();
//     }

//     // poruszanie wroga
//     enemy.shapeEnemy.move(enemy.xVelocity, enemy.yVelocity);

//     // poruszanie się graczem oraz zamykanie okna
//     while (window.pollEvent(event)) {
//       if (event.type == sf::Event::Closed) {
//         window.close();
//       }
//       if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
//         window.clear(sf::Color::Cyan);
//         menu();
//       }
//     }

//     // rysowanie gracza, wroga, punktów, High score oraz tła
//     window.clear(sf::Color::Black);

//     window.draw(textTime);
//     window.draw(textPoints);
//     window.draw(enemy.shapeEnemy);
//     window.draw(player.shapePlayer);

//     window.display();
//   }
// }

// Funkcja odpowiadająca za zapisywanie najwyższego wyniku w trybie gry Infinite
// Game mode do pliku
// void savingHighScore(int highScore) {
//   std::ofstream saveHighScore("highScore.txt");
//   saveHighScore << highScore;
//   saveHighScore.close();
// }

// // Funkcja odpowiada za ekran końcowy gry dla trybu Goal Game mode
// void leaveGame() {
//   sf::Font font;
//   font.loadFromFile("arial.ttf");
//   sf::Text textEnd;
//   textEnd.setFont(font);
//   textEnd.setCharacterSize(30);
//   textEnd.setFillColor(sf::Color::Green);

//   if (j == 1) {
//     textEnd.setString("Niestety przegrales :(\nSproboj jeszcze raz");
//     textEnd.setPosition(sf::VideoMode::getDesktopMode().width / 2,
//                         sf::VideoMode::getDesktopMode().height / 2);
//     sf::SoundBuffer buffer;
//     sf::Sound sound;
//     buffer.loadFromFile("loss.wav");
//     sound.setBuffer(buffer);
//     sound.play();
//     // if(sound.Stopped)
//     //     window.close();
//   }
//   if (j == 2) {
//     textEnd.setString("Wygrales!!!\nGratulujemy");
//     textEnd.setPosition(sf::VideoMode::getDesktopMode().width / 2,
//                         sf::VideoMode::getDesktopMode().height / 2);
//     sf::SoundBuffer buffer;
//     sf::Sound sound;
//     buffer.loadFromFile("win.wav");
//     sound.setBuffer(buffer);
//     sound.play();
//     // if(sound.Stopped)
//     //     window.close();
//   }

//   while (window.isOpen()) {
//     sf::Event event;

//     while (window.pollEvent(event)) {
//       if (event.type == sf::Event::Closed) {
//         window.close();
//       }
//       if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
//         menu();
//       }
//     }

//     window.clear(sf::Color::Black);
//     window.draw(textEnd);
//     window.display();
//   }
// }