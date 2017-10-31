
#include "Board.h"
#include "SearchNode.h"
#include "UninformedStateSearch.h"
using namespace std;

int main (int argc, char *argv[])
{
	string filename = "../test.txt";
	//filename = argv[1];
	SearchNode startState = SearchNode(Board(filename));
	UninformedStateSearch searchFunc = UninformedStateSearch();

	string searchType = "bfs";
	//searchType = argv[2];

	if (searchType == "bfs") {
		searchFunc.breathFirstSearch(startState);
	}
	else if (searchType == "dfs") {
		searchFunc.depthFirstSearch(startState);
	}
	else if (searchType == "id") {
		searchFunc.iterativeDeepening(startState);
	}
	else {
		cout << "Please choose between 'bfs' 'dfs' and 'id' or read the readme included";
	}

	system("PAUSE");
}
