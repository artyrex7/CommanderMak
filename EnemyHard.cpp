#include <cstdlib>
#include "EnemyHard.h"

EnemyHard::EnemyHard(int fieldWidth) {
    currentPos = rand()%fieldWidth;
    maxMoves = 20;
}

int EnemyHard::move(int max_fields){
  return (currentPos + rand()%maxMoves)%max_fields;
}
