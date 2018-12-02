#include <iostream>
#include "Player.h"
#include "GameState.h"

using namespace std;

class GameClient{
 public:
  GameClient();
  void startGame();
  void printGameState();
 private:
  Player player;
};
