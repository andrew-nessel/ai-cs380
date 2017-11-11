
#include "UninformedStateSearch.h"
using namespace std;

UninformedStateSearch::UninformedStateSearch() {
	nodesExplored = 0;
	timeTaken = 0;
}

bool UninformedStateSearch::breathFirstSearch(SearchNode startState) {
	deque<SearchNode> openList = deque<SearchNode>();
	deque<SearchNode>  closedList = deque<SearchNode>();
	SearchNode currentState = startState;
	
	clock_t begin = clock();

	openList.push_back(startState);

	while (!openList.empty()) {
		nodesExplored++; 
		currentState = openList[0];
		openList.pop_front();

		deque<SearchNode> children = currentState.generateChildren();

		for (SearchNode child : children) {
			if (child.getState().solved()) {

				clock_t end = clock();
				timeTaken = double(end - begin);

				printSolution(child);
				return true;
			}
			else if (!dequeSearch(closedList, child) && !dequeSearch(openList, child)) { //child not in closed and not already in open
				openList.push_back(child);
			}
		}
		closedList.push_back(currentState);
	}
	clock_t end = clock();
	timeTaken = double(end - begin);

	cout << "search failed :(";
	return false;
}

bool UninformedStateSearch::depthFirstSearch(SearchNode startState) {
	deque<SearchNode> openList = deque<SearchNode>();
	deque<SearchNode>  closedList = deque<SearchNode>();
	SearchNode currentState = startState;

	clock_t begin = clock();

	openList.push_back(startState);

	while (!openList.empty()) {
		nodesExplored++;
		currentState = openList.back();
		openList.pop_back();
		closedList.push_back(currentState);

		deque<SearchNode> children = currentState.generateChildren();

		for (SearchNode child : children) {
			if (child.getState().solved()) {
				clock_t end = clock();
				timeTaken = double(end - begin);

				printSolution(child);
				return true;
			}
			else if (!dequeSearch(closedList, child) && !dequeSearch(openList, child)) { //child not in closed
				openList.push_back(child);
			}
		}

		closedList.push_back(currentState);
	}

	clock_t end = clock();
	timeTaken = double(end - begin);

	cout << "search failed :(";
	return false;
}

bool UninformedStateSearch::iterativeDeepening(SearchNode startState, int maxDepth) {
	
	int newDepth = 1;

	clock_t begin = clock();

	while(maxDepth >= newDepth) {
		deque<SearchNode> openList = deque<SearchNode>();
		deque<SearchNode> closedList = deque<SearchNode>();
		SearchNode currentState = startState;

		openList.push_back(startState);

		while ((!openList.empty()) && (currentState.getDepth() < newDepth)) {
			nodesExplored++;
			currentState = openList[0];
			openList.pop_front();

			deque<SearchNode> children = currentState.generateChildren();

			for (SearchNode child : children) {
				if (child.getState().solved()) {
					clock_t end = clock();
					timeTaken = double(end - begin);

					printSolution(child);
					return true;
				}
				else if (!dequeSearch(closedList, child) && !dequeSearch(openList, child)) { //child not in closed
					openList.push_back(child);
				}
			}

			closedList.push_back(currentState);
		}

		newDepth++;		
	}
	
	clock_t end = clock();
	timeTaken = double(end - begin);

	cout << "search failed :(";
	return false;
}

bool UninformedStateSearch::dequeSearch(deque<SearchNode> nodeList, SearchNode state) {

	for (SearchNode node : nodeList) {
		if ((node.getState()).equal(state.getState())) {
			return true;
		}
	}

	return false;
}

void UninformedStateSearch::printSolution(SearchNode solutionState) {
	deque<SearchNode> path = deque<SearchNode>();
	SearchNode currentNode = solutionState;
	path.push_back(solutionState);
	int size = 0;

	cout << "\n";
	cout << "Time taken was " << timeTaken/CLOCKS_PER_SEC << " seconds" << endl;
	cout << "Number of nodes explored was " << nodesExplored << endl;

	while (!currentNode.isRoot()) { //reconstruct the path to the solution
		currentNode = currentNode.getParent();
		path.push_back(currentNode);
		size++;
	}


	cout << "Size of the solution was " << size+1 << endl;
	cout << "\n";

	for (int x = size; x >= 0; x--) { //print each part of the path to the solution
		SearchNode child = path[x];
		if (!child.isRoot()) {
			int block = get<0>(child.getMove());
			direction dir = get<1>(child.getMove());
			string strDir = "up";
			if (dir == direction::down){
				strDir = "down";
			}
			else if (dir == direction::left) {
				strDir = "right";
			}
			else if (dir == direction::right) {
				strDir = "left";
			}
			cout << "(";
			cout << block;
			cout << ",";
			cout << strDir;
			cout << ")" << endl;
			cout << "\n";
		}
		child.getState().printBoard();
	}
}
