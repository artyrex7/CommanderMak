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

  //calls Player.takeTurn() until GameState.getRounds() == 0
  int rounds_remaining = state->getRoundsRemaining();
  int current_player_pos = 0;
  while (rounds_remaining >= 0) {
    current_player_pos = player->takeTurn();
    rounds_remaining = state->decrementRounds();
    updateEnemyMap(current_player_pos);
  }  
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
  // struct winsize terminal_size;
	// ioctl(STDOUT_FILENO,TIOCGWINSZ, &terminal_size);

  int field_width = state->getFieldWidth();
  string output_str_line_1 = "";

  for (int i=0; i<field_width; i++) {
    output_str_line_1 += to_string(state->enemyMap.at(i).size());
    if (i + 1 != field_width) { //prevent | at end
      output_str_line_1 += " | ";
    }
	}
  output_str_line_1 += "\n";
  
  string output_str_line_2 = "";
  for (int i=0; i<player_pos; i++) {
    output_str_line_2 +=  "    ";
  }
  output_str_line_2 += "↑\n";


  cout << output_str_line_1 << "\n" << output_str_line_2;
}
