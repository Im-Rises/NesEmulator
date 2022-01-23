#ifndef DEF_CPU
#define DEF_CPU

class Bus;

class Cpu
{
private:
	//union Reg
	//{
	//	struct
	//	{
	//		char test : 2;
	//	};
	//};

	Bus* bus;

public:
	Cpu();
};

#endif
