#pragma once
#include "Object.h"


enum BlastResistance
{
	UNBREAKABLE = -1, BREAKABLE, SOLID
};

class Block
{
	BlastResistance blastResistance;

public:
	BlastResistance GetBlastResistance()
	{
		return blastResistance;
	}
};

