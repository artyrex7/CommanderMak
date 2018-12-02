#include <iostream>

using namespace std;

class Enemy{
 public:
  virutal void move() = 0;
  int getCurrentPos(){return currentPos}
  int getMaxMoves(){return maxMoves;}
 private:
  int currentPos, maxMoves;
};
