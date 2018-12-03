#include <ctime>
#include <cstdlib>
#include "EnemyHard.h"

EnemyHard::EnemyHard() {
    srand(time(NULL));
    currentPos = rand()%40;
    maxMoves = 20;
}

int EnemyHard::move(int max_fields){
  srand(time(NULL));
  return (currentPos + rand()%maxMoves)%max_fields;
}
