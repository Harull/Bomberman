#include "Player.h"
#include "Macro.h"

Player::Player()
{
	pawn = new Pawn();
	bombSac = std::vector<Bomb*>{ new Bomb() };
}

Player::~Player()
{
	delete pawn;
	pawn = nullptr;
	macro::DeleteVectorWParamPointer(bombSac);
}

