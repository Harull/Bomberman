#pragma once
#include <vector>
#include "Pawn.h"
#include "Bomb.h"

enum Direction
{
	DI_NONE, RIGHT, LEFT, UP, DOWN
};

class Player 
{
	Pawn* pawn;
	std::vector<Bomb*> bombSac;

public:
	Player();
	~Player();

private:
	

public:
	void DropBomb();
	void MovePawn(const Direction& _direction);

};

