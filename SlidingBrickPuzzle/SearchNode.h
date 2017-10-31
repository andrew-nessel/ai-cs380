
#ifndef SEARCHNODE_H
#define SEARCHNODE_H

#include "Board.h";
#include <string>;
#include <stdlib.h>;
#include <iostream>;

using namespace std;

class RandomWalk {

private:
	Board parentState;
	Board currentState;

public:

	SearchNode();
	SearchNode(Board current, Board parent);

	Board getParent();
	Board getState();

};

#endif
