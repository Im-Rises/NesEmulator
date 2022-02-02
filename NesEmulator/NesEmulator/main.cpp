#include <iostream>

#include "Nes.h"

int main()
{
	std::cout << PROJECT_NAME << " " << VER << " by " << AUTHOR << std::endl;

	Nes* nes = Nes::getInstance();

	return 0;
}