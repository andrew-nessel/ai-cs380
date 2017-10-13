
#include "BOARD.h";
#include "RANDOMWALK.h";
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

	Board myBoard3("../normalizeTest.txt");

	//myBoard3.normalize();

	cout << "\n\n";
	cout << myBoard3.equal(myBoard2);

	cout << myBoard3.equal(myBoard);
	cout << myBoard2.equal(myBoard3);

	//RandomWalk rando;
	//rando.walk();

	system("PAUSE");
}
