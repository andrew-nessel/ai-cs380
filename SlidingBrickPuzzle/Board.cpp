
#include "BOARD.h";
	
Board::Board() {

}

Board::Board(string filename) {

}

Board::Board(const Board& board) {

}

void Board::printBoard() { //prints out board to standard out

}

void Board::loadBoard(string filename) { //loads board from a file

}

bool Board::equal(Board board) { //checks equality of this board to another

}

bool Board::solved() { //returns whether this board is solved

}

bool Board::applyMove(tuple<int, int> move) { //applys the given move (block number and direction) to this board

}

Board Board::applyMoveClone(tuple<int, direction> move) { //clones this board and applys the given 
															//move (block number and direction) to the new board

}

void Board::initBoard() {

}

void Board::normalize() {

}

//Board Board::cloneState(Board board){ //utility class for calling without reference
//bool Board::solved(Board board){ //utility class for calling without reference
