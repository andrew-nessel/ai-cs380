#include "SearchNode.h"
using namespace std;

SearchNode::SearchNode(Board current, SearchNode parent, tuple<int, direction> move, int d) {
	currentState = current;
	SearchNode* newParent = new SearchNode(parent);
	parentState = newParent;
	root = false;
	usedMove = move;
	depth = d;
}

SearchNode::SearchNode(Board current) { //if you don't send it a parent it assumes you are giving the root, plus it hopes you don't call getParent() cause you might break
	currentState = current;
	root = true;
	depth = 0;
	parentState = new SearchNode();
}

SearchNode::SearchNode() { //if you don't send it a parent it assumes you are giving the root, plus it hopes you don't call getParent() cause you might break
	currentState = Board();
	root = true;
	depth = 0;
}


SearchNode::SearchNode(const SearchNode& node) {

	currentState = node.getState();
	root = node.isRoot();

	if (!root) {
		SearchNode* newParent = new SearchNode(node.getParent());
		parentState = newParent;
	}

	usedMove = node.getMove();
	depth = node.getDepth();
}

SearchNode SearchNode::getParent() const {
	if (root) {
		return SearchNode();
	}
	return *parentState;
}

Board SearchNode::getState() const {
	return currentState;
}

tuple<int, direction> SearchNode::getMove() const {
	return usedMove;
}

int SearchNode::getDepth() const {
	return depth;
}

bool SearchNode::isRoot() const {
	return root;
}

deque<SearchNode> SearchNode::generateChildren() {
	vector<tuple<int, direction>> moves = currentState.generateMoves();
	deque<SearchNode> children;
	SearchNode* me = this;

	if (!root) {
		//SearchNode rent = *parentState;
		//rent.getState().printBoard();
	}

	for (tuple<int, direction> move : moves) {
		SearchNode newNode = SearchNode(currentState.applyMoveClone(move), *me, move, depth + 1);
		children.push_back(newNode);
	}

	return children;
}
