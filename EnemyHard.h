#include <ctime>
#include <cstdlib>
#include "Enemy.h"

class EnemyHard{
 public:
  EnemyHard(){
    srand(time(NULL));
    currentPos = rand()%40;
    maxMoves = 20;
  }
  void move();
};
