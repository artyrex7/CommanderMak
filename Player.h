#include "GameState.h"
#include "GameClient.h"
#include <iostream>

using namespace std;

class Player{
 public:
  Player();
  void takeTurn();
 private:
  int currentPos;
  int maxMoves;
  void move(int);
  void shoot();
};
