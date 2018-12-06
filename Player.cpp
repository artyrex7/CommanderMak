#include "Player.h"

Player::Player(int max, int position, int width) : maxMoves(max), currentPos(position), fieldWidth(width) {}

int Player::takeTurn(){
    int move_count;
    bool valid_input = false;
    int new_pos = 0;

    while (!valid_input) {
        cout << "How much would you like to move? Positive for right, negative for left (Max: " << maxMoves << "): ";
        cin >> move_count;

        /*
        needs to be fixed later. If user is left and moves more 
        than the left bound, just sticks to 0. Right rotation 
        works fine though.
        */
        if (move_count <= maxMoves) {
            new_pos = (currentPos + move_count) % fieldWidth;
            valid_input = true;
        } else {
            cout << "ERROR. Invalid Input." << endl;
        }
    }
    move(new_pos);
    return currentPos;
}

void Player::move(int new_pos) {
    currentPos = new_pos;
}