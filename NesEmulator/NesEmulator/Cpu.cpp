#include "Cpu.h"

#include <iostream>
#include "Bus.h"

Cpu::Cpu()
{
	pc.reg = 0;
	status.reg = 0;
	sp = 0;
	A = X = Y = 0;

	opcode = 0;
	cycles = 0;

	fetched = 0;
	absoluteAddress = 0;
	relativeAddress = 0;
}

void Cpu::connectToBus(Bus* bus)
{
	this->bus = bus;
}


void Cpu::clock()
{
	if (cycles == 0)
	{
		opcode = read(pc.reg++);//Read current opcode
		(this->*instructions[opcode].executeOpcode)();//Execute opcode
		cycles += instructions[opcode].cycles;//Add the number of cycles of the instruction
	}
	cycles--;
}

void Cpu::reset()//?
{
	pc.lo = read(0xFFFC);
	pc.hi = read(0xFFFD);

	A = X = Y = 0;
	sp = 0xFD;
	status.reg = 0;

	//Set emulation variables
	absoluteAddress = 0;
	relativeAddress = 0;
	fetched = 0;
	opcode = 0;

	cycles = 8;//cycles = 6
}

void Cpu::irq()//?
{
	if (!status.I)
	{
		pushPcToStack();
		status.B = 0;
		status.I = 1;
		write(0x100 + sp--, status.reg);
		pc.lo = read(0xFFFF);
		pc.hi = read(0xFFFF);
		cycles = 7;
	}
}

void Cpu::nmi()//?
{
	pushPcToStack();
	status.B = 0;
	status.I = 1;
	write(0x100 + sp--, status.reg);
	pc.lo = read(0xFFFF);
	pc.hi = read(0xFFFF);
	cycles = 8;
}

uint8 Cpu::read(const uint16& address)const
{
	return bus->read(address);
}

void Cpu::write(const uint16& address, const uint8& data)
{
	bus->write(address, data);
}

void Cpu::fetch()
{
	(this->*instructions[opcode].doAddressing)();
	if (!(instructions[opcode].doAddressing == &Cpu::ACC))
		fetched = read(absoluteAddress);
	//else
	//	fetched = A;
}

void Cpu::updateFetched(const uint8& data)
{
	if (!(instructions[opcode].doAddressing == &Cpu::ACC))
		write(absoluteAddress, data);
	else
		A = data;
}


/// <summary>
/// Addressing modes
/// </summary>	
void Cpu::ACC()
{
	//Operation on the accumulator
	fetched = A;//Not usefull
}

void Cpu::IMM()
{
	absoluteAddress = pc.reg++;
}

void Cpu::ABS()
{
	uint8 lo = read(pc.reg++);
	absoluteAddress = ((read(pc.reg++) << 8) | lo);
}

void Cpu::ZP0()
{
	absoluteAddress = read(pc.reg++) & 0x00FF;
}

void Cpu::ZPX()
{
	absoluteAddress = (read(pc.reg++) + X) & 0x00FF;
}

void Cpu::ZPY()
{
	absoluteAddress = (read(pc.reg++) + Y) & 0x00FF;
}

void Cpu::ABX()
{
	uint8 lo = read(pc.reg++);
	uint8 hi = read(pc.reg++);
	absoluteAddress = ((hi << 8) | lo) + X;

	// If page boundary is corssed and if the instruction can have an additional cycle dureing page boundary
	if (((absoluteAddress & 0xFF00) != (hi << 8)) && instructions[opcode].pageBoundaryAddCycle)
		cycles++;
}

void Cpu::ABY()
{
	uint8 lo = read(pc.reg++);
	uint8 hi = read(pc.reg++);
	absoluteAddress = ((hi << 8) | lo) + Y;

	// If page boundary is corssed and if the instruction can have an additional cycle dureing page boundary
	if (((absoluteAddress & 0xFF00) != (hi << 8)) && instructions[opcode].pageBoundaryAddCycle)
		cycles++;
}

void Cpu::IMP()
{
	//Do nothing
}

void Cpu::REL()
{
	relativeAddress = read(pc.reg++);
	if (relativeAddress & 0x80)//if value is negative than we flip the upper bits to 1 (a relative address can be negative or positive)
		relativeAddress |= 0xFF00;
}

void Cpu::IZX()
{
	uint8 temp = read(pc.reg++);
	uint8 lo = read((temp + X) & 0x00FF);
	absoluteAddress = ((read((temp + X + 1) & 0x00FF) << 8) | lo);
}

void Cpu::IZY()
{
	uint16 temp = read(pc.reg++);
	uint8 lo = read(temp);
	uint8 hi = read((temp + 1) & 0x00FF);
	absoluteAddress = ((hi << 8) | lo) + Y;

	// If page boundary is corssed and if the instruction can have an additional cycle dureing page boundary
	if (((absoluteAddress & 0xFF00) != (hi << 8)) && instructions[opcode].pageBoundaryAddCycle)
		cycles++;
}

void Cpu::IND()
{
	uint8 pointerLo = read(pc.reg++);
	uint16 pointer = ((read(pc.reg++) << 8) | pointerLo);

	if (pointerLo == 0xFF)// Simulate bug
	{
		absoluteAddress = ((read(pointer & 0xFF00) << 8) | read(pointer + 0));
	}
	else// Normal behaviour
	{
		absoluteAddress = ((read(pointer + 1) << 8) | read(pointer + 0));
	}
}

void Cpu::YYY()
{
	cout << "Eror, addressing mode unknown" << endl;
	exit(1);
}


/// <summary>
/// Opcodes
/// </summary>
void Cpu::ADC()
{
	fetch();

	uint16 temp = A + fetched + status.C;

	// (If A and fetched are positives or negatives) && (A and result are not of the same sign) 
	// The carry is not really imporant in the first parentheses. If the accumulator is positive, 
	// even if the carry bit is not set the result cannot be under -128 because the max memory value is -128
	status.V = (((A ^ fetched) & 0x80) == 0) && (((A ^ temp) & 0x80) != 0);//Used for signed values

	status.C = (temp > 0xFF);//Used with unsigned values
	status.Z = ((temp & 0x00FF) == 0);
	status.N = (temp & 0x80);
	A = temp & 0x00FF;
}

void Cpu::AND()
{
	fetch();
	A &= fetched;
	status.Z = (A == 0);
	status.N = (A & 0b10000000);
}

void Cpu::ASL()
{
	fetch();
	uint16 temp = fetched << 1;
	status.C = temp > 0xFF;
	status.Z = ((temp & 0x00FF) == 0);
	status.N = temp & 0x80;
	updateFetched(temp & 0x00FF);
}

void Cpu::BCC()
{
	if (!status.C)
	{
		branchingSubFunction();
	}
}

void Cpu::BCS()
{
	if (status.C)
	{
		branchingSubFunction();
	}
}

void Cpu::BEQ()
{
	if (status.Z)
	{
		branchingSubFunction();
	}
}

void Cpu::BIT()
{
	fetch();
	uint8 temp = A & fetched;
	status.Z = (temp == 0);
	status.N = testBit(temp, 7);
	status.V = testBit(temp, 6);
}

void Cpu::BMI()
{
	if (status.N)
	{
		branchingSubFunction();
	}
}
void Cpu::BNE()
{
	if (!status.Z)
	{
		branchingSubFunction();
	}
}
void Cpu::BPL()
{
	if (!status.N)
	{
		branchingSubFunction();
	}
}
void Cpu::BRK()//?
{
	pc.reg++;
	// BRK appears to push data on the stack
	status.I = 1;
	pushPcToStack();
	status.B = 1;
	write(0x0100 + sp--, status.reg);
	status.B = 0;
	pc.hi = read(0xFFFF);
	pc.lo = read(0xFFFE);
}
void Cpu::BVC()
{
	if (!status.V)
	{
		branchingSubFunction();
	}
}
void Cpu::BVS()
{
	if (status.V)
	{
		branchingSubFunction();
	}
}

void Cpu::CLC()
{
	status.C = 0;
}
void Cpu::CLD()
{
	status.D = 0;
}
void Cpu::CLI()
{
	status.I = 0;
}
void Cpu::CLV()
{
	status.V = 0;
}
void Cpu::CMP()
{
	compareSubFunction(A);
}
void Cpu::CPX()
{
	compareSubFunction(X);
}
void Cpu::CPY()
{
	compareSubFunction(Y);
}

void Cpu::DEC()
{
	fetch();
	uint8 temp = --fetched;
	write(absoluteAddress, temp);
	status.Z = (temp == 0);
	status.N = (temp & 0x80);
}
void Cpu::DEX()
{
	X--;
	status.Z = (X == 0);
	status.N = (X & 0x80);
}
void Cpu::DEY()
{
	Y--;
	status.Z = (Y == 0);
	status.N = (Y & 0x80);
}

void Cpu::EOR()
{
	fetch();
	A ^= fetched;
	status.Z = (A == 0);
	status.N = (A & 0x80);
}

void Cpu::INC()
{
	fetch();
	uint8 temp = ++fetched;
	write(absoluteAddress, temp);
	status.Z = (temp == 0);
	status.N = (temp & 0x80);
}
void Cpu::INX()
{
	X++;
	status.Z = (X == 0);
	status.N = (X & 0x80);
}
void Cpu::INY()
{
	Y++;
	status.Z = (X == 0);
	status.N = (X & 0x80);
}

void Cpu::JMP()
{
	(this->*instructions[opcode].doAddressing)();
	pc.reg = absoluteAddress;
}
void Cpu::JSR()
{
	(this->*instructions[opcode].doAddressing)();
	pushPcToStack();
	pc.reg = absoluteAddress;
}

void Cpu::LDA()
{
	fetch();
	A = fetched;
	status.Z = (A == 0);
	status.N = (A & 0x80);
}
void Cpu::LDX()
{
	fetch();
	X = fetched;
	status.Z = (X == 0);
	status.N = (X & 0x80);
}
void Cpu::LDY()
{
	fetch();
	Y = fetched;
	status.Z = (Y == 0);
	status.N = (Y & 0x80);
}
void Cpu::LSR()
{
	fetch();
	status.C = (fetched & 0x01);
	uint8 temp = fetched >> 1;
	status.Z = (temp == 0);
	status.N = (temp & 0x80);
	updateFetched(temp);
}

void Cpu::NOP()
{
	//Do nothing
}

void Cpu::ORA()
{
	fetch();
	A |= fetched;
	status.Z = (A == 0);
	status.N = (A & 0x80);
}

void Cpu::PHA()
{
	write(0x0100 + sp--, A);
}

void Cpu::PHP()
{
	write(0x0100 + sp--, status.reg);//?
}

void Cpu::PLA()
{
	A = read(++sp + 0x100);
	status.Z = (A == 0);
	status.N = (A & 0x80);
}
void Cpu::PLP()//?
{
	status.reg = read(++sp + 0x100);
}

void Cpu::ROL()
{
	fetch();
	uint16 temp = (fetched << 1) | (status.C & 0x01);
	status.C = (temp & 0xFF00);
	status.Z = (temp == 0);
	status.N = (temp & 0x80);
	updateFetched(temp & 0x00FF);
}
void Cpu::ROR()
{
	fetch();
	uint8 temp = (status.C << 7) | (fetched >> 1);
	status.C = fetched & 0x01;
	status.Z = (temp == 0);
	status.N = (temp & 0x80);
	updateFetched(temp);
}
void Cpu::RTI()//?
{
	status.reg = read(++sp + 0x100);
	status.B = 0;
	pc.lo = read(++sp + 0x100);
	pc.hi = read(++sp + 0x100);
}

void Cpu::RTS()//?
{
	pc.lo = read(++sp + 0x100);
	pc.hi = read(++sp + 0x100);
	//pc.reg++;
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
	status.C = 1;
}
void Cpu::SED()
{
	status.D = 1;
}
void Cpu::SEI()
{
	status.I = 1;
}
void Cpu::STA()
{
	(this->*instructions[opcode].doAddressing)();
	write(absoluteAddress, A);
}
void Cpu::STX()
{
	(this->*instructions[opcode].doAddressing)();
	write(absoluteAddress, X);
}
void Cpu::STY()
{
	(this->*instructions[opcode].doAddressing)();
	write(absoluteAddress, Y);
}

void Cpu::TAX()
{
	X = A;
	status.Z = (X == 0);
	status.N = (X & 0x80);
}
void Cpu::TAY()
{
	Y = A;
	status.Z = (Y == 0);
	status.N = (Y & 0x80);
}
void Cpu::TSX()
{
	X = sp;
	status.Z = (X == 0);
	status.N = (X & 0x80);
}
void Cpu::TXA()
{
	A = X;
	status.Z = (A == 0);
	status.N = (A & 0x80);
}
void Cpu::TXS()
{
	sp = X;
}
void Cpu::TYA()
{
	A = Y;
	status.Z = (A == 0);
	status.N = (A & 0x80);
}

void Cpu::XXX()
{
	cout << "Eror, opcode unknown" << endl;
	exit(1);
}




void Cpu::branchingSubFunction()
{
	cycles++;// Branch occurs so we're adding one cycle
	(this->*instructions[opcode].doAddressing)();//Supposed to be only REL
	absoluteAddress = pc.reg + relativeAddress;

	if ((absoluteAddress & 0xFF00) != (pc.reg & 0xFF00))// If branch occurs to a different page, add one cycle
		cycles++;

	pc.reg = absoluteAddress;
}

void Cpu::compareSubFunction(const uint8& param)
{
	fetch();
	uint16 temp = param - fetched;
	//status.C = param >= fetched;//?//
	status.C = temp > 0xFF;
	status.Z = (temp & 0x00FF) == 0;
	status.N = temp & 0x0080;
}

void Cpu::pushPcToStack()
{
	write(0x0100 + sp--, pc.hi);
	write(0x0100 + sp--, pc.lo);
}