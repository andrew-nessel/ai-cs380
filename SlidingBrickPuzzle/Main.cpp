
#include "BOARD.h";
using namespace std;

int main ()
{
	Board myBoard;
	myBoard.printBoard();

	Board myBoard2("../normalizeTest.txt");
	
	cout << "\n";
	myBoard2.printBoard();
	myBoard2.normalize();

	cout << "\n";
	myBoard2.printBoard();

//	Board myBoard3("C:/Users/Andrew Nessel/Documents/repo/ai-cs380/SlidingBrickPuzzle/normalizeTest.txt");

//	myBoard3.normalize();

//	cout << "\n\n";
//	cout << myBoard3.equal(myBoard2);
	system("PAUSE");
}
