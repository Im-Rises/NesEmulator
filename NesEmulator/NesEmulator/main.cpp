#include <iostream>

#include "Nes.h"

using namespace std;

int main()
{
	cout << PROJECT_NAME << " " << VER << " by " << AUTHOR << endl;

	Nes* nes = Nes::getInstance();

	return 0;
}