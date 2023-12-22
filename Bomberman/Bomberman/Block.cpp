#include "Block.h"

Block::Block(const Coords& _coords, const BlastResistance& _blastResistance) 
	: Object(_coords, true, true)
{
	blastResistance = _blastResistance;
	InitLook();	
}

void Block::InitLook()
{
	switch (blastResistance)
	{
	case UNBREAKABLE:
		look += DARK_GRAY;
		break;
	case BREAKABLE:
		look += LIGHT_BROWN;
		break;
	case SOLID:
		look += BROWN;
		break;
	default:
		break;
	}
	look += "\xDB\xDB" WHITE;
}
