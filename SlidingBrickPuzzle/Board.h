
#ifndef BOARD_H
#define BOARD_H

#include <vector>;
#include <string>;
#include <tuple>;
using namespace std;

enum direction {up, down, right, left};


class Board {

private:
	vector<vector<int>> Matrix;
	void initBoard();
	void normalize();

public:
	Board(); //contructors
	Board(string filename);
	Board(const Board& board);

	void printBoard(); //prints out board to standard out
	void loadBoard(string filename); //loads board from a file
	bool equal(Board board); //checks equality of this board to another
	bool solved(); //returns whether this board is solved
	bool applyMove(tuple<int,int> move); //applys the given move (block number and direction) to this board
	Board applyMoveClone(tuple<int, direction> move); //clones this board and applys the given move (block number and direction) to the new board
	
	//Board cloneState(Board board); //utility class for calling without reference
	//bool solved(Board board); //utility class for calling without reference

};

#endif