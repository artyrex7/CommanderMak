#include <cstdlib>
#include "EnemyEasy.h"

EnemyEasy::EnemyEasy(int fieldWidth) {
  maxMoves = 5;
  currentPos = rand()%fieldWidth;
}

int EnemyEasy::move(int max_fields){
  return (currentPos + rand()%maxMoves)%max_fields;
}
