#pragma once

#include "Utils.h"
#include "Enemy.h"
#include "GameState.h"
#include "EnemyEasy.h"
#include "EnemyHard.h"
#include "EnemyMedium.h"
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class EnemyFactory{
    public:
        unordered_map<int,vector<Enemy*> > generateEnemies(difficultyEnum diff, int numEnemies, int fieldWidth);  
    private:
        Enemy* getEnemy(difficultyEnum diff, int fieldWidth);
};
