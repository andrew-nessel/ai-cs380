
#include "Board.h"
#include "RandomWalk.h"
using namespace std;

int main (int argc, char *argv[])
{

	//string filename(argv[0]);
	//string filename;
	//stringstream newString;
	//newString << argv[0];
	//newString >> filename;

	//int walkLimit;
	//stringstream newInt;
	//newInt << argv[1];
	//newInt >> walkLimit;

	RandomWalk rando(5, "test.txt");
	rando.walk();
}
