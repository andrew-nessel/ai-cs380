
#ifndef SEARCHNODE_H
#define SEARCHNODE_H

#include "Board.h"
#include <string>
#include <stdlib.h>
#include <iostream>
#include <deque>

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
	SearchNode();
	SearchNode(const SearchNode& node);

	SearchNode getParent() const;
	Board getState() const;
	tuple<int, direction> getMove() const;
	int getDepth() const;
	bool isRoot() const;
	deque<SearchNode> generateChildren();

};

#endif
