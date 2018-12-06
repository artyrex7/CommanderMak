#pragma once

#include <unordered_map>
#include <vector>
#include <iostream>
#include "Enemy.h"
#include "Utils.h"

using namespace std;
using namespace Utils;

class GameState{
public:
    GameState(int enemies, int rounds, int width);
    int decrementRounds();
    difficultyEnum getDifficulty();
    int getNumEnemies();
    int getRoundsRemaining();
    int getFieldWidth();
    void resetState();
    unordered_map<int,vector<Enemy*> > enemyMap;

private:
    int numEnemies;
    int roundsRemaining;
    int fieldWidth;
    difficultyEnum enemyDifficulty;
};
