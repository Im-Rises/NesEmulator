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
	fetched = 0;
}

void Cpu::doCycle()
{
	cycles = 0;
	opcode = read(pc.reg++);
	//(this->*instructions[opcode].executeOpcode)();//Execute opcode
	cycles += instructions[opcode].cycles;
}

void Cpu::connectToBus(Bus* bus)
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


/// <summary>
/// Addressing modes
/// </summary>	
void Cpu::ACC()
{
	//fetched = A;
}

void Cpu::IMM()
{
	//fetched = read(pc.reg++);
}

void Cpu::ABS()
{
	//uint8 lo = read(pc.reg++); fetched = (lo | (read(pc.reg++) << 8));
}

void Cpu::ZP0()
{
	//fetched = read(pc.reg++);
}

void Cpu::ZPX()
{
	//fetched = read(pc.reg++) + X;
}

void Cpu::ZPY()
{
	//fetched = read(pc.reg++) + Y;
}

void Cpu::ABX()
{
	//uint8 lo = read(pc.reg++);
	//uint8 hi = read(pc.reg++);
	//uint16 address = ((lo | (hi << 8)) + X);
	//fetched = read(address);
	//((hi << 8) != (address & 0xFF00)) ? cycles++ : cycles;
}

void Cpu::ABY()
{
	//uint8 lo = read(pc.reg++);
	//uint8 hi = read(pc.reg++);
	//uint16 address = ((lo | (hi << 8)) + Y);
	//fetched = read(address);
	//((hi << 8) != (address & 0xFF00)) ? cycles++ : cycles;
}

void Cpu::IMP()//ERROR
{
	//fetched = read(A);
}

void Cpu::REL()
{
	//int8 relAddress = (int8)read(pc.reg++);
	//uint16 tempPc = pc.reg + relAddress;

	//if ((tempPc & 0xFF00) == (pc.reg & 0xFF00))//If branch on the same page
	//{
	//	cycles++;
	//}
	//else//If branch on a different page
	//{
	//	cycles += 2;
	//}
	//pc.reg = tempPc & 0x00FF;
}

void Cpu::IZX()
{
	//uint8 address = read(pc.reg++) + X;
	//fetched = read((read(address + 1) << 8) | read(address + 0));
}

void Cpu::IZY()
{
	//uint8 address = read(pc.reg++);
	//uint8 lo = read(address + 0);
	//uint8 hi = read(address + 1);
	//uint16 absAddress = ((hi << 8) | lo);
	//absAddress += Y;
	//fetched = read(absAddress);
	//((hi << 8) != (address & 0xFF00)) ? cycles++ : cycles;
}

void Cpu::IND()
{
	//uint8 ptrLo = read(pc.reg++);
	//uint8 ptrHi = read(pc.reg++);
	//uint16 pointer = (ptrHi << 8) | ptrLo;

	//if (ptrLo == 0x00FF)//Simulate hardware bug
	//{
	//	fetched = read(((read(pointer & 0xFF00) << 8) | read(pointer + 0)));
	//}
	//else
	//{
	//	fetched = read(((read(pointer + 1) << 8) | read(pointer + 0)));
	//}
}

void Cpu::YYY()
{
	cout << "Eror, addressing mode unknown" << endl; exit(1);
}


/// <summary>
/// Opcodes
/// </summary>
void Cpu::ADC()//Work with unsigned and signed values...
{
	uint16 temp = A + fetched + status.C;

	// (If A and fetched are positives or negatives) && (A and result are not of the same sign) 
	// The carry is not really imporant in the first parentheses. If the accumulator is positive, 
	// even if the carry bit is not set the result cannot be under -128 because the max memory value is -128
	status.V = (((A ^ fetched) & 0x80) == 0) && (((A ^ temp) & 0x80) != 0);//Used for signed values

	status.C = (temp > 0xFF);//Use with unsigned values //Carry bit same as (temp > 0xFF)
	status.Z = ((temp & 0x00FF) == 0);
	status.N = (temp & 0x80);
	A = temp & 0x00FF;
}

void Cpu::AND()
{
	A &= fetched;
	status.Z = (A == 0);
	status.N = (A & 0b10000000);
}

void Cpu::ASL()
{
	uint16 temp = fetched << 1;
	status.C = temp > 0xFF;
	status.Z = ((temp & 0x00FF) == 0);
	status.N = temp & 0x80;
	A = temp & 0x00FF;
	//Memory write to implement
}

void Cpu::BCC()
{
	if (!status.C)
	{

	}
}

void Cpu::BCS()
{
	if (status.C)
	{

	}
}

void Cpu::BEQ()
{
	if (status.Z)
	{

	}
}

void Cpu::BIT()
{
	uint8 temp = A & fetched;
	status.Z = (temp == 0);
	status.N = testBit(temp, 7);
	status.V = testBit(temp, 6);
}
void Cpu::BMI()
{
	if (status.N)
	{

	}
}
void Cpu::BNE()
{
}
void Cpu::BPL()
{
}
void Cpu::BRK()
{
}
void Cpu::BVC()
{
}
void Cpu::BVS()
{
}

void Cpu::CLC()
{
}
void Cpu::CLD()
{
}
void Cpu::CLI()
{
}
void Cpu::CLV()
{
}
void Cpu::CMP()
{
}
void Cpu::CPX()
{
}
void Cpu::CPY()
{
}

void Cpu::DEC()
{
}
void Cpu::DEX()
{
}
void Cpu::DEY()
{
}

void Cpu::EOR()
{
}

void Cpu::INC()
{
}
void Cpu::INX()
{
}
void Cpu::INY()
{
}

void Cpu::JMP()
{
}
void Cpu::JSR()
{
}

void Cpu::LDA()
{
}
void Cpu::LDX()
{
}
void Cpu::LDY()
{
}
void Cpu::LSR()
{
}

void Cpu::NOP()
{
}

void Cpu::ORA()
{
}

void Cpu::PHA()
{
}
void Cpu::PHP()
{
}
void Cpu::PLA()
{
}
void Cpu::PLP()
{
}

void Cpu::ROL()
{
}
void Cpu::ROR()
{
}
void Cpu::RTI()
{
}
void Cpu::RTS()
{
}

void Cpu::SBC()
{
	//Thanks to wikipedia for the explanation about subtract with borrow and subtract with carry (https://en.wikipedia.org/wiki/Carry_flag)

	// The Nes only use carry bit so, it is a subtract with carry to get the borrow. Borrow bit is equals to (1 - C), take a look at the wikipedia's chart
	// Be carefull on the wikipedia page C can be the borrow or the carry bit
	// A = A - M - B
	// A = A - M - (1 - C)
	// A = A + -M - (1 - C)
	// A = A + (~M + 1) - (1 - C)
	// A = A + ~M + C

	uint16 temp = A + ~fetched + status.C;

	//Because it is an addition, we can use the same expression as ADC to know the overflow :)
	status.V = (((A ^ ~fetched) & 0x80) == 0) && (((A ^ temp) & 0x80) != 0);

	status.C = (temp & 0xFF00);//Carry bit same as (temp > 0xFF)
	status.Z = ((temp & 0x00FF) == 0);
	status.N = (temp & 0x80);
	A = temp & 0x00FF;
}
void Cpu::SEC()
{
}
void Cpu::SED()
{
}
void Cpu::SEI()
{
}
void Cpu::STA()
{
}
void Cpu::STX()
{
}
void Cpu::STY()
{
}

void Cpu::TAX()
{
}
void Cpu::TAY()
{
}
void Cpu::TSX()
{
}
void Cpu::TXA()
{
}
void Cpu::TXS()
{
}
void Cpu::TYA()
{
}

void Cpu::XXX()
{
	cout << "Eror, opcode unknown" << endl; exit(1);
}