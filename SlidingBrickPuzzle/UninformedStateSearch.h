#ifndef UNINFORMEDSTATESEARCH_H
#define UNINFORMEDSTATESEARCH_H

#include "Board.h"
#include "SearchNode.h"
#include <string>
#include <stdlib.h>
#include <iostream>
#include <ctime>

using namespace std;

class UninformedStateSearch {

private:
	int nodesExplored;
	double timeTaken;

public:

	UninformedStateSearch();

	bool breathFirstSearch(SearchNode startState);
	bool depthFirstSearch(SearchNode startState);
	bool iterativeDeepening(SearchNode startState, int maxDepth);

	bool dequeSearch(deque<SearchNode> nodeList, SearchNode state);
	void printSolution(SearchNode solutionState);

};

#endif