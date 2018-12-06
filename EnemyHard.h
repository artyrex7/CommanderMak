#pragma once

#include "Enemy.h"

class EnemyHard : public Enemy {
public:
    EnemyHard(int fieldWidth);
    int move(int max_fields);
};
