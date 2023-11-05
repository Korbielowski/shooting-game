#include "include/saving_high_score.hpp"

#include <fstream>

void saving_high_score(int highScore) {
  std::ofstream saveHighScore("highScore.txt");
  saveHighScore << highScore;
  saveHighScore.close();
}