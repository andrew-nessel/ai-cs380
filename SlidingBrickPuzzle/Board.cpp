
#include "BOARD.h";
	
Board::Board() {
	loadBoard("test.txt");
}

Board::Board(string filename) {
	loadBoard(filename);
}

Board::Board(const Board& board) {
	Board(); //NOT FINISHED 
}

void Board::printBoard() //prints out board to standard out
{
	int length = Matrix.size();
	int width = Matrix[0].size();
	for(int x=0; x<length; x++)
	{
		for(int y=0; y<width; y++)
		{
			cout<<Matrix[x][y];
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
	newInt >> length;

	getline(lineStream,value,',');
	newInt = stringstream(value);
	newInt >> width;
	initBoard(length,width);

	int x = 0;
	int y = 0;
    while(!infile.eof())
	{
		getline(infile,nextLine);
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
	return false; //NOT FINISHED
}

bool Board::solved() //returns whether this board is solved
{
	return false; //NOT FINISHED
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
	std::vector<std::vector<int>> array_2d(length, std::vector<int>(width, 0));
	//Matrix = vector<vector<int>>(length);
	//for (int x=0; x<length; x++)
	//{
		//Matrix[x] = vector<int>(width);
	//}
}

void Board::normalize() 
{
	return; //NOT FINISHED
}

//Board Board::cloneState(Board board){ //utility class for calling without reference
//bool Board::solved(Board board){ //utility class for calling without reference
