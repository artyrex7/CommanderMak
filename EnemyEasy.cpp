#include <ctime>
#include <cstdlib>
#include "EnemyEasy.h"

EnemyEasy::EnemyEasy() {
  maxMoves = 5;
  srand(time(NULL));
  currentPos = rand()%40;
}

int EnemyEasy::move(int max_fields){
  srand(time(NULL));
  return (currentPos + rand()%maxMoves)%max_fields;
}
