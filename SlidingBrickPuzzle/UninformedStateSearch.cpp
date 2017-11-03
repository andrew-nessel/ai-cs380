
#include "UninformedStateSearch.h"
using namespace std;

UninformedStateSearch::UninformedStateSearch() {
}

bool UninformedStateSearch::breathFirstSearch(SearchNode startState) {
	vector<SearchNode> openList = vector<SearchNode>();
	vector<SearchNode> closedList = vector<SearchNode>();
	SearchNode currentState = startState;

	openList.push_back(startState);

	while (!openList.empty()) {
		currentState = openList[0];
		openList.erase(openList.begin());
		closedList.push_back(currentState);

		vector<SearchNode> children = currentState.generateChildren();

		for (SearchNode child : children) {
			if (child.getState().solved()) {
				printSolution(child);
				return true;
			}
			else if (!vectorSearch(closedList, child)) { //child not in closed
				openList.push_back(child);
			}
		}
	}

	return false;
}

bool UninformedStateSearch::depthFirstSearch(SearchNode startState) {
	vector<SearchNode> openList = vector<SearchNode>();
	vector<SearchNode> closedList = vector<SearchNode>();
	SearchNode currentState = startState;

	openList.push_back(startState);

	while (!openList.empty()) {
		currentState = openList.back();
		openList.pop_back();
		closedList.push_back(currentState);

		vector<SearchNode> children = currentState.generateChildren();

		for (SearchNode child : children) {
			if (child.getState().solved()) {
				printSolution(child);
				return true;
			}
			else if (!vectorSearch(closedList, child)) { //child not in closed
				openList.push_back(child);
			}
		}
	}

	return false;
}

bool UninformedStateSearch::iterativeDeepening(SearchNode startState, int maxDepth) {
	
	int newDepth = 1;

	while(maxDepth >= newDepth) {
		vector<SearchNode> openList = vector<SearchNode>();
		vector<SearchNode> closedList = vector<SearchNode>();
		SearchNode currentState = startState;

		openList.push_back(startState);

		while ((!openList.empty()) && (currentState.getDepth() < newDepth)) {
			currentState = openList[0];
			openList.erase(openList.begin());
			closedList.push_back(currentState);

			vector<SearchNode> children = (currentState).generateChildren();

			for (SearchNode child : children) {
				if (child.getState().solved()) {
					printSolution(child);
					return true;
				}
				else if (!vectorSearch(closedList, child)) { //child not in closed
					openList.push_back(child);
				}
			}
		}

		newDepth++;		
	}
	
	return false;
}

bool UninformedStateSearch::vectorSearch(const vector<SearchNode>& nodeList, SearchNode state) {

	for (SearchNode node : nodeList) {
		if (node.getState().equal(state.getState())) {
			return true;
		}
	}

	return false;
}

void UninformedStateSearch::printSolution(SearchNode solutionState) {
	vector<SearchNode> path = vector<SearchNode>();
	SearchNode currentNode = solutionState;
	path.push_back(solutionState);

	//cout << "We solved it!!!1!1!";
	//solutionState.getState().printBoard(); //this is a placeholder for the actual print solution 

	while (!currentNode.isRoot()) { //reconstruct the path to the solution
		currentNode = currentNode.getParent();
		//path.push_back(currentNode);
		//currentNode.getState().printBoard();
		//x--;
	}

	for (int x = path.size()-1; x >=0; x--) { //print each part of the path to the solution
		SearchNode child = path[x];
		child.getState().printBoard();
		if (!child.isRoot()) {
			int block = get<0>(child.getMove());
			direction dir = get<1>(child.getMove());
			cout << "\n";
			cout << block;
			cout << ",";
			cout << dir << endl;
		}
		cout << "\n";
	}
}
