#include "EnemyFactory.h"

Enemy* EnemyFactory::getEnemy(difficultyEnum diff){
  switch(diff) {
  case difficultyEnum::EASY:
    return new EnemyEasy();
  case difficultyEnum::MEDIUM:
    return new EnemyMedium();
  case difficultyEnum::HARD:
    return new EnemyHard();
  }
}

unordered_map<int,vector<Enemy*> > EnemyFactory::generateEnemies(difficultyEnum diff, int numEnemies){
    unordered_map<int, vector<Enemy*> > enemyMap;
    for(int i=0; i<40; i++){
        vector<Enemy*> temp;
        enemyMap.emplace(i,temp);
    }
    
    while(numEnemies > 0){
        Enemy* e = getEnemy(diff);
        enemyMap.at(e->getCurrentPos()).push_back(e);
        --numEnemies;
    }
    return enemyMap;
  }
