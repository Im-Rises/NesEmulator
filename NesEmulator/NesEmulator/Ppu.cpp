#include "Ppu.h"

#include <iostream>

#include "Bus.h"
#include "PpuBus.h"
#include "SDL2/include/SDL.h"

Ppu::Ppu()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cout << "Error SDL video init.\n" << SDL_GetError() << std::endl;
		//stopSdl();
		exit(EXIT_FAILURE);
	}

	//if (SDL_CreateWindowAndRenderer(windowWidth, windowHeight, SDL_WINDOW_SHOWN, &window, &renderer) != 0)
	//{
	//	std::cout << "Error window creation.\n" << SDL_GetError() << std::endl;
	//	//stopSdl();
	//	exit(EXIT_FAILURE);
	//}
}

Ppu::~Ppu()
{
	//if (NULL != renderer)
	//{
	//	SDL_DestroyRenderer(renderer);
	//}

	//if (NULL != window)
	//{
	//	SDL_DestroyWindow(window);
	//}

	SDL_Quit();
}

void Ppu::connectToBus(Bus* bus)
{
	this->bus = bus;
}

void Ppu::connectToPpuBus(PpuBus* ppuBus)
{
	this->ppuBus = ppuBus;
}


uint8 Ppu::readPpu(const uint16& address)
{
	switch (address % 8)
	{
	case(0x0000):
	{
		break;
	}
	case(0x0001):
	{
		break;
	}
	case(0x0002):
	{
		break;
	}
	case(0x0003):
	{
		break;
	}
	case(0x0004):
	{
		break;
	}
	case(0x0005):
	{
		break;
	}
	case(0x0006):
	{
		break;
	}
	case(0x0007):
	{
		break;
	}
	default:
	{
		break;
	}
	}

	return 0;
}

void Ppu::write(const uint16& address, const uint8& data)
{
	//address % 8
}



//// Main bus read/write
//uint8 Ppu::readCpuBus(const uint16& address)
//{
//	bus->read(address);
//}
//
//void Ppu::writeCpuBus(const uint16& address, const uint8& data)
//{
//	bus->write(address, data);
//}


//// Ppu bus read/write
//uint8 Ppu::readCpuBus(const uint16& address)
//{
//
//}
//
//void Ppu::writeCpuBus(const uint16& address, const uint8& data)
//{
//
//}