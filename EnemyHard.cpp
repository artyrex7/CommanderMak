#include <ctime>
#include <cstdlib>
#include "EnemyHard.h"

EnemyHard::EnemyHard() {
    srand(time(NULL));
    currentPos = rand()%40;
    maxMoves = 20;
}