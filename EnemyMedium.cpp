#include <ctime>
#include <cstdlib>
#include "EnemyMedium.h"

EnemyMedium::EnemyMedium() {
    srand(time(NULL));
    currentPos = rand()%40;
    maxMoves = 10;
}