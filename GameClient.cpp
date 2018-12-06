#include "GameClient.h"
#include "Enemy.h"
#include <unordered_map>
#include <string>
#include <sys/ioctl.h>
#include <unistd.h>

GameClient::GameClient(GameState* state_in){
  state = state_in;
  player = new Player(5, state->getFieldWidth()/2, state->getFieldWidth());
  factory = new EnemyFactory();
  state->enemyMap = factory->generateEnemies(state->getDifficulty(), state->getNumEnemies(), state->getFieldWidth());
}

void GameClient::startGame(){
  //constructs/sets enemyMap
  unordered_map<int, vector<Enemy*> > new_map = factory->generateEnemies(state->getDifficulty(), state->getNumEnemies(), state->getFieldWidth());

  
  int rounds_remaining = state->getRoundsRemaining();
  int current_player_pos = player->getPlayerPos();

  //Print intiial state
  printGameState(current_player_pos);

  //calls Player.takeTurn() until GameState.getRounds() == 0
  while (rounds_remaining >= 0) {
    current_player_pos = player->takeTurn();
    rounds_remaining = state->decrementRounds();
    updateEnemyMap(current_player_pos);
    if (state->getNumEnemies() == 0) {
      cout << "ENEMIES DEFEATED." << endl;
      cout << "EXITING SIMULATION" << endl;
      break;
    }
  }
  cout << "YOU NEED MORE PRACTICE, PROFESSOR MAK." << endl;
  cout << "EXITING SIMULATION." << endl;
}

void GameClient::updateEnemyMap(int player_pos){
  //updateEnemyPos(), shoot in row of Player.currentPos
  unordered_map<int, vector<Enemy*> > current_map, new_map;
  current_map = state->enemyMap;
  int field_width = state->getFieldWidth();
  //initialize new blank map of vectors
  for (int i = 0; i<field_width; i++) {
    vector<Enemy*> new_vector;
    new_map.insert({i, new_vector});
  }

  //populate new map with updated positions of moved enemies.
  for (int i = 0; i<field_width; i++) {
    if (i != player_pos) {
      for (auto* enemy : current_map.at(i)) {
        int new_enemy_position = enemy->move(field_width);
        new_map.at(new_enemy_position).push_back(enemy);
      }
    }
    else {
      state->killEnemies(current_map.at(i).size());
    }
  }
  
  state->enemyMap = new_map;
  printGameState(player_pos);
}

/*
Desired output of this function:
_
1 | 2 | 5 | 0 | 5 | ...

            ↑
_

Top row is the number of enemies in a position
Bottom row is position of the player.
*/
void GameClient::printGameState(int player_pos){
  struct winsize terminal_size;
	ioctl(STDOUT_FILENO,TIOCGWINSZ, &terminal_size);

  int field_width = state->getFieldWidth();
  string output_str = "";

  /*
  Print spacing:
    Enemy list takes 1 row
    Current Player position takes 1 row
    Game Status takes 1 row
    New input field takes 1 row
  */

  // Print enemies
  for (int i=0; i<field_width; i++) {
    output_str += (i == player_pos ? "*" : to_string(state->enemyMap.at(i).size()));
    if (i + 1 != field_width) { //prevent | at end
      output_str += " | ";
    }
	}
  output_str += "\n";
  
  // Print lazer
  for (int i=0; i<terminal_size.ws_row-4; i++) {
    for (int j=0; j<player_pos; j++) {
      output_str +=  "    ";
    }
    output_str +=  "|\n";
  }


  // Print user
  for (int i=0; i<player_pos; i++) {
    output_str +=  "    ";
  }
  output_str += "↑\n";

  // Print game status
  output_str += "Enemies Left: " + to_string(state->getNumEnemies()) + " | ";
  output_str += "Rounds Remaining: " + to_string(state->getRoundsRemaining()) + "\n";

  cout << output_str;
}