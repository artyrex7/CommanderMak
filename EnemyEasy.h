#include <ctime>
#include <cstdlib>
#include "Enemy.h"

class EnemyEasy{
 public:
  EnemyEasy(){
    srand(time(NULL));
    currentPos = rand()%40;
    maxMoves = 5;
  }
  void move();
 private:
  int currentPos, maxMoves;
};
