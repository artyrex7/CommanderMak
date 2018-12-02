#include <ctime>
#include <cstdlib>
#include "Enemy.h"

class EnemyMedium{
 public:
  EnemyMedium(){
    srand(time(NULL));
    currentPos = rand()%40;
    maxMoves = 10;
  }
  void move();
};
