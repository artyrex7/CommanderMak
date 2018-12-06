#pragma once

#include "Enemy.h"

class EnemyEasy : public Enemy {
 public:
  EnemyEasy(int fieldWidth);
  int move(int max_fields);
};
