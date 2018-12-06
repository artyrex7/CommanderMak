#include <ctime>
#include <cstdlib>
#include "EnemyEasy.h"

EnemyEasy::EnemyEasy(int fieldWidth) {
  maxMoves = 5;
  srand(time(NULL));
  currentPos = rand()%fieldWidth;
}

int EnemyEasy::move(int max_fields){
  srand(time(NULL));
  return (currentPos + rand()%maxMoves)%max_fields;
}
