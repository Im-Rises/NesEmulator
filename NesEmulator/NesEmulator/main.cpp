#include <iostream>

#include "Nes.h"

int main(int argc, char* argv[])
{
	std::cout << PROJECT_NAME << " " << VER << " by " << AUTHOR << std::endl;

	if (argc > 1)
	{
		std::string romPath = argv[1];
		Nes* nes = Nes::getInstance(romPath);
	}

	return 0;
}