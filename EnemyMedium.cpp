#include <ctime>
#include "EnemyMedium.h"

EnemyMedium::EnemyMedium(int fieldWidth) {
    srand(time(NULL));
    currentPos = rand()%fieldWidth;
    maxMoves = 10;
}

int EnemyMedium::move(int max_fields){
  srand(time(NULL));
  return currentPos + (rand() % max_fields) % maxMoves;
}
