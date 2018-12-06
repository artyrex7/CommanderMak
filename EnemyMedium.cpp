#include <cstdlib>
#include "EnemyMedium.h"

EnemyMedium::EnemyMedium(int fieldWidth) {
    currentPos = rand()%fieldWidth;
    maxMoves = 10;
}

int EnemyMedium::move(int max_fields){
  return (currentPos + rand()%maxMoves)%max_fields;
}
