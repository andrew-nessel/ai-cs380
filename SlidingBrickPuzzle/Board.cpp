
#include "Board.h"
using namespace std;
	
Board::Board() { //just calling the board without a file value opens the standard test board
	initBoard(0, 0);
}

Board::Board(string filename) {
	loadBoard(filename);
}

Board::Board(const Board& board) { //this creates a copy of the board sent in
	//just copies the values in the boards matrix
	vector<vector<int>> oldMatrix = board.getMatrix();

	int length = oldMatrix.size();
	int width = 0;

	if (length > 0) {
		width = oldMatrix[0].size();
	}

	initBoard(length, width);

	for (int x = 0; x < length; x++)
	{
		for (int y = 0; y < width; y++) 
		{
			Matrix[x][y] = oldMatrix[x][y];
		}
	}

}

void Board::printBoard() //prints out board to standard out
{ //just prints out every value in the matrix
	string str;
	str = to_string(matrixWidth) + "," + to_string(matrixLength) + "\n";

	for(int x=0; x<matrixLength; x++)
	{
		for(int y=0; y<matrixWidth; y++)
		{
			str += to_string(Matrix[x][y]);
			if ((Matrix[x][y] >= 0) && (Matrix[x][y] < 10)) //this adds an extra space to numbers that are 1 length to keep the blocks lined up (for blocks < 100)
			{
				str += " ";
			}
			str += " ";
		}
		str += "\n";
	}

	cout << str << endl;
}

void Board::loadBoard(string filename) //loads board from a file
{
	string nextLine, value;
	int length, width, block;
	string delim = ",";
	ifstream infile;
	infile.open(filename);

	if(!infile.is_open())
	{
		cout << "Problem reading file, does it exist?";
		return;
	}

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
	board.normalize();

	if ((board.matrixLength != matrixLength) || (board.matrixWidth != matrixWidth))
	{
		return false;
	}

	for (int x = 0; x < matrixLength; x++)
	{
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

bool Board::applyMove(tuple<int, direction> move) //applys the given move (block number and direction) to this board
{//get each of the coordinates for the block and than change the values at the appropriate places

	if (!validMove(move)) //if the move isn't valid just leave
	{
		return false;
	}

	int block = get<0>(move);
	direction dir = get<1>(move);
	int ymove = 0;
	int xmove = 0;

	if (dir == direction::up) { //these just take the direction and make it a numerial relative to (x, y) coordinates
		xmove = -1;
	}
	else if (dir == direction::down) {
		xmove = 1;
	}
	else if (dir == direction::right) {
		ymove = -1;
	}
	else if (dir == direction::left) {
		ymove = 1;
	}
	
	vector<tuple<int, int>> blockCoordinates;

	for (int x = 0; x < matrixLength; x++) //grab all the coordinates that the block is located on
	{
		for (int y = 0; y < matrixWidth; y++)
		{
			if (Matrix[x][y] == block)
			{
				blockCoordinates.push_back(make_tuple(x, y));
			}
		}
	}

	for (tuple<int, int> coor : blockCoordinates) //for each of the block coordinates make that spot free and move the block to its new location
	{
		int x = get<0>(coor);
		int y = get<1>(coor);
		Matrix[x][y] = 0;
	}

	for (tuple<int, int> coor : blockCoordinates) //for each of the block coordinates make that spot free and move the block to its new location
	{
		int x = get<0>(coor);
		int y = get<1>(coor);
		Matrix[x + xmove][y + ymove] = block;
	}

	return true;
	
}

Board Board::applyMoveClone(tuple<int, direction> move) //clones this board and applys the given move (block number and direction) to the new board
{//clone the board with the copy constructor and then call new boards applxmove
	
	Board newBoard = Board(*this);

	newBoard.applyMove(move);

	return newBoard;
}

bool Board::validMove(tuple<int, direction> move)
{
	int block = get<0>(move);
	direction dir = get<1>(move);
	int ymove = 0;
	int xmove = 0;

	if (dir == direction::up) { //these just take the direction and make it a numerial relative to (x, y) coordinates
		xmove = -1;
	}
	else if (dir == direction::down) {
		xmove = 1;
	}
	else if (dir == direction::right) {
		ymove = -1;
	}
	else if (dir == direction::left) {
		ymove = 1;
	}

	for (int x = 0; x < matrixLength; x++) //check the new spot the block will be, if that spot isn't free or contain part of the block then move is impossible (special case where block is 2 moving into the -1 spot)
	{
		for (int y = 0; y < matrixWidth; y++)
		{
			if (Matrix[x][y] == block)
			{
				if (block == 2) 
				{
					if (((Matrix[x + xmove][y + ymove] != 0) && (Matrix[x + xmove][y + ymove] != -1) && (Matrix[x + xmove][y + ymove] != block)))
					{
						return false;
					}
				}
				else if ((Matrix[x + xmove][y + ymove] != 0) && (Matrix[x + xmove][y + ymove] != block))
				{
					return false;
				}
			}
		}
	}

	return true;
}

vector<tuple<int, direction>> Board::generateMoves() //returns a list of all available valid moves
{//get every block number and check if every block + number combo is valid and return a list of the valid ones
	vector<int> closedList;
	vector<tuple<int, direction>> availableMoves;

	for (int x = 0; x < matrixLength; x++) 
	{
		for (int y = 0; y < matrixWidth; y++)
		{
			if (Matrix[x][y] > 1)
			{
				if (closedList.empty() || (!(std::find(closedList.begin(), closedList.end(), Matrix[x][y]) != closedList.end()))) //if closed list is empty or block is not in the closedList
				{
					tuple<int, direction> up = make_tuple(Matrix[x][y], direction::up);
					tuple<int, direction> down = make_tuple(Matrix[x][y], direction::down);
					tuple<int, direction> left = make_tuple(Matrix[x][y], direction::left);
					tuple<int, direction> right = make_tuple(Matrix[x][y], direction::right);

					if (validMove(up)) {
						availableMoves.push_back(up);
					}
					if (validMove(down)) {
						availableMoves.push_back(down);
					}
					if (validMove(left)) {
						availableMoves.push_back(left);
					}
					if (validMove(right)) {
						availableMoves.push_back(right);
					}
				}
			}
		}
	}

	return availableMoves;
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

vector<vector<int>> Board::getMatrix() const {
	return Matrix;
}

//Board Board::cloneState(Board board){ //utility class for calling without reference
//bool Board::solved(Board board){ //utility class for calling without reference
