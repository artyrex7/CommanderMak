#include "Utils.h"
#include "Enemy.h"
#include "GameState.h"
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class EnemyFactory{
 private:
  Enemy* getEnemy(difficultyEnum diff){
    switch(diff){
    case difficultyEnum::EASY:
      return new EnemyEasy();
    case difficultyEnum::MEDIUM:
      return new EnemyMedium();
    case difficultyEnum::HARD:
      return new EnemyHard();
    default:
      return NULL;
    }
  }
 
 public:
  unordered_map<int,vector<Enemy*> > generateEnemy(difficultyEnum diff){
    unordered_map<int, vector<Enemy*> > enemyMap;
    for(int i = 0;i<40;i++){
      vector<Enemy*> temp;
      enemyMap.emplace(i,temp);
    }
    int numEnemies = GameState::getNumEnemies();
    while(numEnemies > 0){
      Enemy* e = getEnemy(diff);
      enemyMap.at(e->getCurrentPos()).push_back(e);
      --numEnemies;
    }
    return enemyMap;
  }
};
