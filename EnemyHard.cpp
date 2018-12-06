#include <ctime>
#include <cstdlib>
#include "EnemyHard.h"

EnemyHard::EnemyHard(int fieldWidth) {
    srand(time(NULL));
    currentPos = rand()%fieldWidth;
    maxMoves = 20;
}

int EnemyHard::move(int max_fields){
  srand(time(NULL));
  return (currentPos + rand()%maxMoves)%max_fields;
}
