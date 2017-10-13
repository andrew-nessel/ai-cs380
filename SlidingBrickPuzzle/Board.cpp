
#include "BOARD.h";
using namespace std;
	
Board::Board() {
	loadBoard("C:/Users/Andrew Nessel/Documents/repo/ai-cs380/SlidingBrickPuzzle/test.txt");
}

Board::Board(string filename) {
	loadBoard(filename);
}

Board::Board(const Board& board) {
	Board(); //NOT FINISHED 
}

void Board::printBoard() //prints out board to standard out
{
	for(int x=0; x<matrixLength; x++)
	{
		for(int y=0; y<matrixWidth; y++)
		{
			cout<<Matrix[x][y];
			if ((Matrix[x][y] >= 0) && (Matrix[x][y] < 10))
			{
				cout << " ";
			}
			cout << " ";
		}
		cout<<"\n";
	}
}

void Board::loadBoard(string filename) //loads board from a file
{
	string nextLine, value;
	int length, width, block;
	string delim = ",";
	ifstream infile;
	infile.open (filename);
	getline(infile, nextLine);

	stringstream lineStream(nextLine);
	stringstream newInt;
	getline(lineStream,value,',');
	newInt = stringstream(value);
	newInt >> width;

	getline(lineStream,value,',');
	newInt = stringstream(value);
	newInt >> length;

	initBoard(length,width);

	int x = 0;
	int y = 0;
    while(getline(infile, nextLine))
	{
		stringstream lineStream(nextLine);
		while(getline(lineStream,value,','))
		{
			newInt = stringstream(value);
			newInt >> block;
			Matrix[x][y] = block;
			y++;
		}
		y=0;
		x++;
	}
	infile.close();
}

bool Board::equal(Board board) //checks equality of this board to another
{
	normalize();
	int i;
	board.normalize();

	if (board.Matrix.size() != matrixLength) 
	{
		return false;
	}

	for (int x = 0; x < matrixLength; x++)
	{
		if (board.Matrix[x].size() != matrixWidth)
		{
			return false;
		}

		for (int y = 0; y < matrixWidth; y++)
		{
			if (Matrix[x][y] != board.Matrix[x][y])
			{
				return false;
			}
		}
	}
	return true; 
}

bool Board::solved() //returns whether this board is solved
{
	for(int x = 0; x < matrixLength; x++)
	{
		for (int y = 0; y < matrixWidth; y++) 
		{
			if (Matrix[x][y] == -1) 
			{
				return false;
			}
		}
	}
	return true;
}

bool Board::applyMove(tuple<int, int> move) //applys the given move (block number and direction) to this board
{
	return false; //NOT FINISHED
}

Board Board::applyMoveClone(tuple<int, direction> move) //clones this board and applys the given move (block number and direction) to the new board
{
	return Board(); //NOT FINISHED
}

void Board::initBoard(int length, int width) 
{
	vector<vector<int>> newMatrix(length, vector<int>(width, 0));
	this->Matrix = newMatrix;
	matrixLength = length;
	matrixWidth = width;
}

void Board::normalize() 
{
	int nextIdx = 3;
	for (int x = 0;x < matrixLength;x++) 
	{
		for (int y = 0;y < matrixWidth;y++) 
		{
			if (Matrix[x][y] == nextIdx) 
			{
				nextIdx++;
			}
			else if (Matrix[x][y] > nextIdx) 
			{
				swapIdx(nextIdx, Matrix[x][y]);
				nextIdx++;
			}
		}
	}
}

void Board::swapIdx(int idx1, int idx2) {
	for (int x = 0;x < matrixLength;x++) 
	{
		for (int y = 0;y < matrixWidth;y++) 
		{
			if (Matrix[x][y] == idx1) 
			{
				Matrix[x][y] = idx2;
			}
			else if (Matrix[x][y] == idx2) 
			{
				Matrix[x][y] = idx1;
			}
		}
	}
}

//Board Board::cloneState(Board board){ //utility class for calling without reference
//bool Board::solved(Board board){ //utility class for calling without reference
