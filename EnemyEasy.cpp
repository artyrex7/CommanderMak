#include <ctime>
#include <cstdlib>
#include "EnemyEasy.h"

EnemyEasy::EnemyEasy() {
    maxMoves = 5;
    srand(time(NULL));
    currentPos = rand()%40;
}