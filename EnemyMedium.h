#pragma once

#include "Enemy.h"

class EnemyMedium : public Enemy {
public:
    EnemyMedium();
    int move(int max_fields);
};
