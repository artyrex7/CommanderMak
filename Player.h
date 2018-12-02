#pragma once

#include <iostream>

using namespace std;

class Player{
    public:
        Player(int max=0, int position=20, int width=40);
        int takeTurn();
    private:
        void move(int);
        int currentPos;
        int fieldWidth;
        int maxMoves;
};
