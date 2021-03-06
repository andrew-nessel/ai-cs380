
#include "Board.h"
#include "SearchNode.h"
#include "UninformedStateSearch.h"
#include <sstream>
using namespace std;

int main (int argc, char *argv[])
{
	string filename = "../SBP-level2.txt";
	//string filename = argv[1];

	SearchNode startState = SearchNode(Board(filename));
	UninformedStateSearch searchFunc = UninformedStateSearch();

	string searchType = "id";
	//string searchType = argv[2];

	if (searchType == "bfs") {
		searchFunc.breathFirstSearch(startState);
	}
	else if (searchType == "dfs") {
		searchFunc.depthFirstSearch(startState);
	}
	else if (searchType == "id") {
		//string deep = argv[3];
		//stringstream num(deep);
		int depth = 20;
		//num >> depth;

		searchFunc.iterativeDeepening(startState, depth);
	}
	else {
		cout << "Please choose between 'bfs' 'dfs' and 'id' or read the readme included";
	}
	system("pause");
}
