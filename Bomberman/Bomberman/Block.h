#pragma once
#include "Object.h"


enum BlastResistance
{
	UNBREAKABLE = -1, BREAKABLE, SOLID
};

class Block : public Object
{
	BlastResistance blastResistance;

public:
	virtual BlastResistance GetBlastResistance()const override
	{
		return blastResistance;
	}

public:
	Block(const Coords& _coords, const BlastResistance& _blastResistance);

private:
	void InitLook();
};

