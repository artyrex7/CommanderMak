#pragma once

#include <iostream>

using namespace std;

class Player{
    public:
        Player(int max=1, int position=20, int width=40);
        int takeTurn();
        int getPlayerPos();
    private:
        void move(int);
        int currentPos;
        int fieldWidth;
        int maxMoves;
};
