
#include "RANDOMWALK.h";
using namespace std;

RandomWalk::RandomWalk() 
{
	maxMoves = 10;
	currentState = Board();
}

RandomWalk::RandomWalk(int moves, string filename)
{
	maxMoves = moves;
	currentState = Board(filename);
}

bool RandomWalk::walk()
{
	srand(time(NULL));
	vector<tuple<int, direction>> moveList;

	for (int x = 0; x < maxMoves; x++)
	{
		moveList = currentState.generateMoves();

		if (moveList.empty()) 
		{
			return false;
		}

		int random = rand() % moveList.size();

		currentState.applyMove(moveList[random]);
		currentState.printBoard();
		cout << "\n\n";
	}

	return currentState.solved();
}