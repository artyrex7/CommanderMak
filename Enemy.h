#pragma once

#include <iostream>

using namespace std;

class Enemy{
 public:
  int getCurrentPos();
  int getMaxMoves();
  virtual int move(int max_fields) = 0;
  int currentPos;
  int maxMoves;
};
