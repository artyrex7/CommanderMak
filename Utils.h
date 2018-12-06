#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include "Enemy.h"

using namespace std;

namespace Utils{
  
  enum difficultyEnum {
    EASY = 1, MEDIUM = 2, HARD = 3
  };

 inline void fillMap(unordered_map<int,vector<Enemy*> >& temp, int field_width){
   for(int i=0;i<field_width;i++){
     vector<Enemy*> t;
     temp.insert({i,t});
   }
 }
 
}
