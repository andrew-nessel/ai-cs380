#include "SearchNode.h"
using namespace std;

SearchNode::SearchNode()
{
}

SearchNode::SearchNode(Board current, Board parent) {
	currentState = current;
	parentState = parent;
}

Board SearchNode::getParent() {
	return parentState;
}

Board SearchNode::getState() {
	return currentState;
}