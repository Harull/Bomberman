#pragma once
#include "Object.h"
#include "PawnColorManager.h"

class Pawn : public Object
{
	bool IsImune;

public:
	Pawn();


public:
	void Move(const Coords& _coordinates);
	
};

