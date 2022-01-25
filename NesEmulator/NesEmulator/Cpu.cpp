#include "Cpu.h"

#include "Bus.h"
#include <iostream>

using namespace std;

Cpu::Cpu()
{
	pc.reg = 0;
	sp.reg = 0;
	status.reg = 0;
	A = X = Y = 0;
	cycles = 0;
}

void Cpu::connectBus(Bus* bus)
{
	this->bus = bus;
}

uint8 Cpu::read(const uint16& address)
{
	return bus->read(address);
}

void Cpu::write(const uint16& address, const uint8& data)
{
	bus->write(address, data);
}

uint8 Cpu::fetchOpcode()
{
	return pc.reg++;
}

void executeOpcode()
{
	//Switch or structure function pointer ?
}



uint8 Cpu::Accum()
{

}

uint8 Cpu::IMM()
{
	return read(pc.reg++);
}

uint16 Cpu::Absolute()
{
	uint8 lo = read(pc.reg++);
	return ((read(pc.reg++) << 8) | lo);
}

uint16 Cpu::ZP()
{
	return read(pc.reg++);
}

uint8 Cpu::ZPX()
{
	return (read(pc.reg++) + X);
}

uint8 Cpu::ZPY()
{
	return (read(pc.reg++) + Y);
}

uint8 Cpu::ABSX()
{
	uint8 lo = read(pc.reg++);
	return ((((read(pc.reg++) << 8) | lo) + X) & 0x00FF);
}

uint8 Cpu::ABSY()
{
	uint8 lo = read(pc.reg++);
	return ((((read(pc.reg++) << 8) | lo) + Y) & 0x00FF);
}

uint8 Cpu::Implied()
{

}

uint8 Cpu::Relative()
{
	int8 relativeAddress = read(pc.reg++);
	pc.reg += relativeAddress;
}

uint8 Cpu::INDX()
{
	return read(X + pc.reg++);
}

uint8 Cpu::INDY()
{
	return read(Y + pc.reg++);
}

uint8 Cpu::Indirect()
{
	uint8 lo = read(pc.reg++);
	pc.reg = (read(pc.reg++) << 8) | lo;
	pc.reg++;
}


void Cpu::ADC() {}
void Cpu::AND() {}
void Cpu::ASL() {}

void Cpu::BCC() {}
void Cpu::BCS() {}
void Cpu::BEQ() {}
void Cpu::BIT() {}
void Cpu::BMI() {}
void Cpu::BNE() {}
void Cpu::BPL() {}
void Cpu::BRK() {}
void Cpu::BVC() {}
void Cpu::BVS() {}

void Cpu::CLC() {}
void Cpu::CLD() {}
void Cpu::CLI() {}
void Cpu::CLV() {}
void Cpu::CMP() {}
void Cpu::CPX() {}
void Cpu::CPY() {}

void Cpu::DEC() {}
void Cpu::DEX() {}
void Cpu::DEY() {}

void Cpu::EOR() {}

void Cpu::INC() {}
void Cpu::INX() {}
void Cpu::INY() {}

void Cpu::JMP() {}
void Cpu::JSR() {}

void Cpu::LDA() {}
void Cpu::LDX() {}
void Cpu::LDY() {}
void Cpu::LSR() {}

void Cpu::NOP() {}

void Cpu::ORA() {}

void Cpu::PHA() {}
void Cpu::PHP() {}
void Cpu::PLA() {}
void Cpu::PLP() {}

void Cpu::ROL() {}
void Cpu::ROR() {}
void Cpu::RTI() {}
void Cpu::RTS() {}

void Cpu::SBC() {}
void Cpu::SEC() {}
void Cpu::SED() {}
void Cpu::SEI() {}
void Cpu::STA() {}
void Cpu::STX() {}
void Cpu::STY() {}

void Cpu::TAX() {}
void Cpu::TAY() {}
void Cpu::TSX() {}
void Cpu::TXA() {}
void Cpu::TXS() {}
void Cpu::TYA() {}