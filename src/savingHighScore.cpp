#include <fstream>

#include "include/savingHighScore.hpp"

void saving_high_score(int highScore)
{
  std::ofstream saveHighScore("highScore.txt");
  saveHighScore << highScore;
  saveHighScore.close();
}