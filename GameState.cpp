#include "GameState.h"

void GameState::resetState(){

}

difficultyEnum GameState::getDifficulty() {
    return enemyDifficulty;
}

int GameState::getRoundsRemaining() {
    return roundsRemaining;
}

int GameState::getFieldWidth(){
    return fieldWidth;
}

int GameState::decrementRounds() {
    return --roundsRemaining;
}

int GameState::getNumEnemies() {
    return numEnemies;
}