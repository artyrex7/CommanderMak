#include <unordered_map>
#include <vector>
#include <iostream>
#include "Enemy.h"

using namespace std;

enum difficultyEnum{
  EASY = 1, MEDIUM = 2, HARD = 3
};

class GameState{
 public:
  //unordered_map<int,vector<Enemy> >* getEnemyMap();
  //void setEnemyMap(unordered_map<int,vector<Enemy> >*);
  int getNumEnemies(){return numEnemies;}
  int getRoundsRemaining(){return roundsRemaining;}
  int getFieldWidth(){return fieldWidth;}
  void resetState();
  void decrementRounds(){roundsRemaining--;}
  unordered_map<int,vector<Enemy> >* enemyMap;
 private:
  int numEnemies, roundsRemaining, fieldWidth, enemyDifficulty;
};
