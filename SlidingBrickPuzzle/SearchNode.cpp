#include "SearchNode.h"
using namespace std;

SearchNode::SearchNode(Board current, SearchNode parent, tuple<int, direction> move, int d) {
	currentState = current;
	parentState = &parent;
	root = false;
	usedMove = move;
	depth = d;
}

SearchNode::SearchNode(Board current) { //if you don't send it a parent it assumes you are giving the root, plus it hopes you don't call getParent() cause you might break
	currentState = current;
	root = true;
	depth = 0;
}

SearchNode SearchNode::getParent() {
	return *parentState;
}

Board SearchNode::getState() {
	return currentState;
}

tuple<int, direction> SearchNode::getMove() {
	return usedMove;
}

int SearchNode::getDepth() {
	return depth;
}

bool SearchNode::isRoot() {
	return root;
}

vector<SearchNode> SearchNode::generateChildren() {
	vector<tuple<int, direction>> moves = currentState.generateMoves();
	vector<SearchNode> children;
	SearchNode* me = this;

	if (!root) {
		//SearchNode rent = *parentState;
		//rent.getState().printBoard();
	}

	for (tuple<int, direction> move : moves) {
		children.push_back(SearchNode(currentState.applyMoveClone(move), *me, move, depth + 1));
	}

	return children;
}
