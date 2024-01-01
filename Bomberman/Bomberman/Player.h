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
	int id;
	std::string name;
	std::vector<Bomb*> bombSac;

public:
	Player(const std::string& _name, const int _id);
	~Player();

private:
	

public:
	void DropBomb();
	void MovePawn(const Direction& _direction);
	void TeleportPawnToCoordinates(const Coords& _coordinates);
};

