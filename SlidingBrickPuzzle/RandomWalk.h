
#ifndef RANDOMWALK_H
#define RANDOMWALK_H

#include "Board.h"
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

class RandomWalk {

public:
	int maxMoves;
	Board currentState;

	RandomWalk();
	RandomWalk(int moves, string filename);

	bool walk();

};

#endif