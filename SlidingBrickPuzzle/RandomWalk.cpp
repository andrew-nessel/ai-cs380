
#include "RandomWalk.h"
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

	currentState.printBoard();

	cout << "\n";

	for (int x = 0; x < maxMoves; x++)
	{
		moveList = currentState.generateMoves();

		if (moveList.empty()) 
		{
			return false;
		}

		int random = rand() % moveList.size();

		tuple<int, direction> move = moveList[random];

		currentState.applyMove(move);

		int block = get<0>(move);
		direction dir = get<1>(move);
		string str;

		if (dir == direction::up) { //these just take the direction and make it a numerial relative to (x, y) coordinates
			str = "up";
		}
		else if (dir == direction::down) {
			str = "down";
		}
		else if (dir == direction::right) {
			str = "left";
		}
		else if (dir == direction::left) {
			str = "right";
		}

		cout << to_string(block) + "," + str + "\n\n";

		currentState.normalize();
		currentState.printBoard();
		cout << "\n";

		if (currentState.solved()) 
		{
			return true;
		}

	}

	return currentState.solved();
}