
#ifndef SEARCHNODE_H
#define SEARCHNODE_H

#include "Board.h";
#include <string>;
#include <stdlib.h>;
#include <iostream>;

using namespace std;

class SearchNode {

private:
	SearchNode* parentState;
	Board currentState;
	tuple<int, direction> usedMove;
	int depth;
	bool root;

public:

	SearchNode(Board current, SearchNode parent, tuple<int, direction> move, int d);
	SearchNode(Board current);

	SearchNode getParent();
	Board getState();
	tuple<int, direction> getMove();
	int getDepth();
	bool isRoot();
	vector<SearchNode> generateChildren();

};

#endif
