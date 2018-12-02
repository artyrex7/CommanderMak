#pragma once

#include "Utils.h"
#include "Enemy.h"
#include "GameState.h"
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class EnemyFactory{
    public:
        unordered_map<int,vector<Enemy*> > generateEnemies(Utils::difficultyEnum diff, int numEnemies);
  
    private:
        Enemy* getEnemy(Utils::difficultyEnum diff);
};
