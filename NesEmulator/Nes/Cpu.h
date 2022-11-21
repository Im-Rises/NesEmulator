#ifndef DEF_CPU
#define DEF_CPU

#include <string>
#include "../binaryLib/binaryLib.h"

class Bus;

class Cpu
{
private:
	union
	{
		struct
		{
			uint8 lo : 8;
			uint8 hi : 8;
		};
		uint16 reg;
	}pc;

	//Bitfield and union
	union
	{
		struct
		{
			bool
				C : 1,
				Z : 1,
				I : 1,
				D : 1,
				B : 1,
				U : 1,	//Unused (supposed to be always at 1)
				V : 1,
				N : 1;
		};
		uint8 reg;
	}status;

	//union
	//{
	//	struct
	//	{
	//		uint8 S : 8;
	//		bool a : 1 = 1;
	//	};
	//	uint16 reg;
	//}sp;
	uint8 sp;

	uint8 A;
	uint8 X;
	uint8 Y;

	uint8 cycles;// Number of cycles to execute
	uint8 opcode;// Opcode being executed

	// Use of a struct with function pointers to handle the different addressing modes and opcodes.
	struct
	{
		std::string opcodeName;
		void (Cpu::* executeOpcode)(void);
		std::string addressingModeName;
		void (Cpu::* doAddressing)(void);
		uint8 cycles;
		bool pageBoundaryAddCycle;// Inform if the instruction can lead to an additional cycle due to page boundary
	}
	const instructions[0xFF + 1] =
	{
		//0x00
		{"BRK",&Cpu::BRK,"IMP",&Cpu::IMP,7,0},
		{"ORA",&Cpu::ORA,"IZX",&Cpu::IZX,6,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"ORA",&Cpu::ORA,"ZP0",&Cpu::ZP0,3,0},
		{"ASL",&Cpu::ASL,"ZP0",&Cpu::ZP0,5,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"PHP",&Cpu::PHP,"IMP",&Cpu::IMP,3,0},
		{"ORA",&Cpu::ORA,"IMM",&Cpu::IMM,2,0},
		{"ASL",&Cpu::ASL,"ACC",&Cpu::ACC,2,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"ORA",&Cpu::ORA,"ABS",&Cpu::ABS,4,0},
		{"ASL",&Cpu::ASL,"ABS",&Cpu::ABS,6,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},

		//0x10
		{"BPL",&Cpu::BPL,"REL",&Cpu::REL,2,0},
		{"ORA",&Cpu::ORA,"IZY",&Cpu::IZY,5,1},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"ORA",&Cpu::ORA,"ZPX",&Cpu::ZPX,4,0},
		{"ASL",&Cpu::ASL,"ZPX",&Cpu::ZPX,6,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"CLC",&Cpu::CLC,"IMP",&Cpu::IMP,2,0},
		{"ORA",&Cpu::ORA,"ABY",&Cpu::ABY,4,1},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"XXX",&Cpu::YYY,"XXX",&Cpu::YYY,0,0},
		{"ORA",&Cpu::ORA,"ABX",&Cpu::ABX,4,1},
		{"ASL",&Cpu::ASL,"ABX",&Cpu::ABX,7,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},

		//0x20
		{"JSR",&Cpu::JSR,"ABS",&Cpu::ABS,6,0},
		{"AND",&Cpu::AND,"IZX",&Cpu::IZX,6,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"BIT",&Cpu::BIT,"ZP0",&Cpu::ZP0,3,0},
		{"AND",&Cpu::AND,"ZP0",&Cpu::ZP0,3,0},
		{"ROL",&Cpu::ROL,"ZP0",&Cpu::ZP0,5,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"PLP",&Cpu::PLP,"IMP",&Cpu::IMP,4,0},
		{"AND",&Cpu::AND,"IMM",&Cpu::IMM,2,0},
		{"ROL",&Cpu::ROL,"ACC",&Cpu::ACC,2,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"BIT",&Cpu::BIT,"ABS",&Cpu::ABS,4,0},
		{"AND",&Cpu::AND,"ABS",&Cpu::ABS,4,0},
		{"ROL",&Cpu::ROL,"ABS",&Cpu::ABS,6,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},

		//0x30
		{"BMI",&Cpu::BMI,"REL",&Cpu::REL,2,0},
		{"AND",&Cpu::AND,"IZY",&Cpu::IZY,5,1},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"AND",&Cpu::AND,"ZPX",&Cpu::ZPX,4,0},
		{"ROL",&Cpu::ROL,"ZPX",&Cpu::ZPX,6,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"SEC",&Cpu::SEC,"IMP",&Cpu::IMP,2,0},
		{"AND",&Cpu::AND,"ABY",&Cpu::ABY,4,1},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"AND",&Cpu::AND,"ABX",&Cpu::ABX,4,1},
		{"ROL",&Cpu::ROL,"ABX",&Cpu::ABX,7,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},

		//0x40
		{"RTI",&Cpu::RTI,"IMP",&Cpu::IMP,6,0},
		{"EOR",&Cpu::EOR,"IZX",&Cpu::IZX,6,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"EOR",&Cpu::EOR,"ZP0",&Cpu::ZP0,3,0},
		{"LSR",&Cpu::LSR,"ZP0",&Cpu::ZP0,5,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"PHA",&Cpu::PHA,"IMP",&Cpu::IMP,3,0},
		{"EOR",&Cpu::EOR,"IMM",&Cpu::IMM,2,0},
		{"LSR",&Cpu::LSR,"ACC",&Cpu::ACC,2,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"JMP",&Cpu::JMP,"ABS",&Cpu::ABS,3,0},
		{"EOR",&Cpu::EOR,"ABS",&Cpu::ABS,4,0},
		{"LSR",&Cpu::LSR,"ABS",&Cpu::ABS,6,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},

		//0x50
		{"BVC",&Cpu::BVC,"REL",&Cpu::REL,2,0},
		{"EOR",&Cpu::EOR,"IZY",&Cpu::IZY,5,1},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"EOR",&Cpu::EOR,"ZPX",&Cpu::ZPX,4,0},
		{"LSR",&Cpu::LSR,"ZPX",&Cpu::ZPX,6,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"CLI",&Cpu::CLI,"IMP",&Cpu::IMP,2,0},
		{"EOR",&Cpu::EOR,"ABY",&Cpu::ABY,4,1},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"EOR",&Cpu::EOR,"ABX",&Cpu::ABX,4,1},
		{"LSR",&Cpu::LSR,"ABX",&Cpu::ABX,7,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},

		//0x60
		{"RTS",&Cpu::RTS,"IMP",&Cpu::IMP,6,0},
		{"ADC",&Cpu::ADC,"IZX",&Cpu::IZX,6,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"ADC",&Cpu::ADC,"ZP0",&Cpu::ZP0,3,0},
		{"ROR",&Cpu::ROR,"ZP0",&Cpu::ZP0,5,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"PLA",&Cpu::PLA,"IMP",&Cpu::IMP,4,0},
		{"ADC",&Cpu::ADC,"IMM",&Cpu::IMM,2,0},
		{"ROR",&Cpu::ROR,"ACC",&Cpu::ACC,2,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"JMP",&Cpu::JMP,"IND",&Cpu::IND,5,0},
		{"ADC",&Cpu::ADC,"ABS",&Cpu::ABS,4,0},
		{"ROR",&Cpu::ROR,"ABS",&Cpu::ABS,6,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},

		//0x70
		{"BVS",&Cpu::BVS,"REL",&Cpu::REL,2,0},
		{"ADC",&Cpu::ADC,"IZY",&Cpu::IZY,5,1},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"ADC",&Cpu::ADC,"ZPX",&Cpu::ZPX,4,0},
		{"ROR",&Cpu::ROR,"ZPX",&Cpu::ZPX,6,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"SEI",&Cpu::SEI,"IMP",&Cpu::IMP,2,0},
		{"ADC",&Cpu::ADC,"ABY",&Cpu::ABY,4,1},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"ADC",&Cpu::ADC,"ABX",&Cpu::ABX,4,1},
		{"ROR",&Cpu::ROR,"ABX",&Cpu::ABX,7,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},

		//0x80
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"STA",&Cpu::STA,"IZX",&Cpu::IZX,6,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"STY",&Cpu::STY,"ZP0",&Cpu::ZP0,3,0},
		{"STA",&Cpu::STA,"ZP0",&Cpu::ZP0,3,0},
		{"STX",&Cpu::STX,"ZP0",&Cpu::ZP0,3,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"DEY",&Cpu::DEY,"IMP",&Cpu::IMP,2,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"TXA",&Cpu::TXA,"IMP",&Cpu::IMP,2,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"STY",&Cpu::STY,"ABS",&Cpu::ABS,4,0},
		{"STA",&Cpu::STA,"ABS",&Cpu::ABS,4,0},
		{"STX",&Cpu::STX,"ABS",&Cpu::ABS,4,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},

		//0x90
		{"BCC",&Cpu::BCC,"REL",&Cpu::REL,2,0},
		{"STA",&Cpu::STA,"IZY",&Cpu::IZY,6,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"STY",&Cpu::STY,"ZPX",&Cpu::ZPX,4,0},
		{"STA",&Cpu::STA,"ZPX",&Cpu::ZPX,4,0},
		{"STX",&Cpu::STX,"ZPX",&Cpu::ZPX,4,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"TYA",&Cpu::TYA,"IMP",&Cpu::IMP,2,0},
		{"STA",&Cpu::STA,"ABY",&Cpu::ABY,5,0},
		{"TXS",&Cpu::TXS,"IMP",&Cpu::IMP,2,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"STA",&Cpu::STA,"ABX",&Cpu::ABX,5,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},

		//0xA0
		{"LDY",&Cpu::LDY,"IMM",&Cpu::IMM,2,0},
		{"LDA",&Cpu::LDA,"IZX",&Cpu::IZX,6,0},
		{"LDX",&Cpu::LDX,"IMM",&Cpu::IMM,2,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"LDY",&Cpu::LDY,"ZP0",&Cpu::ZP0,3,0},
		{"LDA",&Cpu::LDA,"ZP0",&Cpu::ZP0,3,0},
		{"LDX",&Cpu::LDX,"ZP0",&Cpu::ZP0,3,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"TAY",&Cpu::TAY,"IMP",&Cpu::IMP,2,0},
		{"LDA",&Cpu::LDA,"IMM",&Cpu::IMM,2,0},
		{"TAX",&Cpu::TAX,"IMP",&Cpu::IMP,2,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"LDY",&Cpu::LDY,"ABS",&Cpu::ABS,4,0},
		{"LDA",&Cpu::LDA,"ABS",&Cpu::ABS,4,0},
		{"LDX",&Cpu::LDX,"ABS",&Cpu::ABS,4,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},

		//0xB0
		{"BCS",&Cpu::BCS,"REL",&Cpu::REL,2,0},
		{"LDA",&Cpu::LDA,"IZY",&Cpu::IZY,5,1},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"LDY",&Cpu::LDY,"ZPX",&Cpu::ZPX,4,0},
		{"LDA",&Cpu::LDA,"ZPX",&Cpu::ZPX,4,0},
		{"LDX",&Cpu::LDA,"ZPY",&Cpu::ZPY,4,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"CLV",&Cpu::CLV,"IMP",&Cpu::IMP,2,0},
		{"LDA",&Cpu::LDA,"ABY",&Cpu::ABY,4,1},
		{"TSX",&Cpu::TSX,"IMP",&Cpu::IMP,2,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"LDY",&Cpu::LDY,"ABX",&Cpu::ABX,4,1},
		{"LDA",&Cpu::LDA,"ABX",&Cpu::ABX,4,1},
		{"LDX",&Cpu::LDX,"ABY",&Cpu::ABY,4,1},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},

		//0xC0
		{"CPY",&Cpu::CPY,"IMM",&Cpu::IMM,2,0},
		{"CMP",&Cpu::CMP,"IZX",&Cpu::IZX,6,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"CPY",&Cpu::CPY,"ZP0",&Cpu::ZP0,3,0},
		{"CMP",&Cpu::CMP,"ZP0",&Cpu::ZP0,3,0},
		{"DEC",&Cpu::DEC,"ZP0",&Cpu::ZP0,5,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"INY",&Cpu::INY,"IMP",&Cpu::IMP,2,0},
		{"CMP",&Cpu::CMP,"IMM",&Cpu::IMM,2,0},
		{"DEX",&Cpu::DEX,"IMP",&Cpu::IMP,2,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"CPY",&Cpu::CPY,"ABS",&Cpu::ABS,4,0},
		{"CMP",&Cpu::CMP,"ABS",&Cpu::ABS,4,0},
		{"DEC",&Cpu::DEC,"ABS",&Cpu::ABS,6,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},

		//0xD0
		{"BNE",&Cpu::BNE,"REL",&Cpu::REL,2,0},
		{"CMP",&Cpu::CMP,"IZY",&Cpu::IZY,5,1},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"CMP",&Cpu::CMP,"ZPX",&Cpu::ZPX,4,0},
		{"DEC",&Cpu::DEC,"ZPX",&Cpu::ZPX,6,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"CLD",&Cpu::CLD,"IMP",&Cpu::IMP,2,0},
		{"CMP",&Cpu::CMP,"ABY",&Cpu::ABY,4,1},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"CMP",&Cpu::CMP,"ABX",&Cpu::ABX,4,1},
		{"DEC",&Cpu::DEC,"ABX",&Cpu::ABX,7,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},

		//0xE0
		{"CPX",&Cpu::CPX,"IMM",&Cpu::IMM,2,0},
		{"SBC",&Cpu::SBC,"IZX",&Cpu::IZX,6,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"CPX",&Cpu::CPX,"ZP0",&Cpu::ZP0,3,0},
		{"SBC",&Cpu::SBC,"ZP0",&Cpu::ZP0,3,0},
		{"INC",&Cpu::INC,"ZP0",&Cpu::ZP0,5,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"INX",&Cpu::INX,"IMP",&Cpu::IMP,2,0},
		{"SBC",&Cpu::SBC,"IMM",&Cpu::IMM,2,0},
		{"NOP",&Cpu::NOP,"IMP",&Cpu::IMP,2,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"CPX",&Cpu::CPX,"ABS",&Cpu::ABS,4,0},
		{"SBC",&Cpu::SBC,"ABS",&Cpu::ABS,4,0},
		{"INC",&Cpu::INC,"ABS",&Cpu::ABS,6,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},

		//0xF0
		{"BEQ",&Cpu::BEQ,"REL",&Cpu::REL,2,0},
		{"SBC",&Cpu::SBC,"IZY",&Cpu::IZY,5,1},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"SBC",&Cpu::SBC,"ZPX",&Cpu::ZPX,4,0},
		{"INC",&Cpu::INC,"ZPX",&Cpu::ZPX,6,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"SED",&Cpu::SED,"IMP",&Cpu::IMP,2,0},
		{"SBC",&Cpu::SBC,"ABY",&Cpu::ABY,4,1},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0},
		{"SBC",&Cpu::SBC,"ABX",&Cpu::ABX,4,1},
		{"INC",&Cpu::INC,"ABX",&Cpu::ABX,7,0},
		{"XXX",&Cpu::XXX,"YYY",&Cpu::YYY,0,0}

	};

	Bus* bus = nullptr;

	/// <summary>
	/// Temporary datas for the opcodes
	/// </summary>
	uint8 fetched;
	uint16 relativeAddress;
	uint16 absoluteAddress;

public:
	Cpu();
	void connectToBus(Bus* bus);
	void clock();
	void reset();
	void irq();
	void nmi();

private:

	uint8 read(const uint16& address) const;
	void write(const uint16& address, const uint8& data);

	void fetch();
	void updateFetched(const uint8& data);

	/// <summary>
	/// Addressing modes
	/// </summary>	
	void ACC();		//Accum
	void IMM();		//IMM
	void ABS();		//Absolute
	void ZP0();		//ZP
	void ZPX();		//ZP,X
	void ZPY();		//ZP,Y
	void ABX();		//ABS,X
	void ABY();		//ABX,Y
	void IMP();		//Implied
	void REL();		//Relative
	void IZX();		//IND,X
	void IZY();		//IND,Y
	void IND();		//Indirect

	void YYY();		//Unknown addressing mode


	/// <summary>
	/// Opcodes
	/// </summary>
	void ADC();
	void AND();
	void ASL();

	void BCC();
	void BCS();
	void BEQ();
	void BIT();
	void BMI();
	void BNE();
	void BPL();
	void BRK();
	void BVC();
	void BVS();

	void CLC();
	void CLD();
	void CLI();
	void CLV();
	void CMP();
	void CPX();
	void CPY();

	void DEC();
	void DEX();
	void DEY();

	void EOR();

	void INC();
	void INX();
	void INY();

	void JMP();
	void JSR();

	void LDA();
	void LDX();
	void LDY();
	void LSR();

	void NOP();

	void ORA();

	void PHA();
	void PHP();
	void PLA();
	void PLP();

	void ROL();
	void ROR();
	void RTI();
	void RTS();

	void SBC();
	void SEC();
	void SED();
	void SEI();
	void STA();
	void STX();
	void STY();

	void TAX();
	void TAY();
	void TSX();
	void TXA();
	void TXS();
	void TYA();

	void XXX();//unknown opcode


	void branchingSubFunction();
	void compareSubFunction(const uint8& param);
	void pushPcToStack();
	void interruptSubFunction();

public:
	uint16 getPc();
	void setPc(const uint16& value);
};

#endif
