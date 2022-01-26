#include "Cpu.h"

#include "Bus.h"
#include <iostream>

using namespace std;

Cpu::Cpu()
{
	pc.reg = 0;
	sp = 0;
	status.reg = 0;
	A = X = Y = 0;
	opcode = 0;
	cycles = 0;

	cout << instructions[254].addressingModeName << endl;
	(this->*instructions[254].addressingMode)();
}

void Cpu::connectToBus(Bus* bus)
{
	this->bus = bus;
}

void Cpu::doCycle()
{

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

/// <summary>
/// Addressing modes
/// </summary>	
void Cpu::ACC() {}
void Cpu::IMM() {}
void Cpu::ABS() {}
void Cpu::ZP0() {}
void Cpu::ZPX() {}
void Cpu::ZPY() {}
void Cpu::ABX() { cout << "Working" << endl; }
void Cpu::ABY() {}
void Cpu::IMP() {}
void Cpu::REL() {}
void Cpu::IZX() {}
void Cpu::IZY() {}
void Cpu::IND() {}

void Cpu::YYY() {}

/// <summary>
/// Opcodes
/// </summary>
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

void Cpu::XXX() {}