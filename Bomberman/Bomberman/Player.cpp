#include "Player.h"
#include "Macro.h"

Player::Player(const std::string& _name, const int _id)
{
	id = _id;
	name = _name;
	pawn = new Pawn(_name);
	bombSac = std::vector<Bomb*>{ new Bomb() };
}

Player::~Player()
{
	delete pawn;
	pawn = nullptr;
	macro::DeleteVectorWParamPointer(bombSac);
}

void Player::TeleportPawnToCoordinates(const Coords& _coordinates)
{
	pawn->Move(_coordinates);
}

