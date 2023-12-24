#include "Pawn.h"

Pawn::Pawn() : Object(PawnColorManager::ChosePawnColor() + "\xDE\xDD" + COLORRESET, true, false)
{
	IsImune = false;
}

void Pawn::Move(const Coords& _coordinates)
{

}
