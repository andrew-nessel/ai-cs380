
#include "UninformedStateSearch.h";
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
	return false;
}

bool UninformedStateSearch::iterativeDeepening(SearchNode startState) {
	return false;
}

bool UninformedStateSearch::vectorSearch(vector<SearchNode> nodeList, SearchNode state) {

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
	path.insert(path.begin(), solutionState);

	int x = 10;

	//while (!currentNode.isRoot()) {
	while(x>0){
		SearchNode newNode = currentNode.getParent();
		currentNode = newNode;
		path.insert(path.begin(), currentNode);
		currentNode.getState().printBoard();
		x--;
	}

	//for (SearchNode child : path) {
		//child.getState().printBoard();
		//if (!child.isRoot()) {
		//	int block = get<0>(child.getMove());
		//	direction dir = get<1>(child.getMove());
		//	cout << "\n";
		//	cout << block;
		//	cout << ",";
		//	cout << dir << endl;
		//}
		//cout << "\n";
	//}
}
