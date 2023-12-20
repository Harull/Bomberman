#pragma once
#include "Object.h"


class Pawn
{
	string color;
	bool IsImune;

public:
	void Move(const Coords& _coordinates);
};

