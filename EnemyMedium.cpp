#include <ctime>
#include <cstdlib>
#include "EnemyMedium.h"

EnemyMedium::EnemyMedium() {
    srand(time(NULL));
    currentPos = rand()%40;
    maxMoves = 10;
}

int EnemyMedium::move(int max_fields){
  srand(time(NULL));
  return (currentPos + rand()%maxMoves)%max_fields;
}
