#include "GameState.h"
#include "GameClient.h"
#include <iostream>


using namespace std;

int main() {
  srand(time(NULL));
	GameState state(20, 5, 40);
	GameClient client(&state);

	client.startGame();
    
    return 0;
}
