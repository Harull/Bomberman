#pragma once
#include "Object.h"
#include "PawnColorManager.h"

class Pawn : public Object
{
	bool IsImune;

public:
	Pawn(const std::string& _name);


public:
	void Move(const Coords& _coordinates);
	
};

