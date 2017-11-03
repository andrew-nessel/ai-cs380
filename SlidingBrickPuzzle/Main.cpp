
#include "Board.h"
#include "SearchNode.h"
#include "UninformedStateSearch.h"
#include <sstream>
using namespace std;

int main (int argc, char *argv[])
{
	string filename = "../test.txt";
	//string filename = argv[1];

	//cout << argv[1] << endl;
	//cout << argv[2] << endl;

	SearchNode startState = SearchNode(Board(filename));
	UninformedStateSearch searchFunc = UninformedStateSearch();

	string searchType = "bfs";
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
		int depth = 10;
		//num >> depth;

		searchFunc.iterativeDeepening(startState, depth);
	}
	else {
		cout << "Please choose between 'bfs' 'dfs' and 'id' or read the readme included";
	}
}
