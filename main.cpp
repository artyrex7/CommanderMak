#include "GameState.h"
#include "GameClient.h"
#include <iostream>


using namespace std;

int main() {
	GameState state(20, 5, 40);
	GameClient client(&state);

	client.startGame();
    
    return 0;
}