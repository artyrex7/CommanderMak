#include "GameState.h"
#include "GameClient.h"
#include <iostream>


using namespace std;

int main() {
  srand(time(NULL));
	int num_enemies;
	int rounds;
	int field_width;
	cout << "Welcome, COMMANDER MAK" << endl;
	
	//get num enemies
	while (true) {
		cout << "How many enemies will you take on?: ";
		cin >> num_enemies;
		if (cin.fail()) {
				cout << "ERROR: INVALID INPUT";
		} else {
			break;
		}
	}

	//get num rounds
	while (true) {
		cout << "How many rounds?: ";
		cin >> rounds;
		if (cin.fail()) {
				cout << "ERROR: INVALID INPUT";
		} else {
			break;
		}
	}

	//get field width
	while (true) {
		cout << "How many columns is your battlefield?: ";
		cin >> field_width;
		if (cin.fail()) {
				cout << "ERROR: INVALID INPUT";
		} else {
			break;
		}
	}

	GameState state(num_enemies, rounds, field_width);
	GameClient client(&state);

	client.startGame();
    
    return 0;
}
