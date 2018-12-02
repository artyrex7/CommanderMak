#pragma once

#include "Enemy.h"

class EnemyEasy : public Enemy {
public:
    EnemyEasy();
    int move(int max_fields);
};
