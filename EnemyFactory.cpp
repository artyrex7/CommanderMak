#include "EnemyFactory.h"
#include <iostream>

Enemy* EnemyFactory::getEnemy(difficultyEnum diff, int fieldWidth){
  switch(diff) {
  case difficultyEnum::EASY:
    return new EnemyEasy(fieldWidth);
  case difficultyEnum::MEDIUM:
    return new EnemyMedium(fieldWidth);
  case difficultyEnum::HARD:
    return new EnemyHard(fieldWidth);
  }
}

unordered_map<int,vector<Enemy*> > EnemyFactory::generateEnemies(difficultyEnum diff, int numEnemies, int fieldWidth){
    unordered_map<int, vector<Enemy*> > enemyMap;
    fillMap(enemyMap,fieldWidth);
    
    while(numEnemies > 0){
        Enemy* e = getEnemy(diff, fieldWidth);
        enemyMap.at(e->getCurrentPos()).push_back(e);
        --numEnemies;
    }
    return enemyMap;
  }
