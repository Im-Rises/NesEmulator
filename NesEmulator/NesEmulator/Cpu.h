#ifndef DEF_CPU
#define DEF_CPU

#include "binaryLib.h"

class Bus;

class Cpu
{
private:
	union
	{
		struct
		{
			uint8 lo : 4;
			uint8 hi : 4;
		};
		uint8 reg;
	}pc;

	//union
	//{
	//	struct
	//	{
	//		uint8 S : 8;
	//		bool a : 1;
	//	};
	//	uint16 reg;
	//}sp;

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
				: 1,	//Unused
				V : 1,
				N : 1;
		};
		uint8 reg;
	}status;

	uint8 sp;

	uint8 A;
	uint8 X;
	uint8 Y;

	int cycles;

	Bus* bus = nullptr;

public:
	Cpu();
	void connectBus(Bus* bus);

private:
	uint8 read(const uint16& address);
	void write(const uint16& address, const uint8& data);

	void clock();
	void reset();
	void irq();
	void nmi();

	uint8 fetchOpcode();
	void executeOpcode();

	/// <summary>
	/// Addressing modes
	/// </summary>	
	uint8 Accum();
	uint8 IMM();
	uint16 Absolute();
	uint16 ZP();
	uint8 ZPX();
	uint8 ZPY();
	uint8 ABSX();
	uint8 ABSY();
	uint8 Implied();
	uint8 Relative();
	uint8 INDX();
	uint8 INDY();
	uint8 Indirect();


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
};

#endif
