#ifndef UNINFORMEDSTATESEARCH_H
#define UNINFORMEDSTATESEARCH_H

#include "Board.h";
#include "SearchNode.h";
#include <string>;
#include <stdlib.h>;
#include <iostream>;
#include <vector>;
#include <algorithm>;

using namespace std;

class UninformedStateSearch {

public:

	UninformedStateSearch();

	bool breathFirstSearch(SearchNode startState);
	bool depthFirstSearch(SearchNode startState);
	bool iterativeDeepening(SearchNode startState);

	bool vectorSearch(vector<SearchNode> nodeList, SearchNode state);
	void printSolution(SearchNode solutionState);

};

#endif