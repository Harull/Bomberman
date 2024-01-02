#include "Pawn.h"
#include "Grid.h"

Pawn::Pawn(const std::string& _name) : Object(PawnColorManager::ChosePawnColor(_name) + "\xDE\xDD" + COLORRESET, true, false)
{
	IsImune = false;
}

void Pawn::Move(const Coords& _coordinates, const bool _updateScreen)
{
	Grid::MovePawnToCoordinates(this, _coordinates, _updateScreen);
}
